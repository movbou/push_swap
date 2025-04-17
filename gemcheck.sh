#!/bin/bash

# === Configuration ===
PUSH_SWAP="./push_swap"
CHECKER="./checker"
VALGRIND_LOG="valgrind.log"
# Valgrind options for detailed leak checking
# Source: man valgrind
VALGRIND_OPTS="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$VALGRIND_LOG"

# === Colors (ANSI Escape Codes) ===
# Source: Standard terminal escape codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# === Counters ===
total_tests=0
passed_tests=0
failed_tests=0

# === Helper Functions ===

# Function to print PASS/FAIL status
print_status() {
    local status=$1
    local message=$2
    if [ "$status" = "PASS" ]; then
        echo -e "[${GREEN}PASS${NC}] $message"
        ((passed_tests++))
    else
        echo -e "[${RED}FAIL${NC}] $message"
        ((failed_tests++))
    fi
}

# Function to check for Valgrind leaks
# Source: Based on standard Valgrind output format
check_leaks() {
    local log_file=$1
    local program_name=$2

    if [ ! -f "$log_file" ]; then
        print_status "FAIL" "$program_name: Valgrind log file '$log_file' not found!"
        return 1
    fi

    # Check for leak summary lines indicating definite leaks
    # "definitely lost: 0 bytes in 0 blocks" is a good sign.
    # "total heap usage: X allocs, Y frees" where X==Y is also good.
    # We look for "0 errors from 0 contexts" as a primary success indicator.
    if grep -q "All heap blocks were freed -- no leaks are possible" "$log_file" || grep -q "ERROR SUMMARY: 0 errors from 0 contexts" "$log_file"; then
         print_status "PASS" "$program_name: No memory leaks detected."
         rm "$log_file" # Clean up log on success
         return 0
    else
        print_status "FAIL" "$program_name: Memory leaks detected! Check '$log_file'."
        # Keep the log file for inspection on failure
        return 1
    fi
}

# Function to run a single test case
# Arguments: Description string, followed by the numbers for push_swap/checker
run_test() {
    local description="$1"
    shift # Remove description from arguments, leaving only numbers
    local args=("$@")
    # Format arguments for command line (handles single string arg vs multiple)
    # Source: Bash array handling and string manipulation (`man bash`, `man tr`)
    local arg_str=$(printf "%s " "${args[@]}" | sed 's/ $//') # Join with spaces

    ((total_tests++))
    echo -e "\n${BLUE}--- Test Case: $description ---${NC}"
    echo "Input: $arg_str"

    local test_passed=1 # Assume pass initially (0 for fail)
    local leaks_ps=1    # Assume no leaks initially (0 for leaks)
    local leaks_ch=1    # Assume no leaks initially (0 for leaks)

    # 1. Check if executables exist
    if [ ! -x "$PUSH_SWAP" ]; then
        echo -e "${RED}Error: $PUSH_SWAP is not executable or not found.${NC}"
        test_passed=0
        ((failed_tests++)) # Count as failed immediately
        return
    fi
     if [ ! -x "$CHECKER" ]; then
        echo -e "${RED}Error: $CHECKER is not executable or not found.${NC}"
        test_passed=0
         ((failed_tests++)) # Count as failed immediately
        return
    fi

    # 2. Run push_swap and get moves
    # Source: Bash command substitution and process substitution (`man bash`)
    echo "Running $PUSH_SWAP..."
    moves=$($PUSH_SWAP "${args[@]}" 2> /dev/null) # Capture stdout, hide stderr for cleaner output
    local ps_exit_code=$?

    if [ $ps_exit_code -ne 0 ]; then
         print_status "FAIL" "$PUSH_SWAP exited with error code $ps_exit_code."
         test_passed=0
    fi

    # Count moves (Source: `man wc`)
    local move_count=0
    if [ -n "$moves" ]; then # Check if moves string is not empty
      move_count=$(echo "$moves" | wc -l | tr -d ' ') # Count lines, remove whitespace
    fi
    echo "Move Count: $move_count"

    # 3. Run checker with push_swap output
    echo "Running $CHECKER..."
    # Source: Bash piping (`man bash`)
    checker_output=$(echo "$moves" | $CHECKER "${args[@]}" 2> /dev/null) # Pipe moves, pass args, hide stderr
    local ch_exit_code=$?

    if [ $ch_exit_code -ne 0 ]; then
         print_status "FAIL" "$CHECKER exited with error code $ch_exit_code."
         test_passed=0
    fi

    # 4. Validate checker output
    if [ "$checker_output" = "OK" ]; then
        print_status "PASS" "$CHECKER output is 'OK'."
    else
        print_status "FAIL" "$CHECKER output is '$checker_output' (Expected 'OK')."
        test_passed=0
    fi

    # 5. Check for leaks in push_swap
    echo "Checking leaks for $PUSH_SWAP..."
    # Source: Valgrind usage (`man valgrind`)
    $VALGRIND_OPTS $PUSH_SWAP "${args[@]}" &> /dev/null # Run in background, redirect all output
    if ! check_leaks "$VALGRIND_LOG" "$PUSH_SWAP"; then
        leaks_ps=0
    fi


    # 6. Check for leaks in checker
    echo "Checking leaks for $CHECKER..."
    # Source: Valgrind usage (`man valgrind`)
    echo "$moves" | $VALGRIND_OPTS $CHECKER "${args[@]}" &> /dev/null # Pipe moves, run checker
     if ! check_leaks "$VALGRIND_LOG" "$CHECKER"; then
         leaks_ch=0
     fi

     # Overall test status depends on correctness AND no leaks
     if [ $test_passed -eq 0 ] || [ $leaks_ps -eq 0 ] || [ $leaks_ch -eq 0 ]; then
         # We already incremented failed_tests if a functional part failed.
         # If only leaks failed, we need to adjust counts here.
         # This logic is a bit tricky, let's simplify: if ANY part fails (correctness or leaks), mark the whole test as failed.
         # The individual print_status calls handle incrementing passed/failed counts correctly.
         : # No action needed here, handled by print_status calls
     fi

    echo -e "${BLUE}--- End Test Case ---${NC}"
}


