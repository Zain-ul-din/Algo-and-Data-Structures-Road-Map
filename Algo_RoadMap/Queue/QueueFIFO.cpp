#include<iostream>
#include<queue>

using namespace std;
#define MAXQUEUESIZE 5
// Queue FIFO(first in first out)
template<typename T>
class Queue{
	public:
	// constructor
	Queue(){
		size = -1;
	}
	
	// Adding element to Queue
	void Enqueue(T data){
		if(size >= MAXQUEUESIZE-1){
			cout<<"OutOfIndex"<<endl;
			return;
		}
		
		size++;
		arr[size] = data;
	}
	
	// removing element from Queue
	void Dequeue(void){
		if(IsEmpty()){
			
			return;
		}
		// deleting element from the top
		for(int i=0;i<=size;i++)
			arr[i] = arr[i+1];
		
		size--;
	}
	
	// return queue is empty
	bool IsEmpty(void){
		return size == -1;
	}
	
	// return queue is full
	bool IsFill(void){
		return size >= MAXQUEUESIZE;
	}
	
	// return queue have element n
	bool Contains(T data){
		if(IsEmpty()) return false;
		for(int i=0;i<=size;i++)
		   if(arr[i] == data)
		    return true;
		return false;
	}
	
	// top element of queue
	T Peek(void){
		if(IsEmpty())
			return arr[MAXQUEUESIZE];
		return arr[0];
	}
	
	// I/O
	template<class F>
	friend ostream& operator << (ostream& out,Queue<F> &queue);
	
	// Display
	void Diplay(){ cout<<this;}
	
	// Count
	int Count(void){
		return size+1;
	}
	private:
		T arr[MAXQUEUESIZE];
		int size;
};


// Driver Code
int main(){
	queue<int> stdQueue;
	Queue<int> myQueue;
	
	stdQueue.push(3);
	stdQueue.push(1);
	stdQueue.push(9);
	stdQueue.push(5);
	stdQueue.push(7);
	
	myQueue.Enqueue(3);
	myQueue.Enqueue(1);
	myQueue.Enqueue(9);
	myQueue.Enqueue(5);
	myQueue.Enqueue(7);
	myQueue.Enqueue(0);
	
	myQueue.Dequeue();
	
	cout<<"My queue Size : "<<myQueue.Count()<<endl;
	
	cout<<"std Queue  - "<<endl;
	for(int i=0;i<5;i++){
		cout<< " "<<stdQueue.front()<<" ";
		stdQueue.pop();
	}
	
	cout<<endl;
	
	const int myQueueSize = myQueue.Count();
	
	if(myQueue.Contains(1)) cout<<"Queue have 1"<<endl;
	
	cout<<"My Queue  - "<<endl;
	for(int i=0;i<myQueueSize;i++){
		cout<< " "<<myQueue.Peek()<< " ";
		myQueue.Dequeue();
	}
	
	
}

template<class F>
ostream& operator << (ostream& out,Queue<F> &queue){
	if(queue.IsEmpty()) return out;
	for(int i=0;i<queue.Count();i++){
		out<< " "<<queue.arr[i] << " ";
	}
	out<<endl;
	return out;
}