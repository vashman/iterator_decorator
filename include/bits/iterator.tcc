//

#ifndef ITERATOR_DECORATOR_ITERATOR_TCC
#define ITERATOR_DECORATOR_ITERATOR_TCC

#include <type_traits>

namespace iterator_decorator {
/* inserter */
template <
  typename T
, typename Container >
std::insert_iterator<Container>
inserter (
  Container & _c
, typename Container::iterator _i
){
static_assert (
  std::is_same <
    T, Container::value_type >::value
, "Cannot get iterator for differnt"
  " type."
);
return std::inserter(_c, _i);
}

/* front_inserter */
template <
  typename T
, typename Container >
std::front_insert_iterator<Container>
front_inserter (
  Container & _c
){
static_assert (
  std::is_same <
    T,Container::value_type >::value
, "Cannot get iterator for differnt"
  " type."
);
return std::front_inserter(_c); 
}

/* back_inserter */
template <
  typename T
, typename Container >
std::back_insert_iterator<Container>
back_inserter (
  Container & _c
){
static_assert (
  std::is_same <
    T,Container::value_type >::value
, "Cannot get iterator for differnt"
  " type."
);
return std::back_inserter(_c);
}

/* template begin */
template <
  typename T
, typename Container >
typename Container::iterator
begin (
  Container & _c
){
static_assert (
  std::is_same <
    T,Container::value_type >::value
, "Cannot get iterator for differnt"
  " type."
);
return std::begin(_c);
}

/* template end */
template <
  typename T
, typename Container >
typename Container::iterator
end (
  Container & _c
){
static_assert (
  std::is_same <
    T,Container::value_type >::value
, "Cannot get iterator for differnt"
  " type."
);
return std::end(_c);
}

/* template cbegin */
template <
  typename T
, typename Container >
typename Container::const_iterator
cbegin (
  Container & _con
){
static_assert (
  std::is_same <
    T,Container::value_type> ::value
, "Connect get const_iterator for"
  " differnt type."
);
return _con.cbegin();
}

/* template cend */
template <
  typename T
, typename Container >
typename Container::const_iterator
cend (
  Container & _con
){
static_assert (
  std::is_same <
    T,Container::value_type >::value
, "Connect get const_iterator for"
  " differnt type."
);
return _con.cend();
}

} /* iterator_decorator */
#endif
