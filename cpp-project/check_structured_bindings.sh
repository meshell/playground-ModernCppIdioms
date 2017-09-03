#!/bin/sh

if make structured_binding ; then
  ./structured_binding | sed -e 's/^/TECHIO> message -c "Example output" /'
  ./check_structured_bindings
else
  echo "TECHIO> message -c \"Compilation\" Compilation error"
  echo "TECHIO> success false"
fi

