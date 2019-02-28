#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
   long long num;
   int result;
   int case_num = 0;
   string words[4] = {"kuti", "lakh", "hajar", "shata"};
   int basis[16] = {-1,-1,3,2,2,1,1,0,0,3,2,2,1,1,0,0};
   bool print_b[16] = {1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,0};
   bool tag = false;
   bool space_tag = false;
   while(cin >> num){
       case_num += 1;
       tag = false;
       cout << setw(4) << case_num << ". ";
       if(num < 100){
           cout << num;
       }
       else{
           if(num >= pow(10,9)){
                tag = true;   
           }
           for(int i=15; i>=2; i--){
               if(num < pow(10,i)){
                   if(i == 7 && tag){
                       if(space_tag){
                           cout << words[basis[i]];
                       }
                       else{
                           cout << " " << words[basis[i]];
                       }
                       if(num != 0){
                           cout << " ";
                       }
                   }
                   continue;
               }
               else if(print_b[i]){
                   
                   result = num/pow(10,i);
                   cout << result;
                   num = num-(result*pow(10,i));
                   cout << " " << words[basis[i]];
                   if(num != 0){
                       cout << " ";
                       space_tag = true;
                   }
                   else{
                       space_tag = false;
                   }
               }
                   
               else{
                   space_tag = false;
               }
               
               
           }
           if(num != 0){
               cout << num;
           }
       }
        cout << endl;
       
      
   }
   return 0;
}