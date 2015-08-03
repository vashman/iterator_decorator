#ifndef ITER_DECOR_CALLBACK_ITERATOR_TCC
#define ITER_DECOR_CALLBACK_ITERATOR_TCC

namespace iter_decor{
/* ctor */
template <
  typename Iter
, typename Callback
>
  callback_iterator<Iter,Callback>
::callback_iterator(
  Iter const & _iter
, Callback _callback
)
: callback (_callback)
, iter (_iter) {
}

/**/
template <
  typename Iter
, typename Callback
>
callback_iterator<Iter,Callback> &
  callback_iterator<Iter,Callback>
::operator++(
){
this->callback(this->iter);
this->iter++;
return *this;
}

/**/
/*template <
  typename Iter
, typename Callback
>
T const &
  callback_iterator<Iter,Callback>
::operator*(
){
return *(this->iter);
}*/

/**/
/*template <
  typename Iter
, typename Callback
>
T const *
  callback_iterator<Iter,Callback>
::operator->(
){
return *this->iter)->;
}*/

/**/
template <
  typename Iter
, typename Callback
>
callback_iterator<Iter,Callback> &
  callback_iterator<Iter,Callback>
::operator++(
  int _i
){
  while (_i != 0){}
return *this;
}

/**/
/*template <
  typename Iter
, typename Callback
>
callback_iterator<Iter,Callback> &
  callback_iterator<Iter,Callback>
::operator--(
){
return *this;
}*/

} /* iter_decor */
#endif 