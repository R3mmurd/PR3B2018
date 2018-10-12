/** This file contains some examples of queue recursion.

    In C++ this does not make any sense because you can use loops
    in order to don't use the recursion stack. However, if you write
    code in a functional programming language, this is very useful.

    @author: Alejandro J. Mujica
    @date: 11/10/2018
*/

# include <iostream>

using namespace std;

/// Computes n! (factorial) by carrying an accumulated value
unsigned fact(unsigned n, unsigned acc)
{
  if (n < 2)
    return acc;

  return fact(n - 1, acc * n);
}

/// Computes n! (factorial)
unsigned fact(unsigned n)
{
  return fact(n, 1);
}

/// Computes a power b by carrying an accumulated value
int pow(int x, unsigned y, int acc)
{
  if (y == 0)
    return acc;

  return pow(x, y - 1, x * acc);
}

int pow(int x, unsigned y)
{
  return pow(x, y, 1);
}

/// Computes the sum of all of elements in an array
int sum(int * a, int n, int acc)
{
  if (n == 0)
    return acc;

  return sum(a, n - 1, a[n - 1] + acc);
}

/// Computes the sum of all of elements in an array
int sum(int * a, int n)
{
  return sum(a, n, 0);
}

int main()
{
  cout << fact(5) << endl;
  cout << pow(3, 4) << endl;

  int a[] = { 1, 4, 3, 5, 36, 89, 45, 32 };
  cout << sum(a, 8) << endl;
  
  return 0;
}
