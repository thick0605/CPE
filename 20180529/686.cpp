#include <iostream>

using namespace std;
bool isPrime(int);
int main()
{
   int num, i, count;
   while(cin >> num && num != 0){
       i = 2;
       count = 0;
       while(i <= num/2){
           if(isPrime(i) && isPrime(num-i)){
               count += 1;
           }
           i += 1;
       }
       cout << count << endl;
   }
   
   return 0;
}

bool isPrime(int num){
    for(int i=2; i<num; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}