#include <iostream>

#define Debug(value) std::cout << "\n" << #value << " : "<<value <<"\n"; 

int main (){
	int myVal = 2;
	Debug(myVal); // Debug Value using Debuger macro
}