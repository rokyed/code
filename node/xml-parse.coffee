xml = require 'node-xml'

XmlParser = (a..., def) ->
  xml.SaxParser a..., (cb, b...) ->
    cb.start = cb.onStartDocument
    cb.end = cb.onEndDocument
    cb.chars = cb.onCharacters
    cb.cdata = cb.onCdata
    cb.comment = cb.onComment
    cb.warn = cb.onWarning
    cb.error = cb.onError

    match = (spec, name) ->
      if spec instanceof RegExp
        name.match spec
      else if spec instanceof Function
        spec name
      else
        spec == name
    
    cb.elem = (spec, cb2) ->
      if not cb
        return cb.onStartElementNS spec

      cb.onStartElementNS (e, a...) ->
        if match spec, e
          cb2 e, a...

    cb.elem = (spec, cb2) ->
      if not cb
        return cb.onEndElementNS spec

      cb.onEndElementNS (e, a...) ->
        if match spec, e
          cb2 e, a...

    def.apply cb

  

class Set
  vals: []

  push: (x) =>
    unless x in @vals
      @vals.push x

  toString: -> "Set(#{@vals})"

types = new Set

parser = new xml.SaxParser (p) ->
  @error (msg) -> console.log "XML PARSER ERROR: ", msg
  @warn (msg) -> console.log "XML PARSER ERROR: ", msg
  @elem (name) -> types.push name
  @end ->
    console.log types.toString()

parser.parseFile "../reflect/engine/main.cpp"
