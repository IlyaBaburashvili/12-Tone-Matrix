#ifndef TWELVE_TONE_
#define TWELVE_TONE_


#include <iostream>
#include <map>
#include <vector>
using namespace std;

class TwelveToneMatrix{
public:

    TwelveToneMatrix(vector <string> input);
    vector<string> retrograde(vector <string> row);
    vector<string> inversion(vector <string> row);
    vector<string> retrograde_inversion(vector <string> row);   
    vector<string> transpose(vector <string> row, int half_steps);
    vector<vector<string>> Create_Matrix(vector<string>row);



private:

    vector<vector<string>> notes;
    map<string,int> notes_map;
    vector<string> tone_row;
};
#endif
