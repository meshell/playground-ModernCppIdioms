#!/bin/sh

echo "TECHIO> redirect-streams \"Example output\""
./init_statements
echo "TECHIO> redirect-streams --reset"

./check_init_statements

