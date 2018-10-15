/** This file contains examples of how to implement container algorithms
    basic in container iterators.

    @author Alejandro J.Mujica
    @date 12/10/2018
*/

# include <iostream>
# include <string>
# include <vector>

using namespace std;

ostream & operator << (ostream & out, const vector<int> & s)
{
  out << "[ ";

  for (int item : s)
    out << item << ' ';

  out << ']';
  return out;
}

ostream & operator << (ostream & out, const vector<string> & s)
{
  out << "[ ";

  for (const string & item : s)
    out << item << ' ';

  out << ']';
  return out;
}

string to_str(bool value)
{
  return (value ? "true" : "false");
}

/** Builds a new container with elements selected by a predicate from another
    container.

    @targ S Type of container. It should be an iterable object and it should
    have a method push_back to add elements.

    @targ P Type of predicate. It should be a callable object that receive
    a constant reference to the type of value in the container and return
    true if the value should be in the container result.

    @param s Container
    @param p Predicate
    @return A new container with the filtered elements.
*/
template <class S, class P>
S filter(const S & s, const P & p)
{
  S result;
  
  for (const auto & item : s)
    if (p(item))
      result.push_back(item);

  return result;
}

/** Builds a new container by transforming each element from another container.

    @targ S Type of container. It should be an iterable object and it should
    have a method push_back to add elements.

    @targ Op Type of operation. It should be a callable object that receive
    a constant reference to the type of value in the container and return
    an object of the type of value that holds the container selected to result.

    @targ RS Type of container to return, by default is equal to S

    @param s Container
    @param op Transform operation 
    @return A new container with the transformed elements.
*/
template <class S, class RS = S, class Op>
RS map(const S & s, const Op & op)
{
  RS result;
  
  for (const auto & item : s)
    result.push_back(op(item));

  return result;
}

/** Builds a new container by transforming each selected element from another 
    container. The elementes are selected by a predicate.

    @targ S Type of container. It should be an iterable object and it should
    have a method push_back to add elements.

    @targ Op Type of operation. It should be a callable object that receive
    a constant reference to the type of value in the container and return
    an object of the type of value that holds the container selected to result.

    @targ P Type of predicate. It should be a callable object that receive
    a constant reference to the type of value in the container and return
    true if the value should be in the container result.

    @targ RS Type of container to return, by default is equal to S

    @param s Container
    @param op Transform operation 
    @return A new container with the transformed elements.
*/
template <class S, class RS = S, class Op, class P>
RS map_if(const S & s, const Op & op, const P & p)
{
  RS result;
  
  for (const auto & item : s)
    if (p(item))
      result.push_back(op(item));

  return result;
}

/** Computes a generic accumulated element from a container.

    @targ S Type of container. It should be an iterable object and it should
    have a method push_back to add elements.

    @targ Op Type of operation. It should be a callable object that receive
    a constant reference to the type of value in the container and a constant
    reference to an object of the type selected to accumulate, and return
    an object of the type of value that selected to result.

    @RT Type of value to accumulate.

    
    @param s Container
    @param init Initial value to accumulate
    @param op Operation to accumulate
*/
template <class S, typename RT = typename S::value_type, class Op>
RT fold(const S & s, const RT & init, const Op & op)
{
  RT result = init;

  for (const auto & item : s)
    result = op(item, result);

  return result;
}

/// Returns true if for all item in s, p(item) is true.
template <class S, class P>
bool all_of(const S & s, const P & p)
{
  for (const auto & item : s)
    if (not p(item))
      return false;

  return true;
}

/// Returns true if at least for one item in s, p(item) is true.
template <class S, class P>
bool some_of(const S & s, const P & p)
{
  for (const auto & item : s)
    if (p(item))
      return true;

  return false;
}

/// Returns true if for all item in s, p(item) is false.
template <class S, class P>
bool none_of(const S & s, const P & p)
{
  for (const auto & item : s)
    if (p(item))
      return false;

  return true;
}

int main()
{
  vector<int> xs{1,2,3,4,5,6,7,8,9,10};

  cout << "Elements " << xs << endl;

  cout << "Even elements: " << filter(xs, [] (int item)
				      {
					return not (item & 1);
				      })
       << endl;

  cout << "Odd elements: " << filter(xs, [] (int item)
				      {
					return (item & 1);
				      })
       << endl;

  cout << "Elements power 2: " << map(xs, [] (int item)
				      {
					return item * item;
				      })
       << endl;

  cout << "Odd elements power 2: " << map_if(xs, [] (int item)
					     {
					       return item * item;
					     }, [] (int item)
					     {
					       return not (item & 1);
					     })
       << endl;
  
  cout << "Sum(Elements): " << fold(xs, 0, [] (int item, int acc)
				    {
				      return item + acc;
				    })
       << endl;

  cout << "Prod(Elements): " << fold(xs, 1, [] (int item, int acc)
				     {
				       return item * acc;
				     })
       << endl;

  cout << "Are all odd: " << to_str(all_of(xs, [] (int item)
					   {
					     return (item & 1);
					   }))
       << endl;
  
  cout << "Some is odd: " << to_str(some_of(xs, [] (int item)
					    {
					      return (item & 1);
					    }))
       << endl;
  
  cout << "None of them if greater than 100: "
       << to_str(none_of(xs, [] (int item) { return item > 100; })) << endl;

  vector<string> ss{"hello", "bye", "run", "execute"};

  cout << "strings: " << ss << endl;
  cout << "string sizes: "
       << map<vector<string>, vector<int>>(ss, [] (const string & s)
					   {
					     return s.size();
					   })
       << endl;

  cout << "string sizes (less to 5): "
       << map_if<vector<string>, vector<int>>(ss, [] (const string & s)
					      {
						return s.size();
					      },
					      [] (const string & s)
					      {
						return s.size() < 5;
					      })
       << endl;

  cout << "Concat(strings): " << fold(ss, string(""),
				      [] (const string & item,
					  const string & acc)
				      {
					return acc + item;
				      })
       << endl;

  cout << "Number of characters in strings: "
       << fold(ss, 0, [] (const string & item, int acc)
	       {
		 return item.size() + acc;
	       })
       << endl;
  
  return 0;
}
