#ifndef ITERATOR_DECORATOR_CALLBACK\
_ITERATOR_TCC
#define ITERATOR_DECORATOR_CALLBACK\
_ITERATOR_TCC

namespace itertor_decorator {
/* ctor */
template <typename Iter>
template <typename Callback>
  callback_iterator<Iter>
::callback_iterator(
  Iter const & _iter
, Callback _callback
, iter_ops::operation_type const
  _ops
)
: callback (_callback)
, iter (_iter)
, ops (_ops) {
}

/* get_iterator */
template <typename Iter>
Iter
callback_iterator<Iter>::get_iterator (
) const {
return this->iter;
}

/* do_callback */
template <typename Iter>
void
callback_iterator<Iter>::do_callback (
  iter_ops::operation_type const _ops
){
  if (this->ops & _ops){
  this->callback(this->iter);
  }
}

} /* iter_decor */
#endif 
