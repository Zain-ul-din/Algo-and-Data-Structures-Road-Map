// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

int main () {
  int myints[] = {-1,10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end());
  std::cout << "initial max heap   : " << v.front() << '\n';
   
   while(!v.empty()){
     std::pop_heap (v.begin(),v.end());
     v.pop_back();
     std::cout << "max heap after pop : " << v.front() << '\n';
   }
   	

  
 

  std::cout << '\n';

  return 0;
}