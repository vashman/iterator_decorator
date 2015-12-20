#ifndef
#define

#include <iterator>
#include <tuple>

template <typename... TS>
class proxy_iterator
: public std::iterator<> {
public:
/* operator = */
template <typename T>
void
operator=(
  T const &
);

std::tuple<TS...> iterators;

}; /* proxy_iterator */

template <typename... TS>
template <typename T>
void
proxy_iterator<TS...>::operator =(
  T const & _var
){

}

} /* iterator_decorator */
#endif
