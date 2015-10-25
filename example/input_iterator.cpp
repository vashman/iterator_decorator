#include <iostream>
#include <iterator>
#include "../include/callback_iterator.hpp"

using iterator_decorator::bind_callback;
using iterator_decorator::iter_ops;
using std::istream_iterator;
using std::cin;

void
func(
  istream_iterator<char> &
, iter_ops::operation_type const &
);

int main(){
// Create iterator
auto iter (
  bind_callback(
    istream_iterator<char>(cin)
  , func
  )
);

char temp = '\n';
temp = *iter;

std::cout
<< "Value was: "
<< temp
<< " ."
<< std::endl;

return 0;
}

/**/
void
func(
  istream_iterator<char> &
, iter_ops::operation_type const &
){
std::cout << "f-called." << std::endl;
}
