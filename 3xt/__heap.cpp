#include<iostream>
#include<vector>

class Node{
	public:
		std::string user;
		std::vector<std::string> followers;
};

void AddFollower(std::string key , std::string follower , std::vector<Node>& insta){
	for(int i = 0 ; i < insta.size() ; i++)
	    if(key == insta[i].user) insta[i].followers.push_back(follower);
}

void Display(std::vector<Node>& insta){
	for(int i =0 ; i < insta.size() ; i++){
	   std::cout << "\n" << insta[i].user << "\n";
	   std::cout << "Followers :- \n";
	   if(insta[i].followers.empty()) std::cout << "\n " << "Zero Follower " << " ";
	   for(int j = 0 ; j < insta[i].followers.size() ; j++)
	      std::cout << "\t " <<  insta[i].followers[j] << " ";
	   std::cout << "\n";	    	
	}
}

// Instagram Follwers
int main(){
	std::vector<Node> insta;
	insta.push_back({"Zain" , {}});
	insta.push_back({"Fahad" , {}});
	insta.push_back({"Raveel" , {}});
	insta.push_back({"Ahmad" , {}});
	
	AddFollower("Zain" , "Ahmad" , insta);
	AddFollower("Raveel" , "Ahmad" , insta);
	AddFollower("Fahad" , "Raveel" , insta);
	AddFollower("Zain" , "Ali" , insta);
	AddFollower("Ahmad" , "Zain" , insta);
	AddFollower("Fahad" , "Zain" , insta);
	AddFollower("Fahad" , "Ahmad" , insta);
	AddFollower("Fahad" , "Umer" , insta);
	AddFollower("Fahad" , "Hassan" , insta);
	AddFollower("Fahad" , "Nosha" , insta);
	AddFollower("Fahad" , "Raheel" , insta);
	Display(insta);
}