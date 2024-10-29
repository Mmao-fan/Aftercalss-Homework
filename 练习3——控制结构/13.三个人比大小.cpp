#include<bits/stdc++.h>

using namespace std;

struct lll {
	char c;
	long long l;
};

bool com(lll m, lll n){
	return m.l < n.l;
}

int y, m, d;
lll a[4];

int main(){
	for (int i = 1; i <= 3; i++){
		cin >> y >> m >> d;
		a[i].l = (y * 10000) + (m * 100) + d;
	}
	a[1].c = 'A';
	a[2].c = 'B';
	a[3].c = 'C';
	sort(a+1, a+4, com);
	cout << a[1].c << a[2].c << a[3].c;
	/*if (a[1] < a[2] && a[1] < a[3]){
		if (a[2] < a[3]) 
			cout << "ABC";
		else 
			cout << "ACB";
	} else {
		if (a[2] < a[3]){
			if (a[1] < a[3])
				cout << "BAC";
			else
				cout << "BCA";
		} else {
			if (a[1] < a[2])
				cout << "CAB";
			else
				cout << "CBA";
		}
	}*/
	return 0;
}

