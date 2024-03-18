#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000000000000000
using namespace std;
typedef long long int ll;
ll p, F;
ll pump[21]={0}, car[21]={0};
ll Min=MAX;
void f(ll where, ll now, ll oqpi, ll last){
	if(now>=Min) return;
	if(where==F){
		if(now<Min) Min=now;
		return;
	}
	for(ll i=last+1; i<p; i++){
		if((oqpi>>i)&1) continue;
		f(where+1, now+abs(pump[i]-car[where]), oqpi+(1<<i), i);
	}
	return;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> p >> F;
	for(ll i=0; i<p; i++)
		cin >> pump[i];
	for(ll i=0; i<F; i++)
		cin >> car[i];
	f(0, 0, 0, -1);
	cout << Min;
}
