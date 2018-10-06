/* This program performs an experimental proof of the execution time 
   of the binary search algorithm.

   The experiment consists of creating an array with N elements, starting
   with N = 2^32. This sequence is built sorted from 0 to N-1.
   Then is executed the search methods to search the value N (failed
   search, in other words, the worst case). The input size is
   duplicated 20 times to get the plotting data.

   Each experiment is executed 20 times to get the average execution
   time.

   The files bs_data.dat and bs_plot.gp are generated. You need to
   install gnuplot in order to plot this data with the shell command
   gnuplot bs_plot.gp. It will be generated the file bs_graphic.png.

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
    return binary_search(a, k, l, m - 1, cmp);
  else if (cmp(a[m], k))
    return binary_search(a, k, m + 1, r, cmp);
  
  return m;
}

int main()
{
  constexpr int NUM_SAMPLES = 20;
  constexpr int NUM_EXPS = 20;
  
  unsigned sizes[NUM_SAMPLES];
  double sum_times[NUM_SAMPLES];

  for (auto i = 0; i < NUM_SAMPLES; ++i)
    sum_times[i] = 0;

  for (auto k = 0; k < NUM_EXPS; ++k)
    {
      cout << "\nExperiment: " << k + 1 << '\n'
	   << "----------------\n";
	
      ll size = 2147483648; // 2^32

      for (auto i = 0; i < NUM_SAMPLES; ++i)
	{
	  sizes[i] = size;
	  
	  ll * a = new ll[size];
	  
	  for (auto j = 0; j < size; ++j)
	    a[j] = j;
	  
	  auto s = high_resolution_clock::now();
	  binary_search(a, 0, size - 1, size);
	  auto e = high_resolution_clock::now();
	  auto dt = duration_cast<nanoseconds>(e-s).count();

	  cout << "Input size: " << size
	       << "\tExecution time: " << dt << " ns\n";

	  sum_times[i] += dt;
	  	  
	  delete [] a;
	  
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
