# Push Swap

A sorting algorithm project that sorts a stack of integers using a limited set of operations, optimizing for the minimum number of moves.

## 📋 Description

`push_swap` is a program that takes a list of integers as arguments and outputs the smallest list of instructions needed to sort them using two stacks (a and b) and a specific set of operations. The goal is to sort stack `a` in ascending order with the fewest possible operations.

## 🎯 Algorithm Strategy

The implementation uses an intelligent approach based on stack size:

### Sorting Methods

1. **2 Elements**: Simple swap if needed (`sa`)

2. **3 Elements**: Custom algorithm that iteratively checks and applies the optimal operation (swap, rotate, or reverse rotate) until sorted

3. **4-5 Elements**: 
   - Push the smallest element(s) to stack `b`
   - Sort the remaining 3 elements in stack `a`
   - Push everything back from `b` to `a`

4. **6+ Elements**: **Radix Sort (Binary)**
   - Assigns each number an index based on its sorted position (0 for smallest, 1 for second smallest, etc.)
   - Sorts by examining each bit position (LSB to MSB)
   - For each bit position, pushes numbers with bit 0 to stack `b`, keeps numbers with bit 1 in stack `a`
   - Pushes everything back from `b` to `a` after each bit iteration
   - Complexity: O(n × max_bits) where max_bits = log₂(n)

## 🔧 Available Operations

### Swap
- `sa` - Swap the first two elements of stack a
- `sb` - Swap the first two elements of stack b
- `ss` - Execute `sa` and `sb` simultaneously

### Push
- `pa` - Push the top element from stack b to stack a
- `pb` - Push the top element from stack a to stack b

### Rotate (shift up)
- `ra` - Rotate stack a (first element becomes last)
- `rb` - Rotate stack b
- `rr` - Execute `ra` and `rb` simultaneously

### Reverse Rotate (shift down)
- `rra` - Reverse rotate stack a (last element becomes first)
- `rrb` - Reverse rotate stack b
- `rrr` - Execute `rra` and `rrb` simultaneously

## 📁 Project Structure
```
push_swap/
├── main.c                      # Entry point and stack initialization
├── sortType.c                  # Determines which sorting algorithm to use
├── sort3-5.c                   # Sorting algorithms for small stacks
├── radix.c                     # Radix sort implementation for larger stacks
├── generateIndeces.c           # Index assignment and validation functions
├── swap.c                      # Swap operations (sa, sb, ss)
├── push.c                      # Push operations (pa, pb)
├── rotate.c                    # Rotate operations (ra, rb, rr)
├── reverseRotate.c             # Reverse rotate operations (rra, rrb, rrr)
├── ft_atoi.c                   # String to integer conversion with validation
├── ft_isdigit.c                # Digit validation
├── ft_lstnew_bonus.c           # Create new list node
├── ft_lstadd_back_bonus.c      # Add node to end of list
├── ft_lstsize_bonus.c          # Get list size
├── ft_lstclear.c               # Free entire list
├── makestack.c                 # Error handling utilities
├── push.h                      # Header file with structs and prototypes
└── Makefile                    # Compilation rules
```

## 🛠️ Data Structure
```c
typedef struct s_list
{
    int val;              // The actual integer value
    int i;                // Normalized index (position in sorted order)
    struct s_list *next;  // Pointer to next node
} t_list;
```

## 🔄 How It Works

### 1. Input Validation & Stack Creation
- Validates input arguments (must be valid integers)
- Checks for duplicates
- Checks if already sorted (exits early if true)
- Creates stack `a` from input

### 2. Index Generation
- Assigns normalized indices to each element based on sorted position
- Smallest value gets index 0, next smallest gets 1, etc.
- This indexing enables efficient radix sort

### 3. Sorting Algorithm Selection
The program automatically selects the optimal algorithm based on stack size:
- **Size 2**: Direct swap
- **Size 3**: Iterative comparison-based sort
- **Size 4-5**: Min-element extraction + 3-element sort
- **Size 6+**: Radix sort (bit manipulation)

### 4. Radix Sort Deep Dive
For larger stacks, the implementation uses binary radix sort:
```
Example: [5, 2, 8, 1, 9] → indices [3, 1, 4, 0, 5]
Binary representation:
  1 = 000
  2 = 001  
  3 = 011
  4 = 100
  5 = 101

Bit 0: Push elements with bit=0 to b, rotate bit=1
Bit 1: Repeat for second bit
Bit 2: Repeat for third bit
Result: Sorted!
```

## 🔧 Compilation
```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

## 💡 Usage
```bash
# Basic usage
./push_swap 3 2 5 1 4

# Output example
pb
ra
pb
ra
ra
pa
pa

# With large numbers
./push_swap 42 -17 0 999 -2147483648 2147483647

# Test if output is valid (using checker if available)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## ✅ Input Validation

The program performs comprehensive error checking:
- Only accepts valid integers within `int` range (-2147483648 to 2147483647)
- Detects and rejects duplicates
- Handles signs (+/-)
- Validates numeric format
- Outputs "Error\n" to stderr for invalid input

## 📊 Performance

Expected operation counts:
- **3 numbers**: 0-2 operations
- **5 numbers**: maximum 12 operations
- **100 numbers**: < 700 operations (radix sort)
- **500 numbers**: < 5500 operations (radix sort)

## 🎓 Key Concepts Learned

- **Stack manipulation**: Understanding stack operations and their combinations
- **Algorithm optimization**: Choosing the right algorithm based on input size
- **Bit manipulation**: Using binary properties for efficient sorting
- **Index normalization**: Simplifying sorting by working with positions
- **Linked lists**: Dynamic data structure management
- **Memory management**: Proper allocation and deallocation

## 🚀 42 Project

This project is part of the 42 school curriculum, focusing on sorting algorithms, data structures, and algorithmic thinking. The challenge is not just to sort, but to sort with the minimum number of operations.

## 🔍 Error Handling

The program handles various error cases:
- Non-numeric arguments → Error
- Integer overflow → Error  
- Duplicate values → Error
- No arguments → Error
- Invalid characters → Error

All errors output "Error\n" to stderr and exit with status 1.
