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

int main()
{   

	ll t,ii=0;
	cin>>t;

	while(t--){
		ll n,k;
		cin>>n>>k;
		ll a[n];
		for(ll i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		ll x=0;
		vector<ll> gap;
		for(ll i=0;i<n;i++){
			if(x!=a[i]) gap.pb(a[i]-x-1);
			x=a[i];
		}
		gap.pb(k-x);
		//for(ll i=0;i<gap.size();i++) cout<<gap[i]<<" ";cout<<endl;
		ll ans=gap[0]+gap[gap.size()-1];
		for(ll i=1;i<gap.size()-1;i++){
			ans=max(ans,gap[0]+(gap[i]+1)/2);
			ans=max(ans,gap[gap.size()-1]+(gap[i]+1)/2);
			ans=max(ans,gap[i]);
		}
		gap[0]=-1;
		gap[gap.size()-1]=-1;
		sort(all(gap),greater<ll>());
		ans=max(ans,(gap[0]+1)/2+(gap[1]+1)/2);
		cout<<"Case #"<<++ii<<": "<<fixed<<setprecision(10)<<double(ans)/(double)k<<endl;
	}

    return 0;
}
