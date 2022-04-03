#include<iostream>


// Driver Code
int main (){
	int maxIdx = 10;
	
	int leftIdx = -1;
	int rightIdx = -1;
	
	for(int i =0 ; i < maxIdx ; i++ ){
		
		if(leftIdx <= 0)
		   leftIdx = (maxIdx / 2) - 1;
		if(rightIdx >= maxIdx-1)
		   rightIdx = (maxIdx / 2) + 1; 
		       
	   for(int j = 0 ; j < maxIdx ; j++){
	     if(i  == 0){ //  1st Line
	     	if( j == maxIdx/2){
	     	  std::cout << "*"; 
			  leftIdx = (maxIdx / 2) - 1;
			  rightIdx = (maxIdx / 2) + 1; 	
			}else std::cout << " ";
		 }
		 else{
           if(j == leftIdx || j == rightIdx){
           	std::cout << "*";
		   }
		   else std::cout << " ";	
		 }
	   }
	   
	   leftIdx--;
	   rightIdx++;
	   std::cout << "\n";
	}
}