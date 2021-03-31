#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void onegram(vector <string>separatedwords, vector <string>&ngrams ,vector <int>&counting){
    for(int a=0; a<separatedwords.size(); a++){
            if(find(ngrams.begin(), ngrams.end(), separatedwords[a]) == ngrams.end()){
                ngrams.push_back(separatedwords[a]);
                counting.push_back(1);
            }
            else{
                ptrdiff_t pos = find(ngrams.begin(), ngrams.end(), separatedwords[a]) - ngrams.begin();
                counting[pos]= counting.at(pos)+1;
            }
        }
}

void bigram(vector <string>separatedwords, vector <string>&ngrams ,vector <int>&counting){
    string pairs="";
    for(int a=0; a<separatedwords.size()-1; a++){
            for(int b=a+1; b<a+2; b++){
                pairs=separatedwords[a]+" "+separatedwords[b];
                if(find(ngrams.begin(), ngrams.end(), pairs) == ngrams.end()){
                    ngrams.push_back(pairs);
                    counting.push_back(1);
                }
                else{
                    ptrdiff_t pos = find(ngrams.begin(), ngrams.end(), pairs) - ngrams.begin();
                    counting[pos]= counting.at(pos)+1;
                }
            }
        }
}

void trigram(vector <string>separatedwords, vector <string>&ngrams ,vector <int>&counting){
    if(separatedwords.size()>=2){
    int c;
    string trio="";
    for(int a=0; a<separatedwords.size()-2; a++){
            for(int b=a+1, c=a+2; b<a+2; b++, c++){
                trio=separatedwords[a]+" "+separatedwords[b]+" "+separatedwords[c];
                if(find(ngrams.begin(), ngrams.end(), trio) == ngrams.end()){
                    ngrams.push_back(trio);
                    counting.push_back(1);
                }
                else{
                    ptrdiff_t pos = find(ngrams.begin(), ngrams.end(), trio) - ngrams.begin();
                    counting[pos]= counting.at(pos)+1;
                }
            }
        }
    }
}

void CollocationPair(vector <string>separatedwords, vector <string>&ngrams ,vector <int>&counting){
    string pairs="";
    for(int a=0; a<separatedwords.size()-1; a++){
            for(int b=a+1; b<separatedwords.size()-1; b++){
                pairs=separatedwords[a]+" "+separatedwords[b];
                if(find(ngrams.begin(), ngrams.end(), pairs) == ngrams.end()){
                    ngrams.push_back(pairs);
                    counting.push_back(1);
                }
                else{
                    ptrdiff_t pos = find(ngrams.begin(), ngrams.end(), pairs) - ngrams.begin();
                    counting[pos]= counting.at(pos)+1;
                }
            }
        }
}
void CollocationTrio(vector <string>separatedwords, vector <string>&ngrams ,vector <int>&counting){
//if sentence has less than 3 words, you cant form a trigram. So system will crash. thats why we break the loop if there are only 2 words
        if(separatedwords.size()>=2){
            int c;
            string trio="";
            for(int a=0; a<separatedwords.size()-2; a++){
                for(int b=a+1, c=a+2; b<separatedwords.size()-1; b++, c++){
                    trio=separatedwords[a]+" "+separatedwords[b]+" "+separatedwords[c];
                    if(find(ngrams.begin(), ngrams.end(), trio) == ngrams.end()){
                        ngrams.push_back(trio);
                        counting.push_back(1);
                    }
                    else{
                        ptrdiff_t pos = find(ngrams.begin(), ngrams.end(), trio) - ngrams.begin();
                        counting[pos]= counting.at(pos)+1;
                    }
                }
            }
        }
    }

