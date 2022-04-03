#include<iostream>






float domath(int num1 , int num2 , int choice){
	switch(choice){
		case 1:
		   return num1 + num2;	
		break;
		
		case 2:
		   return num1 - num2;
		break;
			
		case 3:
		   return num1 * num2;
		break;
		case 4:
		   if(num2 != 0)
		      return num1 / num2;
		   else INT_MAX;   
		break;	
	}
	return num1;
}

enum class MathOperation{
	Sum , Sub , Mul , Div
};
// here each element have index starts from 0 and it's index also constant value of it
float DoMath(int num1 , int num2 , MathOperation mathOp){
	switch(mathOp){
		case MathOperation::Sum: // as case 0
		   return num1 + num2;	
		break;
		
		case MathOperation::Sub: // as case 1
		   return num1 - num2;
		break;
			
		case MathOperation::Mul: // 2
		   return num1 * num2;
		break;
		case MathOperation::Div: // 3
		   if(num2 != 0)
		      return num1 / num2;
		   else INT_MAX;   
		break;	
	}
	// the control will never reach there
	return num1;
}

int main (){
	std::cout << "Sum : " << DoMath(3 , 4,MathOperation::Sum) <<"\n"; 
	std::cout << "Sum : "<<domath(3,4,5) << "\n";
}
