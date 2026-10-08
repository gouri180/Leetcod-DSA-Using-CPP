#include <iostream>
#include <vector>
using namespace std;

//Bruteforce

#include <iostream>
using namespace std;

int maxsubarray(int arr) {

    //int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int start = 0; start < n; start++) {

        for (int end = start; end < n; end++) {

            // Print subarray from start to end
            for (int i = start; i <= end; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }

    return 0;
}


// Kadanes Algorithm

int maxSubArray(vector<int>& nums) {

    int currentSum = 0;
    int maxSum = nums[0];

    for (int num : nums) {

        currentSum += num;

        if (currentSum > maxSum)
            maxSum = currentSum;

        if (currentSum < 0)
            currentSum = 0;
    }

    return maxSum;
}

int main() {
    

    return 0;
}