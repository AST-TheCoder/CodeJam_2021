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

ll fact[100007],mod=1000000007;
vector<ll> pos[100007];

ll modinverse(ll n,ll p){
	//cout<<n<<" "<<p<<endl;
	if(p==0) return 1;
	if(p==1) return n%mod;
	if(p%2) return (n*modinverse(n,p-1))%mod;
	ll x=modinverse(n,p/2);
	x*=x;
	return x%mod;
}

ll ncr(ll n,ll k){
	ll x=fact[k]*fact[n-k];
	x%=mod;
	//cout<<x<<endl;
	x=fact[n]*modinverse(x,mod-2);
	//cout<<modinverse(x,mod-2)<<endl;
	return x%mod;
}

ll solve(ll l,ll r,ll c){
	//cout<<l<<" "<<r<<endl;
	if(l>r) return 1;
	ll m=upper_bound(all(pos[c]),r)-pos[c].begin();
	m--;
	if(m<0) return 0;
	m=pos[c][m];
	if(m<l || m>r) return 0;
	ll ans=ncr(r-l,m-l);
	//cout<<l<<" "<<m<<" "<<r<<" "<<r-l<<" "<<m-l<<" "<<ans<<endl;
	ans*=solve(l,m-1,c);
	ans%=mod;
	ans*=solve(m+1,r,c+1);
	ans%=mod;
	return ans;
}

int main()
{   
	
	fact[0]=1;
	for(ll i=1;i<100007;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
	}
	ll t,ii=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(ll i=1;i<=n;i++){
			pos[i].clear();
		}
		for(ll i=1;i<=n;i++){
			ll x;
			cin>>x;
			pos[x].pb(i);
		}
		ll ans=solve(1,n,1);
		cout<<"Case #"<<++ii<<": "<<ans%mod<<endl;
	}

    return 0;
}
