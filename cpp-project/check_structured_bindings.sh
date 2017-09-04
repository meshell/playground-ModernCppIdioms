#!/bin/bash

echo "TECHIO> redirect-streams \"Example output\""
./structured_binding
echo "TECHIO> redirect-streams --reset"

./check_structured_bindings

