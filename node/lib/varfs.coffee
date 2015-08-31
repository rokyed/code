def = define? && define || require('amdefine') module
def ["lodash", "util/PromisePP"], (_, PromisePP) ->
  # A simple, virtual file system; mainly for accessing
  # small variables.
  VarFS = {}

  class VarFS.VError extends Error

  class VarFS.NotImplemented extends VarFS.VError
  class VarFS.NoSuchNode extends VarFS.VError
  class VarFS.NodeExists extends VarFS.VError

  class VarFS.InvalidNodeName extends VarFS.VError
  class VarFS.InvalidRealNodeName extends VarFS.InvalidNodeName
  
  class VarFS.WrongNodeType extends VarFS.VError
  class VarFS.NotAFile extends VarFS.WrongNodeType
  class VarFS.NotADirectory extends VarFS.WrongNodeType
  class VarFS.NotASymlink extends VarFS.WrongNodeType

  # Check whether the given node name is valid
  # This will essentially throw an error when a slash is
  # detected in the name
  # @param name The name to check
  VarFS.checkNodeName = (name) ->
    if "/" in name
      throw new VarFS.InvalidNodeName "Node names can not " +
        "contain '/': '" + name + "'"

  # Check whether the given real node name is correct.
  # Real node names are those that refer to real nodes, that
  # being any valid node names except "." and ".."
  # @param name The name to check
  VarFS.checkRealNodeName = (name) ->
    VarFS.checkNodeName name
    if name == "." || name == ".."
      throw new VarFS.InvalidRealNodeName "'.' and '..' can " +
        "not be real node names."

  # Parse the given path into nicely traversable tokens
  #
  # Essentially splits the given path at it's slashes.
  # Any self-referential path elements are removed ("/./", "").
  # If the path is absolute, the first token will not be
  # a valid node name but a slash.
  #
  # @param path The path to parse as a string
  # @return A list of node names
  VarFS.parsePath = (path) ->
    toks = _.reject (path.split "/"), (x) ->
      x == "." || x == ""
    if path[0] == "/" \
      then ["/"].concat toks
      else toks

  # Base class of all nodes in the Inexor VFS is based on.
  # Files as well as Directories. This knows it's parent
  # node and it's name (usually based on what it's parent
  # node tells it usually)
  #
  # Note that Nodes generally can only be regarded as
  # references to the underlying data, because they can be
  # generated on the fly VarFS.Directory#access.
  # This has the practical implication that multiple
  # references can exist to the same resource.
  # This also means, that the '===' operator won't work for
  # comparison;
  # Since the rood node is the only node guaranteed to be
  # a unique reference, comparison should be based on the
  # root node and the path.
  # Use .equal()
  class VarFS.Node
    # Points to the parent node of this; set by the parent
    # node
    parent: null

    # The name of this node; set by the parent node
    name: null

    # Check whether this is the VarFS tree root
    isRoot: =>
      parent == null

    # Find the root of this tree
    findRoot: =>
      if @isRoot() \
        then @
        else @parent.findRoot()

    # Get the path to this node
    path: =>
      if @isRoot \
        then "/"
        else "#{@parent.path()}/#{@name}"

    # Check if two nodes refer to equal resources.
    equal: (otr) =>
      @findRoot() == otr.findRoot() && @path() == otr.path()


    ls: => throw new VarFS.NotADirectory @path()
    access: => throw new VarFS.NotADirectory @path()
    create: => throw new VarFS.NotADirectory @path()
    rm: => throw new VarFS.NotADirectory @path()
    traverse: => throw new VarFS.NotADirectory @path()

    resolve: => throw new VarFS.NotASymlink @path()

    read: => throw new VarFS.NotAFile @path()
    write: => throw new VarFS.NotAFile @path()

  # A Node that points at some other node
  class VarFS.Symlink extends VarFS.Node
    # Get the path this points to
    link: => PromisePP.resolve(null).then =>
      @__subLink__()

    __subLink__: => throw new VarFS.NotImplemented

    # Resolve the Node this symlink points too
    resolve: =>
      @link().then @parent.traverse

  # A File is a leave in any VarFS tree.
  #
  # It contains a value, can be red from and written to;
  # it can not contain other VarFS nodes
  class VarFS.File extends VarFS.Node
    # Read the contents of this file
    #
    # @return A promise containing the data red
    read: => PromisePP.resolve(null).then =>
      @__subRead__()

    __subRead__: => throw new VarFS.NotImplemented

    # Write to this file
    #
    # @param dat The data to write
    # @return A promise resolved when the data is written
    write: (dat) => PromisePP.resolve(null).then =>
      @__subWrite__(dat)
    
    __subWrite__: => throw new VarFS.NotImplemented

  # A directory is a VarFS node that contains other VarFS
  # nodes.
  class VarFS.Directory extends VarFS.Node
    # List the contents of this directory
    #
    # @return A promise that resolves to an array containing
    # the names of all the sub nodes.
    ls: => PromisePP.resolve(null).then =>
      @__subLs__()

    __subLs__ => throw new VarFS.NotImplemented

    # Retrieve the sub node with the given name
    #
    # @returns A promise resolving to the node referenced to
    #   by the given name.
    access: (name) => PromisePP.resolve(null).then =>
      VarFS.checkRealNode name
      @__subAccess__ @

    __subAccess__: => throw new VarFS.NotImplemented

    # Create a sub node
    #
    # In subclasses you should overwrite __subCreate__ so
    # you don't have to handle replace manually.
    #
    # @param name The name of the sub node
    # @param value The sub node itself
    # @param replace Whether a sub node should be replaced
    create: (name, value, {replace}) =>
      PromisePP.resolve(null).then =>
        VarFS.checkRealNodeName name
        if !replace && @access name
          throw new VarFS.NodeExists "Node '#{@path()}/#{name}' " +
            "exists. Can't create a new node without replacing " +
            "that one, but the replace option was not specified."
        @__subCreate__ name, value

    __subCreate__: => throw new VarFS.NotImplemented

    # Remove a sub node
    # Subclasses should implement __sumRm__
    # @param name The name of the node to remove
    rm: (name) => PromisePP.resolve(null).then =>
      VarFS.checkRealNodeName name
      if @access name
        throw new VarFS.NoSuchNode "Can not remove non-" +
          "existing node '#{@path()}/#{name}'"
      @__subRm__ name

    __subRm__: => throw new VarFS.NotImplemented

    # Access the node at the given path
    #
    # Can be a relative or absolute paths.
    # Unlike on unix, the path '/..' would be erronous
    #
    # @param path The path to traverse to; either a re
    traverse: (path, {ignore_missing}) =>
      if _.isString path \
        then @traverse VarFS.parsePath path
        else @_traverse_toks_ path
      
    _traverse_toks_: ([next, rest...]) =>
      # Resolve the next element
      frev = =>
        switch first
          when "."  then @
          when ".." then @parent
          when "/"  then @findRoot()
          else @access(node)

      # Resolve any symlinks
      freal = (rev) =>
        if rev instanceof VarFS.Symlink \
          then rev.resolve()
          else rev

      # Recurse to the next node if necessary
      frecurse = (real) =>
        if rest.length == 0 \
          then real
          else real?.resolve(rest, ignore_missing: true)

      # Throw an error if we could not find the element
      fexist = (node) =>
        if node != undefined || ignore_missing \
          then node
          else throw new VarFS.NoSuchNode \
            "'#{path}' relative to '#{@path()}'"

      PromisePP.resolve(null)
        .then(frev)
        .then(freal)
        .then(frecurse)
        .then(fexist)
