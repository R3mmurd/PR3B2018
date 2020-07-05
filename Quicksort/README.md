# Quicksort

This directory contains a program that implements various versions
of the [quicksort](https://en.wikipedia.org/wiki/Quicksort) algorithm
on arrays.

The goal is to demonstrate how to improve the algorithm in order to
make it more time and space-efficient. Each implementation counts
the execution time and stack usage.

This program has an implementation of the partition function as a
higher-order function that receives as a parameter the function that
selects the pivot. There is a function that selects the first element
on the array as the pivot and another one that selects the median between
the first, the last, and the middle elements. It is implemented the
[insertion sort](https://en.wikipedia.org/wiki/Insertion_sort) algorithm.
Finally, there are four versions of non-recursive quicksort algorithms.
Each quicksort implementation is described below:

- **Basic implementation**: This is the simplest way to implement the algorithm.
   In this case, always the first element of the array partition is selected as
   the pivot, and the left partition is added to the stack before the right one.

- **First improvement**: This improvement consists in stacking first the smaller
  partition in order to save memory.

- **Second improvement**: This improvement keeps the first one and also selects
  the median as pivot in order to save time.

- **Third improvement**: This improvement keeps the second one and also makes a call
  to the insertion sort algorithm when the size of the partition small enough.

## Usage

By default, it is excecuted on an array with 10000 elements.

```bash
$ ./qs-time-space
Basic quicksort
---------------
Max stack size: 5001
Execution time: 85 ms

Quicksort (first improvement)
-------------------------
Max stack size: 2
Execution time: 85 ms

Quicksort (second improvement)
--------------------------
Max stack size: 3
Execution time: 45 ms

Quicksort (third improvement)
--------------------------
Max stack size: 3
Execution time: 44 ms
```

You can set the size of the array.

```bash
$ ./qs-time-space 100000
Basic quicksort
---------------
Max stack size: 50001
Execution time: 8266 ms

Quicksort (first improvement)
-------------------------
Max stack size: 2
Execution time: 8340 ms

Quicksort (second improvement)
--------------------------
Max stack size: 3
Execution time: 4408 ms

Quicksort (third improvement)
--------------------------
Max stack size: 3
Execution time: 4383 ms
```
