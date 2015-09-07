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
/**/
struct iter_ops {
  typedef unsigned int operation_type;

  static const
  operation_type none = 0x00;

  static const
  operation_type read = 0x01; // x

  static const
  operation_type write = 0x02; // x

  static const
  operation_type increment = 0x04; // x

  static const
  operation_type deincrement = 0x08;//

  static const
  operation_type random = 0x10; //

  static const
  operation_type add = 0x20;//

  static const
  operation_type subtract = 0x40;//

  static const
  operation_type deference = 0x80;// x
};

/* callback_iterator */
template <typename Iter>
class callback_iterator
: public std::iterator <
  typename Iter::iterator_category
, typename Iter::value_type
, typename Iter::difference_type
, typename Iter::pointer
, typename Iter::reference
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

  typedef typename
  Iter::pointer pointer;

  typedef typename
  Iter::reference reference;

  typedef typename
    Iter
  ::iterator_category iterator_category;

  /* ctor */
  template <typename Callback>
  explicit
  callback_iterator(
    Iter const &
  , Callback
  , iter_ops::operation_type const
    _ops = 0x00
  );

  /* ctor copy */
  callback_iterator(
    callback_iterator<Iter>
    const &
  ) = default;

  /* operator copy */
  callback_iterator<Iter> &
  operator=(
    callback_iterator const &
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

  /* operator increment */
  callback_iterator<Iter> &
  operator++(
  ){
  this->
  do_callback(iter_ops::increment);
  (this->iter)++;
  return *this;
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
  , bool
  >::type
  operator==(
    callback_iterator<Iter> const &
    _other
  ) const {
  return (this->iter == _other.iter);
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
  , bool
  >::type
  operator!=(
    callback_iterator<Iter> const &
    _other
  ) const {
  return (this->iter != _other.iter);
  }

  /* operator *
    Output iterator.
  */
  template <
    typename Cat = iterator_category
  >
  typename std::enable_if<
    std::is_same<
      Cat
    , std::output_iterator_tag
    >::value
  , Iter
  >::type
  operator*(){
  this->
  do_callback(iter_ops::deference);
  return *(this->iter);
  }

  /* operator *
    Input iterator
  */
  template <
    typename Cat = iterator_category
  >
  typename std::enable_if<
    std::is_same<
      Cat
    , std::input_iterator_tag
    >::value
  , typename Iter::value_type
  >::type
  operator*(){
  this->
  do_callback(iter_ops::deference);
  return *(this->iter);
  }

  /* operator * */
  template <
    typename Cat = iterator_category
  >
  typename std::enable_if<
    std::is_same<
      Cat
    , std::forward_iterator_tag
    >::value
  ||
    std::is_same<Cat, std::bidirectional_iterator_tag>::value
  ||
    std::is_same<Cat, std::random_access_iterator_tag>::value
  , typename Iter::reference
  >::type
  operator*(){
  this->
  do_callback(iter_ops::deference);
  return *(this->iter);
  }

  /* operator ->
    Input iterator.
  */
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
  , typename Iter::pointer
  >::type
  operator->(){
  this->
  do_callback(iter_ops::deference);
  return (this-iter).operator->();
  }

  /* operator increment */
  callback_iterator<Iter> &
  operator++(
    int _dummy
  ){
  this->
  do_callback(iter_ops::increment);
  ++(this->iter);
  return *this;
  }

  /* operator deincrement */
  template <typename Cat = iterator_category>
  typename std::enable_if<
    std::is_same<Cat, std::bidirectional_iterator_tag>::value
  ||
    std::is_same<Cat, std::random_access_iterator_tag>::value
  , callback_iterator<Iter> & 
  >::value
  operator--(){
  this->
  do_callback(iter_ops::deincrement);
  (this->iter)--;
  return *this;
  }

/* Random Access */
  template <
    typename Cat = iterator_category
  >
  std::enable_if<
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

  template <
    typename Cat = iterator_category
  >
  std::enable_if<
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

  template <
    typename Cat = iterator_category
  >
  std::enable_if<
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

  template <
    typename Cat = iterator_category
  >
  std::enable_if<
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
  std::enable_if<
    std::is_same<
      Cat
    , std::random_access_iterator_tag
    >::value
  , callback_iterator<Iter> &
  >::value
  operator+=(
    size_type _size
  ) const {
  this->iter += _size;
  return *this;
  }

  /* operator + */
  template <
    typename Cat = iterator_category
  >
  std::enable_if<
    std::is_same<
      Cat
    , std::random_access_iterator_tag
    >::value
  , callback_iterator<Iter>
  >::value
  operator+(
    size_type _size
  ) const {
  return 
  callback_iterator<Iter>(
    (this->iter+size)
  , this->callback
  , (this->iter+size)
  );
  }

  /* operator -= */
  template <
    typename Cat = iterator_category
  >
  std::enable_if<
    std::is_same<
      Cat
    , std::random_access_iterator_tag
    >::value
  , callback_iterator<Iter> &
  >::value
  operator-=(
    size_type _size
  ) const {
  this->iter -= _size;
  return *this;
  }

  Iter
  get_iterator() const;

private:
  std::function<
    void(
      Iter &
    , iter_ops::operation_type const
    )
  > callback;

  Iter iter;

  iter_ops::operation_type const ops;

  void
  do_callback(
    iter_ops::operation_type const
  );
};

} /* iter_decor */
#include <bits/callback_iterator.tcc>
#endif
