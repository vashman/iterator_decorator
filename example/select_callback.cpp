// Shows how to select when to run callback.

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
#include "../include/callback_iterator.hpp"

using std::function;
using std::vector;
using std::list;
using iterator_decorator::bind_callback;
using iterator_decorator::callback_iterator;
using std::find;
using iterator_decorator::iter_ops;
using iterator_decorator::begin;
using iterator_decorator::end;

/* func
  function explictiy taking the
  iterator type.
*/
void
func(
  vector<int>::iterator &
, iter_ops::operation_type const &
);

/*func2
  Function taking a templated
  iterator type.
*/
template <typename Iter>
void
func2(
  Iter &
, iter_ops::operation_type const &
);

class functor {
public:
  template <typename T>
  void
  operator ()(T _v, iter_ops::operation_type _op){
  std::cout << "functor called.\n";
  }
};

int main (){
vector<int> vec;
list<char> ll {'A','Z'};

/* create a callback iterator using
  begining of the vector bound to func2.

  The callback is only called upon
  incrementing the iterator.
*/
auto
iter_b (bind_callback(
  vec.begin()
, func2<decltype(vec.begin())>
, iter_ops::increment
));

callback_iterator<vector<int>::iterator>
iter_e (vec.end());


auto
iter_func = bind_callback(
  ll.begin()
, func2<decltype(ll.begin())>
, iter_ops::deference
);

callback_iterator<vector<int>::iterator>
iter_lam (
  vec.begin()
, [](
    vector<int>::iterator & _iter
  , iter_ops::operation_type const &_ops
  ){
  std::cout << "Lam called.\n";
  }
, iter_ops::deference
);

callback_iterator<vector<int>::iterator>
iter_lam_end (
  vec.begin()
, [](
    vector<int>::iterator & _iter
  , iter_ops::operation_type const &_ops
  ){
  std::cout << "Lam called.\n";
  }
);

callback_iterator<list<char>::iterator>
itertor (bind_callback(
  ll.begin()
, functor()
, iter_ops::increment
));

auto
itertor_end (bind_callback(ll.end()));

std::copy(itertor, itertor_end, std::ostream_iterator<char>(std::cout));


return 0;
}

template <typename Iter>
void
func2(
  Iter & _iter
, iter_ops::operation_type const & _ops
){
std::cout << "function called.\n";
}

void
func(
  vector<int>::iterator & _iter
, iter_ops::operation_type const & _ops
){
std::cout << "Func called.\n";
}
