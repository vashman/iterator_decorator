
#ifndef ITERATOR_DECORATOR_CAST_ITERATOR_TCC
#define ITERATOR_DECORATOR_CAST_ITERATOR_TCC

namespace iterator_decorator {

template <typename T, typename Iterator>
auto
make_cast_iterator (
  Iterator _iterator
)
-> cast_iterator <T,Iterator, typename std::iterator_traits<Iterator>::iterator_category> {
return cast_iterator <
  T, Iterator, typename std::iterator_traits<Iterator>::iterator_category > (_iterator);
}

}
#endif

