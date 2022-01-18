#include <iostream>
#include <vector>
using namespace std;

#include "12tone.cpp"

int main(int argc, char** argv){
    vector<string> tone_row;
    for (int i = 1; i < argc; i++){
        tone_row.push_back(argv[i]);
    }
    TwelveToneMatrix m(tone_row);
    vector<vector<string>>matrix=m.Create_Matrix(tone_row);
    for(int i=0; i<matrix.size();i++){
        for(int j=0; j<matrix.size(); j++){
            cout << matrix[i][j] << " ";
            if(matrix[i][j].length()==1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
