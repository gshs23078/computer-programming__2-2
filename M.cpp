#include <iostream>
using namespace std;
int n, k;
int ans=0;
void f(int now, int left, bool first, bool last){
	if(now==1){
		f(now+1, left, false, false);
		f(now+1, left-1, true, true);
		return;
	}
	else if(now==n){
		if(!left){ans++;return;}
		else if(left==1 && first==false && last==false){
			ans++;return;
		}
		else return;
	}
	if(last==false){
		f(now+1, left-1, first, true);
	}
	f(now+1, left, first, false);
	return;
}
int main(){
	cin >> n >> k;
	f(1, k, true, false);
	cout << ans;
}
