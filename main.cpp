#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Datasets.cpp"
#include "ngramsFunctions.cpp"
using namespace std;

int main(){
    vector<string> separatedwords, ngrams;
    vector<int> counting;
    string word="",currentsentence;

    Dataset d;
    vector<string> allSentences = d.getSentences();
    /*verifying dataset
    for(int i=0; i<allSentences.size(); i++)
        cout<<i<<" "<<allSentences[i]<<endl;
    */
    int choice, ngramSelector,topo;
    cout<<"************************************************************************************************"<<endl;
    cout<<"*                                                                                              "; cout<<"*"<<endl;
    cout<<"*                               N-grams and Collocations                                       *"<<endl;
    cout<<"*                                                                                              "; cout<<"*"<<endl;
    cout<<"************************************************************************************************"<<endl;
    cout<<"*                                                                                              "; cout<<"*"<<endl;
    cout<<"*N-grams are simply all combinations of adjacent n words that you can find in your source text.*"<<endl;
    cout<<"*                                                                                              "; cout<<"*"<<endl;
    cout<<"************************************************************************************************"<<endl;
    cout<<"*                                                                                              "; cout<<"*"<<endl;
    cout<<"*          Collocation refers to a group of n words that usually go together.                  *"<<endl;
    cout<<"*                                                                                              "; cout<<"*"<<endl;
    cout<<"************************************************************************************************"<<endl;
    cout<<"*Enter 1 for N-grams                                                                           *"<<endl;
    cout<<"*Enter 2 for Collocations                                                                      *"<<endl;
    cout<<"*";cin>>choice;
    cout<<"************************************************************************************************"<<endl;
    cout<<"*Which type of N-gram or Collocation you want?                                                 *"<<endl;
    cout<<"*Enter 1 for 1-Gram or 1 word collocation                                                      *"<<endl;
    cout<<"*Enter 2 for 2-Gram or 2 words Collocation                                                     *"<<endl;
    cout<<"*Enter 3 for 3-Gram or 3 words Collocation                                                     *"<<endl;
    cout<<"*";cin>>ngramSelector;
    cout<<"************************************************************************************************"<<endl;
    cout<<"*How many most occuring N-grams or Collocations do you wanna display                           *"<<endl;
    cout<<"*";cin>>topo;
    cout<<"************************************************************************************************"<<endl;

    for(int i=0; i<allSentences.size(); i++){
        currentsentence=allSentences[i];
        for(int j=0; j<currentsentence.size();j++){
            //need to convert each char to lowercase
            char lowercase= tolower(currentsentence[j]);
            if((lowercase==' ')||(lowercase=='.')||(lowercase=='?')||(lowercase=='!')){
                separatedwords.push_back(word);
                word="";
            }
            else{
                word=word+lowercase;
            }
        }
            if((word != "")&&(word !=" "))
                separatedwords.push_back(word);

        switch(choice){
        case 1:
            switch(ngramSelector){
                case 1: onegram(separatedwords,ngrams ,counting);
                break;
                case 2: bigram(separatedwords,ngrams ,counting);
                break;
                case 3: trigram(separatedwords,ngrams ,counting);
                break;
                default: cout<<"Input should be only 1 to 3"<<endl;
            }
        break;
        case 2:
            switch(ngramSelector){
                case 1: onegram(separatedwords,ngrams ,counting);
                break;
                case 2: CollocationPair(separatedwords,ngrams ,counting);
                break;
                case 3: CollocationTrio(separatedwords,ngrams ,counting);
                break;
                default: cout<<"Input should be only 1 to 3"<<endl;
            }
        break;
        default: cout<<"Only input 1 and 2 are allowed";
        }
        separatedwords.clear();
    }
    //output the ngrams
    vector<string> top;
    vector<int> score;
    int largest=0,index;
    int size=ngrams.size();

    for(int y=0;y<topo;y++){
        for(int i=0;i<size;i++){
            if(counting[i]>=largest){
                largest=counting[i];
                index=i;
         }
    }
    top.push_back(ngrams[index]);
    score.push_back(counting[index]);
    counting.erase(counting.begin()+index);
    ngrams.erase(ngrams.begin()+index);
    size--;
    largest=0;
}
    for(int k=0;k<topo;k++){
    cout<<k+1<<"."<<top[k]<<"\t\t"<<score[k]<<endl;
    }

    cout<<"************************************************************************************************"<<endl;
    return 0;

}
