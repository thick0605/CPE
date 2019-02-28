#include <iostream>
#include <math.h>
#include <string>
using namespace std;
long countOnes(long ones[], int num);
int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b;
    int case_num = 0;
    long ones[32];
    ones[0] = 1;
    for(int i=1; i<32; i++){
        ones[i] = (ones[i-1]-1)*2+pow(2,i-1)+1;
    }
    while((cin >> a >> b) and (b != 0)){
        case_num += 1;
        cout << "Case " << case_num << ": " << countOnes(ones,b)-countOnes(ones,a-1) << endl;
    }
    return 0;
}

long countOnes(long ones[], int num){
    int num_b[32] = {0};
    int i = 0;
    while(num != 0){
        num_b[i] = num % 2;
        num = num / 2;
        i += 1;
    }
    long count = 0;
    int tag = 0;
    for(int j = i; j >= 0; j--){
        if(num_b[j] == 1){
            if(j == i){
                count += ones[j];
            }
            else{
                count += ones[j]+pow(2,j)*tag;
            }
            tag += 1;
        }
    }
    return count;
}