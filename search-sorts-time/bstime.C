/* This program performs an experimental proof of the execution time 
   of the binary search algorithm.

   @author: Alejandro J. Mujica
   @date:   20/11/2015
*/

# include <iostream> 
# include <fstream>
# include <chrono>

using namespace std;
using namespace chrono;

using ll = long long;

template <typename T, class Compare = std::less<T>>
ll binary_search(T * a, ll l, ll r, const T & k,
		 const Compare & cmp = Compare())
{
  if (l > r)
    return l;

  ll m = (l + r) / 2;

  if (cmp(k, a[m]))
    return binary_search(a, l, m - 1, k, cmp);
  else if (cmp(a[m], k))
    return binary_search(a, m + 1, r, k, cmp);
  
  return m;
}

int main()
{
  constexpr int NUM_SAMPLES = 20;
  constexpr int NUM_EXPS = 20;
  
  unsigned sizes[NUM_SAMPLES];
  double sum_times[NUM_SAMPLES];

  for (int i = 0; i < NUM_SAMPLES; ++i)
    sum_times[i] = 0;

  for (int k = 0; k < NUM_EXPS; ++k)
    {
      cout << "\nExperiment: " << k + 1 << '\n'
	   << "----------------\n";
	
      ll size = 1024; // 2^10

      for (auto i = 0; i < NUM_SAMPLES; ++i)
	{
	  sizes[i] = size;
	  
	  ll * a = new ll[size];

	  
	  for (ll j = 0; j < size; ++j)
	    a[j] = j;
	  
	  
	  auto s = high_resolution_clock::now();
	  binary_search(a, 0, size - 1, size);
	  auto e = high_resolution_clock::now();
	  auto dt = duration_cast<nanoseconds>(e-s).count();

	  cout << "Input size: " << size
	       << "\tExecution time: " << dt << " ns\n";

	  sum_times[i] += dt;
	  	  
	  delete [] a;

	  cout << size << endl;
	  size <<= 1;
	}
    }

  ofstream file("bs_data.dat");

  for (auto i = 0; i < NUM_SAMPLES; ++i)
    file << sizes[i] << '\t' << sum_times[i] / double(NUM_EXPS)
	 << '\n';
      
  file.close();
  
  file.open("bs_plot.gp");

  file << "set title 'Binary Search'\n"
       << "set xlabel 'Input size'\n"
       << "set ylabel 'Execution time (ns)'\n"
       << "set term png\n"
       << "set output 'bs_graphic.png'\n"
       << "plot 'bs_data.dat' w l\n"
       << "quit\n";
  
  file.close();
  
  return 0;
}
