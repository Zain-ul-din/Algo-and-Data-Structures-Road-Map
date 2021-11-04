// Arrays Methods 

/*
   git pull --set-upstream origin master
   https://docs.github.com/en/github/importing-your-projects-to-github/importing-source-code-to-github/adding-an-existing-project-to-github-using-the-command-line
*/
#include<iostream>
#include<algorithm>
using namespace std;

template<typename T>
class ArrayHelper{
	public:
		ArrayHelper(T arr[],int sizeOfArr,T defaultGarbge){
			for(int i=0;i<sizeOfArr;++i)
				arr[i] = defaultGarbge;
			this->sizeOfArr = sizeOfArr;
			this->defaultGarbge = defaultGarbge;
			currentIndex = -1;
		}
		
		// Call Backs
		template<class Func>
	    void ForEach(T arr[],Func CallBack){
			for(int i=0;i<sizeOfArr;++i)
			    CallBack(&arr[i]);
		}
		
		// push_back
		void Push_Back(T arr[],T element){
			if(currentIndex == (sizeOfArr -1)){
				cout<<"ERROR : Array Has been fulled can't add more elements"<<"Size of Array : "<<sizeOfArr<<endl;
				return;
			}
			currentIndex++;
			arr[currentIndex] = element;
		}
		
		// Pop Back
		void Pop_Back(T arr[]){
			if(currentIndex < 0) return; // Avoid Empty Array
			arr[currentIndex] = defaultGarbge;
			currentIndex --;
		}
		
		// Push_Top
		void Push_Top(T arr[],T element,bool overWrite = false){
			if(currentIndex == (sizeOfArr-1) && !overWrite){
				cout<<"ERROR : Array is Already Full : Use instead 'overWrite = true '"<<endl;
				return;
			}
			
			if(currentIndex < (sizeOfArr-1)){ // free Space at the end
				for(int i=currentIndex+1;i>=0;--i)
				   arr[i] = arr[i-1];
				arr[0] = element;
				currentIndex ++;
				return;   
			}
			else arr[0] = element;
		}
		
		// Pop
		void Pop(T arr[],bool deleteFirstElement=false){
			if(currentIndex == (sizeOfArr-1) && !deleteFirstElement){
				cout<<"ERROR : Array is already filled use Instead : 'deleteFirstElement= true' "<<endl;
				return;
			}
		     
			if(currentIndex < (sizeOfArr-1)){
				for(int i=0;i<currentIndex+1;++i)
			      arr[i] = arr[i+1];
			    
			    currentIndex --;
			} else arr[0] = defaultGarbge;  
		}
		
		void Print(T arr[]){
			if(Is_Empty(arr)) return;
			cout<<endl;
			for(int i=0;i<currentIndex+1;++i)
				cout<<" "<<arr[i]<<" ";
			cout<<endl;
		}
		
		void Debug(T arr[]){
			cout<<endl<<"--DEBUG--"<<endl;
			for(int i=0;i<sizeOfArr;++i)
			  cout<<" "<<arr[i]<<" ";
		    cout<<endl;
		    cout<<"Current Index : "<<currentIndex<<endl;
		}
		
		// Is Empty
		bool Is_Empty(T arr[]){ return currentIndex < 0;}
		
		void DeleteAll(T arr[],bool deleteAll){
			if(deleteAll)
			  for(int i=0;i<currentIndex;++i)
			      arr[i] = defaultGarbge;
		}
		
		void Delete(T arr[],short index){
			if(index > currentIndex || index < 0) return;
			if(index == currentIndex){
				currentIndex--;
				return;
			}
		
			for(int i=index;i<currentIndex;++i)
			    swap(arr[i],arr[i+1]);
			arr[currentIndex] = defaultGarbge;
			currentIndex--;
		}
		
		void Delete(T arr[],T &element){
			if(element == defaultGarbge) return;
			short index = -1;
			for(int i=0;i<currentIndex+1;++i){
				if(arr[i] == element){
					index = i;
					break;
				}
			}
			if(index == -1){
				cout<<"ERROR : can't delete existing elment"<<endl;
				return;
			} 
			Delete(arr,index);
		}
		
		int FindElement(T arr[],T element,bool useBinarySearch=false){
			if(useBinarySearch){ // use Binary Search
			    sort(arr,arr+1);
				T expectedMatch;
				int leftPtr = 0,rightPtr = sizeOfArr-1;
				int midPtr;
				while(rightPtr >= leftPtr){
					midPtr = (leftPtr + rightPtr) / 2;
					expectedMatch = arr[midPtr];
					if(expectedMatch == element)
					    return midPtr;
					else if(element < expectedMatch)
					    leftPtr = midPtr+1;
					else if(element > expectedMatch)
					    rightPtr = midPtr -1;
				}
				return -1;
			}
			else{
				for(int i=0;i<currentIndex+1;++i)
					if(arr[i] == element)
					   return i;
				return -1;
			}
		}
		
		
	private:
		int sizeOfArr;
		T defaultGarbge;
		int currentIndex;
		// Swap
		void Swap(T& val1,T& val2){
			val1 = val1 ^ val2;
			val2 = val1 ^ val2;
			val1 = val1 ^ val2;
		}
};
// Driver Code
int main(){
	int arr[5];
	ArrayHelper<int> arrayHelper(arr,sizeof(arr)/sizeof(arr[0]),-1);
	// Adding element
	 /*arrayHelper.Push_Back(arr,1);
	 arrayHelper.Push_Back(arr,2);
	 arrayHelper.Push_Back(arr,3);*/
	 //arrayHelper.Push_Back(arr,4);
	 //arrayHelper.Push_Back(arr,5);
	 
	arrayHelper.Print(arr);
	
	int elementToDelete = 9;
	
	arrayHelper.Push_Top(arr,3);
	arrayHelper.Push_Top(arr,4);
	arrayHelper.Push_Top(arr,9);
	arrayHelper.Push_Top(arr,6);
	arrayHelper.Push_Top(arr,7);
	
	arrayHelper.Delete(arr,elementToDelete);
	// Finding element in Array
	cout<<arrayHelper.FindElement(arr,3,true)<<endl;
	
	arrayHelper.Debug(arr);
	arrayHelper.Print(arr);
}
