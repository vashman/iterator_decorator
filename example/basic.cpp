#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <list>
#include "../include/callback_iterator.hpp"

using std::function;
using std::vector;
using std::list;
using iter_decor::callback_iterator;
using iter_decor::make_callback_iterator;
using std::find;

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

auto bb = make_callback_iterator(
  b
, func2
);

auto cce = make_callback_iterator(
  e
, function<void(vector<int>::iterator)>
  (func)
);

auto gvg = make_callback_iterator(
  e
, func
);

auto tor = make_callback_iterator(
  e
, functor()
);

auto lam = make_callback_iterator(
  e
, [](vector<int>::iterator){
  std::cout << "Lam called.\n";
  }
);

//find(bb, bbe, 3);
std::is_any(bb, cce, 4);

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
