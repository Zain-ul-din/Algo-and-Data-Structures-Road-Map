#include<iostream>
#define n 5

static int N = 4;


void staticTest(int &number){
	number++;
	return ;
}
// Driver Code
int main () { 

   for (int  i = 0 ;i < n ;   ++i ){
   	
        for( int j = i ; j < n ; ++j )
           std :: cout << " " ;
           
        for( int j = -1; j < i ; ++j )
           std :: cout << "*" ;
           
        for( int j = 0 ; j < i ; ++j )
           std :: cout << "*" ;
           
        std::cout<< "\n";
   }     
   
    
    std::cout<<"\n";
    
    static int num =2;
    
    staticTest(num);
    
    std::cout<<num<<std::endl;
  // #error Pattern Maked
}