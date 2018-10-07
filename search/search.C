# include <iostream>
# include <random>
# include <vector>
# include <chrono>

using namespace std;

# include "search.H"
# include "person.H"

using rng_t = mt19937_64;
using unif  = uniform_int_distribution<int>;
using uniff = uniform_real_distribution<float>;
using bern  = bernoulli_distribution;

ostream & operator << (ostream & out, const vector<Person> & ps)
{
  auto sz = ps.size();
  out << "Set with " << sz;
  if (sz == 1)
    out << " person\n";
  else
    out << " people\n";

  for (const Person & p : ps)
    out << p.to_string() << endl;

  return out;
}

/** Search criterium to a person with a height greater than 1.8 meters
    as a C standar function.
*/
bool first_height_greater_than_180(const Person & p)
{
  return p.get_height() > 1.8;
}

/** Search criterium to a person with a height greater than 1.8 meters as
    a functor.
*/
class FirstHeightGreaterThan180
{
public:
  bool operator () (const Person & p) const
  {
    return p.get_height() > 1.8;
  }
};

/** Search criterium to a person with a height greater than any value as
    a functor. The constructor receives the value to be compared inside the
    call method.
*/
class FirstHeightGreaterThan
{
  float h;

public:
  FirstHeightGreaterThan(float _h) : h(_h) {}


  bool operator () (const Person & p) const
  {
    return p.get_height() > h;
  }
};

/** Search criterium to a person with a height greater than any value as
    a functor to be used in variadic_search.
*/
class FirstHeightGreaterThanV2
{
public:
  bool operator () (const Person & p, float h) const
  {
    return p.get_height() > h;
  }
};

/** Search criterium to a person with a height greater than any value as
    a C standar function to be used in variadic_search.
*/
bool first_height_greater_than(const Person & p, float h)
{
  return p.get_height() > h;
}

int main()
{
  rng_t rng(chrono::system_clock::now().time_since_epoch().count()
	    % rng_t::max());

  unif  age_r(18, 45);
  uniff height_r(1.5f, 2.3f);
  uniff weight_r(60.f, 130.f);
  bern  glasses_r(0.3);

  vector<Person> ps = {
    Person("Steve", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Mike", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Paul", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("John", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("James", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Tarja", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Amy", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Floor", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
    Person("Bruce", age_r(rng), height_r(rng), weight_r(rng), glasses_r(rng)),
  };

  cout << ps << endl;

  Person * r = search(ps, first_height_greater_than_180);

  cout << "Result searching with a standar C function\n";

  if (r)
    cout << r->to_string()
	 << " is the first person with height greater than 1.80\n";
  else
    cout << "There is not person with height greater than 1.80\n";

  r = search(ps, FirstHeightGreaterThan180());

  cout << "Result searching with a functor\n";

  if (r)
    cout << r->to_string()
	 << " is the first person with height greater than 1.80\n";
  else
    cout << "There is not person with height greater than 1.80\n";

  r = search(ps, [] (const Person & p)
	     {
	       return p.get_height() > 1.8f;
	     });

  cout << "Result searching with a lambda function\n";

  if (r)
    cout << r->to_string()
	 << " is the first person with height greater than 1.80\n";
  else
    cout << "There is not person with height greater than 1.80\n";

  cout << "Result searching with a functor with h as variable\n";

  r = search(ps, FirstHeightGreaterThan(1.5));

  if (r)
    cout << r->to_string()
	 << " is the first person with height greater than 1.50\n";
  else
    cout << "There is not person with height greater than 1.50\n";

  float h = 1.9;

  cout << "Result searching with a lambda function with h as variable\n";

  r = search(ps, [h] (const Person & p)
	     {
	       return p.get_height() > h;
	     });

  if (r)
    cout << r->to_string()
	 << " is the first person with height greater than " << h << endl;
  else
    cout << "There is not person with height greater than " << h << endl;

  cout << "Result searching with a C standar with h as variable by using "
       << "variadic_seach\n";

  h = 1.85;

  r = variadic_search(ps, first_height_greater_than, h);

  if (r)
    cout << r->to_string()
	 << " is the first person with height greater than " << h << endl;
  else
    cout << "There is not person with height greater than " << h << endl;

  cout << "Result searching with a lambda function with h as variable by "
       << "usinfg variadic_seach\n";
  h = 1.6;

  r = variadic_search(ps, [] (const Person & p, float h)
		      {
			return p.get_height() > h;
		      }, h);

  if (r)
    cout << r->to_string()
	 << " is the first person with height greater than " << h << endl;
  else
    cout << "There is not person with height greater than " << h << endl;

  cout << "Result searching with a functor with h as variable by using "
       << "variadic_search\n";

  h = 1.6;
  r = variadic_search(ps, FirstHeightGreaterThanV2(), h);

  if (r)
    cout << r->to_string()
	 << " is the first person with height greater than " << h << endl;
  else
    cout << "There is not person with height greater than " << h << endl;

  // Write your own searches with any criterium by using the different ways to
  // implement them.

  return 0;
}
