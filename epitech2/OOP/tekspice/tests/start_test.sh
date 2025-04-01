#!/bin/bash

EXEC="nanotekspice"
TEST_DIRECTORY="$PWD/tests"
REFER="/bin/tcsh -f"
TRAPSIG=0

CAT=`which cat`
GREP=`which grep`
RM=`which rm`

clear
echo "Testing $EXEC"


if [ ! -f "$EXEC" ]; then
    echo "Executable not found: $EXEC"
    make re
fi

cd "$TEST_DIRECTORY"
cp "../$EXEC" "$TEST_DIRECTORY/$EXEC"

for test_file in "$TEST_DIRECTORY"/*.nanotest; do
    while read -r line; do
            if [[ "$line" =~ ID=(.*) ]]; then
                test_id="${BASH_REMATCH[1]}"
            elif [[ "$line" =~ NAME=\"(.*)\" ]]; then
                test_name="${BASH_REMATCH[1]}"
            elif [[ "$line" =~ TESTFILE=\"(.*)\" ]]; then
                test_input="${BASH_REMATCH[1]}"
            elif [[ "$line" =~ COMMANDFILE=\"(.*)\" ]]; then
                test_command="${BASH_REMATCH[1]}"
            elif [[ "$line" =~ OUTPUTFILE=\"(.*)\" ]]; then
                test_output="${BASH_REMATCH[1]}"
            fi

        if [[ -n "$test_name" && -n "$test_input" && -n "$test_output" && -n "$test_id" && -n "$test_command" ]]; then
            ./test.sh "$test_name" "$test_id" "$EXEC" "$test_input" "$test_output" "$test_command"

            if [ $? -ne 0 ]; then
                echo "Test failed $test_name ($test_id)"
                rm "$TEST_DIRECTORY/$EXEC"
                exit 1
            fi

            test_name=""
            test_input=""
            test_output=""
            test_command=""
            test_id=""
        fi
    done < "$test_file"
done

rm "$TEST_DIRECTORY/$EXEC"

cd ..