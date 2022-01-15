//
// Created by 97152 on 12/01/2022.
//

#include<iostream>

class A{
public:
    A(){
        data = nullptr;
    }
    int pub;
protected:
    int pro;
    int* data;

};

class B : public A{
    B() {
        pub = 2;
    }

    void Display(){
        pub = 2;
        std::cout << pub << std::endl;
        data = nullptr;
    }
};
