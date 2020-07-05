# include <iostream>
# include <stack>
# include <chrono>

using namespace std;
using namespace chrono;

using Partition = pair<int, int>;
using Sz = stack<Partition>::size_type;

/// Performs the array partition with a given function to select the pivot.
int generic_partition(int * a, int l, int r,
		      int (*select_pivot)(int*, int, int))
{
  int pivot = select_pivot(a, l, r);
  
  std::swap(a[pivot], a[r]);
  
  int i = l - 1;
  int j = r;
  
  while (i <= j)
    {
      while (a[++i] < a[r]);
      
      while (a[r] < a[--j])
	if (j == l)
	  break;
      
      if (i >= j)
	break;

      std::swap(a[i], a[j]);
    }

  std::swap(a[i], a[r]);

  return i;
}

/// Function to select the left element as pivot.
int left_element(int *, int l, int)
{
  return l;
}

/// Partition selecting the left element as pivot.
int partition(int * a, int l, int r)
{
  return generic_partition(a, l, r, left_element);
}

/// Basic non-recursive quicksort
Sz quicksort(int * a, int l, int r)
{
  stack<Partition> st;
  st.push(Partition(l, r));

  Sz max_stack_size = 0;

  while (not st.empty())
    {
      max_stack_size = max(max_stack_size, st.size());
      Partition p = st.top();
      st.pop();

      if (p.first >= p.second)
	continue;

      int pivot = partition(a, p.first, p.second);

      st.push(Partition(pivot + 1, p.second));
      st.push(Partition(p.first, pivot - 1));
    }

  return max_stack_size;
}

/** Quicksort improved by stacking first the smaller partition in order to
    save memory.
*/
Sz quicksort_first_improvement(int * a, int l, int r)
{
  stack<Partition> st;
  st.push(Partition(l, r));

  Sz max_stack_size = 0;
  
  while (not st.empty())
    {
      max_stack_size = max(max_stack_size, st.size());
      Partition p = st.top();
      st.pop();
      
      if (p.first >= p.second)
	continue;
      
      int pivot = partition(a, p.first, p.second);
      
      if (pivot - p.first < p.second - pivot)
      	{
	  st.push(Partition(pivot + 1, p.second));
      	  st.push(Partition(p.first, pivot - 1));
	}
      else
	{
	  st.push(Partition(p.first, pivot - 1));
	  st.push(Partition(pivot + 1, p.second));
	}
    }

  return max_stack_size;
}

/// Select the median between the left, the mid, and the right element as pivot.
int median(int * a, int l, int r)
{
  int m = (l + r) / 2;
  
  int partial_min = (a[l] < a[m]) ? l : m;
  
  return (a[partial_min] < a[r]) ? partial_min : r;    
}

/// Partition by selecting the median as pivot.
int improved_partition(int * a, int l, int r)
{
  return generic_partition(a, l, r, median);
}

/** Quicksort improved by stacking first the smaller partition in order to
    save memory and also select the median as pivot in order to save time.
*/
Sz quicksort_second_improvement(int * a, int l, int r)
{
  stack<Partition> st;
  st.push(Partition(l, r));

  Sz max_stack_size = 0;
  
  while (not st.empty())
    {
      max_stack_size = max(max_stack_size, st.size());
      Partition p = st.top();
      st.pop();
      
      if (p.first >= p.second)
	continue;
      
      int pivot = improved_partition(a, p.first, p.second);
      
      if (pivot - p.first < p.second - pivot)
      	{
	  st.push(Partition(pivot + 1, p.second));
      	  st.push(Partition(p.first, pivot - 1));
	}
      else
	{
	  st.push(Partition(p.first, pivot - 1));
	  st.push(Partition(pivot + 1, p.second));
	}
    }

  return max_stack_size;
}

void insertion_sort(int * a, int l, int r)
{
  for (int i = l + 1; i <= r; ++i)
    {
      int j = i;

      int tmp = a[j];

      for ( ; j > l and tmp < a[j - 1]; --j)
	a[j] = a[j - 1];
      
      a[j] = tmp;
    }
}

constexpr int QS_THRESHOLD = 40;

/** Quicksort improved to call insertion_sort when the size of the array
    is less to QS_THRESHOLD
*/
Sz quicksort_third_improvement(int * a, int l, int r)
{
  stack<Partition> st;
  st.push(Partition(l, r));

  Sz max_stack_size = 0;
  
  while (not st.empty())
    {
      max_stack_size = max(max_stack_size, st.size());
      Partition p = st.top();
      st.pop();
      
      if (p.first >= p.second)
	continue;

      if (p.second - p.first < QS_THRESHOLD)
	{
	  insertion_sort(a, p.first, p.second);
	  continue;
	}

      int pivot = improved_partition(a, p.first, p.second);
      
      if (pivot - p.first < p.second - pivot)
      	{
	  st.push(Partition(pivot + 1, p.second));
      	  st.push(Partition(p.first, pivot - 1));
	}
      else
	{
	  st.push(Partition(p.first, pivot - 1));
	  st.push(Partition(pivot + 1, p.second));
	}
    }

  return max_stack_size;
}

int main(int argc, char * argv[])
{
  int sz = argc < 2 ? 10000 : stoi(argv[1]);
  int a1[sz], a2[sz], a3[sz], a4[sz];

  for (int i = sz; i > 0; --i)
    a1[sz - i] = a2[sz - i] = a3[sz - i] = a4[sz - i] = i;

  auto t0 = system_clock::now();
  Sz m1 = quicksort(a1, 0, sz - 1);
  auto t1 = system_clock::now();
  Sz m2 = quicksort_first_improvement(a2, 0, sz - 1);
  auto t2 = system_clock::now();
  Sz m3 = quicksort_second_improvement(a3, 0, sz - 1);
  auto t3 = system_clock::now();
  Sz m4 = quicksort_third_improvement(a4, 0, sz - 1);
  auto t4 = system_clock::now();

  string time_unit = "ms";

  auto dt1 = duration_cast<milliseconds>(t1 - t0).count();
  auto dt2 = duration_cast<milliseconds>(t2 - t1).count();
  auto dt3 = duration_cast<milliseconds>(t3 - t2).count();
  auto dt4 = duration_cast<milliseconds>(t4 - t3).count();

  cout << "Basic quicksort\n";
  cout << "---------------\n";
  cout << "Max stack size: " << m1 << endl;
  cout << "Execution time: " << dt1 << ' ' << time_unit << endl << endl;
  cout << "Quicksort (first improvement)\n";
  cout << "-------------------------\n";
  cout << "Max stack size: " << m2 << endl;
  cout << "Execution time: " << dt2 << ' ' << time_unit << endl << endl;
  cout << "Quicksort (second improvement)\n";
  cout << "--------------------------\n";
  cout << "Max stack size: " << m3 << endl;
  cout << "Execution time: " << dt3 << ' ' << time_unit << endl << endl;
  cout << "Quicksort (third improvement)\n";
  cout << "--------------------------\n";
  cout << "Max stack size: " << m4 << endl;
  cout << "Execution time: " << dt4 << ' ' << time_unit << endl;

  return 0;
}
