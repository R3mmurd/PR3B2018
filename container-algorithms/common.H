# ifndef COMMON_H
# define COMMON_H

# include <iostream>
# include <string>
# include <vector>

using namespace std;

ostream & operator << (ostream & out, const vector<int> & s)
{
  out << "[ ";

  for (int item : s)
    out << item << ' ';

  out << ']';
  return out;
}

ostream & operator << (ostream & out, const vector<string> & s)
{
  out << "[ ";

  for (const string & item : s)
    out << item << ' ';

  out << ']';
  return out;
}

string to_str(bool value)
{
  return (value ? "true" : "false");
}

# endif // COMMON_H
