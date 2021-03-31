#include "datasets.h"
#include <fstream>
Dataset:: Dataset(){

}
Dataset:: ~Dataset(){

}
vector<string> Dataset:: getSentences(){
    ifstream f("CreoleSentences.txt");
    string text;
    while(true){
        getline(f,text);
        if(f.eof())
            break;
        sentences.push_back(text);
    }

    f.close();
    return sentences;
}
