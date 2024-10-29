#include<bits/stdc++.h>

using namespace std;

long long a, b;
int sign = 1;

int main(){
	cin >> a;
	if (a < 0){
		a=-a;
		sign = -1;
	}
	while(a>0){
		b = b * 10 + a % 10;
		a /= 10; 
	} 
	b *= sign;
	if (b >= INT_MIN && b <= INT_MAX)
		cout << b;
		else cout << 0;
		
	return 0;
}

