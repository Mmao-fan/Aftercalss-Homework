/*
【问题描述】
    在以下问题中，定义学生的结构体student，录入学生信息，并存入到二进制文件grade.bin中，要求存入的是按照总成绩从大到小的顺序存储，数据可以分多次录入，每次录入前，都将显示文件中已有的数据，其具体形式如下：
No: 3
Name: Hong
Sex: F
Age: 9
Scores: 123.000000 531241.000000

No: 2
Name: Zhang
Sex: F
Age: 98
Scores: 123.000000 434.000000

No: 1
Name: Wang
Sex: M
Age: 32
Scores: 12.000000 54.000000

Input continue(y/n)?
   在提示Input continue(y/n)?下输入'y'，则可以继续输入，否则将退出。继续输入的内容将与现有的数据进行重新按总分从大到小的顺序排列后重新写入文件grade.bin中。
【输入形式】
Input continue(y/n)?y
No: 15
Name: LiuYing
Sex(M/F): M
Age: 25
Chinese score: 100
Computer score: 85
Input continue(y/n)?y
No: 16
Name: WangLiLi
Sex(M/F): F
Age: 23
Chinese score: 95.5
Computer score: 68.8
Input continue(y/n)?n
*/
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

/*
    定义结构体student用于表示学生的基本信息，采用链表结构
*/
struct student {
	int no;                       // 学号
	char name[20], sex;           // 姓名以及性别, 请思考如果将name[20]修改为*name，结果将会怎样，还适合本题的处理方式吗？
	int age;                      // 年龄
	float chinese, computer;      // 表示两门课程的成绩
	student *next;
	bool operator<(const student &another) const {    // 重载运算符 < (小于)，用于结构体对象之间的比较，在LinkSort中比较链表的两个节点大小
//		return (	);
		return ((chinese+computer) < (another.chinese+another.computer));
	}
};

student* ReadFile(ifstream& infile, student *head, int &n);  // 从二进制文件(文件指针为fp)中将所有数据读入，存储于以head为头指针的链表中
void display(student *head);                         // 用于显示链表的内容
void WriteFile(ofstream& outfile, student *head);             // 将以head为头指针的链表中的数据写入二进制文件(文件指针为fp)
student* input(student *head, int &n);               // 输入新的数据，将新数据连接到链表末尾
student* LinkSort(student *head, const int &n);      // 实现对链表的排序，按总成绩从大到小排列，冒泡排序
void swapNode(student *s, student *q);               // 实现对链表节点的数据交换，用于排序, 在函数LinkSort中调用

int main() {
	int n = 0;
	student *head = NULL;

	ifstream getf;
//
	getf.open("grade.bin", ios::binary);
	head = ReadFile(getf, head, n);
	display(head);
	getf.close();

	head = input(head, n);
	head = LinkSort(head, n);

	ofstream putf;
//
	putf.open("grade.bin", ios::binary);
	WriteFile(putf, head);
	putf.close();

	return 0;
}

student* ReadFile(ifstream& infile, student* head, int &n) {
//
//	infile.open("grade.bin", ios::binary);
//	if (!infile) {
//		cout << "Unable to open file" << endl;
//		return head;
//	}
	student *temp;
	while (infile) {
		temp = new student;
		if (infile.read((char*)temp, sizeof(student))) {
			temp->next = head;
			head = temp;
			n++;
		} else {
			delete temp;
		}
	}
//	infile.close();
	return head;
}

void display(student* head) {
	student *p = head;
	while(p) {
		printf("No: %d\n", p->no);
		printf("Name: %s\n", p->name);
		printf("Sex: %c\n", p->sex);
		printf("Age: %d\n", p->age);
		printf("Scores: %f %f\n\n", p->chinese, p->computer);
		p = p->next;
	}
}

student* input(student* head, int &n) {
	student *q = head;
	if (head)
		while(q->next) q = q->next;
	while(1) {
		printf("Input continue(y/n)?");
		if (getchar() != 'y')
			break;
		student *p = new student;
		printf("No: ");
		scanf("%d", &p->no);
		getchar();
		printf("Name: ");
		//     gets(p->name);
		cin.getline(p->name, 20);
		printf("Sex(M/F): ");
		p->sex = getchar();
		printf("Age: ");
		scanf("%d", &p->age);
		printf("Chinese score: ");
		scanf("%f", &p->chinese);
		printf("Computer score: ");
		scanf("%f", &p->computer);
		p->next = NULL;
		getchar();
		if (!head)
			head = p;
		else
			q->next = p;
		q = p;
		n++;
	}
	return head;
}

student* LinkSort(student* head, const int &n) {
	student *p;
	for(int i = 1; i <= n - 1; i++) {
		p = head;
		for(int j = 1; j <= n - i; j++) {
			if (*p < *p->next) {
//				swapNode();
				swapNode(p, p->next);
			}
			p = p->next;
		}
	}

	return head;
}

void swapNode(student* s, student* q) {
	student *snext = s->next, *qnext = q->next, tmp;
	tmp = *s;
	*s = *q;
	*q = tmp;
	s->next = snext;
	q->next = qnext;
}

void WriteFile(ofstream& outfile, student* head) {
//
//	outfile.open("grade.bin", ios::binary);
//	if (!outfile) {
//		cout << "Unable to open file" << endl;
//		return;
//	}
	student *temp = head;
	while (temp) {
		outfile.write((char*)temp, sizeof(student));
		temp = temp->next;
	}
//	outfile.close();
}

