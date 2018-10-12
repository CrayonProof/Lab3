#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool is_of_some(string encompassing_string, const string s){
  return s.find_first_not_of(encompassing_string) == string::npos;
}

bool string_contains(string s, char ch)
{
    for(int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ch)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    
    string fileName = argv[2];
    
    string line;
    ifstream inputFile;
    
    inputFile.open(argv[1]);
    
    set<string> wordsSet;
    vector<string> wordsVector;
    string word;
    string chari;
    
    char ch;
    fstream fin(argv[1], fstream::in);
    while (fin >> noskipws >> ch)
    {
        if (string_contains(" ,.;:!?-()", ch) || ch == '\n')
        {
            if (word != "")
            {
                wordsSet.insert(word);
            wordsVector.push_back(word);
            }
            //cout << word << endl;
            word = "";
        }
        else
        {
            word = word + ch;
        }
    }

    inputFile.close(); 
    ofstream outFileSet;
    outFileSet.open (fileName + ".txt", std::ifstream::out | std::ifstream::trunc);
    
    for (string s : wordsSet)
    {
        outFileSet << s << endl;
    }
    outFileSet.close();
    
    inputFile.close(); 
    ofstream outFileVec;
    outFileVec.open (fileName + "_vector.txt", std::ifstream::out | std::ifstream::trunc);
    
    for (string s : wordsVector)
    {
        outFileVec << s << endl;
    }
    outFileVec.close();
    
    map<string, string> wordsMap;
    wordsMap.add("", wordsVector.at(i));
    
    for (for int i = 0; i < wordsVector.size(); i++)
    {
        wordsMap.add(wordsVector.at(i), wordsVector.at(i + 1));
    }
    
    return 0;
}