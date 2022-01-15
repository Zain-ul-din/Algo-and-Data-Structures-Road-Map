//
// Abstract Factory Pattern Implementation
//

#ifndef CLIONAPP_HOTDRINK_H
#define CLIONAPP_HOTDRINK_H

#include <iostream>
#include <memory>

// A interface
class IHotDrink{
public:
    virtual ~IHotDrink() = default;
    virtual void Prepare(int amount) = 0;
};


class Tea :public IHotDrink{
public:
    ~Tea() override = default;

    void Prepare(int amount) override {
       std::cout << "Tea  Amount : " << amount << "\n";
    }
};

class Coffee :public IHotDrink{
public:
    ~Coffee() override = default;

    void Prepare(int amount) override {
      std::cout << "Coffee Amount : " << amount << "\n";
    }
};



#endif //CLIONAPP_HOTDRINK_H
