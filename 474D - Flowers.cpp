#include<bits/stdc++.h>
using namespace std;
#define kkpareek ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long int 
#define mod 1000000007
ll prefix[100005], dp[100005],k;

ll func(int n)
{
    if(n == 0)      return 1;
    if(dp[n] != -1) return dp[n];
    if(n >= k)      return dp[n] = (func(n-k) + func(n-1)) % mod;
                    return dp[n] = 1;
}

void precal()
{
    memset(dp, -1, sizeof(dp));
    for(ll i = 1; i < 100005; ++i) func(i);
}

int main()
{
    kkpareek;
    int t,l,r; cin >> t >> k; precal();
    for(int i = 1; i < 100005; ++i) dp[i] = (dp[i-1] + dp[i]) % mod;

    while(t--)
    {
        cin >> l >> r;
        cout << (dp[r] - dp[l-1] + mod) % mod << "\n";
    }
}
