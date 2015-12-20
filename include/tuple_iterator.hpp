//

#ifndef ITERATOR_DECORATOR_TUPLE_ITERATOR_TCC
#define ITERATOR_DECORATOR_TUPLE_ITERATOR_TCC

#include <iterator>
#include <tuple>
#include <typesystems/typelist.hpp>

namespace iterator_decorator {
/* tuple container */
template <typename... Ts>
class tuple_container {
public:

typedef typesystems
::typelist<Ts...> type;

private:

std::tuple <Ts...> con;
};
  
/* tuple iterator */
template <typename T>
class tuple_iterator
: public std::iterator <
  std::random_access_iterator_tag
, typename std::iterator_traits<Iter>
  ::value_type
, typename std::iterator_traits<Iter>
  ::difference_type
, typename std::iterator_traits<Iter>
  ::pointer
, typename std::iterator_traits<Iter>
  ::reference
>
{
public:

/* ctor */
template <typename... Ts>
tuple_iterator (tuple_container<Ts...>);

}; /* tuple iterator */

template <typename T, typename... Ts>
tuple_iterator<T>
begin (
  std::tuple<Ts...> & _tuple
){
  
}

template <typename T, typename... Ts>
tuple_iterator<T>
end (
  std::tuple<Ts...> & _tuple
){
  
}

} /* iterator decorator */
#endif
