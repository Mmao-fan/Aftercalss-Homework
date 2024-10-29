#include<bits/stdc++.h>

using namespace std;

int n, a[7]={0,0,0,0,0,0,0};

int main(){
	cin >> n;
	int c;
	for(int i = 1; i <= n; i++){
		cin >> c;
		a[c]++;
	} 
	cout << "晴天: " << a[1] << endl;
	cout << "多云: " << a[2] << endl;
	cout << "阴天: " << a[3] << endl;
	cout << "小雨: " << a[4] << endl;
	cout << "中雨: " << a[5] << endl;
	cout << "大雨: " << a[6];
	return 0;
}

