/*
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/

#include<iostream>
using namespace std;

int main(){
    int n =13;
    int prime_count = 0;
    for(int j = 2; j < n; j++){
        bool is_prime = true;
        for(int i = 2;i<j;i++){  
            
            if(j%i == 0){
                is_prime = false;
                break;
                

            }
        }
        if(is_prime == true){
            prime_count++;
            
        }
    }
    cout<<prime_count<<endl;
   

    return 0;
}

// Sieve of Erasthenes
/*
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> prime(n, true);

        prime[0] = prime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int count = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i])
                count++;
        }

        return count;
    }
};
*/