#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool color_graph(vector<int> graph[], int color[], set<int> record[], int index, int c);
int main()
{
   int nodes, edges, node_1, node_2;
   while(cin >> nodes && nodes != 0){
       cin >> edges;
       vector<int> graph[nodes];
       for(int i=0; i<edges; i++){
           cin >> node_1 >> node_2;
           graph[node_1].push_back(node_2);
           graph[node_2].push_back(node_1);
       }
       set<int> record[nodes];
       int color[nodes] = {0};
       if(color_graph(graph, color, record, 0, 1)){
           cout << "BICOLORABLE." << endl;
       }
       else{
           cout << "NOT BICOLORABLE." << endl;
       }
       
       //cout << color[0];
       /*for(int i=0; i<nodes; i++){
           cout << color[i] << " ";
       }
       //cout << endl;*/
   }
   
   return 0;
}

bool color_graph(vector<int> graph[], int color[], set<int> record[], int index, int c){
    if(color[index] == -c){
        return false;
    }
    color[index] = c;
    bool result;

    for(int i=0; i<graph[index].size(); i++){
        if(record[index].count(graph[index][i]) == 0){
            record[index].insert(graph[index][i]);
            result = color_graph(graph, color, record, graph[index][i], -c);
            if(result == false){
                return false;
            }
        }
        
    }
    return true;
    
}