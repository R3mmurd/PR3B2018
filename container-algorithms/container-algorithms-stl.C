/** This file contains examples of how to use some of the STL container
    algorithms.

    @author Alejandro J.Mujica
    @date 12/10/2018
*/

# include <common.H>
# include <algorithm>
# include <random>
# include <functional>

vector<int> generate_set(int n)
{
  vector<int> ret(n);

  mt19937_64 rng(time(nullptr) % mt19937_64::max());
  uniform_int_distribution<int> unif_dist(0, 1000);
  auto unif = bind(unif_dist, rng);

  generate(ret.begin(), ret.end(), [&unif] () { return unif(); });
  return ret;
}

int main()
{
  auto xs = generate_set(10);
  cout << "Generated set = " << xs << endl;

  cout << "Are all elements greater or equal than 0? ";
  cout << to_str(all_of(xs.begin(), xs.end(), [] (int x) { return x >= 0; }))
       << endl;
  cout << "Are all elements odd? ";
  cout << to_str(all_of(xs.begin(), xs.end(), [] (int x) { return x & 1; }))
       << endl;

  cout << "Is any element greater or equal than 0?  ";
  cout << to_str(any_of(xs.begin(), xs.end(), [] (int x) { return x >= 0; }))
       << endl;
  cout << "Is any element equal to 0?  ";
  cout << to_str(any_of(xs.begin(), xs.end(), [] (int x) { return x == 0; }))
       << endl;
  cout << "Is any element odd?  ";
  cout << to_str(any_of(xs.begin(), xs.end(), [] (int x) { return x & 1; }))
       << endl;

  cout << "Is none element greater or equal than 0? ";
  cout << to_str(none_of(xs.begin(), xs.end(), [] (int x) { return x >= 0; }))
       << endl;
  cout << "Is none element negative? ";
  cout << to_str(none_of(xs.begin(), xs.end(), [] (int x) { return x < 0; }))
       << endl;
  cout << "Is none element equal to 0?  ";
  cout << to_str(none_of(xs.begin(), xs.end(), [] (int x) { return x == 0; }))
       << endl;
  cout << "Is none element odd?  ";
  cout << to_str(none_of(xs.begin(), xs.end(), [] (int x) { return x & 1; }))
       << endl;

  cout << "Printing each element by using for_each: ";
  for_each(xs.begin(), xs.end(), [] (int x) { cout << x << ' '; });
  cout << endl;

  cout << "Num of elements equal to 0: "
       << count(xs.begin(), xs.end(), 0) << endl;

  cout << "Num of odd elements: "
       << count_if(xs.begin(), xs.end(), [] (int x) { return x & 1; }) << endl;

  vector<int> xs2;
  int counter = 0;
  transform(xs.begin(), xs.end(), back_inserter(xs2), [&counter] (int x)
	    {
	      if (counter++ > 4)
		return x*2;
	      else
		return x;
	    });

  cout << "xs  = " << xs << " and\n"
       << "xs2 = " << xs2 << endl;

  auto p = mismatch(xs.begin(), xs.end(), xs2.begin());
  cout << "They mismath since " << *p.first << " from xs and "
       << *p.second << " from xs2\n";

  auto f10 = find(xs.begin(), xs.end(), 10);
  if (f10 == xs.end())
    cout << "10 not found in xs\n";
  else
    cout << *f10 << " found in xs\n";

  auto fl300 = find_if(xs.begin(), xs.end(), [] (int x) { return x < 300; });
  if (fl300 == xs.end())
    cout << "There is not element greater than 300 in xs\n";
  else
    cout << "The first element less than 300 in xs is: " << *fl300 << endl;

  vector<int> xs3;
  copy(xs.begin(), xs.end(), back_inserter(xs3));

  cout << "xs  = " << xs << " and\n"
       << "xs3 = " << xs3 << endl;

  vector<int> xs4;
  copy_if(xs.begin(), xs.end(), back_inserter(xs4), [] (int x)
	  {
	    return x & 1;
	  });
  
  cout << "xs  = " << xs << " and\n"
       << "xs4= " << xs4<< endl;

  fill(xs3.begin(), xs3.end(), 0);
  cout << xs3 << endl;

  vector<int> xs5{1,2,3,4,5,5,7,6,8,9};
  auto faxs5 = adjacent_find(xs5.begin(), xs5.end());
  cout << *faxs5 << endl;

  auto faxs6 = adjacent_find(xs5.begin(), xs5.end(), [] (int x, int y)
			     {
			       return x > y;
			     });
  cout << *faxs6 << endl;

  vector<int> xs6 {1,2,3,12,2,3,12,2,3};
  xs6.erase(remove(xs6.begin(), xs6.end(), 3), xs6.end());
  cout << xs6 << endl;

  vector<int> xs7 {1,2,3,12,2,3,12,2,3};
  xs7.erase(remove_if(xs7.begin(), xs7.end(), [] (int x) { return x & 1; }),
	    xs7.end());
  cout << xs7 << endl;

  vector<int> xs8 {1,2,3,12,2,3,12,2,3};
  vector<int> xs9;
  remove_copy(xs8.begin(), xs8.end(), back_inserter(xs9), 3);
  cout << "xs8 = " << xs8 << " and\n"
       << "xs9 = " << xs9 << endl;

  vector<int> xs10;
  remove_copy_if(xs8.begin(), xs8.end(), back_inserter(xs10),
		 [] (int x) { return x & 1; });
  cout << "xs8 = " << xs8 << " and\n"
       << "xs10 = " << xs10 << endl;

  replace(xs8.begin(), xs8.end(), 3, 0);
  cout << xs8 << endl;
  
  
  return 0;
}
