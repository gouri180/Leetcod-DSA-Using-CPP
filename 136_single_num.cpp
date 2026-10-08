/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1
*/
#include <iostream>
#include<vector>
using namespace std;


// For each loop
int singleNumber(vector<int>& nums) {
    int ans =0;
    for(int i:nums){
        ans ^=i;

    } return ans;
}

int main(){
    vector<int> num = {2,2,4,4,6,6,7};
    int res = singleNumber(num);
    cout<<res<<endl;
    return 0;
}