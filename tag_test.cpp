#include <iostream>
#include <sstream>
#include <cstdint>
#include "tag.cpp"
using namespace std;

int main(){
    tag a1,a2;
    string str = "11112222 keep # Thisisatest";
    a1.setAll(str);
    a1.info_output();
    string str2 = "11112222 keep # Thisisatest2";
    a2.setAll(str2);
    cout<<a1.operator<(a2)<<endl;
}