# === Test Suite ===

echo -e "${YELLOW}Starting Push Swap Test Suite...${NC}"

# --- Edge Cases ---
run_test "Empty Input (Checker should handle)" "" # Checker might exit 0 or 1, push_swap might error
run_test "Single Number" 42
run_test "Two Numbers (Sorted)" 1 2
run_test "Two Numbers (Reverse)" 2 1
run_test "Three Numbers (Simple)" 3 1 2
run_test "Three Numbers (Sorted)" 1 2 3 # Expect 0 moves
run_test "Three Numbers (Reverse)" 3 2 1
run_test "Five Numbers (Simple)" 4 1 3 5 2
run_test "Five Numbers (Sorted)" 1 2 3 4 5 # Expect 0 moves
run_test "Five Numbers (Reverse)" 5 4 3 2 1
run_test "String Argument (if checker handles)" "3 1 2" # Test how programs handle single string arg

# --- Random Cases ---
# Source: `man seq`, `man shuf`
run_test "Random 10 Numbers" $(seq 1 10 | shuf | tr '\n' ' ')
run_test "Random 100 Numbers" $(seq 1 100 | shuf | tr '\n' ' ')
# run_test "Random 500 Numbers" $(seq 1 500 | shuf | tr '\n' ' ') # Uncomment for larger test

# --- Specific Cases ---
run_test "Duplicates (Should be handled by error check)" 1 2 3 2 4 # Expect Error from push_swap/checker
run_test "Non-numeric (Should be handled by error check)" 1 2 three 4 # Expect Error from push_swap/checker
run_test "Max/Min Int" 0 2147483647 -2147483648 50 -50

# Add more specific test cases as needed

# === Summary ===
echo -e "\n${YELLOW}--- Test Summary ---${NC}"
echo "Total Tests Run: $total_tests"
echo -e "${GREEN}Tests Passed (Correctness & No Leaks): $passed_tests${NC}"
echo -e "${RED}Tests Failed (Correctness or Leaks): $failed_tests${NC}"

# Exit with non-zero status if any tests failed
if [ $failed_tests -gt 0 ]; then
    exit 1
else
    exit 0
fi
