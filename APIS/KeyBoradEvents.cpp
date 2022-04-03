#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>
#include<string>
#include<assert.h>
#include<algorithm>
#include<chrono>
#include<thread>
#include<stdio.h>

#define VKEY GetAsyncKeyState(VK_UP) < 0
#define CLS system("cls");
#define LISTEN(KEY_FLAG , ENTER_FLAG) while(true) {getch(); if(KEY_FLAG || ENTER_FLAG) break;}

void clearScreen() {
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void set_cursor(bool visible){
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 10;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

bool GetKeyDown (int key){	return GetAsyncKeyState(key) < 0; }

template<class... T>
void LISTEN_KEY (bool &canRender ,T... keyCode ){
	while(true){
//	  std::cin.clear();
//	  std::cin.sync();	
	  getch();
	  
	  bool pressed = false;
	  
	  ([&] (int &_keyCode) {
	  	if(GetKeyDown(_keyCode))
	  	   pressed = true;
	  }(keyCode) , ...);
	  
	  canRender = pressed;
	  
	  if(pressed)
	    break;
	}
}
class Menu{
    public:
		template<class... T>
		Menu (T... menus){
			
			([&](auto menu){
				choices.push_back(menu);
			}(menus),... );
			
		}
		
		void Render (int& rendererKey){
			if(choices.empty())
			   return;
	        
	        key %= choices.size();
	        std::cout << "\n ==== Inventory System ===  \n";
	       // key += 1;
			int _key = 0;
			std::for_each (choices.begin() , choices.end() , [&](std::string& ss){
				std::cout << "\n " << (key == _key ? "====> " : "      " )<< ss << " \n";
				_key += 1;
			});
			
			key += 1;
	   }
		
		void Re_Render (int& rendererKey){
			if(choices.empty())
			   return;
	        
	        key -= 1;
	        
	        if (key < 0)
	          key = choices.size() - 1;
	        
	        
	        std::cout << "\n ==== Inventory System ===  \n";
	        
			int _key = 0;
			std::for_each (choices.begin() , choices.end() , [&](std::string& ss){
				std::cout << "\n " << (key == _key ? "====> " : "      " )<< ss << " \n";
				_key += 1;
			});
			std::this_thread::sleep_for(std::chrono::nanoseconds((int64_t)(0.058 * 1e9 )));
			
			
		}
		
		int GetChoiceIdx (){ return key == 0 ? 0 : key-1;}
		
    private:
		std::vector < std::string >	choices;
		char prefix;
		int key = 0;
		
};

bool RenderContent (std::vector<std::string> &choices , Menu& menu){
	int renderState = 0;
	if(VKEY) {
      	  clearScreen(); // flickering fix
     	  menu.Render(renderState);
     	  std::this_thread::sleep_for(std::chrono::milliseconds(100));
     	  return false;
      } 
      else if (GetKeyDown(VK_DOWN)){
      	  clearScreen();     
      	  menu.Re_Render(renderState);
		  std::this_thread::sleep_for(std::chrono::milliseconds(100));   
		  return false;    
	  }
      
     // getch();
    if(GetAsyncKeyState(VK_RETURN) < 0){
      	std::cout << "\n>> You Select _ "<<choices[menu.GetChoiceIdx()] << " ";
      	set_cursor(true);
      	return true;
	}
}

int main () {
	
	if ("true")
	   std::cout << "true";
	else std::cout << "false";   
	
	system("pause");
	
  // Changing text color (GetStdHandle(-11), colorcode)
   set_cursor(false);
   std::cout << "Loading ...  ";
   SetConsoleTextAttribute(GetStdHandle(-11), 27);
   int barl = 30;
   std::cout << " ";     
   for (int i = 0; i < barl; i++) {         
      std::this_thread::sleep_for(std::chrono::nanoseconds((int64_t)(0.058 * 1e9 )));
      std::cout << " ";  
   }
   std::cout << " ";
    
   // Reset color
   SetConsoleTextAttribute(GetStdHandle(-11), 7);	
   CLS
   
   HANDLE hStdout;


  char c;	
  std::vector <std::string> choices = {
  	"M416" , "Akm" , "M16A4" , "Kar98" , "M24" , "Groza" , "AWM" , "UZI" , "M762"
  };
  
  int rendererState = 0;
  Menu menu (choices[0] ,choices[1] ,choices[2] , choices[3] , choices[4] , choices[5] , choices[6] , choices[7] ,choices[8]  );
  menu.Render(rendererState);
  
  bool canRender = false;
  
  while(true){
  	  set_cursor(false);
  	  //  LISTEN(VKEY , GetKeyDown(VK_RETURN))
  	  LISTEN_KEY (canRender ,VK_UP , VK_DOWN , VK_RETURN );
      if ( RenderContent( choices , menu ) )
        break;
  }
  
  
  
  std::cout << "\n Program has been End !!";
  
  return 0;
}

// GetAsyncKeyState(VK_UP) < 0 .. Up arrow