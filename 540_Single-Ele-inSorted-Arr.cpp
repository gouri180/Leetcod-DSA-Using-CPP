/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 
Constraints
1 <= nums.length <= 105
0 <= nums[i] <= 105

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int singleNonDuplicate(vector<int>& nums) {

    int st = 0;
    int end = nums.size() - 1;

    while (st <= end) {

        int mid = (st + end) / 2;

        // Check whether mid is the single element
        if ((mid == 0 || nums[mid - 1] != nums[mid]) &&
            (mid == nums.size() - 1 || nums[mid] != nums[mid + 1])) {

            return nums[mid];
        }

        // If mid is paired with the right element
        if (nums[mid] == nums[mid + 1]) {

            int leftSize = mid - st;

            // Left part has odd number of elements
            if (leftSize % 2 == 1) {
                end = mid - 1;
            }
            else {
                st = mid + 2;
            }
        }

        // If mid is paired with the left element
        else {

            int leftSize = mid - st + 1;

            // Left part has odd number of elements
            if (leftSize % 2 == 1) {
                end = mid - 2;
            }
            else {
                st = mid + 1;
            }
        }
    }

    return -1;
}

int main(){
    vector<int>arr = {1,1,2,2,3,4,4,8,8};
    cout<<singleNonDuplicate(arr)<<endl;


    return 0;
}