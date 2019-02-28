#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;
long long fib[50];
void fibPrint(long long, long long, long long);
int main()
{
   int case_num;
   long long index, start, end;
   fib[0] = 1, fib[1] = 1;
   for(int i=2; i<50; i++){
       fib[i] = fib[i-2]+fib[i-1];
   }
   cin >> case_num;
   for(int i=0; i<case_num; i++){
       cin >> index >> start >> end;
       if(index > 48){
           index = 48 - (index%2);
       }
       fibPrint(index,start,end);
       cout << endl;
       
   }
   
   return 0;
}

void fibPrint(long long index, long long start, long long end){
    if(start > end){
        return;
    }
    else if(index == 0){
        cout << "0";
    }
    else if(index == 1){
        cout << "1";
    }
    else{
        if(start < fib[index-2]){
            fibPrint(index-2, start, min(end,fib[index-2]-1));
            fibPrint(index-1, 0,end-fib[index-2]);
        }
        else{
            fibPrint(index-1, start-fib[index-2],end-fib[index-2]);
        }
    }
}