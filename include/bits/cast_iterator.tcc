namespace iterator_decorator {

template <typename T, typename Iterator>
auto
make_typed_iterator (
  Iterator _iterator
)
-> typed_iterator <T,Iterator, typename std::iterator_traits<Iterator>::iterator_category> {
return typed_iterator <
  T, Iterator, typename std::iterator_traits<Iterator>::iterator_category > (_iterator);
}

}
