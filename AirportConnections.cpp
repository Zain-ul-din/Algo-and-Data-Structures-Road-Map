// Airport Connections Problem
/*
  *  Question Analysis
  *  -> Given 3 Inputs
     * List of Airports (lhr,uae,usa ..)
     * Route (lhr -> UAE)
     * starting AirPort
   
   * Expected Output : 
   
*/
#include<bits/stdc++.h>
using namespace std;
// Route
class Route{
	public:
	Route(){}
	
	Route(string startAirPort,string targetAirPort){
		this->startAirPort =  startAirPort;
		this->targetAirPort = targetAirPort;
	}
	// I/O
	friend istream& operator >> (istream& iStream,Route& route); 
	friend ostream& operator << (ostream& oStream,Route& route);
	// Var
		string startAirPort,targetAirPort;
};

// AirPortNode
class AirPortNode{
 public:
	AirPortNode(string airPortName){
		this->airPortName = airPortName;
		this->isReachable = true;
	}
	// Var
    string airPortName;	
    bool isReachable;
    vector<Route> conections;
    vector<Route> unReachAbleConections;
};

// Inputs
void Inputs(vector<AirPortNode> &airPortList,vector<Route> &routesList);

// List of AirPorts & List of Routes
map<string,AirPortNode> MakeGraphOfAirPorts(vector<AirPortNode> &airPortList,vector<Route> &routesList){
	// Dictionary => Key : airportname , Val : AirPortNode
	map<string,AirPortNode> airPortDictionary;
	
	for(auto airPort: airPortList){
	 for(auto route : routesList)
	     airPort.conections.push_back(route);      
	 airPortDictionary.insert({airPort.airPortName,airPort}); 
	}
	
	return airPortDictionary;
}

int main(){
	
}

 // Route Friend Implementation 
 
 istream& operator >> (istream& iStream,Route& route){
 	cout<<"Enter starting Airport : ";
 	iStream>> route.startAirPort;
 	cout<<"Enter Airport Conection : ";
 	iStream>> route.targetAirPort;
 	return iStream;
 }
 ostream& operator << (ostream& oStream,Route& route){
	oStream<<route.startAirPort<<" -> "<<route.targetAirPort<<endl;
	return oStream;
 }
 
 void Inputs(vector<AirPortNode> &airPortList,vector<Route> &routesList){
	short numberOfAirPorts,numberOfRoutes;
	cout<<"Enter Number of AirPorts : ";
	cin>>numberOfAirPorts;
	string temp_str;
	for(int i=0;i<numberOfAirPorts;++i){
		cout<<"Enter "<<i+1<<" Airport Name _ ";
		cin>>temp_str;
		airPortList.push_back(AirPortNode(temp_str));
	}
	cout<<"Enter Number of Routes : ";
	cin>>numberOfRoutes;
	Route temp_route;
	for(int i=0;i<numberOfRoutes;++i){
		cin>>temp_route;
		routesList.push_back(temp_route);
	}
}