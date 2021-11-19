#include<iostream>
#include<queue>// using STD Queue
using namespace std;



// Driver Code
int main(){
	priority_queue<int> pQueue;
	pQueue.push(3);
	pQueue.push(1);
	pQueue.push(9);
	pQueue.push(5);
	pQueue.push(7);
	
	while(!pQueue.empty()){
		cout<< " "<<pQueue.top() << " ";
		pQueue.pop();
	}
	
	return 0;
}