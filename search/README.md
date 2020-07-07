# Search

This directory contains the implementation of a generic search
and its usage demo. The content of each file is described below:

- **[Makefile](Makefile)**: Contains the rules to compile the C++ program.

- **[math_utils.H](math_utils.H)**: Contains utility functions to round
  floating-point numbers.

- **[person.H](person.H)**: Contains the implementation of a Person class.

- **[search.H](search.H)**: Contains the implementation of the generic search.
  There are two versions of the algorithm: The first one performs the search
  on a generic set with a generic criterium. The second one is similar to
  the previous one but it adds variadic arguments.

- **[search.C](search.C)**: Contains a program that implements some criteria
  to search a Person instance in an array. It also contains a demo that
  fills a vector of people and performs searches with the defined criteria.

- **[search.py](search.py)**: Contains a Python program with all the same
  features described above.

## Usage

Compiling the C++ program

```bash
$ make search
```

Executing the C++ program

```bash
$ ./search 
Set with 9 people
< name: "Steve", age: 34, height: 2.03, weight: 102.75, has glasses: false >
< name: "Mike", age: 25, height: 2.08, weight: 105.88, has glasses: true >
< name: "Paul", age: 27, height: 1.58, weight: 116.71, has glasses: true >
< name: "John", age: 21, height: 1.97, weight: 71.53, has glasses: false >
< name: "James", age: 41, height: 1.75, weight: 104.09, has glasses: false >
< name: "Tarja", age: 25, height: 2.19, weight: 65.44, has glasses: false >
< name: "Amy", age: 18, height: 1.81, weight: 117.13, has glasses: true >
< name: "Floor", age: 40, height: 1.78, weight: 65.46, has glasses: false >
< name: "Bruce", age: 22, height: 1.88, weight: 69.85, has glasses: false >

Result searching with a standar C function
< name: "Steve", age: 34, height: 2.03, weight: 102.75, has glasses: false > is the first person with height greater than 1.80
Result searching with a functor
< name: "Steve", age: 34, height: 2.03, weight: 102.75, has glasses: false > is the first person with height greater than 1.80
Result searching with a lambda function
< name: "Steve", age: 34, height: 2.03, weight: 102.75, has glasses: false > is the first person with height greater than 1.80
Result searching with a functor with h as variable
< name: "Steve", age: 34, height: 2.03, weight: 102.75, has glasses: false > is the first person with height greater than 1.50
Result searching with a lambda function with h as variable
< name: "Steve", age: 34, height: 2.03, weight: 102.75, has glasses: false > is the first person with height greater than 1.9
Result searching with a C standar with h as variable by using variadic_seach
< name: "Steve", age: 34, height: 2.03, weight: 102.75, has glasses: false > is the first person with height greater than 1.85
Result searching with a lambda function with h as variable by usinfg variadic_seach
< name: "Steve", age: 34, height: 2.03, weight: 102.75, has glasses: false > is the first person with height greater than 1.6
Result searching with a functor with h as variable by using variadic_search
< name: "Steve", age: 34, height: 2.03, weight: 102.75, has glasses: false > is the first person with height greater than 1.6
```

Executing the Python program

```bash
$ python3 search.py 
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False >
< name: "Mike", age: 44, height: 2.14, weight: 108.75, has glasses: False >
< name: "Paul", age: 40, height: 1.87, weight: 77.23, has glasses: False >
< name: "John", age: 22, height: 1.62, weight: 102.66, has glasses: False >
< name: "James", age: 39, height: 1.61, weight: 62.86, has glasses: False >
< name: "Tarja", age: 44, height: 2.12, weight: 65.43, has glasses: False >
< name: "Amy", age: 35, height: 1.81, weight: 72.95, has glasses: False >
< name: "Floor", age: 24, height: 1.9, weight: 129.08, has glasses: False >
< name: "Bruce", age: 28, height: 1.65, weight: 69.12, has glasses: False >
Result searching with a function
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False > is the first person with height greater than 1.8
Result searching with a functor
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False > is the first person with height greater than 1.8
Result searching with a lambda
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False > is the first person with height greater than 1.8
Result searching with a functor and h as variable
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False > is the first person with height greater than 1.5
Result searching with a lambda and h as variable
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False > is the first person with height greater than 1.5
Result searching with a function and variadic_search
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False > is the first person with height greater than 1.6
Result searching with another function and variadic_search
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False > is the first person with height greater than 1.6
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False > is the first person with height greater than 1.6
Result searching with another functor and variadic_search
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False > is the first person with height greater than 1.6
Result searching with lambda and variadic_search
< name: "Steve", age: 26, height: 1.96, weight: 114.4, has glasses: False > is the first person with height greater than 1.6
```
