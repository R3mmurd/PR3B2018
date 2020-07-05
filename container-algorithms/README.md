# Container algorithms

This directory contains two programs with generic containers algorithms
such as filter, map, fold, etc.

- **[container-algorithms-impl.C](container-algorithms-impl.C)**: Contains
  implementation and demos of some of these algorithms.

- **[container-algorithms-stl.C](container-algorithms-stl.C)**: Contains
  demos of using the implementation of the algorithms from the
  [STL](https://en.wikipedia.org/wiki/Standard_Template_Library).

## Usage

```bash
$ ./container-algorithms-impl
Elements [ 1 2 3 4 5 6 7 8 9 10 ]
Even elements: [ 2 4 6 8 10 ]
Odd elements: [ 1 3 5 7 9 ]
Elements power 2: [ 1 4 9 16 25 36 49 64 81 100 ]
Odd elements power 2: [ 4 16 36 64 100 ]
Sum(Elements): 55
Prod(Elements): 3628800
Are all odd: false
Some is odd: true
None of them if greater than 100: true
strings: [ hello bye run execute ]
string sizes: [ 5 3 3 7 ]
string sizes (less to 5): [ 3 3 ]
Concat(strings): hellobyerunexecute
Number of characters in strings: 18
```

```bash
$ ./container-algorithms-stl
Generated set = [ 907 137 735 643 164 350 88 341 293 663 ]
Are all elements greater or equal than 0? true
Are all elements odd? false
Is any element greater or equal than 0?  true
Is any element equal to 0?  false
Is any element odd?  true
Is none element greater or equal than 0? false
Is none element negative? true
Is none element equal to 0?  true
Is none element odd?  false
Printing each element by using for_each: 907 137 735 643 164 350 88 341 293 663 
Num of elements equal to 0: 0
Num of odd elements: 7
xs  = [ 907 137 735 643 164 350 88 341 293 663 ] and
xs2 = [ 907 137 735 643 164 700 176 682 586 1326 ]
They mismath since 350 from xs and 700 from xs2
10 not found in xs
The first element less than 300 in xs is: 137
xs  = [ 907 137 735 643 164 350 88 341 293 663 ] and
xs3 = [ 907 137 735 643 164 350 88 341 293 663 ]
xs  = [ 907 137 735 643 164 350 88 341 293 663 ] and
xs4= [ 907 137 735 643 341 293 663 ]
[ 0 0 0 0 0 0 0 0 0 0 ]
5
7
[ 1 2 12 2 12 2 ]
[ 2 12 2 12 2 ]
xs8 = [ 1 2 3 12 2 3 12 2 3 ] and
xs9 = [ 1 2 12 2 12 2 ]
xs8 = [ 1 2 3 12 2 3 12 2 3 ] and
xs10 = [ 2 12 2 12 2 ]
[ 1 2 0 12 2 0 12 2 0 ]
```
