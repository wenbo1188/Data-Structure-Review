#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    char name[20];
    char password[20];
}Account;

int replace_password(char *password, int len)
{
    int flag = 0;
    for (int i = 0;i < len;++i)
    {
        if (password[i] == '1')
        {
            password[i] = '@';
            flag = 1;
        }
        else
        {
            if (password[i] == '0')
            {
                password[i] = '%';
                flag = 1;
            }
            else
            {
                if (password[i] == 'l')
                {
                    password[i] = 'L';
                    flag = 1;
                }
                else
                {
                    if (password[i] == 'O')
                    {
                        password[i] = 'o';
                        flag = 1;
                    }
                }
            }
        }
    }
    if (flag)
    {
        return 1;
    }
    return 0;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int M = 0;
    vector<Account> modified;
    char name[20] = {0};
    char password[20] = {0};
    scanf("%d", &M);
    int modify = 0;
    Account tmp = {0};
    for (int i = 0;i < M;++i)
    {
        scanf("%s %s", name, password);
        strcpy(tmp.name, name);
        strcpy(tmp.password, password);
        if (replace_password(tmp.password, strlen(tmp.password)))
        {
            ++modify;
            modified.push_back(tmp);
        }
    }
    if (modify)
    {
        cout << modify << endl;
        for (int i = 0;i < modified.size();++i)
        {
            printf("%s %s\n", modified[i].name, modified[i].password);
        }
    }
    else
    {
        if (M == 1)
        {
            printf("There is 1 account and no account is modified\n");
        }
        else
        {
            printf("There are %d accounts and no account is modified\n", M);
        }
    }
    
    return 0;
}