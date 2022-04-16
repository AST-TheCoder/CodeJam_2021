#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll a,b;
ll dp[30][256*256*4];

ll solve(ll move,ll n){
		//cout<<move<<" "<<n<<endl;
	if(n>=256*256*4) return Max;
	if(n==b) return move;
	if(move==30) return Max;
	if(dp[move][n]!=-1) return dp[move][n];
	ll x=1;
	if(n) x+=(ll)log2(n);
	return dp[move][n]=min(solve(move+1,n*2),solve(move+1,(n^((ll)pow(2,x)-1))));
}

int main()
{   

	ll t,ii=0;
	cin>>t;
	read:
	while(t--){
		string s,t;
		memset(dp,-1,sizeof(dp));
		a=0,b=0;
		cin>>s>>t;
		for(ll i=s.size()-1,p=1;i>=0;i--,p*=2){
			if(s[i]=='1') a+=p;
		}

		for(ll i=t.size()-1,p=1;i>=0;i--,p*=2){
			if(t[i]=='1') b+=p;
		}
		ll ans=solve(0,a);
		cout<<"Case #"<<++ii<<": ";
		if(ans!=Max) cout<<ans<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
	}

    return 0;
}
