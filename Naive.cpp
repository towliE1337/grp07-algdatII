
#include <iostream>
#include <fstream>
#include <chrono>
#include "Naive.h"

int Naive::doNaiveAlgorithmn(string subText) const {
        int i=0;
        int j=0;
        int k=0;
        while(i < subText.length() && j < pattern.length()){
            if(subText[i] == pattern[j]){
                i++;
                j++;
            }else{
                j=0;
                k++;
                i = k;
            }
        }
        if(j == pattern.length()){
            return k+j;
        }
        return -1;
}

void Naive::writeHtmlFile() {
    ofstream myfile;
    myfile.open (pattern + ".html");
    myfile << "<html><head><style>.p-colored em {background: #7FFF00;}</style></head><body><div class=\"p-colored\"><h1>Suche nach Pattern (\"";
    myfile << pattern;
    myfile << "\") ergab ";
    myfile << counter;
    myfile << " Treffer</h1>";
    if(!perfomanceTest) {
        myfile << "<h1> Ben&ouml;tigte Zeit: ";
        myfile << elapsedTime;
        myfile << " (Microsekunden) </h1>";
    }
    myfile << htmlOutput;
    myfile << "</div></body></html>";
    myfile.close();   
}

vector<int> Naive::run() {
    
    chrono::steady_clock::time_point startTime; 
    chrono::steady_clock::time_point endTime;
    chrono::duration<double, std::micro> elapsedTime;

    // hold all resulting indices
    vector<int> indices = {};

    int result = 0;
    int alreadyCutOff = 0;

    counter = 0;
    htmlOutput = "";
    
    string subText = string(text);
    
    while(result >= 0) {

        startTime = chrono::steady_clock::now();
        result = doNaiveAlgorithmn(subText);
        endTime = chrono::steady_clock::now();

        elapsedTime += (endTime-startTime);

        if(result >= 0) {

            indices.push_back(alreadyCutOff+((result-pattern.length())));
            htmlOutput += subText.substr(0, result-pattern.length());
            htmlOutput += "<em>" + pattern + "</em>";

            cout << "Pattern found at Index: ";
            cout << alreadyCutOff+((result-pattern.length()));
            cout << " - ";
            cout << alreadyCutOff+result;
            cout << "\n";

            alreadyCutOff += result;
            subText = subText.substr(result);
            counter++;
            
       } else {
          htmlOutput += subText;
       }
    } 
    
    cout << "\nPattern found ";
    cout << counter;
    cout << " times\n";

    this->elapsedTime = elapsedTime.count();
    writeHtmlFile();

    return indices;
}
