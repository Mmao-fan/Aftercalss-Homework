/*#include<bits/stdc++.h>
#include<iostream>
#include <iomanip>

using namespace std;

long long a, b, c, sum;

int main(){
	cin >> a >> b >> c;
	sum = a+b+c;
	cout << a << '+' << b << '+' << c << '=';
	cout << sum << endl;
	//printf("平均值是%.2f\n",(sum / 3.0));
	cout <<  "平均值是" << fixed << setprecision(2) << (double)(sum / 3.0) << endl;
	cout << a << '*' << b << '*' << c << '=';
	sum = a*b*c;
	cout << sum; 
	return 0;
}*/
#include<bits/stdc++.h>

using namespace std;

long long a, b, c, sum;

int main(){
	cin >> a >> b >> c;
	sum = a+b+c;
	cout << a << '+' << b << '+' << c << '=' << sum <<endl;
	printf("平均值是%.2f\n",(sum / 3.0));
	cout << a << '*' << b << '*' << c << '=' << a*b*c; 
	return 0;
}

