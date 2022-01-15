//
// Created by 97152 on 26/12/2021.
//

#ifndef OOP_INCPLUSPLUS_TAG_H
#define OOP_INCPLUSPLUS_TAG_H

#include "Utilities.h"

class Tag{ public: std::string open , close;};

enum class Key{
    p , small,
    h1 , h2 ,h3 , h4, h5 , h6 ,
    div , span ,
    code
};

std::map<Key,Tag> TagList = {
        {Key::p  , Tag{"<p>"  ,  "</p>"    }},
        {Key::h1 , Tag{"<h1>" ,  "</h1>"   }},
        {Key::h2 , Tag{"<h2>" ,  "</h2>"   }},
        {Key::h3 , Tag{"<h3>" ,  "</h3>"   }},
        {Key::h4 , Tag{"<h4>" ,  "</h4>"   }},
        {Key::h5 , Tag{"<h5>" ,  "</h5>"   }},
        {Key::h6 , Tag{"<h6>" ,  "</h6>"   }},
        {Key::div , Tag{"<div>",   "</div>"}},
        {Key::span , Tag{"<span>",   "</span>"}},
        {Key::code ,Tag{"<code>" , "</code>"}},
        {Key::small ,Tag{"<small>" , "</small>"}},
};


void GetStarterHtml(std::vector<std::string> &vec,std::string &title){
    vec.push_back("<!DOCTYPE html>");
    vec.push_back("<html>");
    vec.push_back("<head>");
    vec.push_back("<title>" + title +"</title>");
    vec.push_back("</head>");
    vec.push_back("<body>");
}

void GetEndHtml(std::vector<std::string> &vec){
    vec.push_back("<script>");
    vec.push_back("alert('Hey')");
    vec.push_back("</script>");
    vec.push_back("</body>");
    vec.push_back("</html>");
}
#endif //OOP_INCPLUSPLUS_TAG_H
