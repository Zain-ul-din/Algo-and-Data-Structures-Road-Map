
#ifndef OOP_INCPLUSPLUS_HTMLHELPER_H
#define OOP_INCPLUSPLUS_HTMLHELPER_H

#include"Tag.h"
#include<string>
#include<sstream>
#include<queue>

std::string WrapElement(char c){
    std::stringstream ss;
    ss<<TagList[Key::code].open<<c<<TagList[Key::code].close;
    return ss.str();
}


std::string GetElementsOfQueue(std::queue<char>& q){
    if(q.empty())return "";
    std::string ss;
    while(!q.empty()){
        ss.push_back(q.front());
        q.pop();
    }
    return ss;
}

void MakeElement(std::queue<char>& q , std::vector<std::string> &svec){
    if(GetCharInfo(q.front()) == CharInfo::CapitalAlphabet){
        svec.push_back(TagList[Key::h1].open);
        svec.push_back(GetElementsOfQueue(q));
        svec.push_back(TagList[Key::h1].close);
    }else{
        svec.push_back(TagList[Key::p].open);
        svec.push_back(GetElementsOfQueue(q));
        svec.push_back(TagList[Key::p].close);
    }
}

std::vector<std::string> LinetoHTML(std::string& line){
    std::vector<std::string> res;
    res.push_back(TagList[Key::div].open);

    std::queue<char> charQueue;

    for(auto word : line){
        auto type = GetCharInfo(word);
        switch(type){
            case CharInfo::Number:
                charQueue.push(word);
            break;
            case CharInfo::CapitalAlphabet:
                charQueue.push(word);
            break;
            case CharInfo::Operator:
                 if(!charQueue.empty()){
                     MakeElement(charQueue , res);
                 }
                 res.push_back(WrapElement(word));
            break;
            case CharInfo::SmallAlphabet:
                charQueue.push(word);
            break;
            case CharInfo::Braces:
                if(!charQueue.empty()){
                    MakeElement(charQueue , res);
                }
                res.push_back(WrapElement(word));
            break;
            case CharInfo::Symbol:
                if(!charQueue.empty()){
                    MakeElement(charQueue , res);
                }
                res.push_back(WrapElement(word));
            break;
            case CharInfo::emoji:
                if(word == ' '){
                    charQueue.push(word);
                }
                else {
                    if (!charQueue.empty()) {
                        MakeElement(charQueue , res);
                    }
                    res.push_back(WrapElement(word));
                }
            break;
        }
    }

    if(!charQueue.empty()){
        MakeElement(charQueue , res);
    }

    res.push_back(TagList[Key::div].close);
    return res;
}

#endif //OOP_INCPLUSPLUS_HTMLHELPER_H
