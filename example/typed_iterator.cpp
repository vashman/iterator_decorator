#include <iostream>
#include <vector>
#include "../include/typed_iterator.hpp"

using std::begin;
using std::vector;
using std::end;
using iterator_decorator::typed_iterator;
using iterator_decorator::make_typed_iterator;

int main (){

vector<char> vec = {'d', 'b', 'c'};

auto iter (begin(vec)), e (end(vec));
typed_iterator <int, decltype(begin(vec)), std::input_iterator_tag> i (iter);
typed_iterator <int, decltype(begin(vec)), std::input_iterator_tag> ii (e);

  while (i != ii){
  std::cout << *i++ << ":";
  }

auto t (
  make_typed_iterator<int>(iter) );

return 0;
}
