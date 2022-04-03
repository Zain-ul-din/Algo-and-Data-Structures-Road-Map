#include<iostream>

bool IsPrime(int num){
	if(num <= 2) 
	    return true;
	    
	for(int i = 2 ; i < num ; i++)
	    if(num % i  == 0) return false;
	        
	return true;
}

int main () {
	std::cout << "List of Prime Number's from 1 to 100 :- \n";
	for(int i =1 ; i <= 100 ; i++)
	   if(IsPrime(i)) std::cout << " " << i << " ";
	std::cout << "\n";   
	return 0;   
}