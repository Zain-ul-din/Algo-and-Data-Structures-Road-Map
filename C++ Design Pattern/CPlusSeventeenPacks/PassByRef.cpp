#include<iostream>

using namespace std;

class Data{
public:
    Data* data;
    string name;
    Data(const string name) : name(name) {}
    Data(){
        data = new Data("Unkown");
    }

    Data* GetData(){return data;} //  Pass By ref like c Sharp
};

void FuncTest(Data* data){
    data->name = "Func name";
}

void CloneTest(Data* data){
    Data* funcData = data;
    funcData->name = "Clone Data";
}


template<class T> class Property{
public:
    T val;
    Property (){
        *this = val;
    }
    void operator = (T newVal){
        val = newVal;
        return;
    }
};


#include<sstream>
class FileData{
public:
    string name;
    int rollno;

    string ToString(){
        // name$rollno
        stringstream ss;
        ss <<name<<"$"<<rollno;
        return ss.str();
        // name 90
        // `
    }
};


int main(){
     Data data;


     Property<int> myProp;
     myProp = 2;
     cout<<myProp.val;
//    Data * ptr = data.GetData(); //  like c sharp
//    ptr->name = "My Name";
//    Data* ptr = data.data; // working
//    ptr->name = "My Name"; //  working
//    FuncTest(data.data); //  also work
    // lets make clone of Dynamic object

   // CloneTest(data.data);  // also works

   // cloning is problem which may done using copy constructor or deep cloning
     cout<< "Hello world in c++ ! "<<std::endl;cout<<"\n";// nice end line
     cout<<  data.data->name;cout<<"\n";// nice end line


     cout<<"\n";// nice end line
}