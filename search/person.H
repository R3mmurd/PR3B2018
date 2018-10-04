# ifndef PERSON_H
# define PERSON_H

# include <sstream>
# include <math_utils.H>

class Person
{
  std::string name;
  int         age;
  float       height;
  float       weight;
  bool        glasses;

public:
  Person(const string & n, int a, float h, float w, bool g)
    : name(n), age(a), height(h), weight(w), glasses(g)
  {
    // empty
  }

  Person(std::string && n, int a, float h, float w, bool g)
    : name(move(n)), age(a), height(h), weight(w), glasses(g)
  {
    // empty
  }

  Person(const Person & p)
    : name(p.name), age(p.age), height(p.height), weight(p.weight),
      glasses(p.glasses)
  {
    // empty
  }

  Person(Person && p)
    : name(""), age(0), height(0.f), weight(0.f), glasses(false)
  {
    swap(p);
  }

  void swap(Person & p)
  {
    std::swap(name, p.name);
    std::swap(age, p.age);
    std::swap(height, p.height);
    std::swap(weight, p.weight);
    std::swap(glasses, p.glasses);
  }

  Person & operator = (const Person & p)
  {
    if (&p == this)
      return *this;

    name = p.name;
    age = p.age;
    height = p.height;
    weight = p.weight;
    glasses = p.glasses;

    return *this;
  }

  Person & operator = (Person && p)
  {
    swap(p);
    return *this;
  }

  std::string to_string() const
  {
    std::stringstream s;
    s << "< name: \"" << name  << "\", age: " << age
      << ", height: " << round(height, 2)
      << ", weight: " << round(weight, 2)
      << ", has glasses: " << (glasses ? "true" :  "false") << " >";
    return s.str();
  }

  const std::string & get_name() const
  {
    return name;
  }

  int get_age() const
  {
    return age;
  }


  float get_height() const
  {
    return height;
  }

  float get_weight() const
  {
    return weight;
  }

  bool has_glasses() const
  {
    return glasses;
  }
};

# endif // PERSON_H
