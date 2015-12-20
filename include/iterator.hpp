//

#ifndef ITERATOR_DECORATOR_ITERATOR_HPP
#define ITERATOR_DECORATOR_ITERATOR_HPP

\#include <iterator>

namespace iterator_decorator {
/* inserter */
template <
  typename T
, typename Container >
std::insert_iterator<Container>
inserter (
  Container &
, typename Container::iterator
);

/* front_inserter */
template <
  typename T
, typename Container >
std::front_insert_iterator<Container>
front_inserter (
  Container &
);

/* back_inserter */
template <
  typename T
, typename Container >
std::back_insert_iterator<Container>
back_inserter (
  Container &
);

/* template begin */
template <
  typename T
, typename Container >
typename Container::iterator
begin (
  Container &
);

/* template begin */
template <
  typename T
, typename Container >
typename Container::iterator
end (
  Container &
);

/* template cbegin 
Returns a const iterator for container.
If the container is of a differnt type,
then compling fails.
*/
template <
  typename T
, typename Container >
typename Container::const_iterator
cbegin (
  Container &
);

/* template cend
Returns a const iterator for container.
If the container is of a differnt type,
then compling fails. 
*/
template <typename T,typename Container>
typename Container::const_iterator
cend (
  Container &
);

} /* iterator_decorator */
#include "bits/iterator.tcc"
#endif
