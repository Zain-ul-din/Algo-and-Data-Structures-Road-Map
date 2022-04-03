#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r,int size)
{
	int i=l; ///l is left
	int j=m+1;
	int k=l; ///l is left
	int temp[size];
	
	while(i<=m && j<=r)
	{
		if (arr[i]<=arr[j])
		{
			temp[k]=arr[i];
			i++;k++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
			k++;
		}
	}
	while(i<=m)
	{
	    temp[k]=arr[i];
			i++;
			k++;
	}
	while(j<=r)
	{
		temp[k]=arr[i];
			j++;
			k++;
	}
	
	for (int p=l;p<=r;p++)
	{
		
		arr[p]=temp[p];
	}
}


void mergeSort(int arr[],int l,int r,int size)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergeSort(arr,l,m,size);
		mergeSort(arr,m+1,r,size);
		
		merge(arr,l,m,r,size);
		
	}
	
}

int main()
{
	int size;
	cout<<"Enter Size of Array: "<<endl;
	cin>>size;
	int arr[size];
	
	cout<<"Enter "<<size<<" integers in any order: "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	cout<<"\nBEFORE SORTING..."<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
	
	mergeSort(arr,0,(size-1),size);///(arr,left,right)
	
	cout<<"\nAfter Sorting..."<<endl;
	for(int i=0;i<size;i++)
	{
     	cout<<arr[i]<<"  ";
	}
	cout<<endl;
}
