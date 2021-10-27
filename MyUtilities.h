// #include<bits/stdc++.h>
#include <iostream>
#include <time.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <thread>
#include <fstream>
using  namespace std;
using  namespace chrono;

namespace MyUtilities{
 // Stack
 #define SIZEOFSTACK 100
 template<typename T>
 class Stack{
	public:
		Stack(){
		   top = -1;
		}
		
		void Push(T val){
			top++;
			stackArr[top] =  val;
		}
		
		void Pop(){
		    top--;
		}
		
		T Top(){
			return stackArr[top];
		}
		
		
		// Is Stack Empty
		bool IsEmpty(){return top < 0;}
	private:
		T stackArr[SIZEOFSTACK];
	    short top;
 };
 
  /*                    Time Class                  */
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
  /*                        End Time class         */
  
    
} // namespace 

// STL Utilities
namespace STLUtilities{
	
}