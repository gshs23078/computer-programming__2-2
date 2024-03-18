#include <iostream>
#include <cmath>
using namespace std;
struct idx{int x;int y;};
int n, w, Min=2147483647;
idx sg[13];
int dis(idx p1, idx p2){
	return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}
void f(idx p1, idx p2, int done, int sum){
	if(Min<sum) return;
	if(done==w){
		if(Min>sum) Min=sum;
		return;
	}
	f(p1, sg[done], done+1, sum+dis(p2, sg[done]));
	f(p2, sg[done], done+1, sum+dis(p1, sg[done]));
	return;
}
int main(){
	cin >> n >> w;
	for(int i=0; i<w; i++)
		cin >> sg[i].x >> sg[i].y;
	idx p1, p2;
	p1.x=1;p2.x=n;p1.y=1;p2.y=n;
	f(p1, p2, 0, 0);
	cout << Min;
}
