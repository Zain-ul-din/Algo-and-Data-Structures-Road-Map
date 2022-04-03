// Abstract Factory

#ifndef CLIONAPP_ISAVEABLE_H
#define CLIONAPP_ISAVEABLE_H
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

// Rules for saving in text Files
template<class T>
class ISaveAble{
public:
   virtual std::string ToString () = 0;
   virtual T StrToObj(std::string ss) = 0;
};

class Data : public ISaveAble<Data>{
public:
    std::string ToString() override {
        std::stringstream  ss;
        ss << name <<"," <<age;
        return ss.str();
    }

    Data StrToObj(std::string ss) override {
        Data data;
        std::vector<std::string> vec;
        std::string str = "";
        for(auto c : ss) {
            if (c == ',') {
               vec.push_back(str);
               str ="";
            } else str.push_back(c);
        }

        data.name = vec[0];
        data.age = std::stoi(vec[1]);

        return data;
    }

private:
    std::string name;
    int age;
};

template<class T>
void SaveData(const char fileName[] ,ISaveAble<T>& data){
    std::ofstream out;
    out.open(fileName , std::ios::out);
    out << data.ToString() << "\n";
    out.close();
}

void Demo(){
    Data data;
    SaveData("hello.text" ,data);

}

#endif //CLIONAPP_ISAVEABLE_H
