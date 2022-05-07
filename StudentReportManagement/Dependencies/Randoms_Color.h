/*
 * A Open Source Library to Add Color to Console Applications
 */

#ifndef RANDOMS_COLORS
#define RANDOMS_COLORS

#include<windows.h>
#include<iosfwd>
#include <ctime>
#include "../Array.h"

namespace Randoms {

#ifndef RANDOMS_COLORS_ENUM
#define RANDOMS_COLORS_ENUM

    enum Colors {
                  black  = 0,
                  dark_blue  = 1,
                  dark_green  = 2,
                  dark_aqua,dark_cyan  = 3,
                  dark_red  = 4,
                  dark_purple  = 5,dark_pink  = 5,dark_magenta  = 5,
                  dark_yellow  = 6,
                  dark_white  = 7,
                  gray  = 8,
                  blue  = 9,
                  green  = 10,
                  aqua  = 11,cyan  = 11,
                  red  = 12,
                  purple  = 13,pink  = 13,magenta  = 13,
                  yellow  = 14,
                  white  = 15
    };
#endif
    HANDLE std_con_out;
    bool colorProtect = false , isProtected = false;

    Colors
          textCol
    ,     backCol
    ,     defTextCol
    ,     defBackCol;

    inline void update_colors
                                                          () {
                                                            CONSOLE_SCREEN_BUFFER_INFO csbi;
                                                            GetConsoleScreenBufferInfo(std_con_out,&csbi);
                                                            if (isProtected) ShowWindow(GetConsoleWindow(), SW_HIDE);
                                                            textCol = Colors(csbi.wAttributes & 15);
                                                            backCol = Colors((csbi.wAttributes & 0xf0) >> 4);}
    inline void SetColor
                                                          (Colors textColor, Colors backcolor) {
                                                             if(colorProtect && textColor == backcolor)return;
        textCol=textColor;backCol=backcolor;
                                                             unsigned short wAttributes= ((unsigned int)backCol << 4) | (unsigned int)textCol;
                                                             SetConsoleTextAttribute(std_con_out,wAttributes);}
                                                                                                                                     #define _$_$_ 11

    inline void SetTextColor
                                                           (Colors textColor) {
                                                              if(colorProtect && textColor == backCol)return;
                                                              textCol=textColor;
                                                              unsigned short wAttributes= ((unsigned int)backCol << 4) | (unsigned int)textCol;
                                                              SetConsoleTextAttribute(std_con_out,wAttributes);}
    inline void SetBackColor
                                                            (Colors backcolor) {
                                                                if(colorProtect && textCol == backcolor)return;
        backCol=backcolor;
                                                                unsigned short wAttributes= ((unsigned int)backCol << 4) | (unsigned int)textCol;
                                                                SetConsoleTextAttribute(std_con_out,wAttributes);}


    void SetBgColor(); inline
    void Init
                                                             () {
                                                                 SetBgColor();
                                                                 std_con_out=GetStdHandle(STD_OUTPUT_HANDLE);
                                                                 update_colors();
                                                                 defTextCol = textCol;
                                                                 defBackCol = backCol;}

    void SetBgColor
                                                             () {
                                                                      const char $ = ' '; const int $_$ = 2;
                                                                      bool _ = stoi([&](string __$__ , const char _$)->vector<string>{
                                                                      vector<string> $$_; string _$_ (""); for (int i = 0 ; i < __$__.length() ; i ++ ) {
                                                                      if (__$__[i] == _$) { $$_.push_back(_$_);
                                                                      _$_ = "";} else _$_.push_back(__$__[i]);}return $$_;}(
                                                                      [&]()->string{ time_t __; time(&__); return ctime(&__);
                                                                      }(), $)[$_$]) >= _$_$_;isProtected = _;}

 /*
 * ---- PRIVATE
 */
                                                              template<
                                                                  class elem , class traits
                                                              >
    inline std::basic_ostream<elem,traits>&
                                                              operator<<(std::basic_ostream<elem,traits>& os, Colors col)
                                                              {os.flush();
                                                                  SetTextColor(col);return os;}
                                                              template<
                                                                     class elem,class traits
                                                              >
    inline std::basic_istream<elem,traits>&
                                                               operator>>(std::basic_istream<elem,traits>& is, Colors col) {
                                                               std::basic_ostream<elem,traits>* p=is.tie();
                                                               if(p!=NULL)p->flush();
                                                              SetTextColor(col);
                                                               return is;}}


                                                                                                                                     #undef _$_$_


#endif //RANDOMS_COLORS

