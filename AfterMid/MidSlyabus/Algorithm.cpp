
// BFS using Queue

#include<iostream>
#include<vector>
#include<queue>

#define Debug(X) std::cout << "\n" << "Value of " << "' " << #X << " '" << " = " << X << "\n"

class Node{
public:
    char name;
    std::vector<Node> children;

    // Add child to node
    void AddChildren(const char name){
        children.push_back(Node{name});
    }

    // BFS Algo
    std::vector<char> BFS(){

        std::vector<char> res;

       std::queue<Node> queue ; // Helper Data structure
       queue.push(Node {this->name}); // add root node to the queue

       while(!queue.empty()) {
         Node current = queue.front();
         queue.pop();
         res.push_back(current.name); // adds to the res list

         for(auto i = current.children.begin() ; i != current.children.end() ; i++)
             queue.push(Node{*i});
       }

       return res;
    }
} ;

#include<string>
#include<sstream>
#include<algorithm>
#include<exception>
#include<functional>

/// Dependencies
//  -> #include<string>
//  -> #include<sstream>
//  -> #include<algorithm>




// C++ Save Interface
template<class... Func>
class ISaveAble{
public:

};

template<class returnType , class Sender ,class... EventHandler>
class Event {
public:
      Event(){}

      void operator |= (std::function<returnType(EventHandler...)> e) {
          eArray.push_back(e);
      }


      template<class... Args>
      inline void Invoke(Args&... argu)const{
          if(eArray.empty()) return;
          for(auto  e : eArray)e(argu...);
      }

private:
    std::vector<std::function<returnType(EventHandler...)>> eArray;
};

// Sub Approach using Interface
template<class Func>
class IEvent{
public:
    virtual void Sub(Func func) = 0;
};

class Data : IEvent<std::function<void(int& , std::string)>>{
public:

    Event<void , Data ,int& , std::string&> OnDataChange;

    Data(int id, const std::string &name) : id(id), name(name) {}
    Data(){}

private:
    // using interface approach
    void Sub(std::function<void(int &, std::string)> func) override {
       OnDataChange |= func;
    }

public:

    // Get Id
    int getId() const {
        return id;
    }

    // Best Sub
    void Sub_OnDataChange(void(*e)(int &, std::string&)){
        OnDataChange |= e;
    }

    void setId(int id) {
        this->id = id;
        OnDataChange.Invoke(this->id , this->name);
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        this->name = name;
    }

private:
    int id;
    std::string name;
};

class String : std::string {
public:
    String(const basic_string<char, std::char_traits<char>, std::allocator<char>> &right) : basic_string(right) {}
    String(const basic_string<char, std::char_traits<char>, std::allocator<char>> &right,
           const std::allocator<char> &al) : basic_string(right, al) {}
    String() {}
    String(const std::allocator<char> &al) : basic_string(al) {}
    String(const basic_string<char, std::char_traits<char>, std::allocator<char>> &right, const size_type roff,
           const std::allocator<char> &al) : basic_string(right, roff, al) {}
    String(const basic_string<char, std::char_traits<char>, std::allocator<char>> &right, const size_type roff,
           const size_type count, const std::allocator<char> &al) : basic_string(right, roff, count, al) {}
    String(const char *const ptr, const size_type count) : basic_string(ptr, count) {}
    String(const char *const ptr, const size_type count, const std::allocator<char> &al) : basic_string(ptr, count,
                                                                                                        al) {}
    String(const char *const ptr) : basic_string(ptr) {}
    String(const char *const ptr, const std::allocator<char> &al) : basic_string(ptr, al) {}
    String(const size_type count, const char ch) : basic_string(count, ch) {}
    String(const size_type count, const char ch, const std::allocator<char> &al) : basic_string(count, ch, al) {}

#ifdef _VECTOR_
    // Splits String into Array by separator
    std::vector<String> Split(const char separator){
        std::vector<String> arr;
        String _temp;

        iterator itr = this->begin();
        while (itr != this->end()){
            if(*itr == separator){
                if(!_temp.empty())
                    arr.push_back(_temp);
                _temp = "";
            } else _temp.push_back(*itr);
        }
        return arr;
    }
#endif


    std::string* std_str(){return &(static_cast<std::string& >(*this));}
    std::string* operator () (){return &(static_cast<std::string& >(*this));}



};


void Func(int num){
   std::cout << "I 'm Func :-) \n";
}



// Driver Code
int main () {
     const int SIZE = 5;
     std::vector<int> nodes[5];

     std::string string = "Hello world in c++";

     // string slicing
     std::string slice_str = string.substr( 15, string.length()-1);

     String ss;


     Debug(slice_str);

     // find & slice
     size_t pos = string.find("c++");
     slice_str = string.substr(pos); // slice from pos to the end
     Debug(slice_str);

    // Event Handler using c++
    Data data(2,  "Zain ul din");
    data.OnDataChange |= [&](int& id , std::string& name){
        std::cout << "Data Has been Changed !\n";
        std::cout << id << " " << name <<"\n";
    };

    data.OnDataChange |= [&](int& id , std::string & name){
         std::cout << "Data Has been Changed by 2nd sub\n";
    };

    data.setId(3);
}

// CallBack