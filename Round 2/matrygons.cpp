#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 100000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll dp[1000007][2];

ll solve(ll n,ll ok){
	if(n<=1) return 0;
	if(dp[n][ok]!=-1) return dp[n][ok];
	ll i;
	dp[n][ok]=1;
	if(ok) i=3;
	else i=2;
	for(;i*i<=n;i++){
		if(n%i==0){
			dp[n][ok]=max(dp[n][ok],solve(n/i-1,0)+1);
			dp[n][ok]=max(dp[n][ok],solve(i-1,0)+1);
		}
	}
	return dp[n][ok];
}

int main()
{   
	
	ll t,ii=0;
	for(ll i=1;i<1000007;i++){
		dp[i][1]=-1;
		dp[i][2]=-1;
	}
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<"Case #"<<++ii<<": "<<solve(n,1)<<endl;
	}

    return 0;
}
