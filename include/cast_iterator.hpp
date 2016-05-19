//

#ifndef ITERATOR_DECORATOR_CAST_ITERATOR_HPP
#define ITERATOR_DECORATOR_CAST_ITERATOR_HPP

#include <iterator>

namespace iterator_decorator {

template <
  typename T
, typename Iterator
, typename Catagory >
struct cast_iterator ;

template <typename T, typename Iterator>
struct cast_iterator <
  T
, Iterator
, std::input_iterator_tag >;

template <typename T, typename Iterator>
struct cast_iterator <
  T
, Iterator
, std::output_iterator_tag >;

template <typename T, typename Iterator>
struct cast_iterator <
  T
, Iterator
, std::forward_iterator_tag >;

template <typename T, typename Iterator>
struct cast_iterator <
  T
, Iterator
, std::bidirectional_iterator_tag >;

template <typename T, typename Iterator>
struct cast_iterator <
  T
, Iterator
, std::random_access_iterator_tag >;

template <typename T, typename Iterator>
auto
make_cast_iterator (
  Iterator
)
-> cast_iterator <T,Iterator, typename std::iterator_traits<Iterator>::iterator_category>;

}
#include "./bits/cast_iterator_input.hpp"
#include "./bits/cast_iterator_output.hpp"
#include "./bits/cast_iterator_forward.hpp"
#include "./bits/cast_iterator_bidirectional.hpp"
#include "./bits/cast_iterator_random.hpp"
#include "./bits/cast_iterator.tcc"
#endif

