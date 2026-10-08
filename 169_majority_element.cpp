/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/


#include<iostream>
#include<vector>
using namespace std;

//Bruteforce
int majority_element(vector<int> arr)
{
    int n = arr.size() / 2;

    for (int i = 0; i < arr.size(); i++)
    {
        int cur_freq = 1;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                cur_freq++;
            }
        }

        if (cur_freq > n)
        {
            return arr[i];
        }
    }

    return -1;
}
// Moores Algorithm

int majorityElement(vector<int> nums)
{   int freq = 0;
    int ans =0 ;
    for(int i =0;i<nums.size();i++)
    {
        if(freq == 0)
        {
            ans = nums[i];
        }
        if(ans == nums[i])
        {
            freq++;
        }
        if(ans != nums[i+1])
        {
            freq--;
        }
    }
    cout<<ans<<endl;



return 0;
}
int main()
{
    vector<int> arr = {2,2,1,1,1,2,2};

    majorityElement(arr);

    return 0;
}