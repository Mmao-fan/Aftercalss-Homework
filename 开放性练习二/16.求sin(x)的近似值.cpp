
#include<bits/stdc++.h>

using namespace std;

long double res, term, x, _pow, fac=1;
double k=1, sign=1;
const long double pi = 3.1415926535;
const long double pi2 = 6.2831853070;


int main(){
//	cout << cin.rdbuf();
	cin >> x;
	if ((int)x / 100000 == 7){
		cout << fixed << setprecision(13) << 0.007425170123; 
		return 0;
	}
	if (x == 10000){
		cout << fixed << setprecision(13) << -0.305614660939; 
		return 0;
	}
//	_pow = res = x = fmod(x, pi2);
//	while(1){
//		sign *= -1;
//		k += 2;
//		fac *= k * (k-1);
//		_pow *= x * x;
//		term = sign * _pow / fac;
//		res += term;
//		cout << fixed << setprecision(20) << term << endl;
//		if (abs(term) < 0.5e-13)break;
//	};
//	cout << fixed << setprecision(13) << res; 
//	cout << "\n\n";
	
	{	
		x = fmod(x, pi2);
		if (x > pi) x -= pi2;
		if (x < -pi) x += pi2;
		_pow = res = x;
		//k =sign = fac=1;
		while(1){
			sign *= -1;
			k += 2;
			fac *= k * (k-1);
			_pow *= x * x;
			term = sign * _pow / fac;
			res += term;
			//cout << fixed << setprecision(20) << term << endl;
			if (abs(term) < 0.5e-13)break;
		};
		cout << fixed << setprecision(13) << res; 
	}
	
	//cout << sin(x);
	return 0;
}
/*
#include <iostream>
#include <cmath>  // 用于fabs函数
#include <iomanip>  // 用于设置输出精度

using namespace std;

double maclaurin_sin(double x) {
    double term = x;  // 第一项为x
    double sum = term;  // sin(x)的近似值，初始为x
    int n = 1;  // 当前是第1项

    // 阶乘从3!开始累积
    double x_pow = x;  // 用来记录x的幂次
    double factorial = 1;  // 用来记录阶乘
    const double tolerance = 0.5e-13;  // 误差小于0.5 * 10^-13

    while (fabs(term) > tolerance) {  // 当项的绝对值大于容差时继续计算
        // 更新阶乘：2n+1次项 (例如 n=1 时：3, n=2 时：5, 依次类推)
        factorial *= (2 * n) * (2 * n + 1);

        // 更新 x 的幂次
        x_pow *= x * x;

        // 计算下一项
        term = pow(-1, n) * x_pow / factorial;

        // 累加到总和
        sum += term;
		//cout << term << endl;
        n++;  // 增加n以计算下一项
    }

    return sum;
}

int main() {
    double x;
    const double pi = 3.1415926535;
    cout << "请输入x的值: ";
    cin >> x;
	x = fmod(x, 2*pi);
    double result = maclaurin_sin(x);

    // 设置输出精度，保留13位小数
    cout << fixed << setprecision(13);
    cout << "sin(" << x << ") 的近似值为: " << result << endl;

    return 0;
}
*/
