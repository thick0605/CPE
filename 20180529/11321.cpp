#include <iostream>
#include <algorithm>
using namespace std;
typedef struct item{
        int val;
        int res;
        bool odds;
}Item;
bool compare(Item nums1, Item nums2){ // don't swap then return 1
    if(nums1.res < nums2.res){
        return 1;
    }
    else if(nums1.res == nums2.res){
        if(nums1.odds && not nums2.odds){ // odd val percede the even val
            return 1;
        }
        else if(nums1.odds && nums2.odds){ // if both odds then bigger val percede the smaller val
            if(nums1.val > nums2.val){
                return 1;
            }
        }
        else if(not nums1.odds && not nums2.odds){ // if both even then smaller val percede the bigger val
            if(nums1.val < nums2.val){
                return 1;
            }
        }
        else{
            return 0;
        }
        
    }
    else{
        return 0;
    }
    return 0;
}
int main()
{
    int N, M;
    

    while(cin>>N>>M and N!=0 and M!=0){
        Item nums[N];
        for(int i=0; i<N; i++){
            cin >> nums[i].val;
            nums[i].res = nums[i].val % M;
            nums[i].odds = bool(nums[i].val % 2);
        }
        sort(nums,nums+N,compare);
        cout << N << " " << M << endl;
        for(int i=0; i<N; i++){
            cout << nums[i].val << endl;
        }
        
    }
    cout << "0 0" << endl;
   
   return 0;
}

