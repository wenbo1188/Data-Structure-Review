#include <bits/stdc++.h>

using namespace std;

#define MAX_WAIT_TIME 539
typedef struct
{
    int hour;
    int min;
}Time;
typedef struct customer
{
    int transaction;
    int wait_time;
    int leave_time;
    int id;
}customer;
typedef struct window_queue
{
    queue<customer> q;
    int capacity;
    int num_wait;
}w_queue;

int cmp1(w_queue a, w_queue b)
{
    return a.num_wait < b.num_wait;
}

int cmp2(w_queue a, w_queue b)
{
    return a.q.front().transaction < b.q.front().transaction;
}

int cmp3(customer a, customer b)
{
    return a.id < b.id;
}

Time get_time(int wait_time)
{
    int hour = wait_time / 60;
    int min = wait_time % 60;
    Time res = {0};
    res.hour = hour;
    res.min = min;
    return res;
}

int main()
{
    int num_window = 0;
    int capacity = 0;
    int num_customer = 0;
    int num_query = 0;
    int trans_time = 0;
    int now_time = 0;
    int count = 0;
    cin >> num_window >> capacity >> num_customer >> num_query;
    vector<customer> customers(num_customer + 1);
    vector<int> queries(num_query + 1, 0);
    vector<w_queue> window_queues(num_window);
    queue<customer> pub_q;
    vector<customer> res(num_customer + 1);
    for (int i = 0;i < num_window;++i)
    {
        window_queues[i].capacity = capacity;
        window_queues[i].num_wait = 0;
    }
    customers[0].id = 65535;
    for (int i = 1;i <= num_customer;++i)
    {
        cin >> trans_time;
        customers[i].leave_time = 0;
        customers[i].transaction = trans_time;
        customers[i].wait_time = 0;
        customers[i].id = i;
    }
    for (int i = 1;i <= num_query;++i)
    {
        cin >> queries[i];
    }

    // printf("1\n");
    if (num_customer > num_window * capacity)
    {
        for (int i = 1;i <= num_window * capacity;++i)
        {
            sort(window_queues.begin(), window_queues.end(), cmp1);
            window_queues[0].q.push(customers[i]);
            window_queues[0].num_wait++;
        }
        for (int i = num_window * capacity + 1;i <= num_customer;++i)
        {
            pub_q.push(customers[i]);
        }
    }
    else
    {
        for (int i = 1;i <= num_customer;++i)
        {
            sort(window_queues.begin(), window_queues.end(), cmp1);
            window_queues[0].q.push(customers[i]);
            window_queues[0].num_wait++;
        }
    }
    
    // printf("2\n");
    int flag = 0;
    while (now_time <= MAX_WAIT_TIME && flag != 1)
    {
        printf("now: %d\n", now_time);
        sort(window_queues.begin(), window_queues.end(), cmp2);
        int short_work = window_queues[0].q.front().transaction;
        now_time += short_work;
        flag = 1;
        for (int i = 0;i < num_window;++i)
        {
            if (!window_queues[i].q.empty())
            {
                customer cus = window_queues[i].q.front();
                cus.transaction -= short_work;
                if (cus.transaction == 0)
                {
                    window_queues[i].q.pop();
                    cus.wait_time = now_time;
                    res[count++] = cus;
                }
                flag = 0;
            }
        }
        int flag1 = 1;
        while (!pub_q.empty() && flag1 == 1)
        {
            flag1 = 0;
            sort(window_queues.begin(), window_queues.end(), cmp1);
            customer cus = pub_q.front();
            if (window_queues[0].num_wait < window_queues[0].capacity)
            {
                pub_q.pop();
                window_queues[0].q.push(cus);
                flag1 = 1;
            }
        }
    }
    if (!flag)
    {
        for (int i = 0;i < num_window;++i)
        {
            while (!window_queues[i].q.empty())
            {
                customer cus = window_queues[i].q.front();
                window_queues[i].q.pop();
                cus.wait_time = 65535;
                res[count++] = cus;
            }
        }
        while (!pub_q.empty())
        {
            customer cus = pub_q.front();
            pub_q.pop();
            cus.wait_time = 65535;
            res[count++] = cus;
        }
    }
    sort(res.begin(), res.begin() + count, cmp3);

    // printf("3\n");
    Time finish = {0};
    for (int i = 1;i <= num_query;++i)
    {
        printf("query: %d, id: %d, wait_time:%d\n", queries[i], res[queries[i]].id, res[queries[i]].wait_time);
        if (res[queries[i]].wait_time == 65535)
        {
            printf("Sorry\n");
        }
        else
        {
            finish = get_time(res[queries[i]].wait_time);
            printf("%2d:%2d\n", finish.hour, finish.min);
        }
    }

    return 0;
}