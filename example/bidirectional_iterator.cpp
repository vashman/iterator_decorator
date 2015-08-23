// Shows differnt type of callbacks.

#include <iostream>
#include <vector>
#include "../include/callback_iterator.hpp"

using std::vector;
using iter_decor::callback_iterator;

class functor {
public:
  template <typename T>
  void
  operator ()(T _v){
  std::cout << "functor called.\n";
  }
};

int main (){
vector<int> vec;
auto b = vec.begin(), e = vec.end();

callback_iterator<vector<int>::iterator>
iter_b (b, func2, iter_ops::increment);

callback_iterator<vector<int>::iterator>
iter_e (e, func);

callback_iterator<vector<int>::iterator>
iter_func (b, functor());

callback_iterator<vector<int>::iterator>
iter_lam (
  b
, [](vector<int>::iterator){
  std::cout << "Lam called.\n";
  }
);

//find(iter_b, iter_e, 3);

return 0;
}
