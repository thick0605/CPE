#include <iostream>
#include <vector>
using namespace std;
bool checkOrder(int[], int);
int main()
{
   int B;
   bool break_tag;
   while(cin>>B && B!=0){
       break_tag = false;
       int orders[B];
       while(true){
           for(int i=0; i<B; i++){
               cin >> orders[i];
               if(orders[0] == 0){
                   break_tag = true;
                   break;
               }
           }
           if(break_tag){
               break;
           }
           else{
               if(checkOrder(orders, B)){
                   cout << "Yes" << endl;
               }
               else{
                   cout << "No" << endl;
               }
           }
       }
       cout << endl;
   }
   
   return 0;
}

bool checkOrder(int orders[], int B){
    vector<int> stations;
    int block_index = 1;
    int i = 0;
    while(i<B){
        if(stations.empty() || stations.back()<orders[i]){
            while(block_index < orders[i]){
                stations.push_back(block_index);
                block_index += 1;
            }
            i += 1;
            block_index += 1;
        }
        else if(stations.back() == orders[i]){
            stations.pop_back();
            i += 1;
        }
        else if(stations.back() > orders[i]){
            return false;
        }
    }
    return true;
}