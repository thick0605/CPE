#include <iostream>
#include <algorithm>
using namespace std;
void checkSquare(int[]);
int main()
{
   int N;
   long long total, sum;
   while(cin >> N){
       total = 0;
       sum = 0;
       for(int i=1; i<=N; i=i+2){
           total += i;
       }
       if(total > 1){
           sum = 3*(2*total-1)-6;
       }
       else{
           sum = 1;
       }
       cout << sum << endl;
   }
}