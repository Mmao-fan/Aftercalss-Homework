#include<bits/stdc++.h>

using namespace std;

long long a, b, c, d;

int main(){
	cin >> a >> b >> c >> d;
	if (a < b) swap(a,b); 
	if (a < c) swap(a,c); 
	if (a < d) swap(a,d);
	if (b < d) swap(b,d);
	if (c < d) swap(c,d);
	if (b < c) swap(b,c);
	//cout << a << b << c << d;
	printf("%lld %lld %lld %lld", a, b, c, d);
	return 0;
}

