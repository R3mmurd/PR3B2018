# Searching and sorting time

This directory contains programs that measure searching and sorting times
and prove experimentally some concepts. 

## Binary search

The file[bstime.C](bstime.C) contains a program that performs an experimental
proof of the execution time of the
[binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm).

### The experiment

The experiment consists of creating an array with N elements, starting with
N = 2^10. This sequence is built sorted from with numbers from 0 to N-1. Then
is executed the search method to search the value N (failed search, in other
words, the worst case). The input size is duplicated 20 times to get the data
to be plotted. Each experiment is executed 20 times to get the average execution
time.

Each experiment is executed 20 times to get the average execution time.

### Output

This programs generates two files: bs_plot.dat with the data to plot the size of
the array vs the execution time, and bs_plot.gp with the instructions to generate
a graphic with [gnuplot](http://www.gnuplot.info/).

### Usage

Compiling the program:

```bash
$ make bstime
```

Excecuting the program:

```bash
$ ./bstime
Experiment: 1
----------------
Input size: 1024	Execution time: 1825 ns
1024
Input size: 2048	Execution time: 1213 ns
2048
Input size: 4096	Execution time: 1238 ns
4096
Input size: 8192	Execution time: 1494 ns
8192
Input size: 16384	Execution time: 1584 ns
16384
Input size: 32768	Execution time: 1575 ns
32768
Input size: 65536	Execution time: 400 ns
65536
Input size: 131072	Execution time: 371 ns
131072
Input size: 262144	Execution time: 363 ns
262144
Input size: 524288	Execution time: 410 ns
524288
Input size: 1048576	Execution time: 503 ns
1048576
Input size: 2097152	Execution time: 754 ns
2097152
Input size: 4194304	Execution time: 1049 ns
4194304
Input size: 8388608	Execution time: 1463 ns
8388608
Input size: 16777216	Execution time: 1378 ns
16777216
Input size: 33554432	Execution time: 1436 ns
33554432
Input size: 67108864	Execution time: 1567 ns
67108864
Input size: 134217728	Execution time: 1795 ns
134217728
Input size: 268435456	Execution time: 2222 ns
268435456
Input size: 536870912	Execution time: 2326 ns
536870912

...

Experiment: 20
----------------
Input size: 1024	Execution time: 376 ns
1024
Input size: 2048	Execution time: 257 ns
2048
Input size: 4096	Execution time: 257 ns
4096
Input size: 8192	Execution time: 273 ns
8192
Input size: 16384	Execution time: 327 ns
16384
Input size: 32768	Execution time: 314 ns
32768
Input size: 65536	Execution time: 372 ns
65536
Input size: 131072	Execution time: 361 ns
131072
Input size: 262144	Execution time: 401 ns
262144
Input size: 524288	Execution time: 470 ns
524288
Input size: 1048576	Execution time: 507 ns
1048576
Input size: 2097152	Execution time: 524 ns
2097152
Input size: 4194304	Execution time: 733 ns
4194304
Input size: 8388608	Execution time: 1244 ns
8388608
Input size: 16777216	Execution time: 1643 ns
16777216
Input size: 33554432	Execution time: 1586 ns
33554432
Input size: 67108864	Execution time: 1987 ns
67108864
Input size: 134217728	Execution time: 1757 ns
134217728
Input size: 268435456	Execution time: 1779 ns
268435456
Input size: 536870912	Execution time: 2251 ns
536870912
```

Generating the graphic:

```bash
$ gnuplot bs_plot.gp
$ eog bs_graphic.png
```

![bs_graphic.png](graphics/bs_graphic.png)
