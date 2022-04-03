#include<iostream>


template<class T>
class Ptr {
	public:
		Ptr (T* node){ 
		   this->node = node;	
		}
		
		DeletePtr () {
			delete node;
		}
		
		bool operator == (nullptr_t ptr){
			return node == ptr;
		}
		
	private:
		T* node;
};

int main () {
	
}