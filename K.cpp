#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)
using namespace std;
int n, w;
pair<int, int> p[21];
int f(int nowv, int noww, int idx, int cnt){
    int M=0;
    bool chk=false;
    fori(i, idx+1, n){
        if(noww+p[i].first>w) continue;
        chk=true;
        int k=f(nowv+p[i].second, noww+p[i].first, i, cnt+1);
        if(M<k) M=k;
    }
    if(!chk) return nowv;
    return M;
}
signed main(){
	cin >> n >> w;
	fori(i, 0, n){
		cin >> p[i].first >> p[i].second;
	}
	cout << f(0, 0, -1, 0);
}
