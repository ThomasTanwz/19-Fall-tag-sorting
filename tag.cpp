#include <iostream>
#include <sstream>
using namespace std;
#include <cstdint>

// tag has following variables: group, element, code and keyword.
// set up constants for code reading.
const size_t KEEP_CODE(1);
const size_t ANON_CODE(2);
// declare an empty tag object, a tag object to process each single line, and a function to print the current tag's content.
class tag{
    unsigned int group;
    unsigned int element;
    unsigned int code;
    string keyword;
    public:
    tag();
    void setAll(const string &str);
    void set_group_element(const string &str);
    void set_code_keyword(const string &str);
    void info_output();
    int compare_group_element(const tag& a, const tag& b);
    string tagKeyword();
    bool operator=(const tag &b);
    bool operator>(const tag &b);
    bool operator<(const tag &b);
};

//empty constructor
tag::tag(): group(0), element(0), code(0), keyword(""){

}

void tag::setAll(const string &str){
    set_code_keyword(str);
    set_group_element(str);
}

void tag::set_group_element(const string &str){
    string a;
    for(int i = 0; str[i] != ' '; i++){
        a += str[i];
    }
    string g = a.substr(0,4);
    string e = a.substr(4,4);
    stringstream groupString, elementString;
    groupString << std::hex<< g;
    elementString << std::hex<< e;
    groupString >> group;
    elementString >> element;
}

void tag::set_code_keyword(const string &str){
    int i,j,k;
    string strcode;
    for(i = 0; str[i] != ' '; i++){
       
    }
    for(j = i + 1; str[j] != ' '; j++){
       
    }
    strcode = str.substr(i+1,j - (i+1));
    if(strcode == ""){
        code = 0;
    } else if (strcode == "anon"){
        code = ANON_CODE;
    } else if (strcode == "keep"){
        code = KEEP_CODE;
    } else if (strcode == "null"){
        code = 3;
    } else {
        code = 4;
    }
    for(k = j + 1; str[k] != ' '; k++){
       
    }
    keyword = str.substr(k+1, str.length() - (k+1));
}

void tag::info_output(){
    cout<<"group: "<<group<<endl;
    cout<<"element: "<<element<<endl;
    cout<<"code: "<<code<<endl;
    cout<<"keyword: "<<keyword<<endl;
}

bool tag::operator=(const tag &b){
    return keyword.compare(b.keyword) == 0;
}

bool tag::operator>(const tag &b){
    return keyword.compare(b.keyword) > 0;
}

bool tag::operator<(const tag &b){
    return keyword.compare(b.keyword) < 0;
}

string tag::tagKeyword(){
    return keyword;
}

int tag::compare_group_element(const tag& a, const tag& b){
    if(a.group > b.group){
        return 1;
    } 
    //a.group <= b.group
    if(a.group == b.group){
        if(a.element > b.element){
            return 1;
        }
        if(a.element == b.element){
            return 0;
        }
    }
    //a.group < b.group
    return -1;
}






