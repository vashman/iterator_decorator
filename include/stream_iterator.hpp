#ifndef ITERATOR_DECORATOR_STREAM_ITERATOR_HPP
#define ITERATOR_DECORATOR_STREAM_ITERATOR_HPP

//#include <iostream>

namespace iterator_decorator {
/* ostream inserter overload
  The insert postion is used for ?

template <
  typename T
, typename CharT
, typename traits >
std::ostream_iterator<T,CharT,traits>
inserter (
  std::basic_ostream<CharT,traits> &
, std::ostream_iterator<T,CharT,traits>
); */

/* ostream front inserter
  Should set the stream to

template <
  typename T
, typename CharT
, typename traits >
std::ostream_iterator<T,CharT,traits>
front_inserter (
  std::basic_ostream<CharT,traits>
  &
); */

/* ostream back inserter 
template <
  typename T
, typename charT
, typename traits >
std::ostream_iterator<T,charT,traits>
back_inserter (
  std::basic_ostream<charT,traits> &
); */

/* istream begin
template <
  typename T
, typename charT
, typename traits
>
std::istream_iterator<T,charT,traits>
begin (
  std::basic_istream<charT,traits> &
); */

/* istream end 
template <
  typename T
, typename charT
, typename traits >
std::istream_iterator<T,charT,traits>
end (
  std::basic_istream<charT,traits>
  const &
); */

} /* iterator_decorator */
#include "bits/stream_iterator.tcc"
#endif
