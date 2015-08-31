def = define? && define || require('amdefine') module
def ["object-has", "lodash"], (ObjectHash, _) ->

  # This provides a stronger version of lodash's memoize
  # function:
  #
  # By default lodash coerces the first argument into
  # a string and uses that as the cache key.
  #
  # This function instead uses a full-blown hash over the
  # arguments, so this memoizes by the full list of
  # arguments which can by of any JS type.
  memoizeByHash = (f) ->
    _.memoize f, (a...) -> ObjectHash a
