#include<iostream>
#include<queue>
using namespace std;


int main(){
	queue<int> q;
	q.push(3);
	q.push(1);
	q.push(9);
	q.push(5);
	q.push(7);
	
	cout<<q.front()<<endl;
}