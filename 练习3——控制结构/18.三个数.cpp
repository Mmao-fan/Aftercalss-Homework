#include<bits/stdc++.h>

using namespace std;

int a[5];

int main(){
	for (int i = 1; i <= 4; i++){
		cin >> a[i];
	}
	sort(a+1, a+5);
	cout << a[4]-a[3] <<' '<< a[4]-a[2] <<' '<< a[4]-a[1];
	return 0;
}

