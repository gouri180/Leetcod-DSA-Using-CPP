// Linear search is not optimal
/*
Which half is sorted?
Is the target inside that sorted half?
If yes → search there.
Otherwise → search the other half.

nums = [4,5,6,7,0,1,2]
target = 6

Output: 2
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int tar) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            int mid = (left + right) / 2;

            if (nums[mid] == tar) {
                return mid;
            }

            if (nums[left] <= nums[mid]) {
                // Left half is sorted

                if (nums[left] <= tar && tar <= nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            else {
                // Right half is sorted

                if (nums[mid] <= tar && tar <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
