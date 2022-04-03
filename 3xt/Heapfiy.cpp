#include<iostream>

#include<utility>
using namespace std;
class heapify
{
		void swap(int& a, int &b)
		{
			int temp;
			temp=a;
			a=b;
			b=a;
		}
	public:
	
		void heap( int n, int a[], int largest )
	  {
	  	int i=largest;
	  	int left, right;
	  	if( n>= right&&a[largest]>a[right])
	  	{
	  		largest=right;
		  }
		if( n>= left&&a[largest]>a[left])
	  	{
	  		largest=left;
		  }
		  if( i!=largest )
		  {
		  	swap ( a[largest], a[i]);
		  	heap(n ,a,largest);
		  }
		    
	  }
		
};
int main()
{
	heapify e;
	int a;
	
	cout<<"HOW MUCH DATA DO YOU WANT TO ENTER "<<endl;
	cin>>a;
	a--;
	int b[a];
	for( int i=0; i<a; i++)
	{
		cout<<"ENTER INDEX VALUE OF"<<i<<endl;
		cin>>b[i];
	}
	int largest;
	largest=(a/2)-1;
	for( int i=largest; i>=0; i--)
	{
	
	e.heap(a,b,largest );

}
for( int i=0; i<=a; i++)
{
	cout<<"dsd"<<b[i];
}
}