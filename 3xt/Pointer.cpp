#include<iostream>
#include <fstream>

const char FILENAME[] = "BF.dat";

void Save(int &ss,size_t bytes){
	std::ofstream out;
	out.open(FILENAME, std::ios::out | std::ios::binary);
	out.write((char*)&ss , bytes);
	out.close();
}

int LoadData(){
	int ss;
	size_t bytes = sizeof(ss);
	std::ifstream in;
	in.open(FILENAME , std::ios::in);
	in.read(reinterpret_cast<char*>(&ss),bytes);
	std::cout << ss << "\n";
	return ss;
}

// so that's it

void CallBack(void(*callBack)(int,int)){
	int num1 = 2;
	int num2 = 4;
	callBack(num1, num2);
}

void Print(int num1,  int num2){
	std::cout << num1 << "- "<<num2 <<"\n";
}

int main () {
	int* num = new int(101);
//	Save(*num , sizeof(*num));
	std::cout << LoadData() <<" \n";
	
	// Func Def
	void (*MyFunc) (int,int) = Print;
	CallBack(MyFunc);
	
	
}