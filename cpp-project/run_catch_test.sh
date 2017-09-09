#!/bin/bash

echo "TECHIO> redirect-streams \"Test output\""
if $@ ; then
  echo "TECHIO> success true"
else
  echo "TECHIO> success false"
fi

