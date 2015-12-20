//

#ifndef ITERATOR_DECORATOR_CALLBACK\
_ITERATOR_HPP
#define ITERATOR_DECORATOR_CALLBACK\
_ITERATOR_HPP

#include <iterator>
#include <type_traits>
#include <functional>
#include "iterator.hpp"

namespace iterator_decorator {
/* iter_ops */
struct iter_ops {
typedef unsigned int operation_type;

static const
operation_type none = 0x00;

static const
operation_type read = 0x01;

static const
operation_type write = 0x02;

static const
operation_type increment = 0x04;

static const
operation_type deincrement = 0x08;

static const
operation_type random = 0x10;

static const
operation_type add = 0x20;

static const
operation_type subtract = 0x40;

static const
operation_type deference = 0x80;
}; /* iter_ops */

/* callback_iterator */
template <
  typename Iter
, typename Iterator_catagory
>
class callback_iterator
: public std::iterator <
  typename std::iterator_traits<Iter>
  ::iterator_category
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
typedef Iter iterator_type;

typedef typename
std::iterator_traits<Iter>::value_type
value_type;

typedef typename
  std::iterator_traits<Iter>
::difference_type difference_type;

typedef typename Iter::pointer pointer;

typedef typename Iter::reference
reference;

typedef typename Iter::iterator_category
iterator_category;

/* ctor */
template <typename Callback>
explicit
callback_iterator(
  Iter const &
, Callback
, iter_ops::operation_type const
  _ops = iter_ops::none
);

/* ctor */
explicit
callback_iterator(
  Iter const &
, iter_ops::operation_type const
  _ops = iter_ops::none
);

/* ctor copy */
callback_iterator(
  callback_iterator<Iter> const &
) = default;

/* operator copy */
callback_iterator<Iter> &
operator=(
  callback_iterator<Iter> const &
) = default;

/* operator move */
callback_iterator(
  callback_iterator<Iter> &&
) = default;

/* ctor move */
callback_iterator<Iter> &
operator=(
  callback_iterator<Iter> &&
) = default;

/***************************** Output */
/****************************** Input */
/* operator -> */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::input_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::forward_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::bidirectional_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, typename Iter::pointer
>::type
operator->(){
this->do_callback(iter_ops::deference);
return (this-iter).operator->();
}

/* operator * */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::input_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::forward_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::bidirectional_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, typename Iter::reference
>::type
operator*(){
this->do_callback(iter_ops::deference);
return *(this->iter);
}

/* != */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::input_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::forward_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::bidirectional_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, bool
>::type
operator!=(
  callback_iterator<Iter> const & _lhs
) const {
return (this->iter != _lhs.iter);
}

/* == */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::input_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::forward_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::bidirectional_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, bool
>::type
operator==(
  callback_iterator<Iter> const & _lhs
) const {
return (this->iter == _lhs.iter);
}

/**************************** Forward */
/* default ctor */
callback_iterator(
){

}

/********************* Bi-Directional */
/* operator -- */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::bidirectional_iterator_tag
  >::value
, callback_iterator<Iter> &
>::value
operator--(){
this->
do_callback(iter_ops::deincrement);
this->iter--;
return *this;
}

/* operator -- */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
||
  std::is_same<
    Cat
  , std::bidirectional_iterator_tag
  >::value
, callback_iterator<Iter> &
>::value
operator--(int _dummy){
this->
do_callback(iter_ops::deincrement);
--(this->iter);
return *this;
}

/********************** Random Access */
/* operator < */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, bool
>::value
operator<(
  callback_iterator<Iter> const & _rhs
) const {
return (this->iter < _rhs.iter);
}

/* operator > */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, bool
>::value
operator>(
  callback_iterator<Iter> const & _rhs
) const {
return (this->iter > _rhs.iter);
}

/* operator <= */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, bool
>::value
operator<=(
  callback_iterator<Iter> const & _rhs
) const {
return (this->iter <= _rhs.iter);
}

/* operator >= */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, bool
>::value
operator>=(
  callback_iterator<Iter> const & _rhs
) const {
return (this->iter >= _rhs.iter);
}

/* operator += */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, callback_iterator<Iter> &
>::value
operator+=(
  typename bits
  ::if_type<difference_type>::type _n
) const {
this->iter += _n;
return *this;
}

/* operator + */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, callback_iterator<Iter>
>::value
operator+(
  typename bits
  ::if_type<difference_type>::type _n
) const {
return
callback_iterator<Iter>(
  (this->iter+_n)
, this->callback
, this->ops
);
}

/* operator - */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, difference_type
>::value
operator-(
  callback_iterator<Iter> const & _lhs
) const {
return (this->iter - _lhs.iter);
}

/* operator - */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, callback_iterator<Iter>
>::value
operator-(
  typename bits
  ::if_type<difference_type>
  ::type const _n
) const {
return callback_iterator<Iter>(
  (this->iter - _n)
, this->callback
, this->ops
);
}

/* operator -= */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, callback_iterator<Iter> &
>::value
operator-=(
  typename bits
  ::if_type<difference_type>::type _n
) const {
this->iter -= _n;
return *this;
}

/* operator [] */
template <
  typename Cat = iterator_category
>
typename std::enable_if<
  std::is_same<
    Cat
  , std::random_access_iterator_tag
  >::value
, reference
>::value
operator[](
  typename bits
  ::if_type<difference_type>::type _n
) const {
return this->iter[_n];
}

}; /* callback_iterator */

/* operator + */
template <typename Iter>
typename std::enable_if<
  std::is_same<
    typename std
    ::iterator_traits<Iter>
    ::iterator_category
  , std::random_access_iterator_tag
  >::value
, callback_iterator<Iter>
>::value
operator+ (
  typename std
  ::iterator_traits<Iter>
  ::difference_type _n
, callback_iterator<Iter> const & _iter
){
return
callback_iterator<Iter>(
  (_iter.iter+_n)
, _iter.callback
, _iter.ops
);
}

/* bind_callback
  Make a callback iterator using the
  Callback object.
*/
template <
  typename Iter
, typename Iter_Catagory
, typename Callback >
callback_iterator<Iter, Iter_Catagory>
bind_callback (
  Iter _iter
, Callback _callback
, iter_ops::operation_type
  const _ops = iter_ops::none
){
return
callback_iterator<Iter,Iter_Catagory> (
  _iter
, _callback
, _ops
);
}

/* bind_callback
  Make a callback iterator.
*/
template <
  typename Iter
, typename Iter_Catagory >
callback_iterator<Iter,Iter_Catagory>
bind_callback (
  Iter _iter
){
return
callback_iterator<Iter,Iter_Catagory> (
  _iter
, iter_ops::none
);
}

} /* iter_decor */
#include "bits/callback_iterator.tcc"
#endif
