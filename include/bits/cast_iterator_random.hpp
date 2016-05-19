//

#ifndef ITERATOR_DECORATOR_CAST_ITERATOR_RANDOM_HPP
#define ITERATOR_DECORATOR_CAST_ITERATOR_RANDOM_HPP

#include "cast_iterator_bidirectional.hpp"

namespace iterator_decorator {

template <typename T, typename Iterator>
struct cast_iterator <
  T
, Iterator
, std::random_access_iterator_tag >
: public
  cast_iterator <T, Iterator, std::bidirectional_iterator_tag>
{

explicit
cast_iterator (
  Iterator &
);

cast_iterator (
  cast_iterator <
    T
  , Iterator
  , std::random_access_iterator_tag > const &
) = default;

cast_iterator <
  T,Iterator,std::random_access_iterator_tag > &
operator = (
  cast_iterator  <
    T
  , Iterator
  , std::random_access_iterator_tag> const &
) = default;

cast_iterator (
  cast_iterator <
    T
  , Iterator
  , std::random_access_iterator_tag > &&
) = default;

cast_iterator <
  T,Iterator,std::random_access_iterator_tag > &
operator = (
  cast_iterator  <
    T
  , Iterator
  , std::random_access_iterator_tag> &&
) = default;

}; /* typed iterator random */

template <typename T, typename Iterator>
cast_iterator <
  T, Iterator, std::random_access_iterator_tag >
::cast_iterator (
  Iterator & _iterator
)
: cast_iterator <T,Iterator,std::bidirectional_iterator_tag>
  (_iterator)
{
}

}
#endif

