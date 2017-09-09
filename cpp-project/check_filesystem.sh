#!/bin/bash

echo "TECHIO> redirect-streams \"Example output\""
./filesystem
echo "TECHIO> redirect-streams --reset"

./check_filesystem_exercise

