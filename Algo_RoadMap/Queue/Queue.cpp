#include<iostream>
using namespace std;
#define ARRAYSIZE 5

template<typename T>
class Queue{
	public:
		Queue(void){
			size = -1;
		}
		
		void Enqueue(T data){
			if(size < ARRAYSIZE){
			  size++;
			  arr[size] = data;	
			}
		}
		
		void Dequeue(void){
			if(IsEmpty()){
				size --;
				
			}
		}
		
		
		inline bool IsEmpty(void){
		  return size == -1;	
		}
		
	private:
		T arr[ARRAYSIZE];
		int size;
};
// Driver Code
int main(){
	
}