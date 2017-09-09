#!/bin/bash

echo "TECHIO> redirect-streams \"Test output\""
if ./test_optional -s ; then
  echo "TECHIO> success true"
else
  echo "TECHIO> success false"
fi


