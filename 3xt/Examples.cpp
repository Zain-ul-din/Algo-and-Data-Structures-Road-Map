// get_money manipulator example
#include <iostream>     // std::cin, std::cout
#include <iomanip>      // std::get_money
#include<fstream>
#include<utility>

int main ()
{
	
  std::ofstream outfile ("test.txt");

  for (int n=0; n<100; n++)
    outfile << n << std::ends;

  outfile.close();
  int val;
   
	
	// Get Price
  long double price;
  std::cout << "Please, enter the price: ";
  std::cin >> std::get_money(price);

  if (std::cin.fail()) std::cout << "Error reading price\n";
  else std::cout << "The price entered is: " << price << '\n';
   
  // put money
  std::cout << "Price:" << std::put_money(10.50L) << '\n';
  
  
  struct std::tm when;
  std::cout << "Please, enter the time: ";
  std::cin >> std::get_time(&when,"%R");   // extract time (24H format)

  if (std::cin.fail()) std::cout << "Error reading time\n";
  else {
    std::cout << "The time entered is: ";
    std::cout << when.tm_hour << " hours and " << when.tm_min << " minutes\n";
  }
  
//  std::setw(4);
//  std::cout <<"*";
  
  int n = 2;
  std::cout.width(10); std::cout << std::internal << n << '\n';
  std::cout.width(10); std::cout << std::left << n << '\n';
  std::cout.width(10); std::cout << std::right << n << '\n';
  return 0;

}