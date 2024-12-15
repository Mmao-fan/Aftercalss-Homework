/*
������������
    �����������У�����ѧ���Ľṹ��student��¼��ѧ����Ϣ�������뵽�������ļ�grade.bin�У�Ҫ�������ǰ����ܳɼ��Ӵ�С��˳��洢�����ݿ��Էֶ��¼�룬ÿ��¼��ǰ��������ʾ�ļ������е����ݣ��������ʽ���£�
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
   ����ʾInput continue(y/n)?������'y'������Լ������룬�����˳���������������ݽ������е����ݽ������°��ִܷӴ�С��˳�����к�����д���ļ�grade.bin�С�
��������ʽ��
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
    ����ṹ��student���ڱ�ʾѧ���Ļ�����Ϣ����������ṹ
*/
struct student {
	int no;                       // ѧ��
	char name[20], sex;           // �����Լ��Ա�, ��˼�������name[20]�޸�Ϊ*name������������������ʺϱ���Ĵ���ʽ��
	int age;                      // ����
	float chinese, computer;      // ��ʾ���ſγ̵ĳɼ�
	student *next;
	bool operator<(const student &another) const {    // ��������� < (С��)�����ڽṹ�����֮��ıȽϣ���LinkSort�бȽ�����������ڵ��С
//		return (	);
		return ((chinese+computer) < (another.chinese+another.computer));
	}
};

student* ReadFile(ifstream& infile, student *head, int &n);  // �Ӷ������ļ�(�ļ�ָ��Ϊfp)�н��������ݶ��룬�洢����headΪͷָ���������
void display(student *head);                         // ������ʾ���������
void WriteFile(ofstream& outfile, student *head);             // ����headΪͷָ��������е�����д��������ļ�(�ļ�ָ��Ϊfp)
student* input(student *head, int &n);               // �����µ����ݣ������������ӵ�����ĩβ
student* LinkSort(student *head, const int &n);      // ʵ�ֶ���������򣬰��ܳɼ��Ӵ�С���У�ð������
void swapNode(student *s, student *q);               // ʵ�ֶ�����ڵ�����ݽ�������������, �ں���LinkSort�е���

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

