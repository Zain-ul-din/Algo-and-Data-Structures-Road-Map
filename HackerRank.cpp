#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>


void ReadInput (std::string& string) {
    std::cin.sync();
    std::getline (std::cin , string);
}

/*
4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value
*/

class Tag {
    public:
      Tag (std::string htmlCode) {
          for (int i = 0 ; i < htmlCode.length() ; i += 1) {
            if (htmlCode[i] == '<') {
                i += 1;
                for ( ; htmlCode[i] != '>' || htmlCode[i] != ' ' ; i ++) {
                    tagName += htmlCode[i];
                    std::cout << htmlCode [i] << " ";
				}
            }
            
            if (!tagName.empty()) { // find attributes
              std::string attr_name , attr_val;
              for ( ; htmlCode[i] != '=' || htmlCode[i] != ' ' ; i += 1) {
                  if (htmlCode[i] != ' ') {
                      attr_name += htmlCode[i];
                  }
              }
              
              // Grab Value
              std::stack<char> stack;
              stack.push (htmlCode[i]);
              
              if (stack.top() == '"') {
                  while (!stack.empty())
                    if (stack.top() != '"')
                      attr_val += stack.top();
              }
              attributes.insert({attr_name , attr_val}); // add to map
            }
          }
      }
      std::string tagName ;
      std::map < std::string , std::string > attributes;
};

void Parser (
    std::vector<Tag>& html ,
    std::vector<std::string>& quries,
    std::string &input ,
    int tagsLen , int queriesLen
) {
    std::stack<char> stack;
    for (int i = 0 ; i < input.length() ; i += 1) {
        stack.push(input [i]);
    	if (stack.top() != '<') stack.pop ();
        if (input[i] == '>' && stack.top()  == '<') { // end of the tag
            std::string tag;
            while (!stack.empty()) tag += stack.top();
            Tag _tag (tag);
            if (!_tag.tagName.empty())
               html.push_back(_tag);
        }
    }
}

int main() {  
     std::cout << "Enter Input : ";
    std::vector <Tag> html;
    std::vector<std::string> quries;
    std::string input;
    ReadInput(input);
    int tagsLen , queriesLen;
    Parser (html , quries , input , tagsLen , queriesLen);
    
    for (auto tag : html)
	std::cout << tag.tagName << "\n";
    return 0;
}
