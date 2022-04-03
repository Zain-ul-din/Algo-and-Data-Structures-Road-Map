#include<iostream>

template<class... T>
void Print (T... params){
	([&](auto param){
		std::cout << param << " ";
	} (params),...);
}


void NewNumber () {
	// Add New Number
}

int main () {
	Print (3,4,5,6, " My Name");
}