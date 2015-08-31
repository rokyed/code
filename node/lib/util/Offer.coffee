def = define? && define || require('amdefine') module
def ["util/PromisePP", "util/io"], (PromisePP, IOUtil) ->

  class Offer
    constructor: (x) ->
      return x if x instanceof Offer
      @__resolverFun__ = x

    take: (a...) =>
      p = PromisePP.resolve @__resolverFun__()
      if a.length > 0 \
        then p.then a...
        else p

    then: (a...) =>
      new Offer =>
        @take a...

    catch: (onReject) =>
      @then undefined, onReject

  class Resource

  if require # Node
    Fs = require 'fs'
    Http = require 'http'

    class Offer.Stream extends Offer
      getStream: =>
        PromisePP.resolve @__streamGen__()

      constructor: (@__streamGen__, @binary=false) ->
        super =>
          @getStream.then (stream) =>
            @resolve if @binary \
              then IOUtil.dumpStream stream
              else IOUtil.dumpStreamAsText stream


    class Offer.File extends Offer.Stream
      constructor: (@__path__) ->
        super => Fs.createReadStream @__path__

    class Offer.URLDownload extends Offer.Stream
      constructor: (@__url__) ->
        super =>
          new PromisePP (resolve, reject) =>
            Http.request @__url__, resolve

  else require ['jquery'], ($) ->
    class Offer.URLDownload extends Offer
      constructor: (@__url__) ->
        super =>
          new PromisePP (resolve, reject) =>
            req = $.get @__url__
            req.done resolve
            req.fail reject


