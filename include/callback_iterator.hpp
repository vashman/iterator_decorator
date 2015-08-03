#ifndef ITER_DECOR_CALLBACK_ITERATOR_HPP
#define ITER_DECOR_CALLBACK_ITERATOR_HPP

#include <iterator>
#include <type_traits>

namespace iter_decor {
/**/
template <
  typename Iter
, typename Callback
>
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
  typedef typename
  Iter::value_type value_type;

  typedef typename
  Iter::difference_type difference_type;

  typedef typename
  Iter::pointer pointer;

  typedef typename
  Iter::reference reference;

  typedef typename
    Iter
  ::iterator_category iterator_category;

  explicit
  callback_iterator(
    Iter const &
  , Callback
  );

  callback_iterator(
    callback_iterator<Iter,Callback>
    const &
  ) = default;

  callback_iterator<Iter,Callback> &
  operator=(
    callback_iterator const &
  ) = default;

  callback_iterator(
    callback_iterator<Iter,Callback> &&
  ) = default;

  callback_iterator<Iter,Callback> &
  operator=(
    callback_iterator &&
  ) = default;

  /* operator increment */
  callback_iterator<Iter,Callback> &
  operator++();

  /**/
  template <
    typename Cat = iterator_category
  >
  typename std::enable_if<
    (
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
    )
  , bool
  >::type
  operator==(
    callback_iterator<Iter,Callback>
    const & _callback
  ) const {
  this->callback(this->iter);
  return (*this == _callback.iter);
  }

  /**/
  template <
    typename Cat = iterator_category
  >
  typename std::enable_if<
    (
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
    )
  , bool
  >::type
  operator!=(
    callback_iterator<Iter,Callback>
    const & _callback
  ) const {
  this->callback(this->iter);
  return !(*this == _callback);
  }

  bool
  operator==(
    Iter const & _iter
  ) const {
  return (this->iter == _iter);
  }

  bool
  operator!=(
    Iter const & _iter
  ) const {
  this->callback(this->iterator);
  return (this->iter != _iter);
  }

  /* operator * */
  typename Iter::reference
  operator*() const;

  /* operator -> */
  typename Iter::pointer
  operator->() const;


  /* operator increment */
  callback_iterator<Iter,Callback> &
  operator++(
    int
  );

  template <
    typename Cat = iterator_category
  >
  typename std::enable_if<
    (
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
    )
  , callback_iterator<Iter,Callback> &
  >::type
  operator--(){
  this->callback(this->iter);
  (this->iter)--;
  return *this;
  }

private:
  Callback callback;
  Iter iter;
};

template <
  typename Iter
, typename Callback
>
callback_iterator<Iter,Callback>
make_callback_iterator(
  Iter _iter
, Callback _callback
){
return
callback_iterator<Iter,Callback>(
  _iter
, _callback
);
}

} /* iter_decor */
#include "bits/callback_iterator.tcc"
#endif
