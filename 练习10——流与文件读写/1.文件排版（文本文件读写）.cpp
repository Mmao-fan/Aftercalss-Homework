/*
【问题描述】
英文电影中参演人员名单一般以某种方式进行排版显示。给定一个未排版的文件listin.txt，该文件中每行参演人员名单由冒号ldquo:rdquo分隔成前后两部分，但格式杂乱无章，单词（由除空格和水平制表符之外的其它字符构成）之间可能有多个空格或水平制表符分隔。编写程序，要求将其按如下排版规则排版输出到另一个文件listout.txt中：
1.从标准输入整数，作为排版后所有各行冒号在一行中的固定位置，输入的整数肯定大于排版后所有各行冒号前的字符个数，位置从1开始计数；
2.冒号左边的单词串以行头为基准左对齐，左边的最后一个单词与冒号之间以空格填充；冒号右边的单词串以冒号基准左对齐，最后一个单词后只有回车换行符，不再有其它字符；
3.冒号左右两边的单词间都只有一个空格分隔，并且要求冒号两边至少各有一个空格。
假设输入文件中每行字符个数不超过100。
【输入形式】
待排版的参演人员名单从当前目录下的listin.txt文件中读入，表示冒号位置的整数从标准输入读入。
【输出形式】
排版后的参演人员名单输出到当前目录下的listout.txt中。
【输入样例】
假设文件listin.txt内容为：
   Digital Intermediate by :   EFILM 
Supervising    Digital Colorist : STEVEN J. SCOTT  
 Second Colorist :ANDREW FRANCIS
 Digital Intermediate Producer:LOAN PHAN
Digital  Intermediate Editor:  DEVON MILLER     
表示冒号固定位置的整数为：
40
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//string formatLine(const string& line, int colonPosition) {
//	vector<string> parts = split(line, ':');
//	if (parts.size() != 2) {
//		throw runtime_error("Invalid line format: " + line);
//	}
//	string leftPart = parts[0];
//	string rightPart = parts[1];
//	vector<string> leftWords = split(leftPart, ' ');
//	vector<string> rightWords = split(rightPart, ' ');
//	ostringstream formattedLine;
//	// Format left part
//	for (size_t i = 0; i < leftWords.size(); ++i) {
//		if (i > 0) {
//			formattedLine << ' ';
//		}
//		formattedLine << leftWords[i];
//	}
//	// Calculate padding needed for the colon
//	int padding = colonPosition - formattedLine.str().size() - 1;
//	if (padding < 0) {
//		throw runtime_error("Colon position too small for line: " + line);
//	}
//	// Append colon with padding
//	formattedLine << string(padding, ' ') << ':';
//	// Format right part
//	for (size_t i = 0; i < rightWords.size(); ++i) {
//		if (i > 0 || !leftWords.empty()) { // Ensure at least one space before first word if left part is not empty
//			formattedLine << ' ';
//		}
//		formattedLine << rightWords[i];
//	}
//	return formattedLine.str();
//}

int main() {
	ifstream infile("listin.txt");
	if (!infile.is_open()) {
//		cerr << "Error opening listin.txt" << endl;
		return 1;
	}
	ofstream outfile("listout.txt");
	if (!outfile.is_open()) {
//		cerr << "Error opening listout.txt" << endl;
		return 1;
	}
	int pos;
	cin >> pos;
	string lpart, rpart, s;
	while (getline(infile, lpart, ':'),getline(infile, rpart)) {
//		try {
//			outfile << lpart<<endl<<rpart;
			stringstream ssl(lpart), osl;
			ssl>>ws>>s;
			osl<<s;
			while(ssl>>ws>>s){
				osl<<' '<<s;
			}
			outfile<<left<<setw(pos-1)<<osl.str()<<":";
			stringstream ssr(rpart);
			while(ssr>>ws>>s){
				outfile<<' '<<s;
			}
			outfile<<endl;
//			string fLine = formatLine(line, pos);
//			outfile << fLine << endl;
//		} catch (const exception& e) {
//			cerr << "Error formatting line: " << line << ". Error: " << e.what() << endl;
//		}
	}
	infile.close();
	outfile.close();
	return 0;
}

