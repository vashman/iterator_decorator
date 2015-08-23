#include <vector>
#include <iostream>
#include "../include/iterator.hpp"

using std::vector;
using std::cout;
using std::ostream_iterator;
using iterator_decorator::inserter;

int main (){
vector<char> vec;
auto iter (
  inserter<int>(vec, vec.begin())
);

auto oiter (
  inserter<bool>(
    cout
  , ostream_iterator<bool>(cout)
  )
);
return 0;
}
