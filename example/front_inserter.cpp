#include <list>
#include <iostream>
#include "../include/iterator.hpp"

using std::cout;
using std::list;
using iterator_decorator::front_inserter;

int main (){
list<char> li;
auto iter (front_inserter<int>(li));

auto oiter (front_inserter<int>(cout));
return 0;
}
