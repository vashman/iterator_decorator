#ifndef ITERATOR_DECORATOR_STREAM_ITERATOR_TCC
#define ITERATOR_DECORATOR_STREAM_ITERATOR_TCC

namespace iterator_decorator {

/* ostream inserter overload 
template <
  typename T
, typename CharT
, typename traits >
std::ostream_iterator<T,CharT,traits>
inserter (
  std::basic_ostream<CharT,traits> &
  _stream
, std::ostream_iterator<T,CharT,traits>
  _iterator
){
return _iterator;
} */

/* ostream front inserter
  Should set the stream to

template <
  typename T
, typename CharT
, typename traits >
std::ostream_iterator<T,CharT,traits>
front_inserter (
  std::basic_ostream<CharT,traits>
  & _stream
){
// _stream. ??
return std
::ostream_iterator<T,CharT,traits>(
  _stream
);
}*/

/* ostream back inserter 
template <
  typename T
, typename charT
, typename traits >
std::ostream_iterator<T,charT,traits>
back_inserter (
  std::basic_ostream<charT,traits> &
  _stream
){
return
std::ostream_iterator<T,charT,traits>
(_stream);
} */

/* istream begin 
template <
  typename T
, typename charT
, typename traits
>
std::istream_iterator<T,charT,traits>
begin(
  std::basic_istream<charT,traits> & _is
){
return std
::istream_iterator<T,charT,traits>(_is);
}*/

/* istream end
template <
  typename T
, typename charT
, typename traits >
std::istream_iterator<T,charT,traits>
end (
  std::basic_istream<charT,traits>
  const &
){
return std
::istream_iterator<T,charT,traits>();
}*/

} /* iterator_decorator */
#endif
