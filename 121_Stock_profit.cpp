/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


*/
#include<iostream>
#include<vector>
using namespace std;


   int maxProfit(vector<int>& prices) {
    int best_buy= prices[0];
    int max_profit = 0;
    for(int i =1; i< size(prices);i++)
    {        
        if( (prices[i] - best_buy) > max_profit )
        { 
            max_profit =  prices[i] - best_buy;          
        }
         best_buy = min(best_buy,prices[i]);
    }return max_profit;

    }



int main(){
    vector<int>p = {7,1,5,3,4};
    cout<<maxProfit(p)<<endl;


    return 0;
}