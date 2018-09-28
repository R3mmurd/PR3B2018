# ifndef MATH_UTIL_H
# define MATH_UTIL_H

# include <cmath>

int ten_power(int n)
{
  if (n == 0)
    return 1;

  return ten_power(n - 1) * 10;
}

float round(float n, int num_dec = 0)
{
  int factor = ten_power(num_dec);
  int new_value = n * factor;
  int next_decimal = (n * factor - new_value) * 10;
  if (next_decimal >= 5)
    ++new_value;
  return float(new_value) / float(factor);
}

# endif // MATH_UTIL_H
