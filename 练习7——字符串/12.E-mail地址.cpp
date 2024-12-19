/*
#include <bits/stdc++.h>
#include <iostream>
#include <regex>
#include <sstream>

using namespace std;

// 使用正则表达式验证电子邮件地址的有效性
bool isValidEmail(string& email) {
    regex emailRegex(R"(([^@\s]+)@([^@\s]+\.[^@\s]+))");
    return regex_match(email, emailRegex);
}

// 在一个包含多个email地址的字符串中计算有效email地址的数量
int countValidEmails(const string& s) {
    istringstream iss(s);
    string email;
    int count = 0;
    while (iss >> email) {
        if (isValidEmail(email)) {
            ++count;
        }
    }
    return count;
}

int main() {
    string s;
    getline(cin, s);
    cout << countValidEmails(s) << endl;
    return 0;
}
*/

#include <bits/stdc++.h>
#include <iostream>
#include <regex>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '@') {
			int l = i-1;
			while(isalpha(s[l]) || isdigit(s[l]) || s[l] == '_'){
				l--;
			}
			while(s[l] == '_' || isdigit(s[l])){
				l++;
			}
			int r = i+1;
			
		}
	}
	return 0;
}

//#include <iostream>
//#include <regex>
//#include <string>
//
//using namespace std;
//
//int count_possible_emails(const string& text) {
//    regex email_pattern(R"([a-zA-Z\w-]*@[a-zA-Z]+(\.[a-zA-Z]+)+)");
//    smatch match;
//    int count = 0;
//    string::const_iterator searchStart(text.cbegin());
//    while (regex_search(searchStart, text.cend(), match, email_pattern)) {
//        ++count;
//        searchStart = match.suffix().first;
//    }
//
//    return count;
//}
//
//int main() {
//    string text = "(x@x.x@x.x_e_@r1.com)";
//    int emailCount = count_possible_emails(text);
//    cout << "Possible valid email addresses found: " << emailCount << endl;
//    return 0;
//}
