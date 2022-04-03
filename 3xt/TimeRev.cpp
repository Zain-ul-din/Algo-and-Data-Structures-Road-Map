
#include<iostream>
#include<ctime>

int main () {
	time_t timeNow;
	time(&timeNow);
	std::cout << " " << ctime(&timeNow) << " ";
	
	int a = 10;
	int *b = &a;
	*b = 2;
	std::cout << "\n" << a;
	return 0;
}