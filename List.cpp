

    #include <iostream>
    #include <algorithm>
    #include <list>
     
    template <typename T>
    std::ostream & operator << (std::ostream & os, const std::list<T> & vec){
      std::for_each (vec.begin () , vec.end() , [&](const auto& val){
       std::cout << val << " ";
      });
      return os;
    }

    int main () {
      std::list <std::string> menu = {"Black Coffee", "Espresso", "Latte", "Cappucino"};
      std::cout << menu << "\n";
      return 0;
    }