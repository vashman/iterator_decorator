//

#ifndef ITERATOR_DECORATOR_TYPED_ITERATOR_BASE_HPP
#define ITERATOR_DECORATOR_TYPED_ITERATOR_BASE_HPP

#include <iterator>

namespace iterator_decorator {

template <typename T, typename Iterator>
struct typed_iterator_base;

template <typename T, typename Iterator>
bool
operator == (
  typed_iterator_base<T,Iterator> const&
, typed_iterator_base<T,Iterator> const&
);

template <typename T, typename Iterator>
bool
operator != (
  typed_iterator_base<T,Iterator> const&
, typed_iterator_base<T,Iterator> const&
);


/* typed iterator base */
template <typename T, typename Iterator>
struct typed_iterator_base
: public std::iterator <
    typename std
    ::iterator_traits <Iterator>
    ::iterator_category
  , typename std
    ::iterator_traits <Iterator>
    ::value_type
  , typename std
    ::iterator_traits <Iterator>
    ::difference_type
  , typename std
    ::iterator_traits <Iterator>
    ::pointer
  , typename std
    ::iterator_traits <Iterator>
    ::reference
>
{

explicit
typed_iterator_base (
  Iterator &
);

typed_iterator_base (
  typed_iterator_base<T,Iterator> const&
) = default;

typed_iterator_base <T,Iterator> &
operator = (
  typed_iterator_base<T,Iterator> const&
) = default;

typed_iterator_base (
  typed_iterator_base<T,Iterator> &&
) = default;

typed_iterator_base <T,Iterator> &
operator = (
  typed_iterator_base<T,Iterator> &&
) = default;

protected:
  Iterator iterator;

friend bool
operator != <>(
  typed_iterator_base<T,Iterator> const&
, typed_iterator_base<T,Iterator> const&
);

}; /* typed iterator base */

template <typename T, typename Iterator>
  typed_iterator_base <T,Iterator>
::typed_iterator_base (
  Iterator & _iterator
)
: iterator (_iterator)
{
}

template <typename T, typename Iterator>
bool
operator == (
  typed_iterator_base<T,Iterator>
  const & _lhs
, typed_iterator_base<T,Iterator>
  const & _rhs
){
return !(_lhs != _rhs);
}

template <typename T, typename Iterator>
bool
operator != (
  typed_iterator_base<T,Iterator>
  const & _lhs
, typed_iterator_base<T,Iterator>
  const & _rhs
){
return _lhs.iterator != _rhs.iterator;
}

}
#endif

