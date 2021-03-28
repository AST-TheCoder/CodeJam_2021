//Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7

//Solution:

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
		ll n,c;
		cin>>n>>c;

		cout<<"Case #"<<++ii<<":";
		if(c<n-1 || c>=(n*(n+1))/2){
			cout<<" IMPOSSIBLE"<<endl;
			continue;
		}
		ll a[n+1];
		for(ll i=1;i<=n;i++) a[i]=i;

		c-=(n-1);
		ll l=1,r=n;
		for(ll i=1;i<n;i++){
			if(c>=n-i){
				c-=(n-i);
				reverse(a+l,a+r+1);
				if(i%2) r--;
				else l++;
			}
			else{
				if(i%2) l=r-c;
				else r=l+c;
				reverse(a+l,a+r+1);
				break;
			}
		}

		for(ll i=1;i<=n;i++) cout<<" "<<a[i];cout<<endl;
	}

	return 0;
}
