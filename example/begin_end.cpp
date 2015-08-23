#include <vector>
#include <iostream>
#include "../include/iterator.hpp"

using std::vector;
using std::cin;
using iterator_decorator::begin;
using iterator_decorator::end;
using iterator_decorator::cbegin;
using iterator_decorator::cend;

int main(){
vector<char> vec;

auto iter (begin<char>(vec));
auto eiter (end<char>(vec));

auto citer (cbegin<char>(vec));
auto ceiter (cend<char>(vec));

auto oiter (begin<int>(cin));
auto eoiter (end<int>(cin));
return 0;
}
