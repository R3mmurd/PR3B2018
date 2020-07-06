# Recursion

This directory contains some examples of recursive algorithms by applying
different techniques. The programs are structured as follows:

- **[recursion.C](recursion.C)**: Contains the implementation of some basic
  recursive algorithms. They are factorial, Fibonacci, power, search, and sum.

- **[queue-recursion.C](queue-recursion.C)**: Contains examples of how to implement
    queue recursion on the algorithms: factorial, power, and sum. This technique
    does not make sense in programming languages like C++ because it has loops.
    It makes sense in functional programming languages.

- **[queue-recursion.sml](queue-recursion.sml)**: Contains the same examples of
  [queue-recursion.C](queue-recursion.C) but implemented in
  [Standard ML](https://www.smlnj.org/sml.html).

- **[mutual-recursion.C](mutual-recursion.C)**: Contains an example of a problem
  that could be solved with two functions with one calling the other one and
  vice-versa generating mutual recursion.

- **[static-recursion.C](static-recursion.C)**: Contains examples of recursive
  algorithms solved at compile time. This is by implementing templates.

- **[tuple.C](tuple.C)**: Contains an example of how to implement a generic
  tuple by implementing a class and some functions with static recursion.

## Usage

```bash
$ ./recursion
120
55
81
-1
4
215
```

```bash
$ ./queue-recursion
120
81
215
```

```bash
$ sml
Standard ML of New Jersey v110.79 [built: Sat Oct 26 12:27:04 2019]
- use "queue-recursion.sml";
[opening queue-recursion.sml]
val fact = fn : int -> int
val power = fn : int * int -> int
val fact0 = 1 : int
val fact5 = 120 : int
val power3_4 = 81 : int
val it = () : unit
```

```bash
$ ./mutual-recursion 
true
false
false
true
true
false
```

```bash
$ ./static-recursion 
1
2
6
24
120
0
1
1
2
3
5
8
13
21
34
hello
hello 1 bye 10 8.5
```

```bash
$ ./tuple 
10
1
a
3.1
Hello
```
