#!/bin/sh

if make structured_binding ; then
  ./structured_binding | sed -e 's/^/TECHIO> message -c "output" /'
  ./check_structured_bindings
else
  echo "TECHIO> success false"
fi

