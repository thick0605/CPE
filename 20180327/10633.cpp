#include <iostream>

using namespace std;

int main()
{
   long long R, R_9, R_res;
   while(cin >> R and R!=0){
       if(R % 9 == 0){
           cout << R/9*10-1 << " " << R/9*10;
       }
       else{
           R_9 = ((R/9)+1)*9;
           R_res = R_9 - R;
           cout << R_9/9*10-1-R_res;
       }
       cout << endl;
   }
   
   return 0;
}