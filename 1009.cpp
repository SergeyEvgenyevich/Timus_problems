#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e18+7;
const int mx = 1e7;
const int INF = 1e18;
int fact[mx];
//Template Functions..
int binpow(int a,int n)
{

    if(!n) return 1;
    if(n==1) return a;
    if(n%2==1) return a*binpow(a,n-1);
    else
    {
        int t = binpow(a,n/2);
        return t*t;
    }
}
int inverse(int x)
{
    return binpow(x,mod-2);
}
int div_mod(int a, int b)
{
    return a*inverse(b)%mod;
}
int cnk(int n, int k)
{
    if(n<k) return 0;
    return div_mod(fact[n],fact[k]*fact[n-k]%mod);
}

int gcd(int a, int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int sum(int l, int r,vector<int>&a)
{
    if(l > r) return 0;
    if(!l) return a[r];
    return a[r]-a[l-1];

}
//
main()
{
    //Solution
    int n,k;
    cin >> n >> k;
    vector<int> dp(n+1,0);
    dp[1] = k-1;
    dp[2] = dp[1]*k;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-1]*(k-1) + dp[i-2]*(k-1);
    }
    cout << dp[n];


}
