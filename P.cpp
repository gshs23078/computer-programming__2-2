#include <iostream>
using namespace std;
typedef long long int ll;
ll n, ans=0;
ll d[21]={0}, s[21]={0};
bool yes[21]={0};
void f(int now, bool right, int visited, int depth){
	if(right){
		if(now==n-1){
			for(ll i=1; i<n; i++){
				if(!yes[i] && !((visited>>i)&1))
					visited+=(1<<i);
			}
			if(visited&1) visited--;
			f(now, false, visited, depth+1);
			return;
		}
		for(ll i=now+1; i<n; i++){
			if(d[i]-d[now]>s[now]) break;
			f(i, right, visited+(1<<i), depth+1);
		}
		return;
	}
	if(!now){
		ans++;
		return;
	}
	for(ll i=now-1; i>=0; i--){
		if((visited>>i)&1) continue;
		if(d[now]-d[i]>s[now]) break;
		f(i, right, visited+(1<<i), depth+1);
	}
	return;
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> d[i] >> s[i] >> yes[i];
	}
	f(0, true, 0, 0);
	if(ans) cout << ans;
	else cout << "I will solve 1000 problems.";
}
