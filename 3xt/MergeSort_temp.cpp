
#include<iostream>
using namespace std;

void m1(int arr[],int l,int r,int mid);

void mgs(int arr[],int l,int r)
{
    int mid=(l+r)/2;
    mgs( arr,l,mid);
    mgs(arr,mid+1,r);
    m1(arr,l,r,mid);
}//we know that we have different array now time to merge it in a single

void m1(int arr[],int l,int r,int mid)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];//temporary array
    for(int i=0;i<n1;i++)
    {
        a[i]=a[l+i];

    }
    for(int i=0;i<n2;i++)
    {
        a[i]=a[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l;
    while(i<n1&&j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=arr[i];
            k++;
            i++;

        }
        else
        {
            arr[k]==a[j];
            k++;
            j++;
        }

        while(i<n1)
        {
            arr[k]=a[i];
            k++;
            j++;

        }
        while(j<n2)
        {
            arr[k]=b[j];
            k++;
            j++;

        }

    }

}
int main()
{
    int arr[]={2,3,5,6,7};
    mgs(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<""<<endl;

    }
    cout<<endl;
}