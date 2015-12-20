//

#ifndef ITERATOR_DECORATOR_CALLBACK_ITERATOR_BASE_HPP
#define ITERATOR_DECORATOR_CALLBACK_ITERATOR_BASE_HPP

#include <iterator>
#include <type_traits>
#include <functional>

namespace iterator_decorator {

/* callback_iterator_base */
template <typename Iter>
class callback_iterator_base 
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
/* ctor */
template <typename Callback>
explicit
callback_iterator_base (
  Iter const &
, Callback
, iter_ops::operation_type const
  _ops = iter_ops::none
);

/* ctor */
explicit
callback_iterator_base (
  Iter const &
, iter_ops::operation_type const
  _ops = iter_ops::none
);

/* ctor copy */
callback_iterator_base (
  callback_iterator_base<Iter> const &
) = default;

/* ctor move */
callback_iterator_base (
  callback_iterator_base<Iter> &&
) = default;

/* operator copy */
callback_iterator<Iter> &
operator = (
  callback_iterator<Iter> const &
) = default;

/* ctor move */
callback_iterator_base<Iter> &
operator = (
  callback_iterator_base<Iter> &&
) = default;

/* get_iterator
Return a copy of the internal iterator.
*/
Iter
get_iterator() const;

/* operator increment */
callback_iterator<Iter> &
operator ++ (
){
this->do_callback(iter_ops::increment);
(this->iter)++;
return *this;
}

/* operator increment */
callback_iterator<Iter> &
operator ++ (
  int _dummy
){
this->do_callback(iter_ops::increment);
++(this->iter);
return *this;
}

protected:

Iter iter;

void
do_callback (
  iter_ops::operation_type const
);

private:

std::function<
  void (
    Iter &
  , iter_ops::operation_type const
  )
> callback;

iter_ops::operation_type const ops;
} /* callback_iterator_base */

/* ctor */
template <typename Iter>
template <typename Callback>
  callback_iterator_base<Iter>
::callback_iterator_base (
  Iter const & _iter
, Callback _callback
, iter_ops::operation_type const _ops
)
: callback (_callback)
, iter (_iter)
, ops (_ops) {
}

/* ctor */
template <typename Iter>
  callback_iterator_base<Iter>
::callback_iterator_bases (
  Iter const & _iter
, iter_ops::operation_type const _ops
)
: callback ()
, iter (_iter)
, ops (_ops) {
}

/* get_iterator */
template <typename Iter>
Iter
  callback_iterator_base<Iter>
::get_iterator (
) const {
return this->iter;
}

/* do_callback */
template <typename Iter>
void
  callback_iterator_base<Iter>
::do_callback (
  iter_ops::operation_type const _ops
){
  if (
    (this->callback)
  &&
    (this->ops & _ops)
  ){
  this->callback(this->iter, _ops);
  }
}

} /* iterator_decorator */
#endif

