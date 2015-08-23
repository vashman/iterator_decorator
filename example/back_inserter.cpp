#include <vector>
#include <iostream>
#include "../include/iterator.hpp"

using std::cout;
using std::vector;
using iterator_decorator::back_inserter;

int main (){
vector<char> vec;
auto iter (back_inserter<int>(vec));

auto oiter (back_inserter<char>(cout));
return 0;
}
