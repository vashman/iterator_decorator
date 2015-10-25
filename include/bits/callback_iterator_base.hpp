namespace iterator_decorator {

/* callback_iterator_base */
template <typename Iter>
class callback_iterator_base {
public:

/* get_iterator */
Iter
get_iterator() const;

/* operator increment */
callback_iterator<Iter> &
operator++(
){
this->do_callback(iter_ops::increment);
(this->iter)++;
return *this;
}

/* operator increment */
callback_iterator<Iter> &
operator++(
  int _dummy
){
this->do_callback(iter_ops::increment);
++(this->iter);
return *this;
}

protected:

Iter iter;

void
do_callback(
  iter_ops::operation_type const
);

private:

std::function<
  void(
    Iter &
  , iter_ops::operation_type const
  )
> callback;

iter_ops::operation_type const ops;
} /* callback_iterator_base */

} /* iterator_decorator */
#endif

