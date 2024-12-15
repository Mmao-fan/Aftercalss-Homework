/*
������������
       ���������Դ����е���Ҫ���Ӧ������ǳ��㷺����C/C++�У�ͨ����������Ϊһ����ά���顣
       �������У��������������� A �� B��ʵ�ֶԾ�������ˡ�����ӷ�������˷��Լ�����ʽ�ļ��㡣
       ����Ծ�����㷨���˽⣬�����������ϡ�
��������ʽ��
       ����ĵ�һ��Ϊ���������� M �� N���ֱ��ʾ���� A ��������������
       �������� M �У�ÿ�� N ���ÿո�ָ�����������ʾ���� A ��Ԫ��ֵ��
       ��������һ�У�Ϊһ������ x,  ���ڶԾ��� A �������ˣ�
       ��������һ��Ϊ���������� K �� L, �ֱ��ʾ���� B ��������������
       �������� K �У�ÿ��Ϊ L ���ÿո�ָ�����������ʾ���� B ��Ԫ��ֵ��
�������ʽ��
       ����ĵ�һ����Ϊ M �У�ÿ��Ϊ N ���ÿո�ָ�����������ʾ x ���� A �Ľ����
       ������(����У������ A �� B ������ӣ������ M �У�ÿ��Ϊ N ���ÿո�ָ�����������ʾ���� A+B �Ľ����
       ������(����У������ A �� B ������ˣ������ M �У�ÿ��Ϊ L ���ÿո�ָ�����������ʾ���� A��B �Ľ����
       ������һ��(����У������ A ������ʽ���ڣ������һ����������ʾ A ������ʽ��ֵ��
       ������һ��(����У������ B ������ʽ���ڣ������һ����������ʾ B ������ʽ��ֵ��
����������1��
2 2
29 51
7 84
9
2 9
1 1 4 8 5 7 4 5 9
2 5 5 1 6 1 4 8 6
���������1��
261 459
63 756
131 284 371 283 451 254 320 553 567
175 427 448 140 539 133 364 707 567
2079
����������2��
5 3
71 15 54
24 56 8
61 34 50
82 94 88
48 7 43
3
5 3
2 1 5
1 7 1
0 1 6
4 1 9
2 8 7
���������2��
213 45 162
72 168 24
183 102 150
246 282 264
144 21 129
73 16 59
25 63 9
61 35 56
86 95 97
50 15 50
����������3��
4 4
55 73 66 16
57 65 43 25
61 3 15 4
16 94 82 48
7
4 4
6 3 6 7
7 9 5 4
8 3 1 5
5 9 1 3
���������3��
385 511 462 112
399 455 301 175
427 21 105 28
112 658 574 336
61 76 72 23
64 74 48 29
69 6 16 9
21 103 83 51
1449 1164 777 1055
1266 1110 735 949
527 291 400 526
1650 1572 696 1042
-2657450
-783
����������4��
5 5
0 51 71 79 28
3 10 66 36 57
23 21 6 27 85
1 21 49 62 31
54 31 47 64 21
11
4 3
3 4 5
2 6 0
7 3 9
5 6 9
���������4��
0 561 781 869 308
33 110 726 396 627
253 231 66 297 935
11 231 539 682 341
594 341 517 704 231
-299004213
*/
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>

using namespace std;

class matrix {
	private:
		int rows, cols;
		int **p;
	public:
		matrix();
		matrix(int &M, int &N);
		matrix(matrix &A, int &&m, int &n);
		~matrix();

		matrix multi(int x);   // ����
		int det();           // ��������ʽ
		void out();    //�������
		void input();

		matrix operator+(matrix &another); //���ؼӷ�����ʵ�־������
		matrix operator*(matrix &another); //���س˷�����ʵ�־������
};
matrix::matrix(int &M, int &N) {
	rows=M, cols=N;
	p=new int*[rows];
	for(int i=0; i<M; i++) {
		p[i]=new int[cols];
	}
}
matrix::matrix(matrix &A, int &&m, int &n) { //�Ӿ���A��ɾ����m�е�n�к�õ��µľ���
	rows=A.rows-1, cols=A.cols-1;
	p=new int*[rows];
	for(int i=0; i<rows; i++) {
		p[i]=new int[cols];
	}
	for(int i=0; i<A.rows; i++)
		for(int j=0; j<A.cols; j++)
			p[i-(i>m)][j-(j>n)]=A.p[i][j];
}
matrix::~matrix() {
	for(int i=0; i<rows; i++)
		delete[] p[i];
	delete[] p;
}

matrix matrix::multi(int x) { // ����
	matrix tmp(rows, cols);
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			tmp.p[i][j]=p[i][j]*x;
	return tmp;
}

void matrix::out() {  //�������
	/* ������������ݼ��ÿո�ָ� */
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols-1; j++){
			cout<<p[i][j]<<' ';
		}
		cout<<p[i][cols-1]<<endl;
	}	
}

void matrix::input() {
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			cin>>p[i][j];
}

matrix matrix::operator+(matrix &another) { //���ؼӷ�����ʵ�־������
	matrix tmp(rows, cols);
	/* �����Ӧλ��Ԫ����� */
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			tmp.p[i][j]=p[i][j]+another.p[i][j];
	return tmp;
}

matrix matrix::operator*(matrix &another) { //���س˷�����ʵ�־������
	matrix tmp(rows, another.cols);
	for(int i=0; i<rows; i++) {
		for(int j=0; j<another.cols; j++) {
			/* ����A����ĵ�i����B����ĵ�j��Ԫ�ض�Ӧ��˺�֮�ͣ���Ϊ�¾���ĵ�i�е�j��Ԫ�ص�ֵ */
			tmp.p[i][j]=0;
			for(int k=0; k<cols; k++){
				tmp.p[i][j] += p[i][k]*another.p[k][j];
			}
		}
	}
	return tmp;
}

int matrix::det() {
	if (rows==1)
		return p[0][0];
	else {
		int result=0, flag;
		for(int i=0; i<cols; i++) {
			flag=(i%2)?-1:1;
			matrix tmp(*this, 0, i);
			result=result+flag*p[0][i]*tmp.det();    // ʹ�ô�������ʽ������ʽ��ֵ, �ݹ�
		}
		return result;
	}
}
int main() {
	int M,N;
	// A������к���
	cin>>M>>N;
	matrix mA(M, N);    //����A����
	// �������ֵ
	mA.input();
	// ��������ֵ
	int x;
	cin>>x;
	matrix mm1=mA.multi(x);
	mm1.out();
	//B������к���
	int K, L;
	cin>>K>>L;
	matrix mB(K, L);  //����B����
	mB.input();
	/* �����A�;���B�ĺ� */
	if (M==K && N==L) {
		matrix mm2=mA+mB;
		mm2.out();
	}
	/* �����A�;���B�ĳ˻����� */
	if (N==K) {
		matrix mm3=mA*mB;
		mm3.out();
	}
	/* ����A������ʽ��ֵ */
	if (M==N)
		cout<<mA.det()<<endl;
	if (K==L)
		cout<<mB.det()<<endl;
	return 0;
}

