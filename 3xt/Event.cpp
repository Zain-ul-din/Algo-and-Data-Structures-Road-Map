
// Events in c++

#if __cplusplus < 201103L
#warning Version Error C++ 11 requied

#else
#include<iostream>
#include<functional>
#include<vector> // Add new line



// Event Implementaion in C++
template<class ReturnType , class... Argu>
class Event{
	public:
		
		void operator |= (std::function<ReturnType(Argu...)> func){
			eArray.push_back(func);
		}
		 
		void Invoke(Argu... args){
			if(eArray.empty())
			   return;
			for(auto e : eArray)
			    e(args...);
		} 
	private:	
		std::vector<std::function<ReturnType(Argu...)>> eArray;
};

class Data{
	public:
		
		Data(int id , std::string name): id(id) , name(name){}
		
		void Set_Id(int id){
		     this->id = id;
		  
		     // Fire Event on Data Change
		     OnDataChange.Invoke(id , name);
		}
		void Set_Name(std::string name){
		    this->name = name;
		  
		     // Fire Event on Data Change
		     OnDataChange.Invoke(id , name);
		}
		
		Event<void , int& ,std::string& > OnDataChange;
		
	private:
		int id;
		std::string name;
};

int main(){
	const int MAXID = 1;
	Data data(1 , "Zain ul din");
	
	// Subscribe to the event
	data.OnDataChange |= [&](int& id , std::string& name){
		if(id > MAXID) id = MAXID;
	};
	
	// Multiple Sub
	data.OnDataChange |= [&](int id , std::string name){
		std::cout << " Data Has been Changed !\n";
		std::cout << " id : " << id << "\n" << " Name : "<<name <<"\n";
	};
	
	data.Set_Id(5);
}
/*
OUTPUT:
 Data Has been Changed !
 id : 1
 Name : Zain ul din
*/

#endif