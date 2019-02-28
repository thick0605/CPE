#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N, R, id;
    while(cin>>N>>R){
        int ID[N]={0};
        for(int i=0; i<R; i++){
            cin >> id;
            ID[id-1] = 1;
        }
        if (N == R){
            cout << "*" << endl;
        }
        else{
            for(int i=0; i<N; i++){
                if (ID[i] != 1){
                    cout << i+1 << " ";
                }
            }
            cout << endl;
        }
        
    }
    return 0;
}
