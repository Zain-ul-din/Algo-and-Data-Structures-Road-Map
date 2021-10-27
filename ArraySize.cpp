#include<bits/stdc++.h>
using namespace std;

void SizeOfArray(int arr[]){
	auto size = sizeof(arr)/sizeof(arr[0]);
	cout<<size;
}
int main(){
	int arr[] = {1,2,3,4,5,6,5};
	SizeOfArray(arr);
}