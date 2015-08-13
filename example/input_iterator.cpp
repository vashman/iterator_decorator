#include <iostream>
#include <algorithm>
#include <iterator>
#include "../include/callback_iterator.hpp"

using iter_decor::make_callback_iterator;
using std::istream_iterator;
using std::cin;

void
func(istream_iterator<char> const &);

int main(){
// Create iterator
auto iter (
  make_callback_iterator(
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
func(istream_iterator<char> const &){
}
