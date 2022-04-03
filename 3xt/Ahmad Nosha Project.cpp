#include<iostream>
using namespace std;
class sort
{
	void swap ( int a ,int b)
	{
		int temp;
		temp=a;
		a=b;
		b=temp;
	}
   public:
   	void partition( int  a[] , int lb , int up ){
   	     return ;	
	}
   	
  	  
};

int main()
{
	int a,b,c,d;
	sort e;
	cout<<"HOW MUCH DATA DO YOU WANT TO ENTER IN ARRAY"<<endl;
	cin>>a;
	int arr[a];
	for( int i=0; i<a; i++)
	{
		cout<<"ENTER THE VALUE AT INDEX "<<i<<endl; 
		cin>>arr[i];
	}
	
	int lb=0;
	int up=a;
	
	if( lb<up){
   	    int p;
	    e.partition(arr,lb,up);	
	}
	
}