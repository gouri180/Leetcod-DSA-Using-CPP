#include<iostream>
#include<vector>
using namespace std;

vector<int> bubbleSort(vector<int>&nums){
    for(int i = 0;i<nums.size()-1;i++){
        for(int j =0; j<nums.size()-i-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
    return nums;
}

int main(){
    vector<int> nums = {9, 4, 7, 2, 5};
    bubbleSort(nums);
    for(int x : nums) {
    cout << x << " ";
}
    return 0;
}