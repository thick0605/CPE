#include <iostream>
#include <math.h>
#include <string>
using namespace std;
long countOnes(long ones[], int num);
int main(int argc, const char * argv[]) {
    // insert code here...
    int T, N, D, cur_stone, step;
    int case_num = 0;
    string stone_type;
    while(cin >> T){
        for(int j=0; j<T; j++){
            cin >> N >> D;
            int last_stone = 0;
            int left_bank = 0;
            int max_dist = 0;
            for(int i=0; i<N; i++){
                cin >> stone_type;
                step = atoi(stone_type.substr(2, stone_type.size()).c_str());
                if(stone_type[0]=='B'){
                    
                    max_dist = max(last_stone+step-left_bank,max_dist);
                    last_stone = 0;
                }
                else{
                    cur_stone = step-left_bank;
                    max_dist = max(last_stone+cur_stone,max_dist);
                    last_stone = cur_stone;
                    
                }
                left_bank = step;
            }
            max_dist = max(last_stone+D-step,max_dist);
            cout << "Case " << j+1 << ": " << max_dist << endl;
        }
        
    }
    return 0;
}
