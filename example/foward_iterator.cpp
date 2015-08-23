// Shows differnt type of callbacks.

#include <iostream>
#include <forward_list>
#include "../include/callback_iterator.hpp"

using std::forward_list;
using iter_decor::make_callback_iterator;

int main (){
forward_list<bool> list {false, true};

auto iter (
  make_callback_iterator(
    list.begin()
  , [](forward_list<bool>::iterator i){
    std::cout << "f-called."
    << std::endl; 
    }
  )
);

for (int i=0; i<2 ; ++i){
bool v = *iter;
++iter;
std::cout << v << std::endl;
}

return 0;
}
