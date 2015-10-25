// Shows differnt type of callbacks.

#include <iostream>
#include <forward_list>
#include "../include/callback_iterator.hpp"

using std::forward_list;
using iterator_decorator::bind_callback;
using iterator_decorator::iter_ops;

int main (){
forward_list<bool> list {false, true};

auto iter (
  bind_callback(
    list.begin()
  , [](
      forward_list<bool>::iterator & _i
    , iter_ops::operation_type
    ){
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
