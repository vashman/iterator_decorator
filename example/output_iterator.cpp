#include <iostream>
#include <algorithm>
#include <iterator>
#include "../include/callback_iterator.hpp"

using iter_decor::make_callback_iterator;
using std::ostream_iterator;
using std::cout;

void
func(ostream_iterator<int> const &);

void
func(ostream_iterator<int> const &){
std::cout << "\n" << std::endl;
}

int main(){
// Create the iterator
ostream_iterator<int> A(cout);

// Create a callback iterator
auto iter (
  make_callback_iterator(A, func)
);

for(int i =0;i<15;++i){
*iter++ = i;
}

return 0;
}
