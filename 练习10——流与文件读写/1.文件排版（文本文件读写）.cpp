/*
������������
Ӣ�ĵ�Ӱ�в�����Ա����һ����ĳ�ַ�ʽ�����Ű���ʾ������һ��δ�Ű���ļ�listin.txt�����ļ���ÿ�в�����Ա������ð��ldquo:rdquo�ָ���ǰ�������֣�����ʽ�������£����ʣ��ɳ��ո��ˮƽ�Ʊ��֮��������ַ����ɣ�֮������ж���ո��ˮƽ�Ʊ���ָ�����д����Ҫ���䰴�����Ű�����Ű��������һ���ļ�listout.txt�У�
1.�ӱ�׼������������Ϊ�Ű�����и���ð����һ���еĹ̶�λ�ã�����������϶������Ű�����и���ð��ǰ���ַ�������λ�ô�1��ʼ������
2.ð����ߵĵ��ʴ�����ͷΪ��׼����룬��ߵ����һ��������ð��֮���Կո���䣻ð���ұߵĵ��ʴ���ð�Ż�׼����룬���һ�����ʺ�ֻ�лس����з��������������ַ���
3.ð���������ߵĵ��ʼ䶼ֻ��һ���ո�ָ�������Ҫ��ð���������ٸ���һ���ո�
���������ļ���ÿ���ַ�����������100��
��������ʽ��
���Ű�Ĳ�����Ա�����ӵ�ǰĿ¼�µ�listin.txt�ļ��ж��룬��ʾð��λ�õ������ӱ�׼������롣
�������ʽ��
�Ű��Ĳ�����Ա�����������ǰĿ¼�µ�listout.txt�С�
������������
�����ļ�listin.txt����Ϊ��
   Digital Intermediate by :   EFILM 
Supervising    Digital Colorist : STEVEN J. SCOTT  
 Second Colorist :ANDREW FRANCIS
 Digital Intermediate Producer:LOAN PHAN
Digital  Intermediate Editor:  DEVON MILLER     
��ʾð�Ź̶�λ�õ�����Ϊ��
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

