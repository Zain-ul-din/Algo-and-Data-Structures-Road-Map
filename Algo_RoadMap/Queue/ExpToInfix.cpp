#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool IsOperator(bool _char){
	return _char == '+' || _char == '-' || _char == '*' || _char == '/' || _char == '^';
}

float DoMath(char _char,float val1,float val2){
	switch(_char){
		case '+': return val1 + val2;
		case '-': return val1 - val2;
		case '*': return val1 * val2;
		case '/': return val1 / val2;
	}
	return 1;
}

char PostFixToInfix(string expression){
	stack<char> st;
	string results = "";
	
	for(int i=0;i<expression.length();++i){
		char c = expression[i];
		
		if(!IsOperator(c)){ // operand
			st.push(c - '0');
		}
		
		else if(c == '(' || c == ')') continue;
		else{ // operator
		 float val1;
		 float val2;
		    if(!st.empty())
			val1 = static_cast<float>(st.top());
			if(!st.empty()){
			 val2 = static_cast<float>(st.top());
			} else val2 = 1.0;
			if(val2 != 1.0)
			st.push(DoMath(c,val1,val2));
			else st.push(val1);
		}
	}
	return st.top();
}

// Driver Code
int main(){
	string expression = "231*+9-";
	cout<<PostFixToInfix(expression)<<endl;
}