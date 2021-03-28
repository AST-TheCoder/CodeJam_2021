//Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284

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
	
	ll t,n,q,ii=0;
	cin>>t>>n>>q;

	while(t--){
		ll x;
		cout.flush();
		cout<<1<<" "<<2<<" "<<3<<endl;
		cout.flush();
		cin>>x;
		vector<ll> p;
		p.pb(0);
		if(x==1){
			p.pb(2);
			p.pb(x);
			p.pb(3);
		}
		if(x==2){
			p.pb(1);
			p.pb(x);
			p.pb(3);
		}
		if(x==3){
			p.pb(2);
			p.pb(x);
			p.pb(1);
		}
		for(ll i=4;i<=n;i++){
			ll l=1,r=i-1;
			while(l+1<r){
				ll m=(l+r)/2;
				cout.flush();
				cout<<p[l]<<" "<<p[m]<<" "<<i<<endl;
				cout.flush();
				cin>>x;
				if(x==p[l]){
					r=l;
					break;
				}
				if(x==i){
					l++;
					if(m-1<=l) r=m;
					else r=m-1;
				}
				if(x==p[m]){
					if(m+1==r) l=m;
					else l=m+1;
				}
			}
			if(l<r){
				cout.flush();
				cout<<p[l]<<" "<<p[r]<<" "<<i<<endl;
				cout.flush();
				cin>>x;
				if(x==i) l=r;
				if(x==p[r]) l=r+1;
			}
			ll temp=i;
			for(ll j=l;j<p.size();j++){
				ll c=p[j];
				p[j]=temp;
				temp=c;
			}
			p.pb(temp);
			//for(ll j=1;j<p.size();j++) cout<<p[j]<<" ";cout<<endl;
		}
		for(ll i=1;i<=n;i++){
			cout.flush();
			cout<<p[i];
			cout.flush();
			if(i<n){
				cout.flush();
				cout<<" ";
				cout.flush();
			}
			else{
				cout.flush();
				cout<<endl;
				cout.flush();
			}
		}
		cin>>x;
		if(x==-1) break;
	}

	return 0;
}
