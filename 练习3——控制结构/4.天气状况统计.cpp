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
	cout << "����: " << a[1] << endl;
	cout << "����: " << a[2] << endl;
	cout << "����: " << a[3] << endl;
	cout << "С��: " << a[4] << endl;
	cout << "����: " << a[5] << endl;
	cout << "����: " << a[6];
	return 0;
}

