// Shows differnt type of callbacks.

#include <iostream>
#include <vector>
#include "../include/callback_iterator.hpp"

using std::vector;
using iterator_decorator::bind_callback;
using iterator_decorator::iter_ops;

class functor {
public:
  template <typename T>
  void
  operator ()(T & _v, iter_ops::operation_type const &){
  std::cout << "functor called.\n";
  }
};

int main (){
vector<int> vec;
auto b = vec.begin(), e = vec.end();

auto iter_b (
  bind_callback(b, functor(), iter_ops::increment)
);

auto iter_e (bind_callback(e));

auto iter_func (bind_callback(b));

auto iter_lam (
  bind_callback(
    b
  , [](vector<int>::iterator &, iter_ops::operation_type const &){
    std::cout << "Lam called.\n";
    }
  )
);

//find(iter_b, iter_e, 3);

return 0;
}
