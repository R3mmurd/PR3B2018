/** This file contains some examples of recursive algorithms.

    @author: Alejandro J. Mujica
    @date: 11/10/2018
*/

# include <iostream>

using namespace std;

/// Computes n! (factorial)
unsigned fact(unsigned n)
{
  if (n < 2)
    return 1;

  return n * fact(n - 1);
}

/** Computes the nth Fibonacci number

    Warning: This is an exponential algorithm.
*/
unsigned fibonacci(unsigned n)
{
  if (n < 2)
    return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

/// Computes a power b
int pow(int a, unsigned b)
{
  if (b == 0)
    return 1;

  return a * pow(a, b - 1);
}

/// Searchs an element k in an array a with n elements
int search(int * a, int n, int k)
{
  if (n == 0)
    return -1;

  if (a[n - 1] == k)
    return n - 1;

  return search(a, n - 1, k);
}

/// Computes the sum of all of elements in an array
int sum(int * a, int n)
{
  if (n == 0)
    return 0;

  return a[n - 1] + sum(a, n - 1);
}

int main()
{
  cout << fact(5) << endl;
  cout << fibonacci(10) << endl;
  cout << pow(3, 4) << endl;

  int a[] = { 1, 4, 3, 5, 36, 89, 45, 32 };
  cout << search(a, 8, 10) << endl;
  cout << search(a, 8, 36) << endl;
  cout << sum(a, 8) << endl;
  
  return 0;
}
