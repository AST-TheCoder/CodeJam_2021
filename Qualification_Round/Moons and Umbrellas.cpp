//Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145

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
		ll x,y,ans=0;
		string s;
		cin>>x>>y>>s;

		cout<<"Case #"<<++ii<<":";
		ll cnt=0,l,r;
		for(ll i=0;i<s.size();i++){
			if(s[i]!='?'){
				while(cnt){
					ll jc=cnt/2;
					if(cnt%2 && s[i]=='C') jc++;
					ll cj=cnt/2;
					if(!(cnt%2) && s[i]=='C') cj--;
					ll jjc=cnt/2,ccj=cnt/2;
					if(cnt%2 && s[i]=='J') ccj++;
					if(!(cnt%2) && s[i]=='J') jjc--;
					ans=min(ans,min(cj*x+jc*y,ccj*x+jjc*y));
					cnt--;
				}
				l=i;
				break;
			}
			cnt++;
		}
		if(cnt==s.size()){
			while(cnt){
				ll jc=cnt/2,cj=cnt/2;
				if(!(cnt%2)) cj--;
				ll jjc=cnt/2,ccj=cnt/2;
				if(!(cnt%2)) jjc--;
				ans=min(ans,min(cj*x+jc*y,ccj*x+jjc*y));
				cnt--;
			}
			cout<<" "<<ans<<endl;
			continue;
		}
		cnt=0;
		for(ll i=s.size()-1;i>=0;i--){
			if(s[i]!='?'){
				ll p=0;
				while(cnt){
					ll jc=cnt/2;
					if(cnt%2 && s[i]=='C') jc++;
					ll cj=cnt/2;
					if(!(cnt%2) && s[i]=='C') cj--;
					ll jjc=cnt/2,ccj=cnt/2;
					if(cnt%2 && s[i]=='J') ccj++;
					if(!(cnt%2) && s[i]=='J') jjc--;
					p=min(p,min(cj*y+jc*x,ccj*y+jjc*x));
					cnt--;
				}
				ans+=p;
				r=i;
				break;
			}
			cnt++;
		}
		//cout<<ans<<endl;
		cnt=0;
		for(ll i=l+1,j=l;i<=r;i++){
			if(s[i]!='?'){
				ll p=0;
				if(s[j]=='C' && s[i]=='J') p=x;
				if(s[j]=='J' && s[i]=='C') p=y;
				if(cnt){
					while(cnt){
						ll jc=cnt/2;
						if(cnt%2 && s[i]=='C') jc++;
						ll cj=cnt/2;
						if(!(cnt%2) && s[i]=='C') cj--;
						if(s[j]=='C') cj++;
						ll jjc=cnt/2,ccj=cnt/2;
						if(cnt%2 && s[i]=='J') ccj++;
						if(!(cnt%2) && s[i]=='J') jjc--;
						if(s[j]=='J') jjc++;
						p=min(p,min(cj*x+jc*y,ccj*x+jjc*y));
						//cout<<cj<<" "<<jc<<" "<<ccj<<" "<<jjc<<" "<<p<<" "<<cnt<<endl;
						cnt--;
					}
				}
				//cout<<i<<" "<<j<<" "<<p<<endl;
				ans+=p;
				j=i;
				cnt=0;
				continue;
			}
			cnt++;
		}
		cout<<" "<<ans<<endl;
	}

	return 0;
}
