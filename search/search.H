# ifndef SEARCH_H
# define SEARCH_H

/** Search over any container with any criterium.

    @tparam S class of container that is iterable with range-based for loop
    and exports the type of value that stores as value_type.

    @tparam C type of data that represents the search criterium. That type 
    has to be callable with an instance of the value_type exported by S and
    has to return a value evaluable to either true or false.

    @arg s constant reference to an instance of the container type S.

    @arg c constant reference to an instance of the criterium C.

    @return a pointer to the instance of the object that meets with the search
    criterium or nullptr if its does not exist.
*/
template <class S, typename C>
typename S::value_type * search(const S & s, const C & c)
{
  for (auto & item : s)
    if (c(item))
      return const_cast<typename S::value_type *>(&item);
  
  return nullptr;
}

/** Search over any container with any criterium and variadic arguments.

    @tparam S class of container that is iterable with range-based for loop
    and exports the type of value that stores as value_type.

    @tparam C type of data that represents the search criterium. That type 
    has to be callable with an instance of the value_type exported by S and 
    the additional variadic arguments passed to the function call. Moreover,
    it has to return a value evaluable to either true or false.

    @tparam ...Args the types of the variadic arguments. The number of variadic
    arguments could be 0 or more.

    @arg s constant reference to an instance of the container type S.

    @arg c constant reference to an instance of the criterium C.

    @arg ...args comma-separated variadic arguments. The number of variadic
    arguments could be 0 or more.

    @return a pointer to the instance of the object that meets with the search
    criterium or nullptr if its does not exist.
*/
template <class S, typename C, typename ...Args>
typename S::value_type * variadic_search(const S & s, const C & c, Args ...args)
{
  for (auto & item : s)
    if (c(item, args...))
      return const_cast<typename S::value_type *>(&item);

  return nullptr;
}

# endif // SEARCH_H
