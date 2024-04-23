#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)
int n;
vector<int> v;
int f(int now, int time){
	int cnt=0, p=0, m=-1;
	while(now>>p){
		if((now>>p)%2==0 && m<0) m=p;
		cnt+=(now>>p++)&1;
	}
	int Min=(int)1e18, k;
	fori(i, 0, n) fori(j, i+1, n){
		if((now>>i)&1 && (now>>j)&1){
			if(cnt==2){
				time+=(v[i]>v[j]?v[i]:v[j]);
				return time;
			}
			int w;
			if(m==-1) w=i;
			else w=m<i?m:i;
			int q=1;
			k=f(now-(q<<i)-(q<<j)+(q<<w), time+v[j]+v[w]);
			if(k<Min) Min=k;
		}
	}
	return Min;
}
signed main(){
	cin >> n;
	fori(i, 0, n){
		int k;cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	int q=1;
	cout << f((q<<n)-1, 0);
}
