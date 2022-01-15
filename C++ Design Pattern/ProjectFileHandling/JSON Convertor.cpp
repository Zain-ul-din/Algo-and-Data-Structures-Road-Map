

#include <iostream>
#include <fstream>
#include <typeinfo>
#include <memory>
#include <utility>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

enum class Color{
    red , green , blue , white
};
enum class Size{
    ss , md, xl , xxl
};
// Item Class
class Item{
public:
    string itemName;
    Color itemColor;
    Size itemSize;
};


template<class T> class ISpecification{
public:
       virtual bool IsSpecified(const T& obj) = 0;
};

template<class T> class IFilter {
public:
      virtual void FilterItems(vector<T> &vec ,ISpecification<T> &item) = 0;
};

class Filter :  IFilter<Item>{
public:
    string someName;
    void FilterItems(vector<Item> &vec, ISpecification<Item> &item) override {
        for(auto i : vec)
            if(item.IsSpecified(i)){
                cout<<"Item Has Been Found" <<endl;
                return;
            }
        cout<<"Item not Found ___ "<<endl;
        return;
    }
};

void FilterItems(vector<Item> &vec , ISpecification<Item>& spec){
    for(auto it : vec)
        if(spec.IsSpecified(it)){
            cout << " Item Has Been Found __ \n";
            return;
        }
    cout<<" Item Not Found \n";
}



class ItemNameFilter :
        public ISpecification<Item>{
public:
    bool IsSpecified(const Item &obj) override {return this->name == obj.itemName;}
    explicit ItemNameFilter(string name):  name(name) {}
    string name;
};



// Driver Code
int main () {
    vector<Item> itemList;
    itemList.push_back(Item{"Book" , Color::white , Size::md});
    itemList.push_back(Item{"Some" , Color::white , Size::md});
    itemList.push_back(Item{"Pen" , Color::white , Size::md});
    itemList.push_back(Item{"Table" , Color::white , Size::md});
    itemList.push_back(Item{"Item" , Color::white , Size::md});

    Filter filter;
    ItemNameFilter itemNameFilter("Chair");
    filter.FilterItems(itemList , itemNameFilter); // using Filter Class

    FilterItems(itemList , itemNameFilter); //  using Func
}

