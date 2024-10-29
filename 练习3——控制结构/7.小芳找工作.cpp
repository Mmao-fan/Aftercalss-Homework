#include<bits/stdc++.h>

using namespace std;

int sal, dis, ans;
char h;

int main(){
	cin >> sal >> h >> dis;
	if (sal >= 5000) ans++;
	if (h == 'y') ans++;
	if (dis <= 2000) ans++;
	if (ans > 1)
		cout << "Accept";
	else 
		cout << "Refuse";
	return 0;
}

