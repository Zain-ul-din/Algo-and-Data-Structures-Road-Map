
#include<iostream>

template<class T>
class property
{
    T value_;
public:
	bool isPublic = true;
	
    property(){}
    property(T v) : value_(v){}
    property(property<T> const & other) : value_(other.value_){}

    property<T> & operator=(property<T> const& other){
    	
        value_ = other.value_;
        return *this;
    }
    

    operator T(){return value_;}
};

class MyClass {
	public:
		property<int> myInt;
};

int main () {
	MyClass myClass;
	myClass.myInt = 3;
	std::cout << " " << myClass.myInt << " ";
}