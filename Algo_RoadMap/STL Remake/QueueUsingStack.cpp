#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<typename T>
class Queue{
	public:
		Queue(void){
			
		}
		
		// Adding Element
		void Enqueue(T data){
			st1.push(data);
		}
		
		// Dequeue
		void Dequeue(void){
			if(st1.empty())return;
			cout<<"DEqueue"<<endl;
			while(!st1.empty()){
				st2.push(st1.top());
				st1.pop();
			}
			
			st2.pop();
			
			while(!st2.empty()){
				st1.push(st2.top());
				st2.pop();
			}
		}
        
		void Display(void){
			stack<T> temp;
			temp = st1;
			while(!temp.empty()){
				cout<< " "<<temp.top()<<" ";
				temp.pop();
			}
			cout<<endl;
		}
	private:
		stack<T> st1;
		stack<T> st2;
		
		void FreeStack(stack<T> &st){
			while(!st.empty()){
				st.pop();
			}
			return;
		}
};

// Driver Code
int main(){
	Queue<int> q;
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	q.Enqueue(6);
	q.Dequeue();
	q.Dequeue();
	q.Enqueue(7);
	q.Display();
	
}