#!/bin/bash

command=$1
value=$2

echo -e "$command" | ./42sh
exit_code=$?
echo "Exit code: $exit_code"
[ "$exit_code" -eq "$value" ] && exit 0 || exit 1