#include<iostream>
#include<string>


std::string cell_Number(std::string &number){
	string ss = "...-........";
	for(int i=0 ; i < number.length() ; i++)
	    if(ss[i] == '.')
	        ss[i] = number[i];
	return ss;        
}

int main (){
	
}