#!/bin/sh
# Builds the program, runs it on input.txt and compares the result with output.txt.
set -e
g++ -Wall -Wextra -g main-isll.cpp isll.cpp -o main-isll
if ./main-isll < input.txt | diff -u output.txt -; then
  echo "Test passed: the output matches output.txt"
else
  echo "Test failed: see the differences above"
  exit 1
fi
