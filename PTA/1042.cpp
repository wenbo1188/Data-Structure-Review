#include <bits/stdc++.h>
using namespace std;

vector<string> cards_before;
vector<string> cards_after(54);
vector<int> pos;

char card_type[4] = {'S', 'H', 'C', 'D'};

int main()
{
    // freopen("in.txt", "r", stdin);
    int k = 0;
    scanf("%d", &k);
    string card;
    int p = 0;
    for (int i = 0;i < 4;++i)
    {
        for (int j = 0;j < 13;++j)
        {
            card = " ";
            card[0] = card_type[i];
            card = card + to_string(j + 1);
            // cout << card << endl;
            cards_before.push_back(card);
        }
    }
    cards_before.push_back("J1");
    cards_before.push_back("J2");
    for (int i = 0;i < 54;++i)
    {
        scanf("%d", &p);
        pos.push_back(p);
    }
    // printf("1");
    for (int i = 0;i < k;++i)
    {
        if (i != 0)
        {
            for (int q = 0;q < 54;++q)
            {
                cards_before[q] = cards_after[q];
            }
        }
        for (int j = 0;j < 54;++j)
        {
            cards_after[pos[j] - 1] = cards_before[j];
        }
    }

    // printf("2");
    for (int i = 0;i < cards_after.size() - 1;++i)
    {
        cout << cards_after[i] << " ";
    }
    cout << cards_after[cards_after.size() - 1] << endl;

    return 0;
}