
#ifndef OOP_INCPLUSPLUS_UTILITIES_H
#define OOP_INCPLUSPLUS_UTILITIES_H


enum class CharInfo{
    Operator,
    SmallAlphabet,
    CapitalAlphabet,
    Number,
    emoji,
    Braces,
    Symbol
};

const std::string BRACKETS = "{}()[]<>";
const std::string OPERATORS = "+-*/%^~\0";
const std::string SYMBOLS = ".,':$#@!`&\"";

CharInfo GetCharInfo(char c){
    if(c >= 'a' && c <= 'z' ) return CharInfo::SmallAlphabet;
    else if(c >= 'A' && c <= 'Z' ) return  CharInfo::CapitalAlphabet;
    else if(c >= '0' && c <= '9') return CharInfo::Number;

    for(auto b : BRACKETS)
        if(c == b) return CharInfo::Braces;

    for(auto op : OPERATORS)
        if(op == c) return CharInfo::Operator;

    for(auto s : SYMBOLS)
        if(s == c) return CharInfo::Symbol;

    return CharInfo::emoji;
}



#endif //OOP_INCPLUSPLUS_UTILITIES_H

