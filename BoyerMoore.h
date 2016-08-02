//
// Created by lenovo on 8/1/2016.
//

#ifndef GRP07_ALGDATII_BOYERMOORE_H
#define GRP07_ALGDATII_BOYERMOORE_H
#include <string>
#include <map>

using namespace std;

class BoyerMoore {

private:

    string pattern;
    string text;
    string htmlOutput;
    int counter;
    map<char,int> badMatchTable;

    void writeHtmlFile();
    void run();

    void generateBadMatchTable(string pattern);
    int boyerMooreSearch(string text);

public:

    BoyerMoore(string t, string p) : text(t), pattern(p){
        run();
    }

};



#endif //GRP07_ALGDATII_BOYERMOORE_H
