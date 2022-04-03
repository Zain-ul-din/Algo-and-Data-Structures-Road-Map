#include<iostream>

using namespace std;

int main () {
	const int outerIdx = 30;
	
	int leftIdx  ;
	int rightIdx ;
	
   for(int  i= 0 ;i < outerIdx; i++)
         cout << (i > outerIdx /2 ? "*" : " ");
      
	cout << "\n";
	
	leftIdx = outerIdx / 2;
	rightIdx = outerIdx -1;
	
	for(int i = 0 ;i < outerIdx/3; i++){
	   for(int j = 0 ; j < outerIdx ; j++)
		   cout << (j == leftIdx || j == rightIdx? "*" : " ");
		cout << "\n";
		leftIdx --;
		rightIdx --;   
	}
	
	for(int i= 0 ; i < rightIdx+1 ; i++)
	    cout << (i > leftIdx ? "*" : " ");    	     
}