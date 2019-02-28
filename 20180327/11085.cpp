#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;
void possibleChess(int col, int index, vector<int> tmp_record, int occupy[]);
vector<vector<int>> record;
int main()
{
    int occupy[8] = {0};
    possibleChess(0, 0, {}, occupy);
    stringstream ss;
    string s;
    int num, min_step, step;
    int case_num = 0;
    while(getline(cin,s)){
        case_num += 1;
        ss.clear();
        ss.str(s);
        int nums[8];
        for(int i=0; i<8; i++){
            ss >> nums[i];
        }
        min_step = 8;
        for(int i=0; i<92; i++){
            step = 0;
            for(int j=0; j<8; j++){
                if(nums[j] != record[i][j]){
                    step += 1;
                }
            }
            if(step < min_step){
                min_step = step;
            }
        }
        cout << "Case " << case_num << ": " << min_step << endl;
    }
   
   
   return 0;
}

void possibleChess(int col, int index, vector<int> tmp_record, int occupy[]){
    //cout << col << endl;
    bool tag;
    if(col == 8){
        record.push_back(tmp_record);
        //cout << "h";
        return;
    }
    else{

        for(int i=0; i<8; i++){
            tag = true;
            for(int j=0; j<tmp_record.size(); j++){
                if((col+i) == (j+tmp_record[j]-1) || (7-col+i) == (7-j+tmp_record[j]-1)){
                    tag = false;
                    break;
                }
            }
            if(tag &&  occupy[i] == 0){
                occupy[i] = 1;
                tmp_record.push_back(i+1);
                possibleChess(col+1, i, tmp_record, occupy);
                tmp_record.pop_back();
                occupy[i] = 0;
            }
        }
    }
}