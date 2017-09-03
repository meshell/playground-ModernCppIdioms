#!/bin/sh

echo "TECHIO> redirect-streams \"Example output\""
./test_measure_duration
echo "TECHIO> redirect-streams --reset"

./test_measure_duration

