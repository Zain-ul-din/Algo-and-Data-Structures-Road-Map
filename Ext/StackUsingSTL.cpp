#include<iostream>
//#include<stack> // using Stack

#include "./MyUtilities.h"
using namespace std;
using namespace MyUtilities;


// Stack itr
// O(n)
template<typename T>
void ItrOverStack(Stack<T> stackVal){
//	if(stackVal.IsEmpty()) return;
	while(!stackVal.IsEmpty()){
		cout<<stackVal.Top() <<" , ";
		stackVal.Pop();
	}
	cout<<endl;
}
class FileSystemTest{
	public:
		int a = 10;
		int b  = 20;
};
// Diver Code
int main(){
	SaveSystem saveSystem("BinaryFileTest");
	saveSystem.Save(saveSystem);
	/*
	 Stack<int> stackVar;
	 stackVar.Push(10);
	 stackVar.Push(20);
     stackVar.Push(30);
     stackVar.Push(40);
     ItrOverStack(stackVar);
     */
}