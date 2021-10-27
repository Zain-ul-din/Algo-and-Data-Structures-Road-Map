#include<bits/stdc++.h>
using namespace std;

namespace MyUtilities{
	// Algo Class
	class Algo{
		public:
		template<typename T>
		static bool BinarySearch(T arr[],int leftIndex,int rightIndex,T toFindEle){
			// Sorting Array before
			T potentionMatch;
			int midIndex;
		    bool toggle = true;
			while(rightIndex >= leftIndex){

			  midIndex = leftIndex + rightIndex /2;
			  potentionMatch = arr[midIndex];
			  if(toggle){
			  	cout<<"Mid : "<<midIndex<<endl;
			  	toggle = false;
			  }
				if(potentionMatch == toFindEle)
				   return true;
				else if(toFindEle < potentionMatch){
				//	cout<<"Left Side : "<<rightIndex<<endl;
				   rightIndex = midIndex - 1;
				}
				else{
				//	cout<<"Right Side : "<<leftIndex<<endl;
					leftIndex = midIndex + 1;
				} 
					
			}
			return !true;
		}
	};
}

template<typename T>
bool BinarySearch(T arr[],int leftIndex,int rightIndex,T toFindEle){
			// Sorting Array before
			T potentionMatch;
			int midIndex;
		    int toggle = 0;
			while(rightIndex >= leftIndex){

			  midIndex = (leftIndex + rightIndex) /2;
			  potentionMatch = arr[midIndex];
			if(toggle < 5){
			  toggle++;
			  cout<<"Middle index : "<<midIndex<<" leftIndex : "<<leftIndex<<" right : "<<rightIndex<<endl;
		    }
				if(potentionMatch == toFindEle)
				   return true;
				else if(toFindEle < potentionMatch){
				   rightIndex = midIndex - 1;
				}
				else{
					leftIndex = midIndex + 1;
				} 
					
			}
			return !true;
		}
int main(){
	cout<<"Loading .. "<<endl;
	int arr[10] = {0,1,33,41,45,45,65,71,72,73};
	if(BinarySearch(arr,0,9,33)){
		cout<<"Found";
	} else cout<<"Not found"<<endl;
}