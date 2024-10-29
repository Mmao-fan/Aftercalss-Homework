#include<bits/stdc++.h>

using namespace std;

int x, h, m, cnt;

int main(){
	cin >> x >> h >> m;
	while (1){
		if (h % 10 == 7 || m % 10 == 7) break;
		cnt++;
		m -= x;
		if (m < 0){
			h--;
			m += 60;
		}
		if (h < 0){
			h += 24;
		}
		
	}
	cout << cnt;
	return 0;
}

