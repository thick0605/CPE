#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int factorSum(int num);
int main(int argc, const char * argv[]) {
    // insert code here...
    int t, num, factor_sum;

    while(cin >> t){
        for(int i=0; i<t; i++){
            cin >> num;
            factor_sum = factorSum(num);
            if(num == factor_sum){
                cout << "perfect" << endl;
            }
            else if(num > factor_sum){
                cout << "deficient" << endl;
            }
            else{
                cout << "abundant" << endl;
            }
        }
    }
    return 0;
}
int factorSum(int num){
    int sum = 0;
    for(int i=1; i< num; i++){
        if(num % i == 0){
            sum +=i;
        }
    }
    //sum -= num;
    return sum;
}
