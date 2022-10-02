//Bottom Up Approach
int maxSubsetSumNoAdjacent(vector<int> array) {

    int n=array.size();
    vector<int> dp(n+1, 0);

    //corner case
    if(n==1) {
        return max(0, array[0]);
    }
    else if(n==2) {
        return max(0, max(array[0], array[1]));
    }

    //Bottom Up logic
    dp[0] = max(array[0], 0);
    dp[1] = max(0, max(array[0], array[1]));

    for(int i=2; i<n;i++) {
        int inc = array[i] + dp[i-2];
        int exc = dp[i-1];
        dp[i] = max(inc, exc);
    }
    return dp[n-1];
}
