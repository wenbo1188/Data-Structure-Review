#include <bits/stdc++.h>
using namespace std;

typedef struct charpair
{
    char left;
    char right;
}Charpair;

vector<Charpair> pairs;

int main()
{
    // freopen("in.txt", "r", stdin);
    char str[100] = {0};
    scanf("%s", str);
    int len = strlen(str);
    int indent = 0;
    int k = 0;
    Charpair tmp;
    for (k = 0;k < len / 2;++k)
    {
        tmp.left = str[k];
        tmp.right = str[len - 1- k];
        pairs.push_back(tmp);
        if (k + 3 > len - 2 * (k + 2))
        {
            break;
        }
    }
    str[len - 1 - k] = '\0';
    indent = len - 2 * (k + 1) - 2;
    for (int i = 0;i < pairs.size();++i)
    {
        printf("%c", pairs[i].left);
        printf("%*s", indent, " ");
        printf("%c\n", pairs[i].right);
    }
    printf("%s\n", str + k + 1);
    return 0;
}