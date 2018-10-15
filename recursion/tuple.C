/** This file contains an example of how to implement a tuple of elements
    (collection of n sorted elements of different types) by using static 
    recursion and variadic template.

    @author Alejandro J. Mujica
*/
# include <iostream>
# include <string>

using namespace std;

template <typename Head, typename ...Tail>
struct Tuple
{
  Head           item;
  Tuple<Tail...> t;
};

template <typename Head>
struct Tuple<Head>
{
  Head item;
};

template <int N, typename Head, typename ...Tail>
struct Get
{
  auto operator () (Tuple<Head, Tail...> & t)
  {
    return Get<N-1, Tail...>()(t.t);
  }
};

template <typename Head, typename ...Tail>
struct Get<0, Head, Tail...>
{
  auto operator () (Tuple<Head, Tail...> & t)
  {
    return t.item;
  }
};

template <int N, typename Head, typename ...Tail>
auto mget(Tuple<Head, Tail...> & t)
{
  return Get<N, Head, Tail...>()(t);
}

template <typename Head>
Tuple<Head> maketuple(const Head & item)
{
  Tuple<Head> ret;
  ret.item = item;
  return ret;
}

template <typename Head, typename ...Tail>
Tuple<Head, Tail...> maketuple(const Head & item, const Tail ... tail)
{
  Tuple<Head, Tail...> ret;
  ret.item = item;
  ret.t = maketuple<Tail...>(tail...);
  return ret;
}

int main()
{
  auto t = maketuple(10, true, 'a', 3.1, "Hello");

  cout << mget<0>(t) << endl;
  cout << mget<1>(t) << endl;
  cout << mget<2>(t) << endl;
  cout << mget<3>(t) << endl;
  cout << mget<4>(t) << endl;
  
  return 0;
}
