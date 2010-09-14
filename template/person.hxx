// file      : template/person.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : not copyrighted - public domain

#ifndef PERSON_HXX
#define PERSON_HXX

#include <string>

#include <odb/core.hxx>

#pragma db object
struct person
{
  person (const std::string& first,
          const std::string& last,
          unsigned short age)
      : first_ (first), last_ (last), age_ (age)
  {
  }

  const std::string&
  first () const
  {
    return first_;
  }

  const std::string&
  last () const
  {
    return last_;
  }

  unsigned short
  age () const
  {
    return age_;
  }

public:
  unsigned long
  id () const
  {
    return id_;
  }

private:
  friend class odb::access;

  person () {}

  #pragma db id auto
  unsigned long id_;

  std::string first_;
  std::string last_;
  unsigned short age_;
};

#endif // PERSON_HXX
