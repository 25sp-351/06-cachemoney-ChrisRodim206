#!/bin/bash

# Compile the C code
gcc -o memoization convert.c memoization.c maincache.c -Wall -Wextra

# Check if compilation was successful
if [[ ! -f "memoization" ]]; then
    echo "Compilation failed."
    exit 1
fi

# Test case function
test_case() {
    input=$1           
    expected=$2                    

    # Run the program, suppressing both stdout and stderr (debug output)
    output=$(echo "$input" | ./memoization 2>/dev/null)  

    # Print the actual program output
    echo "Input: $input"
    echo "Program Output:"
    echo "$output"
    echo "Expected Output: $expected"

    # Check if expected output is in the actual output
    if echo "$output" | grep -q "$expected"; then
        echo " Test Passed"
    else
        echo " Test Failed"
    fi
    echo "----------------------"
}

# Test cases r
test_case "0" "zero dollars and zero cents"
test_case "100" "one dollars"
test_case "1000" "ten dollars"
test_case "10000" "one hundred dollars"
test_case "122324" "twelve hundred twenty three dollars and twenty four cents"
test_case "1500" "fifteen dollars"
test_case "657869" "six thousand five hundred seventy-eight dollars and sixty-nine cents"
test_case "-1" "Negative value not supported."

# Clean up 
rm -f memoization
