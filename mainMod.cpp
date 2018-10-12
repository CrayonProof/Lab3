#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <ctime> 
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
        if (ch == ' ')
        {
            if (word != "")
            {
                wordsSet.insert(word);
            wordsVector.push_back(word);
            }
            //cout << word << endl;
            word = "";
        }
        else  if (ch == '\n')
        {
            if (word != "")
            {
              word = word + '\n';
              
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
   wordsMap.insert(pair<string, string>("", wordsVector.at(0)));
    
    for (int i = 0; i < wordsVector.size() -1; i++)
    {
        wordsMap.insert(pair<string, string>(wordsVector.at(i), wordsVector.at(i + 1)));
    }
    
    inputFile.close(); 
    ofstream outFileMap;
    outFileMap.open (fileName + "_1_1", std::ifstream::out | std::ifstream::trunc);
    
    for(auto p : wordsMap)
    {
       outFileMap << p.first << ", " << p.second << "\n";
    }
    outFileMap.close();
    
    string state = "";
    for(int i = 0; i < 100; i++){
      cout << wordsMap[state] << " ";
      state = wordsMap[state];
    }
    cout << endl <<endl;
    
    map<string, vector<string>> wordsMap2;
    string state2 = "";
    for(vector<string>::iterator it=wordsVector.begin(); it !=wordsVector.end(); it++)
    {
      wordsMap2[state2].push_back(*it);
      state2 = *it;
    }
    
    srand(time(NULL)); // this line initializes the random number generated
                   // so you dont get the same thing every time
    state = "";
    for (int i = 0; i < 100; i++) {
      int ind = rand() % wordsMap2[state].size();
      cout << wordsMap2[state][ind] << " ";
      state = wordsMap2[state][ind];
    }
    
    cout << endl << endl;
    
    int M=2;
      map<list<string>, vector<string>> wordsMap3;
      list<string> st;
      for (int i = 0; i < M; i++) {
        st.push_back("");
      }
                            
      for (vector<string>::iterator it=wordsVector.begin(); it!=wordsVector.end(); it++) {
        wordsMap3[st].push_back(*it);
        st.push_back(*it);
        st.pop_front();
      }
      
      st.clear();
      for (int i = 0; i < M; i++) {
        st.push_back("");
      }
      for (int i = 0; i < 100; i++) {
        int ind = rand() % wordsMap3[st].size();
        cout << wordsMap3[st][ind]<<" ";
        st.push_back(wordsMap3[st][ind]);
        st.pop_front();
      }

    return 0;
}