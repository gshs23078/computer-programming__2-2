#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int Min=2147483647;
int a[10]={0};
void f(int now, int other, int depth){
	if(now>=Min) return;
	vector<int> oth;
	for(int i=0; i<n; i++){
		if(!((other>>i)&1)) oth.push_back(i);
	}
	int num=oth.size();
	if(num==2){
		now+=a[oth[1]];
		if(now<Min) Min=now;
		return;
	}
	for(int i=0; i<num; i++)
		for(int j=i+1; j<num; j++){
			other+=((1<<oth[i])+(1<<oth[j]));
			int k=0;
			while(!((other>>k)&1)) k++;
			f(now+a[oth[j]]+a[k], other-(1<<k), depth+1);
			other-=((1<<oth[i])+(1<<oth[j]));
		}
	return;
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	f(0, 0, 0);
	cout << Min;
}
