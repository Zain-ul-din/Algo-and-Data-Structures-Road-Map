//
// Created by 97152 on 22/12/2021.
//

#ifndef DAY1_SOD_H
#define DAY1_SOD_H

/*
 * Day 1:
 * Solid Design Principles Implementation (5)
 *     --> Single Responsibility Principle
 *     --> Open and close Principle
 *     --> Liskov Substitution Principle
 *     --> Interface Segregation Principle
 *     --> Dependency Inversion Principle
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<memory>
#include<sstream>
#include<string>
#include<fstream>



using namespace std;
#define ll long long

// Single responsibility :  Class should have one responsibility and have one reason to change
class Journal{
public:
    string title;
    vector<string> entries;

    Journal(const string &title) : title(title){}

    void AddEntry(const string& entry){
        entries.push_back(entry);
    }

    // Saving is not responsibility of this class
};

template<class T>
void Save(const T& obj){
    // instead , ' Save ' Saves any class Data
}

// Open and close
enum class Color{red , green , blue};
enum class Size {small , medium , large};

class Product{
public:
    string name;
    Color color;
    Size size;
};

class Contact{
public:
    string name;
    ll number;
};

template<class T>
class ICSpecification{
public:
    virtual bool IsMatch(T& contact);
};

template<class T>
class ICFilter{
public:
    virtual T& FilterData(vector<T>& product , ICSpecification<T> spec);
};

class CFilter : ICFilter<Contact>{
public:
private:
    Contact &FilterData(vector<T> &product, ICSpecification<Contact> spec) override {
        for(auto c : product)
            if(spec.IsMatch(c)) return c;
        return {"Unknown" , 9839849834};
    }
};

// Java Script
class Spec : ICSpecification<Contact>{
public:
    string spec_Name;

    Spec(const string &specName) : spec_Name(specName) {}

    bool IsMatch(Contact &contact) override {
        return contact.name  == spec_Name;
    }

   ~Spec() = default;
};



class ProductFilter{
public:
    /*
    vector<Product> ByColor(vector<Product>& items ,Color color){
        vector<Product> results;
        for(auto& i : items)
            if(i.color == color)
                results.push_back(i);
        return results;
    }
    */
    // n properties  == n solution that's not good approach

    // open close principle say you should extend system may be by inheritance but close for modification

};

template<class T> class ISpecification{
public:
    virtual bool isSatisfied(T& item) = 0;
};

template<class T> class IFilter{
public:
    virtual vector<T> filter(vector<T>& items , ISpecification<T>& spec) = 0;
};

class BetterFilter : IFilter<Product>{
public:

    vector<Product> filter(vector<Product> &items, ISpecification<Product> &spec) override {
        vector<Product> res;
        for(auto i : items)
            if(spec.isSatisfied(i)) res.push_back(i);
        return res;
    }
};

class ColorSpecification : public ISpecification<Product>{
public:
    Color color;

    explicit ColorSpecification(Color color) : color(color) {}

    bool isSatisfied(Product &item) override {
        return  item.color == color;
    }
};

template<class T>
class AllSpecification : public ISpecification<Product>{
public:
    T compareAble;

    AllSpecification(T compareAble) : compareAble(compareAble) {}

    bool isSatisfied(Product &item) override {
        return item.size == compareAble;
    }

};

class SizeSpecification : public ISpecification<Product>{
public:
    Size size;
    explicit SizeSpecification (const Size size) : size(size){}

    bool isSatisfied(Product &item) override {
        return size == item.size;
    }
};

// Liskov Substitution Principle



// Driver Code
int SOD(){
    // Single Responsibility Implementation
    Journal journal("Trip to somewhere");
    journal.AddEntry("Lhr to Somewhere");
    journal.AddEntry("Burewala to Somewhere");
    Save(journal);

    // Open and close Implementation

    /*
     * In object-oriented programming, the open???closed principle states "software entities (classes, modules, functions, etc.) should be open for extension,
     * but closed for modification"; that is,
     * such an entity can allow its behaviour to be extended without modifying its source code
     */

    Product product1 {"book" , Color::red,Size::medium };
    Product product2 {"Apple" , Color::green,Size::medium };
    Product product3 {"Bag" , Color::blue,Size::large };
    vector<Product> items {product1 , product2 , product3};

    /*
     ProductFilter pf;
     auto res = pf.ByColor(items , Color::blue);
     for(auto i : res)
        cout<<i.name<<endl;
    */

    BetterFilter betterFilter;
    ColorSpecification colorSpecification(Color::green); //  giving Specifications
    auto products =  betterFilter.filter(items , colorSpecification);

    for(auto p : products)
        cout<<" "<<p.name<<" "; cout<<endl;

    // Better Filter by Generic Spec's :  recommended Call Backs instead
    AllSpecification<Size> sizeSpec(Size::small);
    auto productsG = betterFilter.filter(items , sizeSpec);

    // Liskov Substitution Principle Implementation

    /*
     * The Liskov Substitution Principle in practical software development.
     * The principle defines that objects of a superclass shall be replaceable with objects of its subclasses without breaking the application.
     * That requires the objects of your subclasses to behave in the same way as the objects of your superclass.
     */

    // Interface Segregation Principle

    /*
     * The interface segregation principle states that a class should not be forced to depend on methods it does not use
     * OR
     * Clients should not be forced to depend upon interfaces that they do not use
     * Like Interface IMachine have func's fax , print and also scanner . if modern printer is implementing this then that's fine but not for old printer
     * Valid Approach will be IFax , IPrint , IScanner
     */

    // Dependency Inversion Principle

    /*
     * A :High Level Modules should not depend on low level modules
     * Both should depend on abstractions
     * B : Abstraction may be should not depend on details(other code or already written class)
     * details should depend on abstractions(Interface and base classes).
     */
     return 0;
}


#endif //DAY1_SOD_H
