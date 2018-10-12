/** This file contains the implementation of the algorithm
    to compute the greatest income in the rod cutting problem.

    @author: Alejandro J. Mujica
*/

# include <iostream>
# include <chrono>
# include <unordered_map>

using namespace std;
using namespace chrono;

using ull = unsigned long long;
using mem_table = unordered_map<ull, ull>;

/// Algorithm without memoization
ull cut_rod(ull * prices_table, ull n)
{
  if (n == 0)
    return prices_table[0];

  ull m = 0;

  for (ull i = 1; i <= n; ++i)
    m = max(m, prices_table[i] + cut_rod(prices_table, n - i));

  return m;
}

// Algorithms with memoization
ull mem_cut_rod(ull * prices_table, ull n, mem_table & mem)
{
  if (n == 0)
    return prices_table[0];

  auto r = mem.find(n);

  if (r != mem.end())
    return r->first;

  ull m = 0;

  for (ull i = 1; i <= n; ++i)
    m = max(m, prices_table[i] + mem_cut_rod(prices_table, n - i, mem));

  mem[n] = m;
  return m;
}

// Wrapper to algorithm with memoization
ull mem_cut_rod(ull * prices_table, ull n)
{
  mem_table mem;
  return mem_cut_rod(prices_table, n, mem);

}

int main()
{
  ull n = 20;

  ull table[] = {
    0,1,5,8,9,10,17,17,20,24,25,28,30,31,35,36,37,40,42,45,48
  };

  auto t0 = high_resolution_clock::now();
  ull result1 = cut_rod(table, n);
  auto d1 = high_resolution_clock::now() - t0;
  cout << "Result with basic algorithm: " << result1 << endl;
  cout << "Execution time: " << duration_casgiit st<nanoseconds>(d1).count()
       << " ns\n";

  auto t1 = high_resolution_clock::now();
  ull result2 = mem_cut_rod(table, n);
  auto d2 = high_resolution_clock::now() - t1;
  cout << "Result with memoizated algorithm: " << result2 << endl;
  cout << "Execution time: " << duration_cast<nanoseconds>(d2).count()
       << " ns\n";

  return 0;
}
