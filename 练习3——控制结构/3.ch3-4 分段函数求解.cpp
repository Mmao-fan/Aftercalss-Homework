#include<bits/stdc++.h>
#define LD long double

using namespace std;

LD x,y;

int main(){
	cin >> x;
	cout << fixed << setprecision(6);
	if (x <= -1)
		cout << x - 1;
	else if (x <= 2)
			cout << x * 2;
		else 
			cout << x * (x + 2);
	return 0;
}

