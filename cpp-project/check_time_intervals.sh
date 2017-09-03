#!/bin/sh

echo "TECHIO> redirect-streams \"Example output\""
./test_time_intervals
echo "TECHIO> redirect-streams --reset"

./test_time_intervals

