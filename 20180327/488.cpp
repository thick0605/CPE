#include <iostream>

using namespace std;

int main()
{
   int C, A, F, index;
   while(cin >> C){
       for(int i=0; i<C; i++){
           cin >> A >> F;
           for(int j=0; j<F; j++){
               for(int k=1; k<=2*A-1; k++){
                  
                   if(k > A){
                       index = 2*A-k;
                   }
                   else{
                       index = k;
                   }
                   int l = 1;
                   while(l<=index){
                       cout << index;
                       l += 1;
                   }
                   cout << endl;
               }
               if(j<F-1){
                   cout << endl;
               }
               
           }
           if(i<C-1){
               cout << endl;
           }
       }
   }
   
   return 0;
}