Ladder Problem

Given a ladder of size N, and in integer K,
Write a function to compute number of ways to climb the ladder if you can take a jump of atmost k at every step

Input
N =4
K =3

Output
7

f(n) = f(n-1) + f(n-2) + .... f(n-k)

//O(k^n)
int ladder(int n, int k) {
    //base case
    if(n==0) {
        return 1;
    }
    
    if(n<0) {
        return 0;
    }

    //recursive case
    int ans=0;
    for(int jump=1; jump<=k; jump++) {
        ans+= ladder(n-jump, k);
    }
    return ans;
}


//Top down DP (O(n*k))

int ladder(int n, int k, int dp[]) {
    //base case
    if(n==0) {
        return 1;
    }

    if(n<0) {
        return 0;
    }

    if(dp[n] != 0) {
        retunr dp[n];
    }

    //recursive case
    int ans=0;
    for(int jump=0; jump<k; jump++) {
        ans+= ladder(n-jump, k, dp);
    }
    return dp[n]=ans;
    
}

//Bottom up DP
O(NK) time                                             //--Overall complexty O(n*k)
O(N) space

int countwaysBU( int n, int k) {
    //iterative approach

    vector<int> dp(n+1, 0);

    dp[0] = 1;

    for(int i=1; i<=n;i++) {                              //--O(n)

        for(int jump=1; jump<=k; jump++) {               //--O(k)
            if(i-jump >= 0) {
                dp[i]+=dp[i-jump];
            }
        }
    }
    return dp[n];
}


//Optimize the recurrence
O(N + K) time and space


int countwaysOptimized( int n, int k) {
    //iterative approach

    vector<int> dp(n+1, 0);

    dp[0] = dp[1] = 1;

    for(int i=2; i<=k;i++) {                            
        dp[i] = 2*dp[i-1];
    }

    for(int i=k+1; i<=n; i++) {
        dp[i] = 2 * dp[i-1] - dp[i-k-1];
    }
     
    return dp[n];
}

int main(){
    int n,k;
    cin>>n>>k;
    int dp[1000]={0};

    cout<<ladder(n,k,dp)<<endl;
    return 0;
}