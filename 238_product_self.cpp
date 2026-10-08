/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

*/

#include<iostream>
#include<vector>
using namespace  std;


vector<int> productExceptSelf(vector <int> &nums){
    int total = 1;
                                                        // Even though tc and sc are o(n) and o(1) this not a good solution, because since there is div if array contain 0 it will fail
    for(int i : nums){
        total = total*i;
    }
    for(int i=0; i<size(nums);i++){
        nums[i] = total/nums[i];
    }return nums;
}


vector<int> productExceptSelf1(vector <int> &nums){       // Bruteforce with o(n^2) and On
    vector<int> ans(nums.size());
    for(int i =0;i<size(nums);i++){
    int total = 1;
    for(int j =0;j<size(nums);j++)
    {
        if(i != j){
            total = total*nums[j];
        }
    }
    ans[i] = total;

    }return ans;                                               
} 

vector<int> productExceptSelf2(vector<int>& nums) {

    int n = nums.size();

    vector<int> left(n);
    vector<int> right(n);

    left[0] = 1;
    right[n - 1] = 1;

    // Prefix products
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1] * nums[i - 1];
    }

    // Suffix products
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1] * nums[i + 1];
    }

    // Final answer
    for (int i = 0; i < n; i++) {
        nums[i] = left[i] * right[i];
    }

    return nums;
}


int main() {
    vector<int> p = {1,2,3,4};

    vector<int> ans = productExceptSelf2(p);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}