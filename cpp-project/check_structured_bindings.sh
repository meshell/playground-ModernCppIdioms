#!/bin/sh

if make structured_binding ; then
  ./check_structured_bindings | sed -e 's/^/TECHIO> message -c "output" /'
else
  echo "TECHIO> success false"
fi
