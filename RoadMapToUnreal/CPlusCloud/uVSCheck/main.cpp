#include<iostream>

class A {
	protected:
		int number;

	void GetNumber (){
		std::cout << "Hey";
	}

	void Print(){
		std::cout << number;
	}

	friend class B;
};

class B : public A{
	public:

	void GetNumber (){
        a.GetNumber();
	}
    A a;

};

int main () {
	B b;
}