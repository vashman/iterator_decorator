#ifndef ITERATOR_DECORATOR_ITERATOR_TCC
#define ITERATOR_DECORATOR_ITERATOR_TCC

namespace iterator_decorator {
/* inserter */
template <
  typename T
, typename Container
>
std::insert_iterator<Container>
inserter(
  Container & _c
, typename Container::iterator _i
){
return std::inserter(_c, _i);
}

/* ostream inserter overload */
template <
  typename T
, typename CharT
, typename traits
>
std::ostream_iterator<T,CharT,traits>
inserter(
  std::basic_ostream<CharT,traits> &
  _stream
, std::ostream_iterator<T,CharT,traits>
  _iterator
){
return _iterator;
}

/* front_inserter */
template <
  typename T
, typename Container
>
std::front_insert_iterator<Container>
front_inserter(
  Container & _c
){
return std::front_inserter(_c); 
}

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
  & _stream
){
// _stream. ??
return std
::ostream_iterator<T,CharT,traits>(
  _stream
);
}

/* back_inserter */
template <
  typename T
, typename Container
>
std::back_insert_iterator<Container>
back_inserter(
  Container & _c
){
return std::back_inserter(_c);
}

/* ostream back inserter */
template <
  typename T
, typename charT
, typename traits
>
std::ostream_iterator<T,charT,traits>
back_inserter(
  std::basic_ostream<charT,traits> &
  _stream
){
return
std::ostream_iterator<T,charT,traits>
(_stream);
}

/* template begin */
template <
  typename T
, typename Container
>
typename Container::iterator
begin(
  Container & _c
){
return std::begin(_c);
}

/* template end */
template <
  typename T
, typename Container
>
typename Container::iterator
end(
  Container & _c
){
return std::end(_c);
}

/* istream begin */
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
}

/* istream end */
template <
  typename T
, typename charT
, typename traits
>
std::istream_iterator<T,charT,traits>
end(
  std::basic_istream<charT,traits> const
  &
){
return std
::istream_iterator<T,charT,traits>();
}

/* template cbegin */
template <
  typename T
, typename Container
>
typename Container::const_iterator
cbegin(
  Container & _con
){
return _con.cbegin();
}

/* template cend */
template <
  typename T
, typename Container
>
typename Container::const_iterator
cend(
  Container & _con
){
return _con.cend();
}

} /* iterator_decorator */
#endif
