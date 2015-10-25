#include <iostream>
#include <iterator>
#include "../include/callback_iterator.hpp"

using iterator_decorator::bind_callback;
using iterator_decorator::iter_ops;
using std::ostream_iterator;
using std::cout;

void
func(
  ostream_iterator<int> &
, iter_ops::operation_type const &
);

void
func(
  ostream_iterator<int> &
, iter_ops::operation_type const &
){
std::cout << "\n" << std::endl;
}

int main(){
// Create the iterator
ostream_iterator<int> A(cout);

// Create a callback iterator
auto iter (bind_callback(A, func));

for(int i =0;i<15;++i){
*iter++ = i;
}

return 0;
}
