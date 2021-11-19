#include<iostream>
using namespace std;
#define MAXSIZE 5

// Circular Queue using Real World 
class CircularQueue{
	public:
		CircularQueue(int GV){
			eleCount = 0;
			this->GV = GV;
			
			for(int i=0;i<MAXSIZE;i++)
			  arr[i] = GV;
		}
		
		void Enqueue(int data){
			if(IsFull() || data == GV) return;
			
			for(int i=0;i<MAXSIZE;i++)
				if(arr[i]==GV){
					arr[i] = data;
					eleCount++;
					return;
				}
		}
		
		void Dequeue(void){
			
			for(int i=0;i<indexOfLastElement();i++)
			   Swap(arr[i],arr[i+1]);
			arr[indexOfLastElement()] = GV;
			eleCount--;
			return;
		}
		
		bool IsFull(void){return eleCount == MAXSIZE;}
		bool IsEmpty(void){return eleCount == 0;}
		
		void Display(void){
			int index =0;
			
			while(arr[index] != GV && index < MAXSIZE){
				cout<<" "<<arr[index] <<" ";
				index++;
			}
			cout<<endl;
			return;
		}
	private:
		int eleCount,front,GV;
		int arr[MAXSIZE];
		
		int indexOfLastElement(void){
			for(int i=0;i<MAXSIZE;i++){
				if(arr[i] == GV) return i-1;
			}
			return MAXSIZE-1;
		}
		
		void Swap(int& val1,int& val2)
		{
			int temp = val1;
			val1 = val2;
			val2 = temp;
		}
		void Debug(void){
			for(int i=0;i<MAXSIZE;i++)
			   cout<<" "<<arr[i]<<" ";
			cout<<endl;
		}
};

int main(){
	CircularQueue cq(-1);
	cq.Enqueue(2);
	cq.Enqueue(7);
	cq.Enqueue(3);
	cq.Enqueue(9);
	cq.Enqueue(6);
	cq.Enqueue(6);
	cq.Dequeue();
	
	cq.Display();
	
}