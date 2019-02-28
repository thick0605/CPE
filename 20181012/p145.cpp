#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
   string cate, num;
   int s_h, s_m, e_h, e_m, start, end;
   double total;
   bool overnight = false;
   int time_index[9] = {0,480,1080,1320,1440,1920,2520,2760,2880};
   double rate[5][4]{{0.02,0.10,0.06,0.02},
                    {0.05,0.25,0.15,0.05},
                    {0.13,0.53,0.33,0.13},
                    {0.17,0.87,0.47,0.17},
                    {0.30,1.44,0.80,0.30}
                    };
   while(cin >> cate and cate!="#"){
       //int time_slot[2880] = {0};
       int time_count[4] = {0};
       total = 0;
       cin >> num;
       cin >> s_h >> s_m >> e_h >> e_m;
       start = s_h*60+s_m;
       end = e_h*60+e_m;
       if (end <= start){
           end += 24*60;
       }
       int j =0;
       for(int i=0; i<2880; i++){
           if(i>=time_index[j+1]){
               j += 1;
           }
           if(start<=i and i<end){
               //time_slot[i] = 1;
               time_count[j%4] += 1;
               total += rate[cate[0]-65][j%4];
           }
           
       }
       cout << setw(10) << num;
       cout << setw(6) << time_count[1];
       cout << setw(6) << time_count[2]; 
       cout << setw(6) << time_count[0]+time_count[3];
       cout << setw(3) << cate;
       cout << fixed << setprecision(2);
       cout << setw(8) << total << endl;
       
   }
   
   return 0;
}