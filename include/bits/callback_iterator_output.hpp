
namespace iterator_decorator {

template <typename Iter>
class callback_iterator <
  std::output_iterator_tag
>
: public std::iterator <
  std::output_iterator_tag
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

/* operator * */
Iter
operator* (
){
this->do_callback(iter_ops::deference);
return *(this->iter);
}
} /* callback_iterator */

} /* iterator_decorator */
#endif

