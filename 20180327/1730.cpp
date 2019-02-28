#include <iostream>
#include <math.h>
#include <map>
using namespace std;
int MSCLM(int);
int main()
{
   long long num, l, r, factor, result;
   while(cin >> num && num != 0){
       result = 0;
       l = 1;
       while(l < num){
           factor = num / l;
           r = num / factor;
           result += factor*(l+r)*(r-l+1)/2;
           l = r+1;
       }
       cout << result-1 << endl;
   }
   return 0;
}