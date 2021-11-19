#include<iostream>
using namespace std;
#define MAX 5

class CQ{
	public:
		CQ(void){
			head = -1;
			tail = -1;
			eleCount = 0;
		}
		
		// Enqueue
		void Enqueue(int data){
			
			// if not full
		    head = 
		}
		
		void Dequeue(void){
			// is not empty
			tail++;
			if(rear == MAX) tail = 0;
			arr[tail] = -1;
		}
	private:
		int arr[MAX] , head , tail , eleCount;
};

// Driver Code
int main(){
	
}