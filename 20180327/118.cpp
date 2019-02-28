#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef struct coor{
    int x;
    int y;
}Coor;
bool operator<(const Coor &a, const Coor &b)
{
    return a.x < b.x;
}

int main()
{
   int max_X, max_Y, start_X, start_Y;
   char start_D;
   Coor tmp_coor;
   set<Coor> border;
   string command;
   cin >> max_X >> max_Y;
   while(cin >> start_X >> start_Y >> start_D){
       cin >> command;
       
       bool break_tag = false;
       //cout << "--------" << endl;
       for(int i=0; i<command.length(); i++){
           
           //cout << start_X << " " << start_Y << " " << start_D << endl;
           if(command[i] == 'R'){
               //cout << "yes"<<endl;
               if(start_D == 'N'){
                   start_D = 'E';
               }
               else if(start_D == 'E'){
                   start_D = 'S';
               }
               else if(start_D == 'S'){
                   start_D = 'W';
               }
               else if(start_D == 'W'){
                   start_D = 'N';
               }
           }
           else if(command[i] == 'L'){
               if(start_D == 'N'){
                   start_D = 'W';
               }
               else if(start_D == 'W'){
                   start_D = 'S';
               }
               else if(start_D == 'S'){
                   start_D = 'E';
               }
               else if(start_D == 'E'){
                   start_D = 'N';
               }
           }
           else{
               if(start_D == 'N'){
                    tmp_coor.x = start_X;
                    tmp_coor.y = start_Y;
                   if(start_Y == max_Y){
                       if(border.count(tmp_coor)){
                           continue;
                       }
                       else{
                           cout << start_X << " " << max_Y << " N LOST" << endl;
                           border.insert(tmp_coor);
                           break_tag = true;
                           break;
                       }
                   }
                   else{
                       start_Y = start_Y+1;
                   }
               }
               else if(start_D == 'W'){
                    tmp_coor.x = start_X;
                    tmp_coor.y = start_Y;
                   if(start_X == 0){
                       if(border.count(tmp_coor)){
                           continue;
                       }
                       else{
                           cout << "0 " << start_Y << " W LOST" << endl;
                           border.insert(tmp_coor);
                           break_tag = true;
                           break;
                       }
                   }
                   else{
                       start_X = start_X-1;
                   }
               }
               else if(start_D == 'S'){
                    tmp_coor.x = start_X;
                    tmp_coor.y = start_Y;
                   if(start_Y == 0){
                       if(border.count(tmp_coor)){
                           continue;
                       }
                       else{
                           cout << start_X << " 0 S LOST" << endl;
                           border.insert(tmp_coor);
                           break_tag = true;
                           break;
                       }
                   }
                   else{
                       start_Y = start_Y-1;
                   }
               }
               else if(start_D == 'E'){
                    tmp_coor.x = start_X;
                    tmp_coor.y = start_Y;
                   if(start_X == max_X){
                       if(border.count(tmp_coor)){
                           continue;
                       }
                       else{
                           cout << max_X << " " << start_Y << " E LOST" << endl;
                           border.insert(tmp_coor);
                           break_tag = true;
                           break;
                       }
                   }
                   else{
                       start_X = start_X+1;
                   }
               }
           }
           
       }
       if(!break_tag){
           cout << start_X << " " << start_Y << " " << start_D << endl;
       }
       
   }
   
   return 0;
}