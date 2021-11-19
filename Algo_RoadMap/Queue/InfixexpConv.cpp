#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;


const int numberOfOp = 5;
class Char{
	public:
	char _char;
	int precendenceOfChar;
};

const Char operatorList[] ={
  Char{'+',1},
  Char{'-',1},
  Char{'*',2},
  Char{'/',2},
  Char{'^',3},
};

bool IsOperator(char c){
	for(int i=0;i<numberOfOp;i++)
	 if(c == operatorList[i]._char)
	    return true;
	return false;
}

int PrecendenceOf(char c){
	for(int i=0;i<numberOfOp;i++)
	   if(c == operatorList[i]._char)
	     return operatorList[i].precendenceOfChar;
	return -1;
}

string InfixToPostFix(string exp){
	stack<char> st;
	string result= "";
	for(int i=0;i<exp.length();i++){
		char c = exp[i];
		if(!IsOperator(c) && c != ')' && c != '(')
		result += c;
		else if(c == '(')
		st.push(c);
		else if(c == ')'){
			while(!st.empty() && st.top() != '('){
				result +=st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && PrecendenceOf(c) <= PrecendenceOf(st.top())){
				result +=st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	
	while(!st.empty()){
		result +=st.top();
		st.pop();
	}
	return result;
}

//string InfixToPrefix()
string InfixToPrefix(string exp){
	reverse(exp.begin(),exp.end());
	
	for(int i=0;i<exp.length();i++)
	
	
	string result = InfixToPostFix(exp);
	
	reverse(result.begin(),result.end());
	return result;
}
int main(){
	string exp = "q+t+v/u/w*p^o(+n+m-l+k)";
	cout<<InfixToPostFix(exp)<<endl;
}