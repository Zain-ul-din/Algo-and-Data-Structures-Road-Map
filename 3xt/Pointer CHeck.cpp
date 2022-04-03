#include<iostream>
using namespace std;
void exchange(int&,int&);

void Swap(int& a, int& b ){
	a = a^b;
	b = a^b;
	a = a^b;
}

int main()
{
	int x;
	int y;
	cout << "Enter your 1 number" << endl;
	cin >> x;
	cout << "Enter your 2 number" << endl;
	cin >> y;
	
	
	int a =10;
	int b = 20;
	Swap(a,b);
	
	cout << a << b;
	exchange(x, y);
	cout << "The Multiplied value for above inserted values is "<<x<<"  "<<y<<endl;
	
return 0;
}
void exchange(int &a, int &b)
{
	int z;
	z=a;
	a=b;
	b=z;

}


