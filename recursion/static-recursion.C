/** This file contains some examples of static recursion made through 
    templates. This recursion is evaluated at compile time.

    These examples are the same of recursion examples, but here functions
    receive their parameters as template arguments.

    @author Alejandro J. Mujica
*/

# include <iostream>

using namespace std;

/// Computes N! (factorial) of the template argument
template <int N> int fact()
{
  return N * fact<N - 1>();
}

/// Base case of factorial (0!)
template <> int fact<0>()
{
  return 1;
}

/// Computes the Nth number of fibonacci
template <int N> int fibo()
{
  return fibo<N - 1>() + fibo<N - 2>();
}

/// First base case of fibonacci
template <> int fibo<0>()
{
  return 0;
}

/// Second base case of fibonacci
template <> int fibo<1>()
{
  return 1;
}

/// Base case. Prints 1 element.
template <typename T>
void print(T item)
{
  cout << item << endl;
}

/// Prints multiple elements with variadic template
template <typename T, typename ...Args>
void print(T item, Args ...args)
{
  cout << item << ' ';
  print(args...);
}

int main()
{
  cout << fact<0>() << endl;
  cout << fact<2>() << endl;
  cout << fact<3>() << endl;
  cout << fact<4>() << endl;
  cout << fact<5>() << endl;

  cout << fibo<0>() << endl;
  cout << fibo<1>() << endl;
  cout << fibo<2>() << endl;
  cout << fibo<3>() << endl;
  cout << fibo<4>() << endl;
  cout << fibo<5>() << endl;
  cout << fibo<6>() << endl;
  cout << fibo<7>() << endl;
  cout << fibo<8>() << endl;
  cout << fibo<9>() << endl;

  print("hello");
  print("hello", true, "bye", 10, 8.5);
  return 0;
}
