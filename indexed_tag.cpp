#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "tag.cpp"

using namespace std;

class indexed_tag: public tag{
    public:
    indexed_tag();
    void file_reading(string fileName);
    void singlePrint();
    void vectorPrint();
    void setVector();


    private:
    int index_count;
    int index;
    vector<indexed_tag> indexed_tag_vector;
    vector<string> string_vector;
    
};

indexed_tag::indexed_tag(): index_count(0), index(0), tag(){

}

void indexed_tag::singlePrint(){
    cout<<index<<endl;
    info_output();
    cout<<endl;
}

void indexed_tag::file_reading(string fileName){
    ifstream myfile;
    myfile.open(fileName);
    for(string line; getline(myfile,line);){
        if(line[0] == '#'){
            continue;
        }
        string_vector.push_back(line);
        index_count ++;
    }
}

void indexed_tag::setVector(){
    for(int i = 0; i < index_count; i++){
        index = i;
        setAll(string_vector[i]);
        indexed_tag_vector.push_back(*this);
    }
}

void indexed_tag::vectorPrint(){
    for(int i = 0; i < indexed_tag_vector.size(); i++){
        indexed_tag_vector[i].singlePrint();
        cout<<endl;
    }
}