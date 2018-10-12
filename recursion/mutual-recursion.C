/** This file contains a lazy way to determine whether a number es either even
    or odd as a mutual recursion example.
   
    @author: Alejandro J. Mujica
    @date: 11/10/2018
*/

# include <iostream>
# include <string>

using namespace std;

string to_str(bool value)
{
  return (value ? "true" : "false");
}

bool is_odd(unsigned);

/// Determines wheter n is an even number
bool is_even(unsigned n)
{
  if (n == 0)
    return true;

  return is_odd(n - 1);
}

/// Determines whether n is an odd number
bool is_odd(unsigned n)
{
  if (n == 0)
    return false;

  return is_even(n - 1);
}

int main()
{
  cout << to_str(is_even(0)) << endl;
  cout << to_str(is_odd(0)) << endl;

  cout << to_str(is_even(3)) << endl;
  cout << to_str(is_odd(3)) << endl;

  cout << to_str(is_even(8)) << endl;
  cout << to_str(is_odd(8)) << endl;
    
  return 0;
}
