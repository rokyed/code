def = define? && define || require('amdefine') module
def ["promise"], (BasicPromise) ->

  # Extended version of a JS promise.
  # This provides all the features the promisejs.org
  # implementation/standard provides, and beyond that we
  # provide a reject/resolve methods in the promise instance
  # and support the function passed to the constructor
  # returning another promise
  class PromisePP extends BasicPromise
    constructor: (f) ->
      super (resolve, reject) =>
        @resolve = resolve
        @reject = reject

        return unless f
        p = f resolve, reject
        
        return unless p instanceof BasicPromise
        p.then @resolve, @reject
            

    # Resolve this Promise with the given value
    resolve: -> # dummy

    # Reject this Promise with the given value
    reject: -> # dummy
