#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color
BLUE='\033[0;34m'

# Function to check if a command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Check for required commands
for cmd in gcc valgrind bc; do
    if ! command_exists "$cmd"; then
        echo -e "${RED}Error: $cmd is not installed${NC}"
        echo "Install with: sudo pacman -S $cmd"
        exit 1
    fi
done

# Compile with all warnings and debug symbols
compile() {
    echo -e "${BLUE}Compiling push_swap...${NC}"
    gcc -g -Wall -Wextra -Werror *.c -o push_swap
    if [ $? -ne 0 ]; then
        echo -e "${RED}Compilation failed${NC}"
        exit 1
    fi
}

# Function to check if array is sorted
is_sorted() {
    local prev=$1
    shift
    for i in "$@"; do
        if [ "$i" -lt "$prev" ]; then
            return 1
        fi
        prev=$i
    done
    return 0
}

# Function to count operations
count_operations() {
    local count=$(grep -E "^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$" | wc -l)
    echo "$count"
}

# Function to validate output
validate_sort() {
    local input=("$@")
    local output=$(./push_swap "$@")
    local operations=$(echo "$output" | count_operations)
    local result=($(echo "$output" | grep -E "^[0-9]+$"))
    
    if is_sorted "${result[@]}"; then
        local size=${#input[@]}
        local max_ops
        if [ "$size" -le 3 ]; then
            max_ops=3
        elif [ "$size" -le 5 ]; then
            max_ops=12
        elif [ "$size" -le 100 ]; then
            max_ops=700
        else
            max_ops=5500
        fi
        
        echo -e "${GREEN}✓ Sorted correctly${NC}"
        if [ "$operations" -le "$max_ops" ]; then
            echo -e "${GREEN}✓ Operations: $operations (max: $max_ops)${NC}"
        else
            echo -e "${RED}✗ Too many operations: $operations (max: $max_ops)${NC}"
        fi
    else
        echo -e "${RED}✗ Not sorted correctly${NC}"
        echo "Input: ${input[*]}"
        echo "Output: ${result[*]}"
    fi
}

# Memory check using valgrind
check_memory() {
    echo -e "${BLUE}Checking memory...${NC}"
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap "$@" 2>&1 | grep -E "ERROR SUMMARY|in use at exit|total heap usage"
}

# Test cases
echo -e "${YELLOW}=== Basic Tests ===${NC}"

# Empty input
echo -e "\nTesting empty input:"
./push_swap

# Single number
echo -e "\nTesting single number:"
validate_sort "42"

# Already sorted
echo -e "\nTesting already sorted sequence:"
validate_sort 1 2 3 4 5

# Reverse sorted
echo -e "\nTesting reverse sorted sequence:"
validate_sort 5 4 3 2 1

# Small sequences
echo -e "\nTesting 3 numbers:"
validate_sort 2 1 3

echo -e "\nTesting 5 numbers:"
validate_sort 2 1 5 4 3

# Edge cases (sourced from GitHub evaluations)
echo -e "${YELLOW}\n=== Edge Cases ===${NC}"

# Maximum/Minimum integers
echo -e "\nTesting max/min integers:"
validate_sort 2147483647 -2147483648 0

# Duplicate numbers
echo -e "\nTesting duplicates:"
validate_sort 1 1 2 2 3

# Random sequences
echo -e "${YELLOW}\n=== Random Sequences ===${NC}"

# Generate and test random sequences
for size in 100 500; do
    echo -e "\nTesting $size random numbers:"
    nums=$(seq 1 $size | sort -R | tr '\n' ' ')
    validate_sort $nums
    check_memory $nums
done

# Known test cases from evaluations
echo -e "${YELLOW}\n=== Known Test Cases ===${NC}"
validate_sort 4 8 23 44 47 53 55 56 66

# Complex test cases
echo -e "\nTesting complex sequence:"
validate_sort 73 90 5 23 18 42 12 34 67 89 45 21 98 76 54

# Error handling
echo -e "${YELLOW}\n=== Error Handling ===${NC}"

echo -e "\nTesting non-numeric input:"
./push_swap "abc" 2>&1

echo -e "\nTesting out of range integers:"
./push_swap "2147483648" 2>&1

# Performance summary
echo -e "${YELLOW}\n=== Performance Summary ===${NC}"
echo "Run 'kcachegrind' or 'qcachegrind' for detailed performance analysis"

# Cleanup
rm -f push_swap
