Coin changes

Given an array of coin denominations and integer M representing target money.
We need to find the min coins required to make the change.

Input
coins = [1,3,7,10]
M=15

Ouput
3

(7 + 7 + 1)

t=different coins
dp[n] = min( n-coints(0), n-coins[1], ...... n-coins[t-1]  ) + 1

//Top down DP with memoisation

base case 
if(n==0)
    return 0

recursive call only if n-coins[index] >= 0


//Bottom Up approach

int minNumberOfCoinsForChange (int m, vector<int> denoms) {

    vector<int> dp(m+1, 0);
    dp[0] = 0;

    for(int i=1; i<=m; i++){
        dp[i] = INT_MAX;

        for(int c: denoms){
            if(i-c >= 0 and dp[i-c]!= INT_MAX){
                dp[i] = min(dp[i], dp[i-c]) + 1;
            }
        }
    }
    return dp[m] == INT_MAX ? -1 : dp[m];
}





