
#include "SaveSystem.h"

using namespace Randoms;


class Data : public SaveSystem{
public:
    Data(int id, const std::string &name) : id(id), name(name) {
        Save();
    }

    void Save(){
        this->ToString(id , name);
    }
private:
    int id;
    std::string name;
};

class Container : public IIterator{
public:

    void ForEach(std::function<void(SaveSystem &)> function) override {
           for(int  i =0 ; i <array.size() ;i++)
               function(static_cast<SaveSystem&>(array[i]));
    }

    std::vector<Data> array;
};

class Car{
public:
    Car() {}

    Car(int id, const std::string name) : id(id), name(name) {}


    int id ;
    std::string name;
};

class Student{
    int rollNo;
public:
    void SetRollNo(int arollNo); // define
};


void Student::SetRollNo(int arollNo) {
    rollNo = arollNo;
}


int main(){
    Car obj;
    Car obj1(3 , "BMW");

    std::cout << " " << obj1.name << " ";

    Container container;
    container.array.push_back({2,"Name"});
    container.array.push_back({3,"Name2"});
    container.array.push_back({4,"Name4"});
    container.array.push_back({5,"Name3"});

    SaveData("FileName.text" , container);

}