//

#ifndef ITERATOR_DECORATOR_CALLBACK_ITERATOR_OUTPUT_HPP
#define ITERATOR_DECORATOR_CALLBACK_ITERATOR_OUTPUT_HPP

namespace iterator_decorator {

/* callback_iterator */
template <typename Iter>
class callback_iterator <std::output_iterator_tag>
: public callback_iterator_base <Iter>
{
public:
/* ctor */
using callback_iterator_base<Iter>
::callback_iterator_base;

typename iterator_traits<>::
operator -> (){
this->do_callback(iter_ops::deference);
return (this->iter).operator->();
}

}; /* callback_iterator */

} /* iter_decor */
#include "bits/callback_iterator.tcc"
#endif
