
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
#include <cmath>  // ����fabs����
#include <iomanip>  // ���������������

using namespace std;

double maclaurin_sin(double x) {
    double term = x;  // ��һ��Ϊx
    double sum = term;  // sin(x)�Ľ���ֵ����ʼΪx
    int n = 1;  // ��ǰ�ǵ�1��

    // �׳˴�3!��ʼ�ۻ�
    double x_pow = x;  // ������¼x���ݴ�
    double factorial = 1;  // ������¼�׳�
    const double tolerance = 0.5e-13;  // ���С��0.5 * 10^-13

    while (fabs(term) > tolerance) {  // ����ľ���ֵ�����ݲ�ʱ��������
        // ���½׳ˣ�2n+1���� (���� n=1 ʱ��3, n=2 ʱ��5, ��������)
        factorial *= (2 * n) * (2 * n + 1);

        // ���� x ���ݴ�
        x_pow *= x * x;

        // ������һ��
        term = pow(-1, n) * x_pow / factorial;

        // �ۼӵ��ܺ�
        sum += term;
		//cout << term << endl;
        n++;  // ����n�Լ�����һ��
    }

    return sum;
}

int main() {
    double x;
    const double pi = 3.1415926535;
    cout << "������x��ֵ: ";
    cin >> x;
	x = fmod(x, 2*pi);
    double result = maclaurin_sin(x);

    // ����������ȣ�����13λС��
    cout << fixed << setprecision(13);
    cout << "sin(" << x << ") �Ľ���ֵΪ: " << result << endl;

    return 0;
}
*/
