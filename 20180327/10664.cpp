#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
bool equalWeight(vector<int> nums, int index, int remain);
int main(){
    int case_num, num, total;
    stringstream ss;
    string s;
    cin >> case_num;
    getline(cin, s); // read the return line symbol
    for (int i=0; i<case_num; i++)
    {
        getline(cin, s);
        ss.clear();
        ss.str(s);
        vector<int> nums;
        total = 0;
        while (ss >> num)
        {
            nums.push_back(num);
            total += num;
        }
        if(total%2 != 0){
            cout << "NO" << endl;
        }
        else{
            if(equalWeight(nums,0,total/2)){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

bool equalWeight(vector<int> nums, int index, int remain){
    if(remain == 0){
        return true;
    }
    else if(remain < 0){
        return false;
    }
    else{
        for(int i=index+1; i<nums.size(); i++){
            if(equalWeight(nums, i, remain-nums[i])){
                return true;
            }
        }
        return false;
    }
}
