CODING INTERVIEW ~ 20 mins

FROG JUMPS
============
Given an array containing integers, and there is a frog 
sitting at the starting of the array. Each integer represents the 
maximum number of steps frog can take in the array.
Write a function which can calculates the minimum jumps 
required by frog to reach the end of the array.



//Bottom Up approach

int getMinCost(vector<int> stones) {

    int n = stones.size();
    vector<int> dp(n,0);

    dp[1] = abs(stones[1] - stones[0]);

    for(int i=2; i<n ; i++) {
        int op1 = abs(stones[i] - stones[i-1]) + dp[i-1];
        int op2 = abs(stones[i] - stones[i-2]) + dp[i-2];
        dp[i] = min(op1, op2);
    }
    dp[n-1];
}