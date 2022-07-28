#include <iostream>
#include <conio.h>
#include <fstream>

// driver code
int main () {
	system ("del todo.txt");
	system ("echo > todo.txt start it");
	std::cout << "Starting...\n";
	int _ = 0;
	const int MAX = 50;
	for (int i = 0 ; i < MAX ; i += 1) {
	  std::string str = "qwertyuiopasdfghjklzxcvbnm";
      std::ofstream out;
	  out.open("todo.txt" , std::ios::app);
	  _+=1;
	  if (_>MAX/2) _ = 0;
	  for (; _< i ; _++) out << " ";
	  std::string $ = "git commit -m " ;
	  $ += " \"Commit ";  
	  for (int idx = 0 ; idx <= i ; idx += 1) {
	  	out << str [rand() % str.length()];
	  	if (idx < 10) $+= str [rand() % str.length()];
	  }
	  out << " \n";
	  $+= "\"";
	  out.close();
	  system ("git status");
	  system ("git add .");
	  system  ($.c_str());
	  system ("git push -u origin master");
    } 
    system ("start .");
    return 0;
}