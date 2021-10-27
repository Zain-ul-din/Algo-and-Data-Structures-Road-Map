#include<iostream>
using namespace std;

// Fill Array
template<typename T>
void FillArray(T arr[],int size,T val){
  if(size > 0)
	for(int i=0;i<size-1;++i)
	   arr[i] = val; 
}

// Delete Element From the Array
template<typename T>
void DeleteElement(T arr[],int &size,int index){
	if(!size > 0) return;
	if(arr[size-1] == arr[index]){
		size--;
		return;
	}
	
}

int main(){
	int arr[10];
	
	
	    
}