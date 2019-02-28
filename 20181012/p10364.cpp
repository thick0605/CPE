#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
bool findSum(int[], int[], int, int, int, int);
int main()
{
   int N, M;
   while(cin >> N){
       for(int i=0; i<N; i++){
           cin >> M;
           int sticks[M];
           int take[M];
           int total_len = 0;
           int square_len = 0;
           for(int j=0; j<M; j++){
               cin >> sticks[j];
               total_len += sticks[j];
               take[j] = 1;
           }
           sort(sticks,sticks+M);
           if(total_len % 4 or sticks[M-1] > total_len/4){
                cout << "no" << endl;
            }
            else{
                square_len = total_len/4;
                if(findSum(sticks, take, 0, square_len, 0, M)){
                    cout << "yes" << endl;
                }
                else{
                    cout << "no" << endl;
                }
            }
        }
   }
}

bool findSum(int sticks[], int take[], int cur_sum , int l, int start_index, int M){
    int remain_element = 0;
    for(int i=0; i<M; i++){
        remain_element += take[i];
    }
    if(remain_element == 0){
        return true;
    }
    for(int i=start_index; i<M; i++){
        if(cur_sum+sticks[i] <= l && take[i]){
            take[i] = 0, cur_sum += sticks[i];
            if(cur_sum == l){
                if(findSum(sticks, take, 0, l, 0, M)){
                    return true;
                }
                else{
                    take[i] = 1, cur_sum -= sticks[i];
                }
            }
            else if(findSum(sticks, take, cur_sum, l, i+1, M)){
                return true;
            }
            else{
                take[i] = 1, cur_sum -= sticks[i];
            }
        }
    }
    return false;
}