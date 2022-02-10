
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<typeinfo>
#include<functional>



namespace SaveSystem {

    class SaveAble {
     public:

        template<class... Argu> // c++ 17 fold expressions
        void Save(Argu... args){
            __stringV = "";
            std::stringstream _ss;
            ([&](auto data){
              _ss << data << " - ";
            }(args) ,...);
            __stringV = _ss.str();
        }

    protected:
        std::string __stringV;
        friend class ITraverseAble;
    };

     // Interface for container
    class ITraverseAble {
     public:
        virtual void ForEach(void(*callBack)(SaveAble &obj)) = 0;
    };
};



template<class CallBack>
class Action{
public:
    size_t typeSize;

};

int main ( ){
   std::vector<Action<void(size_t)>> actionArr;

}
