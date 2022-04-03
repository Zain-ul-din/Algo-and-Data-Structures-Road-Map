#include<iostream>
#include<vector>

int main(){
	std::vector<int> vector;
	vector.push_back(1000);
	vector.push_back(2000);
	vector.push_back(5000);
	vector.push_back(4000);
	
	vector.insert(vector.begin()+2, 4000);
	
	for( int  i = 0 ; i < vector.size() ; i ++)
		std::cout << " " << vector[i] << " ";
	
	return 0;
}
