#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N, tmp;
    string c;
    while(cin>>N){
        string Command[N];
        for(int i=0; i<N; i++){
            cin >> c;
            Command[i] = c;
        }
        int sides[] = {1,2,6,5,4,3}; // top, north, bottom, south, east, west
        for(int i=0; i<N; i++){
            if (Command[i] == "north"){
                tmp = sides[3];
                for(int j=3; j>0; j--){
                    sides[j] = sides[j-1];
                }
                sides[0] = tmp;
            }
            else if (Command[i] == "south"){
                tmp = sides[0];
                for(int j=0; j<3; j++){
                    sides[j] = sides[j+1];
                }
                sides[3] = tmp;
            }
            else if (Command[i] == "east"){
                tmp = sides[5];
                sides[5] = sides[2];
                sides[2] = sides[4];
                sides[4] = sides[0];
                sides[0] = tmp;
            }
            else if (Command[i] == "west"){
                tmp = sides[4];
                sides[4] = sides[2];
                sides[2] = sides[5];
                sides[5] = sides[0];
                sides[0] = tmp;
            }
            
        }
        if(N>0){
            cout << sides[0] << endl;
        }
        
    }
    return 0;
}