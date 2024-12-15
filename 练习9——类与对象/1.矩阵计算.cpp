/*
【问题描述】
       矩阵是线性代数中的重要概念，应用领域非常广泛，在C/C++中，通常将矩阵定义为一个二维数组。
       本问题中，将输入两个矩阵 A 和 B，实现对矩阵的数乘、矩阵加法、矩阵乘法以及行列式的计算。
       如果对矩阵的算法不了解，请查阅相关资料。
【输入形式】
       输入的第一行为两个正整数 M 和 N，分别表示矩阵 A 的行数和列数；
       接下来的 M 行，每行 N 个用空格分隔的整数，表示矩阵 A 的元素值；
       接下来的一行，为一个整数 x,  用于对矩阵 A 进行数乘；
       接下来的一行为两个正整数 K 和 L, 分别表示矩阵 B 的行数和列数；
       接下来的 K 行，每行为 L 个用空格分隔的整数，表示矩阵 B 的元素值。
【输出形式】
       输出的第一部分为 M 行，每行为 N 个用空格分隔的整数，表示 x 数乘 A 的结果；
       接下来(如果有），如果 A 和 B 可以相加，则输出 M 行，每行为 N 个用空格分隔的整数，表示矩阵 A+B 的结果；
       接下来(如果有），如果 A 和 B 可以相乘，则输出 M 行，每行为 L 个用空格分隔的整数，表示矩阵 A×B 的结果；
       接下来一行(如果有），如果 A 的行列式存在，则输出一个整数，表示 A 的行列式的值；
       接下来一行(如果有），如果 B 的行列式存在，则输出一个整数，表示 B 的行列式的值。
【样例输入1】
2 2
29 51
7 84
9
2 9
1 1 4 8 5 7 4 5 9
2 5 5 1 6 1 4 8 6
【样例输出1】
261 459
63 756
131 284 371 283 451 254 320 553 567
175 427 448 140 539 133 364 707 567
2079
【样例输入2】
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
【样例输出2】
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
【样例输入3】
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
【样例输出3】
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
【样例输入4】
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
【样例输出4】
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

		matrix multi(int x);   // 数乘
		int det();           // 计算行列式
		void out();    //输出矩阵
		void input();

		matrix operator+(matrix &another); //重载加法运算实现矩阵相加
		matrix operator*(matrix &another); //重载乘法运算实现矩阵相乘
};
matrix::matrix(int &M, int &N) {
	rows=M, cols=N;
	p=new int*[rows];
	for(int i=0; i<M; i++) {
		p[i]=new int[cols];
	}
}
matrix::matrix(matrix &A, int &&m, int &n) { //从矩阵A中删除第m行第n列后得到新的矩阵
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

matrix matrix::multi(int x) { // 数乘
	matrix tmp(rows, cols);
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			tmp.p[i][j]=p[i][j]*x;
	return tmp;
}

void matrix::out() {  //输出矩阵
	/* 逐行输出，数据间用空格分隔 */
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

matrix matrix::operator+(matrix &another) { //重载加法运算实现矩阵相加
	matrix tmp(rows, cols);
	/* 矩阵对应位置元素相加 */
	for(int i=0; i<rows; i++)
		for(int j=0; j<cols; j++)
			tmp.p[i][j]=p[i][j]+another.p[i][j];
	return tmp;
}

matrix matrix::operator*(matrix &another) { //重载乘法运算实现矩阵相乘
	matrix tmp(rows, another.cols);
	for(int i=0; i<rows; i++) {
		for(int j=0; j<another.cols; j++) {
			/* 计算A矩阵的第i行与B矩阵的第j列元素对应相乘后之和，作为新矩阵的第i行第j列元素的值 */
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
			result=result+flag*p[0][i]*tmp.det();    // 使用代数余子式求行列式的值, 递归
		}
		return result;
	}
}
int main() {
	int M,N;
	// A矩阵的行和列
	cin>>M>>N;
	matrix mA(M, N);    //生成A矩阵
	// 输入矩阵值
	mA.input();
	// 输入数乘值
	int x;
	cin>>x;
	matrix mm1=mA.multi(x);
	mm1.out();
	//B矩阵的行和列
	int K, L;
	cin>>K>>L;
	matrix mB(K, L);  //生成B矩阵
	mB.input();
	/* 求矩阵A和矩阵B的和 */
	if (M==K && N==L) {
		matrix mm2=mA+mB;
		mm2.out();
	}
	/* 求矩阵A和矩阵B的乘积矩阵 */
	if (N==K) {
		matrix mm3=mA*mB;
		mm3.out();
	}
	/* 矩阵A的行列式的值 */
	if (M==N)
		cout<<mA.det()<<endl;
	if (K==L)
		cout<<mB.det()<<endl;
	return 0;
}

