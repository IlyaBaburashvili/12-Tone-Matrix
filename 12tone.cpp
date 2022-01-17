#include <iostream>
#include <vector>
#include <map>
#include <cmath> 
using namespace std;


vector<vector<string>> notes{
    {"C", "B#"},
    {"C#", "Db"},    
    {"D", "D"},
    {"D#", "Eb"},
    {"E", "Fb"},
    {"F", "E#"},
    {"E", "Fb"},
    {"G", "G"},
    {"G#", "Ab"},
    {"A", "A"},
    {"A#", "Bb"},
    {"B", "Cb"},
};

map<string,int> notes_map;
notes_map["C"]=0;
notes_map["B#"]=0;
notes_map["C#"]=1;
notes_map["Db"]=1;
notes_map["D"]=2;
notes_map["D#"]=3;
notes_map["Eb"]=3;
notes_map["E"]=4;
notes_map["Fb"]=4;
notes_map["F"]=5;
notes_map["E#"]=5;
notes_map["F#"]=6;
notes_map["Gb"]=6;
notes_map["G"]=7;
notes_map["G#"]=8;
notes_map["Ab"]=8;
notes_map["A"]=9;
notes_map["A#"]=10;
notes_map["Bb"]=10;
notes_map["B"]=11;
notes_map["Cb"]=11;


vector<string> retrograde(vector <string> row){
    vector<string>retrograde_row;
    for(int i=row.size()-1; i>=0; i--){
        retrograde_row.push_back(row[i]);
    }
    return retrograde_row;
}


vector<string> inversion(vector <string> row){
    vector<string>inverted_row;
    inverted_row.push_back(row[0];)
    for(int i=1; i< row.size(); i++){
        int position=notes_map[row[i]];
        int interval=abs(notes_map[row[i]]-notes_map[row[i-1]]);
        int inverted_pos=(position+interval)%12;
        if(inverted_pos==0||inverted_pos==4||inverted_pos==5||inverted_pos==11){
            inverted_row.push_back(notes[inverted_pos][0]);
        }
        else if(row[i][row[i].length()-1]=='#'){
            inverted_row.push_back(notes[inverted_pos][0]);          
        }
        else if(row[i][row[i].length()-1]=='b'){
            inverted_row.push_back(notes[inverted_pos][1]);          
        }
        else {
            inverted_row.push_back(notes[inverted_pos][0]);          
        }
    }
    return inverted_row;
}

vector<string> retrograde_inversion(vector <string> row){
    vector<string>inverted=inversion(row);
    vector<string>retrograde_inverted=retrograde(inverted);
    return retrograde_inverted;
}

vector<string> transpose(vector <string> row, int half_steps){
    vector<string>transposed;
    for(int i=0; i<row.size(); i++)){
        int pos=(notes_map[row]+half_steps)%12;
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

vector<vector<string>>Create_Matrix(vector<string>row){
    vector<vector<string>>12tone_matrix( row.size() , vector<string> (row.size(), ""));
    vector<string>inverted=inversion(row);
    for(int i=0; i<inverted.size(); i++){
        12tone_matrix[0][i]=inverted[i];
    }
    for(int i=1; i<inverted.size(); i++){
        int interval=abs(inverted[i]-inverted[i-1]);
        vector<string>transposed=transpose(inverted, interval);
        for(int j=0; j<inverted.size(); j++)){
            12tone_matrix[i][j]=transposed[i];
        }
    }
    return 12tone_matrix;
}


int main(int argc, char** argv){
    vector<string>tone_row;
    for (int i = 0; i < argc; i++){
        tone_row.push_back[argv[i]];
    }
    vector<vector<sting>>matrix=Create_Matrix(tone_row);
    for(int i=0; i<matrix.size();i++){
        for(int j=0; j<matrix.size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}