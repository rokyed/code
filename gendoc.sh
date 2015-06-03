filename="$1"
dirname="`dirname "$filename"`"

cd "$dirname"

find inexor | grep -P "^inexor/(client|server|engine|fpsgame|shared|net|rpc|ui|util)/.*\.h$" \
  | while read f; do
  echo "$f"

  out="`<<< "$f" sed 's@^inexor/@reflect/@; s@$@.xml@'`"
  outd="`dirname "$out"`"
  mkdir -p "$outd"

  ../CastXML/build/bin/castxml \
    -I"$PWD"/inexor/libraries/enet/ \
    -I"$PWD"/inexor/libraries/muparser/include/ \
    -I"$PWD"/inexor/platform/include/all/ \
    -I/usr/include \
    -I/usr/include/SDL2/ \
    -I"$PWD" -x c++ --std=gnu++11 --castxml-gccxml \
    "$f" -o "$out"
done
