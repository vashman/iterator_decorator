//

#ifndef ITERATOR_DECORATOR_TYPED_ITERATOR_FORWARD_HPP
#define ITERATOR_DECORATOR_TYPED_ITERATOR_FORWARD_HPP

#include "typed_iterator_input.hpp"

namespace iterator_decorator {

template <typename T, typename Iterator>
struct typed_iterator <
  T
, Iterator
, std::forward_iterator_tag >
: public typed_iterator <
    T
  , Iterator
  , std::input_iterator_tag >
{

explicit
typed_iterator (
  Iterator &
);

typed_iterator (
  typed_iterator <
    T
  , Iterator
  , std::forward_iterator_tag > const &
) = default;

typed_iterator <
  T,Iterator,std::forward_iterator_tag > &
operator = (
  typed_iterator  <
    T
  , Iterator
  , std::forward_iterator_tag> const &
) = default;

typed_iterator (
  typed_iterator <
    T
  , Iterator
  , std::forward_iterator_tag > &&
) = default;

typed_iterator <
  T,Iterator,std::forward_iterator_tag > &
operator = (
  typed_iterator  <
    T
  , Iterator
  , std::forward_iterator_tag> &&
) = default;

}; /* typed iterator input */

template <typename T, typename Iterator>
typed_iterator <
  T, Iterator, std::forward_iterator_tag >
::typed_iterator (
  Iterator & _iterator
)
: typed_iterator <
    T
  , Iterator
  , std::input_iterator_tag >(_iterator)
{
}

}
#endif

