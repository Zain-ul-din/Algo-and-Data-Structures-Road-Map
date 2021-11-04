#include <iostream>
#include <time.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <thread>
using  namespace std;
using  namespace chrono;

class IO{
	public:
		/* INPUT */
		// * All Types
		template<typename T>
		static void Input(T &val)  {
			cin>>val;
		}
		
		template<typename T>
		static void Input(string msg,T &val) {
			cout<<msg;
			cin>>val;
		}
		
		template<typename T,class Func>
		static void Input(string msg,T &val,Func func)  {
			cout<<msg;
			cin>>val;
			func(&val);
		}
		
		// * String
		
		static void Input(string &val) {
			cin.sync();
			getline(cin,val);
		}
		
		static void Input(string msg,string &val) {
			cout<<msg;
			cin.sync();
			getline(cin,val);
		}
		
		template<class Func>
		static void Input(string msg,string &val,Func func) {
			cout<<msg;
			cin.sync();
			getline(cin,val);
			func(&val);
		}
		
		// * Arrays
		
		template<typename T>
		static void Input(T arr[]){
			int arrLength = *(&arr + 1) - arr;
			
			for(int i=0;i<arrLength-1;++i){
				cout<<"Enter Value at index : ";
				cin>>arr[i];
			}
		} 
		
		template<typename T,class Func>
		static void Input(T arr[],int lastIndex,Func func){
			bool stopItr = false;
			int arrLength = *(&arr + 1) - arr;
			if(arrLength >= lastIndex)
			   return;
			
			for(int i=0;i<=lastIndex;++i){
				if(stopItr)
				  return;
				func(arr[i],i,stopItr);
			}
		} 
		
		// * Vector
		template<typename vecType>
		static void Input(vector<vecType> &vec,int inputCount){
			vecType temp;
			for(int i=0;i<inputCount;++i){
				cout<<"Enter Value At Index : ";
				cin>>temp;
				vec.push_back(temp);
			}
		}
		
		template<typename vecType,class Func>
		static void Input(vector<vecType> &vec,Func func,int inputCount= 0,bool useCallBack=false){
			if(useCallBack){
			   func(vec);
			   return;
			}
			   
			vecType temp;
			for(int i=0;i<inputCount;++i){
				cout<<"Enter Value At Index : ";
				cin>>temp;
				func(vec);
				vec.push_back(temp);
			}
		}
		
	  /* Out Put */
	  template<typename T>
	  static void OutPut(T val){
	  	#define Debug(val) cout<<#val<<" : "<<val<<endl;
	  	Debug(val);
	  }
	  
	  // * https://en.cppreference.com/w/cpp/language/fold <Fold Expression>
	  template<typename... T>
	  static void OutPut(T&... Val){
	  	#define Debug(Val) cout<<#Val<<" : "<<Val;
	  	  (([](auto &foldVal){
	  	  	cout<<" [ ";
	  	  	cout<<foldVal;
	  	  	cout<<" ] ";
		  }(Val)),...);
		  cout<<endl;
	  }
	  
	  // Array
	  
	  template<typename T>
	  static void OutPut(T arr[]){
	    #define Debug(Val) cout<<#Val<<" : "<<Val;
	  	int arrLength = *(&arr + 1) - arr;
			for(int i=0;i<arrLength;++i){
				cout<<" [ ";
				Debug(arr[i]);
				cout<<" ] ";
			}
	  }
	  	
};

/*                 Time Class            */

class Time{
	public:
	  Time(){
	  	startTime = high_resolution_clock::now();
	  }
	  
	  void TimeTakenToSeconds(void){
	  	endTime = high_resolution_clock::now();
	  	auto timeTaken = duration_cast<seconds>(endTime - startTime); 
	  	cout<<"DEV Utilities : Time Taken in Seconds : "<<timeTaken.count()<<" sec"<<endl;
	  }
	  
	  void TimeTakenToMiliSeconds(void){
	  	endTime = high_resolution_clock::now();
	  	auto timeTaken = duration_cast<milliseconds>(endTime - startTime); 
	  	cout<<"DEV Utilities : Time Taken in MiliSeconds : "<<timeTaken.count()<<" ms"<<endl;
	  }
	  
	  void TimeTakenToNanoSeconds(void){
	  	endTime = high_resolution_clock::now();
	  	auto timeTaken = duration_cast<nanoseconds>(endTime - startTime); 
	  	cout<<"DEV Utilities : Time Taken in NanoSeconds : "<<timeTaken.count()<<" nanosec"<<endl;
	  }
	  
	  void TimeTakenToMicroSeconds(void){
	  	endTime = high_resolution_clock::now();
	  	auto timeTaken = duration_cast<microseconds>(endTime - startTime); 
	  	cout<<"DEV Utilities : Time Taken in MicroSeconds : "<<timeTaken.count()<<" micosec"<<endl;
	  }
	  
	  /*                        Static Field                       */
	  
	   static string Std_TimeNow(){
	   	#define LENGTHOFTIMESTR 24
	  	time_t TimeNow;
		string tempStr;
	  	time(&TimeNow);
		string str=ctime(&TimeNow); 
		for(auto it=str.begin();it!=(str.begin()+LENGTHOFTIMESTR);it++)
  	              tempStr.push_back(*it);
        return tempStr;
	  }
	  
	  
	private:
		// Variables
		high_resolution_clock::time_point startTime,endTime;
	
};

/*                      System Class          */

// Command List
enum SystemCommandList{
	pause,
	cls,
	date,
	dir,
};
class System{
	public:
		
		static void RunCommand(const char* _cmd){
	         system(_cmd);
        }
        
        static void Command(SystemCommandList cmd){
        	switch(cmd){
        		case pause:
        			system("pause");
        			return;
        		case cls:
        			system("cls");
        			return;
        		case date:
        			system("date");
        			return;
        		case dir:
        			 system("dir");
        			return;
        		default:
        			return;
			};
		}
		
};
// Array Class
class Array{
	public:
		template<typename T,class Func>
		static void For_Each(T arr[],Func CallBack){
			const int arraySize = sizeof(arr)/sizeof(arr[0]);
			for(int i=0;i<arraySize;++i) 
			    callBack(arr[i]);
		}
		template<typename T>
		static void SortArray(T arr[]){
			const int sizeOfArray = sizeof(arr)/sizeof(arr[0]);
			sort(arr,arr+sizeOfArray);
		}
		
};
long long Factorial(unsigned int number){
	if(number == 0)
	 return 1;
	return number * Factorial(number-1);
}
class BrustCompiler{ 
	public:
		template<class... Thread>
		void static RunOnMutliThread(Thread... _thread){
			([](thread t){t.join();}(_thread),...);
		}
};

int main(){
	
	Time timeTakenUsingLoop;
	for(int i=0;i<10000;i++)
	   cout<<"Loading .. "<<endl;
	timeTakenUsingLoop.TimeTakenToMiliSeconds();
	timeTakenUsingLoop.TimeTakenToSeconds();
	
}