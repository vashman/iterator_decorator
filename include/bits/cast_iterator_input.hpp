//

#ifndef ITERATOR_DECORATOR_CAST_ITERATOR_INPUT_HPP
#define ITERATOR_DECORATOR_CAST_ITERATOR_INPUT_HPP

#include "cast_iterator_base.hpp"

namespace iterator_decorator {

template <typename T, typename Iterator>
struct cast_iterator <
  T
, Iterator
, std::input_iterator_tag >
: public
  cast_iterator_base <T, Iterator>
{

explicit
cast_iterator (
  Iterator &
);

cast_iterator (
  cast_iterator <
    T
  , Iterator
  , std::input_iterator_tag > const &
) = default;

cast_iterator <
  T,Iterator,std::input_iterator_tag > &
operator = (
  cast_iterator  <
    T
  , Iterator
  , std::input_iterator_tag> const &
) = default;

cast_iterator (
  cast_iterator <
    T
  , Iterator
  , std::input_iterator_tag > &&
) = default;

cast_iterator <
  T,Iterator,std::input_iterator_tag > &
operator = (
  cast_iterator  <
    T
  , Iterator
  , std::input_iterator_tag> &&
) = default;

T
operator * ();

T *
operator -> ();

cast_iterator <
  T
, Iterator
, std::input_iterator_tag > &
operator ++ ();

cast_iterator <
  T, Iterator, std::input_iterator_tag >
operator ++ (int);

}; /* typed iterator input */

template <typename T, typename Iterator>
cast_iterator <
  T, Iterator, std::input_iterator_tag >
::cast_iterator (
  Iterator & _iterator
)
: cast_iterator_base <T,Iterator>
  (_iterator)
{
}

template <typename T, typename Iterator>
T
cast_iterator <
  T, Iterator, std::input_iterator_tag >
::operator * (){
return static_cast<T> (
  this->iterator.operator*() );
}

template <typename T, typename Iterator>
T *
cast_iterator <
  T, Iterator, std::input_iterator_tag >
::operator -> (
){
return static_cast<T*> (
  this->iterator.operator->() );
}

template <typename T, typename Iterator>
cast_iterator <
  T
, Iterator
, std::input_iterator_tag > &
cast_iterator <
  T, Iterator, std::input_iterator_tag >
::operator ++ (
){
++this->iterator;
return *this;
}

template <typename T, typename Iterator>
cast_iterator <
  T, Iterator, std::input_iterator_tag >
cast_iterator <
  T, Iterator, std::input_iterator_tag >
::operator ++ (
  int _dummy
){
auto temp (*this);
++this->iterator;
return temp;
}

}
#endif

