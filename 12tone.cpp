#include <iostream>
#include <vector>
#include <map>
#include <cmath> 
#include "12tone.hpp"
using namespace std;

TwelveToneMatrix::TwelveToneMatrix(vector <string> input){
     notes={
        {"C", "B#"},
        {"C#", "Db"},    
        {"D", "D"},
        {"D#", "Eb"},
        {"E", "Fb"},
        {"F", "E#"},
        {"F#", "Gb"},
        {"G", "G"},
        {"G#", "Ab"},
        {"A", "A"},
        {"A#", "Bb"},
        {"B", "Cb"},
    };


    notes_map={
    {"C", 0},
    {"B#", 0},
    {"C#", 1},
    {"Db", 1},
    {"D", 2},
    {"D#", 3},
    {"Eb", 3},
    {"E", 4},
    {"Fb", 4},
    {"F", 5},
    {"E#", 5},
    {"F#", 6},
    {"Gb", 6},
    {"G", 7},
    {"G#", 8},
    {"Ab", 8},
    {"A", 9},
    {"A#", 10},
    {"Bb", 10},
    {"B", 11},
    {"Cb", 11},
    };

    tone_row=input;

}


    vector<string> TwelveToneMatrix::retrograde(vector <string> row){
        vector<string>retrograde_row;
        for(int i=row.size()-1; i>=0; i--){
            retrograde_row.push_back(row[i]);
        }
        return retrograde_row;
    }


    vector<string> TwelveToneMatrix::inversion(vector <string> row){
        vector<string>inverted_row(row.size());
        inverted_row[0]=row[0];
        for(int i=1; i< row.size(); i++){
            int position=notes_map[inverted_row[i-1]];
            int interval=notes_map[row[i-1]]-notes_map[row[i]];
            int inverted_pos=(position+interval);
            if(inverted_pos>11){
                inverted_pos=inverted_pos%12;
            }
            else if(inverted_pos<0){
                inverted_pos+=12;
            }
            if(inverted_pos==0||inverted_pos==4||inverted_pos==5||inverted_pos==11){
                inverted_row[i]=notes[inverted_pos][0];
            }
            else if(row[i][row[i].length()-1]=='#'){
                inverted_row[i]=notes[inverted_pos][0];          
            }
            else if(row[i][row[i].length()-1]=='b'){
                inverted_row[i]=notes[inverted_pos][1];          
            }
            else {
                inverted_row[i]=notes[inverted_pos][0];          
            }
        }
        return inverted_row;
    }

    vector<string> TwelveToneMatrix::retrograde_inversion(vector <string> row){
        vector<string>inverted=inversion(row);
        vector<string>retrograde_inverted=retrograde(inverted);
        return retrograde_inverted;
    }

    vector<string> TwelveToneMatrix::transpose(vector <string> row, int half_steps){
        vector<string>transposed;
        for(int i=0; i<row.size(); i++){
            int pos=(notes_map[row[i]]+half_steps)%12;
            if(pos<0){
                pos+=12;
            }
            if(pos==0||pos==4||pos==5||pos==11){
                transposed.push_back(notes[pos][0]);
            }
            else if(row[i][row[i].length()-1]=='#'){
                transposed.push_back(notes[pos][0]);          
            }
            else if(row[i][row[i].length()-1]=='b'){
                transposed.push_back(notes[pos][1]);          
            }
            else {
                transposed.push_back(notes[pos][0]);          
            }
        }
        return transposed;
    }

    vector<vector<string>> TwelveToneMatrix::Create_Matrix(vector<string>row){
        vector<vector<string>> tone_matrix( row.size() , vector<string> (row.size(), ""));
        vector<string>inverted=inversion(row);
        
        for(int i=0; i<row.size(); i++){
            tone_matrix[0][i]=row[i];
        }
        for(int i=1; i<inverted.size(); i++){
            int interval=notes_map[inverted[i]]-notes_map[row[0]];
            vector<string>transposed=transpose(row, interval);
            for(int j=0; j<inverted.size(); j++){
                tone_matrix[i][j]=transposed[j];
            }
        }
        return tone_matrix;
    }
