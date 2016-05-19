#include <iostream>
#include <vector>
#include "../include/cast_iterator.hpp"

using std::begin;
using std::vector;
using std::end;
using iterator_decorator::cast_iterator;
using iterator_decorator::make_cast_iterator;

int main (){

vector<char> vec = {'d', 'b', 'c'};

auto iter (begin(vec)), e (end(vec));
cast_iterator <int, decltype(begin(vec)), std::input_iterator_tag> i (iter);
cast_iterator <int, decltype(begin(vec)), std::input_iterator_tag> ii (e);

  while (i != ii){
  std::cout << *i++ << ":";
  }

auto t (
  make_cast_iterator<int>(iter) );

return 0;
}
