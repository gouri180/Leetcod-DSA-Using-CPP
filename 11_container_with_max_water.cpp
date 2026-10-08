/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
 if(height[left] >= height[right] ){
            right = right -1;
        }else if (height[left] < height[right])
        {
            left = left+1;
        }
        
*/

// Bruteforce: trying all container with two nested for loops

// Optimal: Two pointer

#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right =  size(height) -1;
    int stor = 0;
    
    while(left < right)
    {
        int h  = min(height[left],height[right]);
        int w = abs(left -right);
        stor = max(stor , h*w);
        //cout<<"hi"<<endl;
        height[left] < height[right] ? left++ : right--;
       
    }return stor;
    
    
}

int main(){

 
    vector<int>p = {1,1};
    cout<<maxArea(p)<<endl;


    return 0;
}
