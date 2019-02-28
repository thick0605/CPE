#include <iostream>
#include <algorithm>
using namespace std;
struct AD{
  int start;
  int floors;
  int profit;
};
bool compare(struct AD ad1, struct AD ad2){
    if(ad1.floors < ad2.floors){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
   int T, N;
   cin >> T;
   for(int j=0; j<T; j++){
       cin >> N;
       struct AD ads[N];
       int profit[200001] = {0};
       for(int i=0; i<N; i++){
           cin >> ads[i].start;
           cin >> ads[i].floors;
           cin >> ads[i].profit;
           ads[i].floors = ads[i].start+ads[i].floors-1;
       }
       sort(ads,ads+N,compare);
       int cur_floor = 0;
       int i = 0;
       while(i < N){
           if(cur_floor == ads[i].floors){
               if(ads[i].start == 0){
                   profit[cur_floor] = max(profit[cur_floor],ads[i].profit);
               }
               else{
                   profit[cur_floor] = max(profit[cur_floor],profit[ads[i].start-1]+ads[i].profit);
               }
               i += 1;
           }
           else{
               cur_floor += 1;
               profit[cur_floor] = profit[cur_floor-1];
           }
       }
       cout << "Case " << j+1 << ": " << profit[cur_floor] << endl;
   }
   
   return 0;
}