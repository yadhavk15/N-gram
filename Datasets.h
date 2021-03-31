#ifndef DATASETS_H_INCLUDED
#define DATASETS_H_INCLUDED
#include <string>
#include <vector>
using namespace std;

class Dataset{
private:
     vector<string> sentences;
public:
    Dataset();
    ~Dataset();
    vector<string> getSentences();

};


#endif // DATASETS_H_INCLUDED
