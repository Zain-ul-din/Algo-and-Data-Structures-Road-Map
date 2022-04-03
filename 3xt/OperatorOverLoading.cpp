#include<iostream>
class Float{
	public:
		float number;
		
	operator float (){
		return number;
	}	
	
	operator Float () {
		return *this;
	}
	
	void operator = (float number){
		this->number = number;
	}
	
	
};

int main (){
	
	Float f;
	float ff = static_cast<float>(f);
	f = static_cast<float>(3.2);
	std::cout << f.number;
}