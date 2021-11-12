#include<iostream>
using namespace std;

template<typename T>
class Queue{
	public:
		// Constructor
		Queue(void){
			size = -1;
		}
		
		void Enqueue(T element){
			// if array already fill
			if(size >= maxSize){
				cout<<"Queue Has been Filled!"<<endl;
				return;
			}
			// if user adding 1st element
			if(size == -1){
				size++;
				arr[0] = element;
				PrintArr();
				return;
			}
			// Handling others 
			for(int i=size+1;i>0;i--){
				if(!i-1 < 0) arr[i] = arr[i-1];
			}
			arr[0] = element;
			size++;
			PrintArr();
			return;
		}
		
		void Dequeue(void){
			if(size == -1){
				cout<<"Queue is Empty"<<endl;
				return;
			}
			
			if(size == 0){
				size = -1;
				PrintArr();
				return;
			}
			
			// Handling Others
			for(int i=0;i<size;i++)
			    Swap(arr[i],arr[i+1]);
			size--;
			PrintArr();
			return;
		}
		
		bool IsEmpty(void){
			return size == -1;
		}
		
		T Peek(void){
			return arr[0];
		}
	private:
		T arr[5];
		int const maxSize = 5;
		int size;
		
		void Swap(T& val1,T& val2){
			T temp = val1;
			val1 = val2;
			val2 = temp;
		}
		
		void PrintArr(void){
			for(int i=0;i<maxSize;i++){
				cout<<" "<<arr[i]<<" ";
			}
			cout<<endl;
		}
};

int main(){
	Queue<int> queue;
	
	queue.Enqueue(3);
	queue.Enqueue(1);
	queue.Enqueue(9);
	queue.Enqueue(5);
	queue.Enqueue(7);
	
	for(int i=0;i<5;i++){
	  cout<<queue.Peek()<<endl;
	  queue.Dequeue();
	}
}