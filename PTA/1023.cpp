#include <bits/stdc++.h>
using namespace std;
int cnt1[10] = { 0 }, cnt2[10] = {0};
 
int main(){
	string s;
	cin >> s;
	string s2 = s;
	for (int i = 0; i < s.size(); i++){
		cnt1[s[i] - '0']++;
	}
	int carry = 0;
	for (int i = s.size() - 1; i >= 0; i--){
		s2[i] = ((s[i] - '0') * 2 + carry )% 10 + '0';
		carry = ((s[i] - '0') * 2 + carry) / 10;
	}
	if (carry){
		char c = carry + '0';
		s2 = c + s2;
		cout << "No\n" << s2 << endl;
		return 0;
	}
	for (int i = 0; i < s2.size(); i++){
		cnt2[s2[i] - '0']++;
	}
	bool flag = true;
	for (int i = 0; i < 10; i++){
		if (cnt1[i] != cnt2[i]){
			flag = false;
			break;
		}
	}
	if (flag) cout << "Yes" << "\n" << s2 << endl;
	else cout << "No\n" << s2;
	return 0;
}