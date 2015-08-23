#ifndef ITERATOR_DECORATOR_ITERATOR_HPP
#define ITERATOR_DECORATOR_ITERATOR_HPP

#include <iostream>
#include <type_traits>
#include <iterator>

namespace iterator_decorator {
/* inserter */
template <
  typename T
, typename Container
>
std::insert_iterator<Container>
inserter(
  Container &
, typename Container::iterator
);

/* ostream inserter overload
  The insert postion is used for ?
*/
template <
  typename T
, typename CharT
, typename traits
>
std::ostream_iterator<T,CharT,traits>
inserter(
  std::basic_ostream<CharT,traits> &
, std::ostream_iterator<T,CharT,traits>
);

/* front_inserter */
template <
  typename T
, typename Container
>
std::front_insert_iterator<Container>
front_inserter(
  Container &
);

/* ostream front inserter
  Should set the stream to
*/
template <
  typename T
, typename CharT
, typename traits
>
std::ostream_iterator<T,CharT,traits>
front_inserter(
  std::basic_ostream<CharT,traits>
  &
);

/* back_inserter */
template <
  typename T
, typename Container
>
std::back_insert_iterator<Container>
back_inserter(
  Container &
);

/* ostream back inserter */
template <
  typename T
, typename charT
, typename traits
>
std::ostream_iterator<T,charT,traits>
back_inserter(
  std::basic_ostream<charT,traits> &
);

/* template begin */
template <
  typename T
, typename Container
>
typename Container::iterator
begin(
  Container &
);

/* template begin */
template <
  typename T
, typename Container
>
typename Container::iterator
end(
  Container &
);

/* istream begin */
template <
  typename T
, typename charT
, typename traits
>
std::istream_iterator<T,charT,traits>
begin(
  std::basic_istream<charT,traits> &
);

/* istream end */
template <
  typename T
, typename charT
, typename traits
>
std::istream_iterator<T,charT,traits>
end(
  std::basic_istream<charT,traits>
  const &
);

/* template cbegin */
template <
  typename T
, typename Container
>
typename Container::const_iterator
cbegin(
  Container &
);

/* template cend */
template <
  typename T
, typename Container
>
typename Container::const_iterator
cend(
  Container &
);

} /* iterator_decorator */
#include "bits/iterator.tcc"
#endif
