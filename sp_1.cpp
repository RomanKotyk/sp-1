/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>

using namespace std;

void countWords(ifstream& inputFile){
    map<string, int> wordCount;
    
    regex wordRegex("\\b\\w{1,30}\\b");

    string line;
    while (getline(inputFile, line)) {
        
        auto wordsBegin = sregex_iterator(line.begin(), line.end(), wordRegex);
        auto wordsEnd = sregex_iterator();

        for (sregex_iterator k = wordsBegin; k != wordsEnd; ++k) {
            smatch match = *k; 
            string word = match.str(); 
            wordCount[word]++;
        }
    }

    map<string, int>::iterator it = wordCount.begin();
 
    while (it != wordCount.end()) {
        cout << it->first << ": " << it->second << endl;
        ++it;
    }
    
    cout<<"---------------------------"<<endl;
}

int main() {
    ifstream inputFile("input2.txt");
    if (!inputFile.is_open()) {
        cerr << "Unable to open input file." << endl;
        return 1;
    }

    countWords(inputFile);
    
    return 0;
}

