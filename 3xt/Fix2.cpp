#include<iostream>
using namespace std;

int multiplication(int, int);
int addition(int, int);

int main()
{
	int x , y , a  , b;

	cout << "Enter your 1 number" << endl;
	cin >> x;
	cout << "Enter your 2 number" << endl;
	cin >> y;

	cout << "The Multiplied value for above inserted values is ";
	cout << multiplication(x, y) << endl;


	cout << "Enter 1 digit" << endl;
	cin >> a;
	
	cout << "Enter 2 digit" << endl;
	cin >> b;
	
	cout << "The Added value for the above mentioned values is ";
	cout << addition(a, b);

    cout << "\n";
	system("pause");

	std::cout << "Get Number is c++\n";
	
	return 0;
}

int multiplication(int a, int b){
	return a*b;
}

int addition(int c, int d){
	return c+d;
}