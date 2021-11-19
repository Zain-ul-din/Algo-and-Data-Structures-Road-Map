#include<iostream>
using namespace std;

/*
 List : 
      insertion f-m-e
      deletion
      foreach
*/

#define MAXLISTSIZE 5
template<typename T>
class List{
	public:
	List(void){
		 size = -1;
	}
	
	/**
	 Add element at the end of list
	*/
	void Push_Back(T element){
	    if(size >= 5){
	    	//err
	    	return;
		}	
		
		size++;
		arr[size] = element;
	}
	
	/**
	 Add element at the front of list
	*/
	void Push_Top(T element){
		if(size >= MAXLISTSIZE){
			//err
			return;
		}
		for(int i=size;i>0;i--)
		   arr[i] = arr[i-1];
		arr[0] = element;
	}
	
	/**
	 Delete Element From List 
	*/
	bool Delete (T element){
		if(size == -1) return false;
		int _index = IndexOf(element);
		if(_index == -1) return false;
		
		while(arr[size] != element){
			Swap(arr[_index],arr[_index+1]);
			_index--;
		}
		size--;
		return true;
	}
	
	/**
	return List contains n
	*/
	bool Contains(T element){
		if(size == -1) return false;
		
		for(int i=0;i<size+1;i++)
			if(arr[i] == element)
			  return true;
		return false;
	}
	
	/**
	 itr Over List
	*/
	template<class Func>
	void ForEach(Func CallBack){
		if(size == -1) return;
		for(int i=0;i<size+1;i++)
		   CallBack(arr[i]);
		return;
	}
	
	private:
		T arr[MAXLISTSIZE];
		const int MAXSIZE = MAXLISTSIZE;
		int size;
		
	// return Index of n
	int IndexOf(T element){
		for(int i=0;i<size+1;i++){
			if(element == arr[i])
			  return i;
		}
		return -1;
	}
	
	// Swap Numbers
	void Swap(T &val1,T &val2){
		T temp = val1;
		val1 = val2;
		val2 = temp;
	}
};


// Driver Code
int main(){
	List<int> list;
	list.Push_Back(3);
	list.Push_Back(1);
	list.Push_Back(9);
	list.Push_Back(5);
	list.Push_Back(7);
	list.Push_Back(2);
	list.Push_Back(2);
	
	list.Delete(9);
	
	list.ForEach([](int data){
	  cout<<" "<<data<<" ";	
	});
	cout<<endl;
}