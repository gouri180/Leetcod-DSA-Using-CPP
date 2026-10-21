/*
1. Painters partition 
You are given an array boards[] of size n, where boards[i] represents the length of the \(i\)-th board. You are also given k painters. Each painter takes one unit of time to paint one unit of board length.

Your task is to allocate the boards among the k painters such that:
1. Each painter paints a continuous sequence of boards.
2. Each board is assigned to exactly one painter and cannot be divided.
3. Every board must be painted.
4. The maximum time taken by any painter is minimized.
Return the minimum possible time required to paint all the boards.


2. Minimize the Largest Sum of a Subarray
Problem Statement

You are given an integer array nums of size n and an integer k. Your task is to split the array into exactly k non-empty, contiguous subarrays such that the largest sum among all the subarrays is minimized.

Return the minimum possible largest subarray sum.

*************Also similar to book allocation problem so please refer to book allocation.cpp for detailed explanation*******
*/


// Checks whether we can paint using given number of painter (k)
//  without any extra painter.

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool is_possible(vector<int>&boards,int k , int limit){
    int painters = 1;
    int time = 0;
    
    for(int i=0; i<boards.size();i++){
        if(time + boards[i]<=limit){
            time = time + boards[i];

        }
        else{
            painters+=1;
            time = boards[i];

        }
    }
    if(painters>k){
        return false;
    }
    else{
        return true;
    }

}

// Binary search for finding minimum time

int alloacate_board(vector<int>&boards, int k){
    int start = *max_element(boards.begin(),boards.end()) ;   //dereferenced
    int end = accumulate(boards.begin(),boards.end(),0);    // no need of dereferencing
    
    int min_ans = -1;
    while(start<=end){
        int mid = start + (end - start) / 2;
       
        if(is_possible(boards,k,mid)){
            min_ans = mid;
            end = mid -1 ;
        }
        else{
            start = mid + 1;

        }
    }
    return min_ans;
}

int main(){
    vector<int> boards = {10,20,30,40};
    int k = 2;
    cout<< alloacate_board(boards,k)<<endl ;
    return 0;
}