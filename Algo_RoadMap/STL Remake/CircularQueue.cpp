#include<iostream>
using namespace std;
#define _MAXSIZE 5

/*
  FIFO Data Type (Circular Queue)
*/
template<typename T>
class CircularQueue{
	public:
		CircularQueue(T garbgeVal){
			front =-1;
			rear = 0;
			eleCount = 0;
			this->garbgeVal = garbgeVal;
		}
		
		void Enqueue(T data){
			
			if(IsFull()){
			 cout<<"INSERATION FAIL _ QUEUE IS ALEADY FILL / STATUS : FAIL"<<endl;
			 return;
			}// Queue is already Full
			
			// filter data before
			
			for(int i=0;i<_MAXSIZE;i++){
				if(arr[i] == grabgeVal){
					front = i;
				}
			}
			
			arr[front] = data;
			eleCount +=1;
			Debug();
		}
		
		void Dequeue(void){
			if(IsEmpty()) {
				cout<<"ARRAY IS ALREADY EMPTY / STATUS : FAIL"<<endl;
				return;
			}
			
			// delete element
			for(int i=0;i<_MAXSIZE;i++){
				if(arr[i] != garbgeVal){
					cout<<"ELEMENT ' "<< arr[i] << " ' "<<"HAS BEEN DELETED / STATUS : SUCESS"<<endl;
					arr[i] = garbgeVal;
					eleCount--;
					rear = i+1;
					return;
				}
			}
		}
		
		bool IsFull(void){ return eleCount == _MAXSIZE;}
		bool IsEmpty(void){return eleCount == 0;}
		
		
		
		void Diplay(void){
			if(IsEmpty()) return;
			
			for(int i=rear;i<_MAXSIZE;i++)
			   cout<<" "<<arr[i]<<" ";
			cout<<endl;
		}
	private:
		// Var
		int front,rear,eleCount;
		T arr[_MAXSIZE],garbgeVal;
		const int MAXSIZE = _MAXSIZE-1;
		
		
		void Debug(void){
			for(int i=0;i<_MAXSIZE;i++)
			  cout<<" "<<arr[i]<<" ";
			cout<<endl;
		}
		
};



// Driver Code
int main(){
   CircularQueue<int> c_queue(-1);
   c_queue.Enqueue(3);
   c_queue.Enqueue(1);
   c_queue.Enqueue(9);
   c_queue.Enqueue(5);
   c_queue.Dequeue();
   c_queue.Enqueue(7);
   c_queue.Dequeue();
   string name = "Any name";
   
   long long myContactNumber = 89482374823;
   c_queue.Dequeue();
   c_queue.Dequeue();
   c_queue.Dequeue();
   c_queue.Dequeue();
   c_queue.Diplay();
}