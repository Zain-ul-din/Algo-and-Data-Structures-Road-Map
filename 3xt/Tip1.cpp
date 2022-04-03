// #1 To to Get Valid Input (istream) / Basic IO

// Difficulty : Intermediate

#include<iostream>
#include<string>


void GetInput_Int(int& val){
	std::cout << "Enter Int Value : ";
	std::cin >> val;
	
	bool isFail = std::cin.fail();
	
	if(isFail)
	   std::cout << "\nInput Buffer is Not Int !\n";
	else return;  
	
	// clears prev cin buffer
	std::cin.clear();
	std::cin.sync();
	
	GetInput_Int(val);   
}

int main (){
	int num;
	GetInput_Int(num);
	std::cout << "Num is : "<<num <<std::endl;
	return 0;
}
/*
OUTPUT:

Enter Int Value : name

Input Buffer is Not Int !
Enter Int Value : hello

Input Buffer is Not Int !
Enter Int Value : 90
Num is : 90

*/