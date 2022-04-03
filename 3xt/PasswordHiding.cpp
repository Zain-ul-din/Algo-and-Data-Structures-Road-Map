// Password Cover

#include <iostream>
#include <vector>
#include <string>
#include  <stdio.h>
#include  <conio.h>

#define Debug(Function) std::cout << #Function <<std::endl;
#define AutoString(Name) std::string Name = #Name;

std::string GetPassword(const int maxLen , const char mask){
	int currentLen = 0;
	std::vector<char> passwordList;
	
	while(currentLen < maxLen){
		char c = getch();
		passwordList.push_back(c);
		currentLen = passwordList.size();
		std::cout << mask;
	}
	std::cout<<std::endl;	
	std::string password = "";
	for (auto itr = passwordList.begin() ; itr != passwordList.end() ; itr++)
	     password += *itr;
	
	return password;     
}

int main (){
   std::cout << std::stoi(GetPassword(4 , '*')) +1 << std::endl;
   system("pause");
   
   Debug(Zain ul din);
   AutoString(Name);
   std::cout << Name << "\n";
   return 0;
}