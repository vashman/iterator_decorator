#ifndef ITER_DECOR_CALLBACK_ITERATOR_HPP
#define ITER_DECOR_CALLBACK_ITERATOR_HPP

#include <iterator>
#include <type_traits>
#include <functional>

namespace iter_decor {
/**/
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
  )
  : callback (_callback)
  , iter (_iter) {
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
  std::enable_if<
  callback_iterator<Iter> &>::value
  operator++(
  ){
  this->callback(this->iter);
  (this->iter)++;
  return *this;
  }

  /* == */
/*  bool
  operator==(
    callback_iterator<Iter>
    const & _callback
  ) const {
  this->callback(this->iter);
  return (this->iter == _callback.iter);
  }
*/
  /* != */
/*  bool
  operator!=(
    callback_iterator<Iter>
    const & _callback
  ) const {
  this->callback(this->iter);
  return (this->iter != _callback.iter);
  }
*/
  /* == iterator_type */
/*  bool
  operator==(
    Iter const & _iter
  ) const {
  this->callback(this->iter);
  return (this->iter == _iter);
  }
*/
  /* != iterator_type */
/*  bool
  operator!=(
    Iter const & _iter
  ) const {
  this->callback(this->iter);
  return (this->iter != _iter);
  }
*/
  /* operator * */
  typename Iter::reference
  operator*(){
  this->callback(this->iter);
  return *(this->iter);
  }

  /* operator -> */
/*  typename Iter::pointer
  operator->(){
  this->callback(this->iter);
  return (this-iter).operator->();
  }
*/
  /* operator increment */
  callback_iterator<Iter> &
  operator++(
    int _dummy
  ){
  this->callback(this->iter);
  ++(this->iter);
  return *this;
  }

  /* operator deincrement */
/*  callback_iterator<Iter> &
  operator--(){
  this->callback(this->iter);
  (this->iter)--;
  return *this;
  }
*/
private:
  std::function<void(Iter &)> callback;
  Iter iter;
};

} /* iter_decor */
#endif
