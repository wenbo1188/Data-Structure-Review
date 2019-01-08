#include <bits/stdc++.h>

using namespace std;

#define MAX 50
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Binode, *Bitree;

vector<int> postorder(MAX, 0);
vector<int> inorder(MAX, 0);

Binode *build_tree(int postleft, int postright, int inleft, int inright)
{
    Binode *root = (Binode *)malloc(sizeof(Binode));
    int leftnum = 0;
    int rightnum = 0;
    root->data = postorder[postright];
    for (int i = inleft;i <= inright;++i)
    {
        if (inorder[i] == root->data)
        {
            leftnum = i - inleft;
            rightnum = inright - i;
            break;
        }
    }

    if (leftnum)
    {
        root->left = build_tree(postleft, postleft + leftnum - 1, inleft, inleft + leftnum - 1);
    }
    else
    {
        root->left = NULL;
    }
    if (rightnum)
    {
        root->right = build_tree(postright - rightnum, postright - 1, inright - rightnum + 1, inright);
    }
    else
    {
        root->right = NULL;
    }
    
    return root;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int num_node = 0;
    cin >> num_node;
    for (int i = 0;i < num_node;++i)
    {
        cin >> postorder[i];
    }
    for (int i = 0;i < num_node;++i)
    {
        cin >> inorder[i];
    }

    Bitree root = build_tree(0, num_node - 1, 0, num_node - 1);
    queue<Binode *> q;
    q.push(root);
    int flag = 1;
    printf("%d", root->data);
    while (!q.empty())
    {
        Binode *tmp = q.front();
        if (flag == 0)
        {
            printf(" %d", tmp->data);
        }
        q.pop();
        if (tmp->left)
        {
            q.push(tmp->left);
        }
        if (tmp->right)
        {
            q.push(tmp->right);
        }
        free(tmp);
        flag = 0;
    }
    return 0;
}