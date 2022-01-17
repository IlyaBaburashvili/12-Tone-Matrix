#include <iostream>
#include "12tone.hpp"
#include <vector>
using namespace std;


int main(int argc, char** argv){
    vector<string>tone_row;
    for (int i = 0; i < argc; i++){
        tone_row.push_back[argv[i]];
    }
    TwelveToneMatrix m(tone_row);
    vector<vector<string>>matrix=m.Create_Matrix(tone_row);
    for(int i=0; i<matrix.size();i++){
        for(int j=0; j<matrix.size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
