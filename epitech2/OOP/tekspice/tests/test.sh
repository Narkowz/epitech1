#!/bin/bash

name=$1
id=$2
exec=$3
test_input=$4
test_output=$5
test_command=$6

echo ""
echo "Running test: $name ($id)"

if [ ! -f "$exec" ]; then
    echo "Test failed $name ($id): executable not found: $exec"
    exit 1
fi

echo "cat $test_command | ./$exec $test_input > $test_output.result"

cat "$test_command" | ./$exec "$test_input" > "$test_output.result"

return_value=$?

if [ $return_value -ne 0 ]; then
    echo "Test failed $name ($id): return value $return_value"
    rm "$test_output.result"
    exit 1
fi

if diff -q "$test_output.result" "$test_output" > /dev/null; then
    echo "Test passed!"
else
    echo "Test failed $name ($id): Differences found:"
    diff --color -y "$test_output.result" "$test_output"
    rm "$test_output.result"
    exit 1
fi

rm "$test_output.result"
