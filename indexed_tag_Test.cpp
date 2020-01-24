#include "indexed_tag.cpp"
#include <string>
#include <iostream>
using namespace std;

int main(){
    indexed_tag tag1;
    tag1.file_reading("dpo_new_brief.txt");
    tag1.setVector();
    tag1.vectorPrint();
}
