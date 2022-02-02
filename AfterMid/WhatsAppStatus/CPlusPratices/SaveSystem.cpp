#include <iostream>
#include <sstream>
#include <vector>
//#include <typeinfo>
#include <fstream>
#include <ctime>
#include <utility>
// utility

// All about TypeInfo Library

template<class T>
class ISaveAble{
public:
    virtual std::string ToString() = 0;
    virtual T StringToObj(std::string& string) = 0;

    friend std::ostream & operator << (std::ostream& out , ISaveAble<T>& data){
        out << "Base Class !" << std::endl;
        return out;
    }
};

class Data : public ISaveAble<Data>{
public:

     Data(){
         userName = "Not Set !";
         password = INFINITY;
     }


    Data(const std::string &userName, int password) : userName(userName), password(password) {}

    const std::string &getUserName() const {
        return userName;
    }

    void setUserName(const std::string &userName) {
        Data::userName = userName;
    }

    int getPassword() const {
        return password;
    }

    void setPassword(int password) {
        Data::password = password;
    }

    std::string ToString() override {
        std::stringstream ss;
        ss << userName << "-" << password;
        return ss.str();
    }

    Data StringToObj(std::string &string) override {
        std::vector<std::string > vector (Split(string , '-'));
        Data data;

        if(vector.empty())
            return data;

        data.userName = vector.at(0);
        data.password = std::stoi(vector[1]);

        return data;
    }

    friend std::ostream &operator<<(std::ostream &os, const Data &data) {
//        os << static_cast<const ISaveAble<Data> &>(data) << " userName: " << data.userName << " password: "
//           << data.password;
        return os;
    }

private:

    std::string userName;
    int password;

    static std::vector<std::string> Split(std::string string , const char seprator ){
        std::vector<std::string> vector;
        std::string temp = "";
        for(int i= 0 ; i < string.length() ; ++i)
            if(string[i] == seprator){
                if(!temp.empty()) vector.push_back(temp);
                temp = "";
            }
            else temp.push_back(string[i]);

        if(!temp.empty())
            vector.push_back(temp);

        return vector;
    }
};


template<class T>
class IIterateAble{
public:
    virtual void ForEach(void(*CallBack)(ISaveAble<T> &saveAble ,bool &StopItr) ) = 0;
};


template<class T>
class Array : public IIterateAble<T>{
public:

    void ForEach(void (*CallBack)(ISaveAble<T> & ,bool &)) override {
         bool stopItr = false;
         for(int i(0) ; i < len ;i ++ ){
             if(stopItr)
                 break;
             CallBack(arr[i], stopItr);
         }
    }

public:
    T arr[10]; int len =10;
};

void CallBack(ISaveAble<Data>& data , bool &stopItr){
    std::cout << data.ToString() << std::endl;
    std::cout << typeid(data).hash_code() << std::endl;
}

template<class T>
void SaveData(IIterateAble<T>& dataArray , const std::string  fileName){
    dataArray.ForEach(CallBack);
}

class Book{
public:
    std::string bookName;
    int id;
    int price;
};


// Std Forward

void GetValByRef(int refInt){
    refInt -- ;
    std::cout << " \n" << refInt << "\n";
}

int main () {



    Data data;
    Array<Data> dataArray;
    for (int i =0 ; i < dataArray.len ; i++)
        dataArray.arr[i] = Data("hello" , 9032);

    void(*callback)(ISaveAble<Data>& data , bool& canStop) = CallBack;

    dataArray.ForEach(callback);

    std::cout << "Save Data :  \n";
    SaveData(dataArray , "Hello world");


    if(typeid(data) == typeid(static_cast< ISaveAble<Data>& > (data))){
        std::cout << typeid(data).name() << " : " << "Have Implemented Class  _ "
        << typeid(static_cast<const ISaveAble<Data>&>(data)).hash_code();
    }


    time_t time1;
    std::time(&time1);
    std::cout << "Time : " <<ctime(&time1)<< std::endl;

    int val = 100;
    GetValByRef(val); // pass by ref
    std::cout << "Val : "<< val << "\n";


     // Check empty File
     std::ifstream in;
     in.open("Some File.text" , std::ios::in);
     if(in.peek() == std::ifstream::traits_type::eof())
         return 1;
     else return 0;
}






