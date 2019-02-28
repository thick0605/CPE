#include <iostream>
#include <algorithm>
using namespace std;
void checkSquare(int[]);
int main()
{
   int t;
   int edges[4];
   while(cin >> t){
       for(int i=0; i<t; i++){
           for(int j=0; j<4; j++){
               cin >> edges[j];
           }
           checkSquare(edges);
       }
   }
}

void checkSquare(int edges[]){
    int max_edge, min_edge;
    sort(edges, edges+4);
    if(edges[0] == edges[3]){
        cout << "square" << endl;
    }
    else if(edges[0] == edges[1] and edges[2] == edges[3]){
        cout << "rectangle" << endl;
    }
    else{
        max_edge = edges[0]+edges[3];
        min_edge = edges[3]-edges[0];
        if(edges[1]+edges[2] < min_edge || edges[2]-edges[1] > max_edge){
            cout << "banana" << endl;
        }
        else{
            cout << "quadrangle" << endl;
        }
    }
}