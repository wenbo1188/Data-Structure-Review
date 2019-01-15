#include<iostream>
#include<stdio.h>
#include<map>
#include<set>
#include<string>
using namespace std;
 
map<string, set<int>> mTitle, mAuthor, mKey, mPub, mYear;
 
void query(map<string, set<int>>& m, string& str)
{
	if (m.find(str) == m.end())
		printf("Not Found\n");
	else
	{
		for (set<int>::iterator it = m[str].begin(); it != m[str].end(); it++)
			printf("%07d\n", *it);
	}
}
 
int main()
{
	int n, m, id, type;
	string title, author, key, pub, year;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &id);
		char c = getchar();
 
		getline(cin, title);
		mTitle[title].insert(id);
 
		getline(cin, author);
		mAuthor[author].insert(id);
 
		while (cin>>key)
		{
			mKey[key].insert(id);
			c = getchar();
			if (c == '\n')
				break;
		}
 
		getline(cin, pub);
		mPub[pub].insert(id);
 
		getline(cin, year);
		mYear[year].insert(id);
	}
 
	string tmp;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d: ", &type);
		getline(cin, tmp);
		cout << type << ": " << tmp << endl;
		if (type == 1)
			query(mTitle, tmp);
		else if (type == 2)
			query(mAuthor, tmp);
		else if (type == 3)
			query(mKey, tmp);
		else if (type == 4)
			query(mPub, tmp);
		else
			query(mYear, tmp);
	}
	return 0;
}
