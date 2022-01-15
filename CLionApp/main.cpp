#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

#include "IHotDrinkFactory.h" // abstract factory
#include "ISaveAble.h"

#define Debug(val) std::cout << #val << " : "<<val <<"\n";
#define AutoString(ss) std::string ss = #ss;




// Gamma Categorization

// - > Creational Design Pattern : Deal with the creations of the objects
// - > Structural Design Pattern : Deal with Class and Struct and allow to design good apis btw them
// - > Behavioral Design Pattern : behavioral design patterns are design patterns that identify common communication patterns among objects


// Builder Design Pattern  - Creational

// Html Builder

class HtmlElement{
public:
        HtmlElement(std::string name, std::string text) : name(name) , text(text){}


        std::string  ToString(){
            std::stringstream ss;
            ss<< " " << "  <" <<name << ">\n";
            ss << "\t" << text << " \n";
            ss<< " " <<  " </" <<name <<">\n";
            return ss.str();
        }

       std::vector<HtmlElement> htmlElementList;
private:
    std::string name , text;
};


// Factories and Abstract Factories

// diff way to implement factory
//    -> Inner static methods to construct Object
//    -> Outer static Class
//    -> Inner static class

 // separate function that makes object like StrToObj in text Files

 class Point{
 private:
     Point(float x , float y) : x(x) , y(y){}
//     friend class Point_Factory; not recommended cuz it's break open close principles
     float x , y;

     // Factory Implementation in class , good practice is have separate class

//     static Point NewCertainPoint(float x , float y){return {x , y};}
//
//     static Point NewPolarPoint(float r , float theta){ return {r* sin(theta) , r*sin(theta)};}

     // here These Static methods allow to construct object and constructor is private
 public:
     friend std::ostream& operator << (std::ostream& out , Point& point){
         out << point.x << " - " << point.y <<"\n";
         return out;
     };

     // Inner Factory , now it can access private members of Point Class

    class Point_Factory{
    public:
        static Point NewCertainPoint(float x , float y){return {x , y};}

        static Point NewPolarPoint(float r , float theta){ return {r* sin(theta) , r*sin(theta)};}

        /*
         * One issue is we can not access the private members of point inside our factory what we could do we can make
         * Factory friend of Point but i'll break open close principles
         * cuz if we delete Factory we also have to remove friend declaration from Point Class so that's not an good idea
         */
    };
 };

 // Factory Class all members are going to be static or we can make them no static

// class Point_Factory{
// public:
//     static Point NewCertainPoint(float x , float y){return {x , y};}
//
//     static Point NewPolarPoint(float r , float theta){ return {r* sin(theta) , r*sin(theta)};}
//
//     /*
//      * One issue is we can not access the private members of point inside our factory what we could do we can make
//      * Factory friend of Point but i'll break open close principles
//      * cuz if we delete Factory we also have to remove friend declaration from Point Class so that's not an good idea
//      */
// };

// Abstract Factories
// In Header HotDrink.h & IHotDrinkFactory

enum class DrinkType{
    Tea , Coffee
};

std::unique_ptr<IHotDrink> HotDrinKFactory(DrinkType type ,int amount){
    std::unique_ptr<IHotDrink> drink;

    if(type  == DrinkType::Tea){
        drink = std::make_unique<Tea>();
        drink->Prepare(amount);
    }else{
        drink = std::make_unique<Coffee>();
        drink->Prepare(amount);
    }

    return drink;
};

int main () {
    HtmlElement element("P" , "Hello world");
    std::cout << element.ToString() << "\n";

//    Point p{2,3};
//      auto point= Point::NewCertainPoint(3,2);
//      std::cout << point;

//      Point p1 = Point_Factory::NewCertainPoint(30,90);
//      p1 = Point_Factory::NewPolarPoint(3.9 , 9.24);
//      std::cout << p1 << "\n";

// Inner Factory
    Point p1 = Point::Point_Factory::NewCertainPoint(30,90);
    p1 = Point::Point_Factory::NewPolarPoint(3.9 , 9.24);
    std::cout << p1 << "\n";

    // Abstract Factory
    auto tea = HotDrinKFactory(DrinkType::Tea ,2);
    std::unique_ptr<IHotDrink> coffee = HotDrinKFactory(DrinkType::Coffee , 1);
}
