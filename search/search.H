# ifndef SEARCH_H
# define SEARCH_H

template <class S, class C>
typename S::value_type * search(const S & s, const C & c)
{
  for (auto & item : s)
    if (c(item))
      return const_cast<typename S::value_type *>(&item);

  return nullptr;
}

# endif // SEARCH_H
