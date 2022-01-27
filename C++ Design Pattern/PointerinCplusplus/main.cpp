// Simple Pointers
// Pointer to Pointer
// references
// Pointer using Array
// pointer as params
// void Pointer
// pointer to functions

// pointer using Func
// Dynamic Memory Allocation
#include<concurrent_priority_queue.h>
// for each Collider in wheel
// wheels.

#include <iostream>
#include <string>

using namespace std;
#define Debug(x) cout<<#x;

// Pointer As Pram
void Swap(int* val1,int* val2){
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return;
}

// void Pointers | pass any type and then try to cast Like Templates
void VoidPtr(void* data){
    int* val = (int*)data; // pointer cast
    int* valStatic = static_cast<int*>(data);// also work
    cout<<*val<<endl;
    cout<<*valStatic<<endl;
}

// New operator overloading
void* operator new (size_t size){
    return malloc(size);
}

void operator delete(void* val){
    free(val);
}

// Pointer to functions ,Like call Back's
int Sum(int val1,int val2){
    return val1 + val2;
}

int sub(int val1,int val2){
    return val1 - val2;
}

int DoOperation(int val1,int val2,int(*callBack)(int,int)){ // pass func signature
    return callBack(val1,val2);
}

void Increment(int* num){
    num++;
    return;
}

void IncPtr(int val,void(*callback)(int*)){
    callback(&val);
}


// Dynamic Alloc using class
class Data{
public:
    string name;
    Data(string ss){
        this->name = ss;
    }
    Data(){
        data = new Data("UNKNOWN");
    }
    Data* GetDataByRef(){
        return data; // return by ref
    }
    Data* data;
};
int main() {
   // Simple Pointer Address-of operator (&)
   int var = 10;
   int* ptrToVar = &var; // stores address of 'var'
    Debug(var) cout<<" _ Val using Ptr : "<<*ptrToVar<<endl; // 10 [Dereference operator (*)]
    cout<<"Address : "<<ptrToVar<<endl; // 00AFFC1C
    cout<<"Address of var : "<<&var<<endl;
    cout<<"Address of ptr it Self : "<<&ptrToVar<<endl; //00BFFA84
    cout<<"size of Ptr : "<<sizeof(ptrToVar)<<endl; //  4 Byte
    // change in ptr will reflect in val also && also change val by ref
    cout<<"var : "<<var<<endl;
    *ptrToVar = 30;
    cout<<"!! Var val change using ptr : "<<var<<endl;

    // const pointer
    const int* PTR = &var;
   // *PTR = 10; //Read-only variable is not assignable

    // Pointer to Pointer
    cout<<endl;
    int** ptrToPTRVAL = &ptrToVar;
    Debug(**ptrToPTRVAL)cout<<"  _ Value from ptrToVar: "<<**ptrToPTRVAL<<endl;
    cout<<"ptrToPTRVAL : "<<ptrToPTRVAL<<endl;
    cout<<"Address of ptrToVar wrt ptrToPTRVAL : "<<*ptrToPTRVAL<<endl;// address of ptr
    cout<<"Address to itr self : "<<&ptrToPTRVAL<<endl;//010FFD50
    // change in **ptrToVARPTR also reflect in var
    cout<<"var : "<<var<<endl;
    *ptrToVar = 40;
    cout<<"!! ptr to ptr ** Var val change using ptr : "<<var<<endl;
    // ** = val
    // * = val address
    // var = ptr address
    // val <- ptr* <- ptr**

    // Pointer using array
    cout<<"Pointer using Array : - "<<endl;
    int arr[5] = {3,1,9,5,7};
    int* ptrToArr = arr; // or = &arr[0]
    for(int* i = arr; i != &arr[5] ;i++)
        cout<<" "<<*i<<" ";
    cout<<endl;

    // Pointer as params
    Swap(&arr[0] , &arr[1]);
    cout<<"After Swapping : "<<endl;
    for(int* i = arr; i != arr+5 ;i++)
        cout<<" "<<*i<<" ";
   cout<<endl;

    // void Pointer
    /* The void type of pointer is a special type of pointer. In C++
     * void represents the absence of type. Therefore, void pointers are pointers that point to a value that has no type
     This gives void pointers a great flexibility, by being able to point to any data type,
     from an integer value or a float to a string of characters.
     In exchange, they have a great limitation:
     the data pointed to by them cannot be directly dereferenced (which is logical, since we have no type to dereference to),
     and for that reason, any address in a void pointer needs to be
     transformed into some other pointer type that points to a concrete data type before being dereferenced.
     */
    VoidPtr(&var); // FAV

    // Pointer to functions
    int val1(10) , val2(20);
    int (*plus)(int,int) = Sum; // return type (*name)(params) = func Name;

    int res(DoOperation(val1,val2,plus));
    cout<<res<<endl;
    /*
     * plus is a pointer to a function that has two parameters of type int. It is directly initialized to point to the function subtraction:
       int (* Sum)(int,int) = AddNumber;
     */
    int num(1);
    void (*increment)(int*) = Increment;
    IncPtr(num , increment);

    // ======== Dynamic Memory Allocation =========

    cout<<endl;
    int* dVal = new int(1);
    int * dVal2 = dVal;
    *dVal2 = 2; // Dynamic allocated object is always pass by ref if we make changes in dVal2 dval is also get reflected
    cout<<*dVal<<endl;

    // Clone of D object
    int clone_dVal  = *dVal; // Pass by val

    delete dVal; // must delete when you're done

    // STL n't work like std type
    // assigment can't reflects
    // Inner Element will change only

    Data data;
    data.GetDataByRef()->name = "myName";
    cout<<data.data->name<<endl;
    Data* refOfData = data.data;
    refOfData->name= "REf name";

//    delete refOfData; // error reflect also

    if(data.data == nullptr){
        cout<<"Null"<<endl;
        return 0;
    }

    cout<<data.data->name<<endl;
}


/*
#include<iostream>

class Node{
  public:
    int data;
    Node* left , *right;
};

void PassByRef(Node** node){
  Node* temp = *node;
  delete temp;
  *node = nullptr;
}  

void PassByPointer(Node** node){
  std::cout << "Adress of Ptr : " << (**node).data <<std::endl;
}

int main (){
   Node* node = new Node{3 , nullptr , nullptr}; 
   std::cout << "Adress in Heap : " << &(*node) <<std::endl;
   PassByRef(&node);
   
}
 // https://pythontutor.com/cpp.html#mode=edit
*/
