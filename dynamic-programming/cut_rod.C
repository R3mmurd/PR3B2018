/** This file contains the implementation of the algorithm
    to compute the greatest income in the rod cutting problem.

    @author: Alejandro J. Mujica
*/

# include <iostream>
# include <chrono>
# include <limits>

using namespace std;
using namespace chrono;

using ll = long long;

/// Algorithm without memoization
ll cut_rod(ll * prices_table, ll n)
{
  if (n == 0)
    return prices_table[0];

  ll m = -numeric_limits<ll>::max();

  for (ll i = 1; i <= n; ++i)
    m = max(m, prices_table[i] + cut_rod(prices_table, n - i));

  return m;
}

// Algorithm with memoization
ll mem_cut_rod(ll * prices_table, ll n, ll * mem)
{
  if (mem[n] >= 0)
    return mem[n];

  ll m = -numeric_limits<ll>::max();;
  
  if (n == 0)
    m = prices_table[0];
  else
    for (ll i = 1; i <= n; ++i)
      m = max(m, prices_table[i] + mem_cut_rod(prices_table, n - i, mem));

  mem[n] = m;
  return m;
}

// Wrapper to algorithm with memoization
ll mem_cut_rod(ll * prices_table, ll n)
{
  ll * mem = new ll[n + 1];
  
  for (ll i = 0; i <= n; ++i)
    mem[i] = -numeric_limits<ll>::max();

  ll result = mem_cut_rod(prices_table, n, mem);

  delete [] mem;

  return result;
}

int main()
{
  ll n = 20;

  ll table[] = {
    0,1,5,8,9,10,17,17,20,24,25,28,30,31,35,36,37,40,42,45,48
  };

  auto t0 = high_resolution_clock::now();
  ll result1 = cut_rod(table, n);
  auto d1 = high_resolution_clock::now() - t0;
  cout << "Result with basic algorithm: " << result1 << endl;
  cout << "Execution time: " << duration_cast<nanoseconds>(d1).count()
       << " ns\n";

  auto t1 = high_resolution_clock::now();
  ll result2 = mem_cut_rod(table, n);
  auto d2 = high_resolution_clock::now() - t1;
  cout << "Result with memoizated algorithm: " << result2 << endl;
  cout << "Execution time: " << duration_cast<nanoseconds>(d2).count()
       << " ns\n";

  return 0;
}
