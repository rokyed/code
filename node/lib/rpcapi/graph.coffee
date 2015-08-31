def = define? && define || require('amdefine') module
define [
    "Clazz",
    "lodash",
    "InexorRpc",
    "fs",
    "path",
    "promise",
    "util/PromisePP",
    "util/Offer"]
(Clazz, _, InexorRpc, Fs, Path, Promise, PromisePP, Offer) ->
  InexorFS = {}

  class InexorFS.Symlink extends InexorFS.File

  class CubeVariable extends Offer
    constructor: (@__var__) ->
      super => InexorRpc.getVariable @__var__

  class CubeEval extends Offer
    constructor: (@__command__) ->
      super => InexorRpc.callCubescript @__command__

  class Previewable extends Clazz
    constructor: (@previewDir, @previewName) ->
      registerAccessors()

    @get preview: ->
      InexorRpc.findImageMedia @previewDir + @previewName

  class Player extends Clazz
    @new: (a...) => new @ a...

    @listClients (local=true, bots=true) ->
      l = local && 1 : 0
      b = bots && 1 : 0
      InexorRpc.callCubescript("listclients #{l} #{b}").then (ci) =>
          ci.split(" ").map Number

    @listPlayers: => @listClients true, false

    @listBots: =>
      preq = [
        @listclients true, true
        @listclients true, false ]
      PromisePP.all preq, (clients, real_players) =>
        _.without clients, real_players

    constructor: (@playerno) ->
      registerAccessors()

    @get local: ->
      # we need the @ this binding here, thus the getter
      new CubeEval("getclientnum").then (num) =>
        num == @playerno

    # TODO: Make Cube... strongly typed
    spectating: \
      new CubeEval("isspectator #{@playerno}").then (i) ->
        i == 1

    name: new CubeEval "getclientname #{@playerno}"
    model: new CubeEval \
      "get_playermodel_name (getclientmodel #{@playerno})"
    team: new CubeEval "getclientteam #{@playerno}"
    bot: new Offer ->
      @listPlayers().then (players) ->
        @playerno not in players

  class Player.List
    ls: Player.listClients
    open: Player.new
  
  class Map extends Previewable
    @new: (a...) => new @ a...
    @dir: "media/map"

    constructor: (@name) ->
      super name, Map.dir

  class Map.List extends VirtualNode
    ls: =>
      InexorRpc.listPackageFiles().then (files) =>
        names = _.find files, (f) =>
          new RegExp("#{Map.dir}/(.*)\\.ogz$").exec(f)?[1]

    open: Map.new

  new InexorFs
    cubescript:
      call: InexorRpc.callCubescript
      getVariable: InexorRpc.getVariable

    maps: Map.List

    game:
      curmap: new CubeVariable("mapname").then (name) =>
        new Symlink "/maps/#{name}"
      mode: new CubeEval("at $modenames $mode")
      # TODO: List other players

    players: Player.list
    local_player: CubeEval("getclientnum").then (num) ->
      new Symlink "/players/#{Number(num)}"
