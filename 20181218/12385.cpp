#include <iostream>
#include <map>
using namespace std;

int main()
{
   int case_num, seq_num, item;
   while(cin >> case_num){
       for(int i=0; i<case_num; i++){
           cin >> seq_num;
           int max_seq[seq_num] = {0};
           map<int,int> index_record;
           for(int j=0; j<seq_num; j++){
               cin >> item;
               if(index_record.count(item)){
                   max_seq[j] = max(max_seq[j-1],max_seq[index_record[item]]+1);
               }
               else if(j>0){
                   max_seq[j] = max_seq[j-1];
               }
               index_record[item] = j;
           }
           cout << max_seq[seq_num-1] << endl;
           
       }
   }
   return 0;
}