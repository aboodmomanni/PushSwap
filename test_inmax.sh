#!/bin/bash

echo "======================================"
echo "Testing INT_MAX and INT_MIN Cases"
echo "======================================"
echo ""

echo "--- VALID CASES (Should sort) ---"
echo ""

echo "Test 1: INT_MAX, 0, INT_MIN"
./push_swap 2147483647 0 -2147483648
echo ""

echo "Test 2: Three near INT_MAX"
./push_swap 2147483647 2147483646 2147483645
echo ""

echo "Test 3: Three near INT_MIN"
./push_swap -2147483648 -2147483647 -2147483646
echo ""

echo "Test 4: Mixed boundaries"
./push_swap 0 2147483647 -2147483648 100 -100
echo ""

echo "Test 5: INT_MAX with small numbers"
./push_swap 2147483647 1 2 3 4
echo ""

echo "Test 6: INT_MIN with small numbers"
./push_swap -2147483648 -1 -2 -3 -4
echo ""

echo "Test 7: Just boundaries"
./push_swap 2147483647 -2147483648
echo ""

echo ""
echo "--- INVALID CASES (Should print 'Error') ---"
echo ""

echo "Test 8: INT_MAX + 1"
./push_swap 2147483648
echo ""

echo "Test 9: INT_MIN - 1"
./push_swap -2147483649
echo ""

echo "Test 10: Overflow in middle"
./push_swap 2147483647 2147483648 0
echo ""

echo "Test 11: Underflow in middle"
./push_swap -2147483648 -2147483649 0
echo ""

echo "Test 12: Way over INT_MAX"
./push_swap 9999999999
echo ""

echo "Test 13: Way under INT_MIN"
./push_swap -9999999999
echo ""

echo "Test 14: Multiple overflows"
./push_swap 2147483648 2147483649 2147483650
echo ""

echo ""
echo "--- MEMORY LEAK TESTS (Use with valgrind) ---"
echo ""

echo "Test 15: Valgrind with INT_MAX"
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 2147483647 0 -2147483648 2>&1 | grep "no leaks"
echo ""

echo "Test 16: Valgrind with overflow (should also have no leaks)"
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 2147483648 2>&1 | grep "no leaks"
echo ""

echo "======================================"
echo "Testing Complete!"
echo "======================================"