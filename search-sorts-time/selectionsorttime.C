/* This program performs an experimental proof of the execution time 
   of the selection sort algorithm.

   The files selection_sort_data.dat and selection_sort_plot.gp are 
   generated. You need to install gnuplot in order to plot this data with 
   the shell command gnuplot selection_sort_plot.gp. It will be generated the
   file selection_sort_graphic.png.

   Autor: Alejandro J. Mujica
   Fecha: 15/11/2015
*/

# include <iostream>
# include <fstream>
# include <random>
# include <chrono>
# include <cassert>

using namespace std;

template <typename T, class Compare = std::less<T>>
bool is_sorted(T * a, int n, const Compare & cmp = Compare())
{
  for (int i = 0; i < n - 1; ++i)
    if (cmp(a[i+1], a[i]))
      return false;

  return true;
}

template <typename T, class Compare = std::less<T>>
void selection_sort(T * a, int n, const Compare & cmp = Compare())
{
  for (int i = 0; i < n - 1; ++i)
    {
      int m = i;

      for (int j = i + 1; j < n; ++j)
	if (cmp(a[j], a[m]))
	  m = j;

      swap(a[m], a[i]);
    }
}

int main()
{
  mt19937_64 rng(time(nullptr) % mt19937_64::max());
  ofstream file("selection_sort_data.dat");

  unsigned size = 500;

  for (auto i = 0; i < 10; ++i)
    {
      int * a = new int[size];

      uniform_int_distribution<int> unif(0, size);

      for (auto j = 0; j < size; ++j)
	a[j] = unif(rng); // Comment this to fill sorted
      // a[j] = j; // Uncomment this to fill sorted

      auto t0 = chrono::high_resolution_clock::now().time_since_epoch();
      selection_sort(a, size);
      auto t1 = chrono::high_resolution_clock::now().time_since_epoch();
      auto dt = chrono::duration_cast<chrono::milliseconds>(t1-t0).count();
      assert(is_sorted(a, size));
      
      delete [] a;
      
      cout << "Array size: " << size << '\t' << "Search time: "
	   << dt << " ms\n";
      file << size << '\t' << dt << '\n';

      size <<= 1;
    }

  file.close();

  file.open("selection_sort_plot.gp");

  file << "set title 'Selection sort'\n"
       << "set xlabel 'Input size'\n"
       << "set ylabel 'Execution time (ms)'\n"
       << "set term png\n"
       << "set output 'selection_sort_graphic.png'\n"
       << "plot 'selection_sort_data.dat' w l\n"
       << "quit\n";
  
  file.close();
  
  return 0;
}
