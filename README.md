

## Memory Allocation Program

This program demonstrates the use of dynamic memory allocation in C using the `malloc` and `free` functions. It allocates memory on the heap for character and integer arrays, assigns values, and then deallocates the memory to prevent memory leaks.

### How to Compile and Run

To compile the program, use the following command:

```sh
gcc -o memory_allocation memory_allocation.c
```

To run the program, you can provide an optional argument specifying the memory size to be allocated. If no argument is provided, the default memory size is 50 bytes.

```sh
./memory_allocation [size]
```

### Program Explanation

1. **Argument Handling**:
   - If the number of arguments (`argc`) is greater than 3, the program takes the first argument as the memory size to be allocated. Otherwise, it uses a default size of 50 bytes.

2. **Memory Allocation**:
   - The program allocates memory for a character array (`char_ptr`) and an integer array (`int_ptr`) using the `malloc` function. It checks if the allocation is successful by verifying that the pointers are not `NULL`.

3. **Memory Usage**:
   - The program copies a string into the allocated character array and assigns a value to the first element of the integer array.

4. **Memory Deallocation**:
   - The program frees the allocated memory using the `free` function to prevent memory leaks.

### Sample Output

When the program is run without arguments:

```sh
./memory_allocation
```

Output:

```
[*]allocating a memory of byte on heap (default size of Memory[50])
[*]char_ptr{address of 0x55b48acd66b0} value of {this is on heap memory address}
[*]int_ptr address of{0x55b48acd66f0} value of {12345}
[*]freeing... the char_ptr
if i set a memory size of char_ptr in {30}
[*]char_ptr address of {0x55b48acd67c0} value of {New memory allocation}
{*}freeing...the int_ptr
{*}freeing...the char_ptr
```

### Detailed Explanation of Functions

- **`malloc`**:
  - `malloc` is used to allocate a specified number of bytes of memory on the heap. It returns a pointer to the allocated memory block. If the allocation fails, it returns `NULL`.

  ```c
  char_ptr = (char *)malloc(_input * sizeof(char));
  if (char_ptr == NULL) {
      fprintf(stderr, "{*}error cannot allocated the memory \n");
      exit(-1);
  }
  ```

- **`free`**:
  - `free` is used to deallocate memory that was previously allocated by `malloc`, `calloc`, or `realloc`. It takes a pointer to the memory block to be freed.

  ```c
  free(char_ptr);
  char_ptr = NULL; // Setting pointer to NULL after free is a good practice to avoid dangling pointers
  ```


