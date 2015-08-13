//

#ifndef ITER_DECOR_CALLBACK_ITERATOR_HPP
#define ITER_DECOR_CALLBACK_ITERATOR_HPP

#include <iterator>
#include <type_traits>
#include <functional>

namespace iter_decor {
/**/
struct iter_ops {
  typedef unsigned int operation_type;
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
    Iter const & _iter
  , Callback _callback
  , iter_ops::operation_type const
    _ops = 0x00
  )
  : callback (_callback)
  , iter (_iter)
  , ops (_ops) {
  }

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
  template <
    typename Cat = iterator_category
  >
  typename std::enable_if<
    std::is_same<
      Cat
    , std::output_iterator_tag
    >::value
  ||
    std::is_same<
      Cat
    , std::input_iterator_tag
    >::value
  , callback_iterator<Iter> &
  >::type
  operator++(
  ){
    if (
      (this->ops & iter_ops::increment)
    ){
    this->callback(this->iter);
    }
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
    if (
      this->ops & iter_ops::deference
    ){
    this->callback(this->iter);
    }
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
    if (
      this->ops & iter_ops::deference
    ){
    this->callback(this->iter);
    }
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
    if (
      this->ops & iter_ops::deference
    ){
    this->callback(this->iter);
    }
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
    if (
      this->ops & iter_ops::deference
    ){
    this->callback(this->iter);
    }
  return (this-iter).operator->();
  }

  /* operator increment */
  template <
    typename Cat = iterator_category
  >
  typename std::enable_if<
    std::is_same<
      Cat
    , std::output_iterator_tag
    >::value
  ||
    std::is_same<
      Cat
    , std::input_iterator_tag
    >::value
  , callback_iterator<Iter> &
  >::type
  operator++(
    int _dummy
  ){
    if (
      this->ops & iter_ops::increment
    ){
    this->callback(this->iter);
    }
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
    if (
      this->ops & iter_ops::deincrement
    ){
    this->callback(this->iter);
    }
  (this->iter)--;
  return *this;
  }

private:
  std::function<void(Iter &)> callback;
  Iter iter;
  iter_ops::operation_type const ops;
};

template <
  typename Callback
, typename Iter
>
callback_iterator<Iter>
make_callback_iterator(
  Iter _iter
, Callback _callback
, iter_ops::operation_type const
  _ops = 0x00
){
return
callback_iterator<Iter>(
  _iter
, _callback
, _ops
);
}

} /* iter_decor */
#endif
