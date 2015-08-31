def = define? && define || require('amdefine') module
def [
    'util/BufferBuilder',
    'lodash',
    'util/PromisePP'],
(BufferBuilder, _, PromisePP) ->
  # A collection of utilities for working with streams and
  # other IO related concept
  IoUtils = {}

  # Read all the chunks in a stream
  # @param [Stream] stream – The stream to read
  # @returns [Promise<Array<Buffer>>] – The list of chunks we red
  IoUtils.collectStreamChunks = (stream) ->
    new PromisePP (resolve, reject) ->
      chunks = []
      stream.on 'data', (buf) -> chunks.push buf
      stream.on 'error', reject
      stream.on 'end', -> resolve chunks

  # Read an entire stream as a Buffer
  # @param [Stream] stream – The stream to read
  # @returns [Promise<Buffer>]
  IoUtils.dumpStream = (stream) ->
    IoUtils.collectStreamChunks(stream).then (chunks) ->
      len = _.sum _.pluck chunks, 'length'
      bbuf = new BufferBuilder alloc: len
      _.each chunks, bbuf.append
      bbuf

  # Read an entire stream as a String
  # @param [Stream] stream – The stream to read
  # @returns [Promise<String>]
  IoUtils.dumpStreamAsText = (stream) ->
    IoUtils.dumpStream(stream).then (buf) -> buf.toString()

  IoUtils
