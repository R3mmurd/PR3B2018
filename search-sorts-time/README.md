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
```

Generating the graphic:

```bash
$ gnuplot bs_plot.gp
$ eog bs_graphic.png
```

![bs_graphic.png](graphics/bs_graphic.png)
