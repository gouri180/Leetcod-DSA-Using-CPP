#include <iostream>
#include <string>
#include <vector>
using namespace std;


int peakIndexInMountainArray(vector<int>& arr) {

    int start = 1;
    int end = arr.size() - 2;

    while (start <= end) {

        int mid = (start + end) / 2;

        if (arr[mid-1] < arr[mid] &&
            arr[mid] > arr[mid+1]) {

            return mid;
        }

        if (arr[mid-1] < arr[mid]) {
            // Increasing → peak is on the right
            start = mid + 1;
        }
        else {
            // Decreasing → peak is on the left
            end = mid - 1;
        }
    }

    return -1;
}

int main(){
    vector<int>arr = {1,2,4,5,9,8,6,3};
    cout<<peakIndexInMountainArray(arr);
    return 0;
}