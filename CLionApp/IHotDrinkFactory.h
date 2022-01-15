//
// Created by 97152 on 15/01/2022.
//

#ifndef CLIONAPP_IHOTDRINKFACTORY_H
#define CLIONAPP_IHOTDRINKFACTORY_H

#include "HotDrink.h"

class IHotDrinkFactory{
public:
    virtual std::unique_ptr<IHotDrink> Make() = 0;
    virtual ~IHotDrinkFactory() =default;
};

class TeaFactory :public IHotDrinkFactory{
public:
    std::unique_ptr<IHotDrink> Make() override {
        return std::unique_ptr<Tea>();
    }

    ~TeaFactory() override = default;
};

class CoffeeFactory :public IHotDrinkFactory{
public:
    std::unique_ptr<IHotDrink> Make() override {
        return std::unique_ptr<Coffee>();
    }

    ~CoffeeFactory() override = default;
};

#endif //CLIONAPP_IHOTDRINKFACTORY_H
