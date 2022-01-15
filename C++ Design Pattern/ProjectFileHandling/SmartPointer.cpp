//
// Created by 97152 on 03/01/2022.
//


#include<iostream>
#include <vector>
#include <memory>
#include <string>
#include <chrono>
#include <queue>
#include <sstream>
#include <future>
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <namespaceapi.h>
#include <wincon.h>
#include <fstream>
#include <map>
#include <unordered_map>
#include <stack>
#include <cctype>
#include <namespaceapi.h>
#include <numeric>



#define DECLARE_CLASS(TClass , )

using namespace std;
using namespace chrono;

// Getter
template<typename T> class Getter{
public:
   T &GetVal(void){
       return val;
   }
private:
    T val;
};

// Setter
template<typename  T> class Setter{
    T* GetVal() {
        return &val;
    }
private:
    T val;
};

class Name{
public:

    Getter<int> rollNo;
    Getter<string> name;
};


string* AllocateMem(){
    return new string[5];
}

class Actor{
public:
    virtual void Tick() = 0;
};

class AMyClass : public Actor{
public:
    void Tick() override {

    }
};

// Driver Code
int main() {
   int number = 2;
   cin >> number;
   cout<<"Std : Number : "<<number<<std::endl;
//    // Dynamic Memory Allocation in Functions
//    string* ss = nullptr;
//    ss = AllocateMem();
   // ss[0] = "20";

//   auto startTime = high_resolution_clock::now();
//
//   for(int i=0;i<1000;i++) cout<<"Hello world"; // Code Here
//
//    cout<<"Hello";
//    string* ss = new string;
//    *ss = "Hello world!";
//    delete ss; // Must Delete req
//
//    // using smart pointer
////    unique_ptr
//    unique_ptr<string> str(new string("Hello world"));
//    *str = "Hello world";
//     // automatically delete done here
//
//     shared_ptr<string> str_Ptr;
//
//     try{
//         throw 2;
//     }catch (exception exe){
//         // Do Some thing
//         exe.what();
//     }
//
//
//    auto endTime = high_resolution_clock::now();
//    auto timeTake = duration_cast<milliseconds>(endTime - startTime);
//
//   cout<<"\n"<<timeTake.count()<<" _ ms";
//
//   // hello world
//   int * ptr;
//   ptr = new int[10];
//   ptr[0] = 2;
//   ptr[1] = 3;

/*
 * Dynamic Memory Allocation using Function
  int Val(int **ptr){
  ptr = new int[10];

}

int main() {
   int* val;
   Val(&val);
  return 0;
}
 */
}
