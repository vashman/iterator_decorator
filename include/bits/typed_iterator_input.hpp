//

#ifndef ITERATOR_DECORATOR_TYPED_ITERATOR_INPUT_HPP
#define ITERATOR_DECORATOR_TYPED_ITERATOR_INPUT_HPP

#include "typed_iterator_base.hpp"

namespace iterator_decorator {

template <typename T, typename Iterator>
struct typed_iterator <
  T
, Iterator
, std::input_iterator_tag >
: public
  typed_iterator_base <T, Iterator>
{

explicit
typed_iterator (
  Iterator &
);

typed_iterator (
  typed_iterator <
    T
  , Iterator
  , std::input_iterator_tag > const &
) = default;

typed_iterator <
  T,Iterator,std::input_iterator_tag > &
operator = (
  typed_iterator  <
    T
  , Iterator
  , std::input_iterator_tag> const &
) = default;

typed_iterator (
  typed_iterator <
    T
  , Iterator
  , std::input_iterator_tag > &&
) = default;

typed_iterator <
  T,Iterator,std::input_iterator_tag > &
operator = (
  typed_iterator  <
    T
  , Iterator
  , std::input_iterator_tag> &&
) = default;

T
operator * ();

T *
operator -> ();

typed_iterator <
  T
, Iterator
, std::input_iterator_tag > &
operator ++ ();

typed_iterator <
  T, Iterator, std::input_iterator_tag >
operator ++ (int);

}; /* typed iterator input */

template <typename T, typename Iterator>
typed_iterator <
  T, Iterator, std::input_iterator_tag >
::typed_iterator (
  Iterator & _iterator
)
: typed_iterator_base <T,Iterator>
  (_iterator)
{
}

template <typename T, typename Iterator>
T
typed_iterator <
  T, Iterator, std::input_iterator_tag >
::operator * (){
return static_cast<T> (
  this->iterator.operator*() );
}

template <typename T, typename Iterator>
T *
typed_iterator <
  T, Iterator, std::input_iterator_tag >
::operator -> (
){
return static_cast<T*> (
  this->iterator.operator->() );
}

template <typename T, typename Iterator>
typed_iterator <
  T
, Iterator
, std::input_iterator_tag > &
typed_iterator <
  T, Iterator, std::input_iterator_tag >
::operator ++ (
){
++this->iterator;
return *this;
}

template <typename T, typename Iterator>
typed_iterator <
  T, Iterator, std::input_iterator_tag >
typed_iterator <
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

