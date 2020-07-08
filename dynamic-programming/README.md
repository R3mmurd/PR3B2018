# Dynamic programming

This directory contains a program with the implementation of
two algorithms to solve the problem,
[Rod Cutting](https://web.stanford.edu/class/archive/cs/cs161/cs161.1168/lecture12.pdf).
The first of them is done with simple
[backtracking](https://en.wikipedia.org/wiki/Backtracking). The second one applies
[dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming) in order to
improve the execution time.

## Usage

```bash
$ ./cut_rod 
Result with basic algorithm: 56
Execution time: 2445573 ns
Result with memoizated algorithm: 56
Execution time: 2319 ns
```
