/* This program performs an experimental proof of the execution time 
   of the insertion sort algorithm.

   Autor: Alejandro J. Mujica
   Fecha: 15/11/2015
*/

# include <iostream>
# include <fstream>
# include <random>
# include <chrono>
# include <cassert>

using namespace std;
using namespace chrono;

template <typename T, class Compare = std::less<T>>
bool is_sorted(T * a, int n, const Compare & cmp = Compare())
{
  for (int i = 0; i < n - 1; ++i)
    if (cmp(a[i+1], a[i]))
      return false;

  return true;
}

template <typename T, class Compare = std::less<T>>
void insertion_sort(T * a, int n, const Compare & cmp = Compare())
{
  for (int i = 1; i < n; ++i)
    {
      int j = i;

      while (j > 0 and cmp(a[j], a[j-1]))
	{
	  swap(a[j], a[j-1]);
	  --j;
	}
    }
}

int main(int argc, char * argv[])
{
  mt19937_64 rng(time(nullptr) % mt19937_64::max());
  ofstream file("insertion_sort_data.dat");

  bool sorted = argc > 1 and stoi(argv[1]) == 1;

  unsigned size = 512;

  for (auto i = 0; i < 10; ++i)
    {
      int * a = new int[size];

      uniform_int_distribution<int> unif(0, size);

      if (sorted)
	for (unsigned j = 0; j < size; ++j)
	  a[j] = j;
      else
	for (unsigned j = 0; j < size; ++j)
	  unif(rng);

      auto t0 = high_resolution_clock::now();
      insertion_sort(a, size);
      auto t1 = high_resolution_clock::now();
      auto dt = duration_cast<milliseconds>(t1-t0).count();
      assert(is_sorted(a, size));
      
      delete [] a;
      
      cout << "Array size: " << size << '\t' << "Search time: "
	   << dt << " ms\n";
      file << size << '\t' << dt << '\n';

      size <<= 1;
    }

  file.close();

  file.open("insertion_sort_plot.gp");

  file << "set title 'Insertion sort'\n"
       << "set xlabel 'Input size'\n"
       << "set ylabel 'Execution time (ms)'\n"
       << "set term png\n"
       << "set output 'insertion_sort_graphic.png'\n"
       << "plot 'insertion_sort_data.dat' w l\n"
       << "quit\n";
  
  file.close();
  
  return 0;
}
