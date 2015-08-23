// Shows how to select when to run callback.

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <list>
#include "../include/callback_iterator.hpp"

using std::function;
using std::vector;
using std::list;
using iterator_decorator::callback_iterator;
using std::find;
using iterator_decorator::iter_ops;
using iterator_decorator::begin;
using iterator_decorator::end;

void
func(vector<int>::iterator);

void
func2(vector<int>::iterator);

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
list<char> ll;
auto b = vec.begin(), e = vec.end();
auto c = ll.begin(), ce = ll.end();

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

auto
  aiter (begin<int>(vec, func2, iter_ops::increment))
, aend (end<int>(vec, func2, iter_ops::increment));

//find(iter_b, iter_e, 3);

return 0;
}

void
func2(vector<int>::iterator){
std::cout << "function called.\n";
}

void
func(vector<int>::iterator){
std::cout << "Func called.\n";
}
