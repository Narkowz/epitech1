#!/bin/bash

file=$1
return_value=$2

echo "exit" | ./nanotekspice "$file"
exit_code=$?
echo "Exit code: $exit_code"
[ "$exit_code" -eq "$return_value" ] && exit 0 || exit 1