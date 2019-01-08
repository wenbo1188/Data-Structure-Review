#include <bits/stdc++.h>

using namespace std;

#define ONLINE 1
#define OFFLINE 0
#define DAY (24 * 60)
#define HOUR 60
#define MAX 1010

typedef struct record
{
    char name[30];
    int day;
    int hour;
    int min;
    int state;
}Record;

typedef struct bill
{
    char start[30];
    char end[30];
    int duration;
    float charge;
}Bill;

typedef struct customer
{
    char name[30];
    deque<Record> records;
    deque<Bill> bills;
}Customer;

vector<int> cost_table(24, 0);

int cmp1(Record a, Record b)
{
    return a.day < b.day;
}

int cmp2(Record a, Record b)
{
    return a.hour < b.hour;
}

int cmp3(Record a, Record b)
{
    return a.min < b.min;
}

int cmp4(Customer a, Customer b)
{
    if (strcmp(a.name, b.name) < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_duration(Record start, Record end)
{
    return (end.day - start.day) * DAY + (end.hour - start.hour) * HOUR + (end.min - start.min);
}

float get_all_day()
{
    float charge = 0.0;
    for (int i = 0;i < 24;++i)
    {
        charge += 60.0 * cost_table[i];
    }
    return charge;
}

float get_fee(Record start, Record end)
{
	float sum=0.0;
	float daycost=0.0;

	for(int i=0; i < 24; i++){
		daycost += cost_table[i] * 60;
	}
	sum += (end.day - start.day) * daycost;
	
	if(start.hour < end.hour){
		sum = sum + (60-start.min) * cost_table[start.hour] + (end.min)*cost_table[end.hour];
		for(int i=start.hour+1; i<end.hour; i++){
			sum += cost_table[i]*60;
		}
	}
	else{
		sum = sum-(60-end.min)*cost_table[end.hour]-(start.min)*cost_table[start.hour];
		for(int i=end.hour+1; i<start.hour; i++){
			sum -= cost_table[i]*60;
		}
	}

	return sum;
}

int main()
{
    int num_record = 0;
    for (int i = 0;i < 24;++i)
    {
        cin >> cost_table[i];
    }
    cin >> num_record;
    deque<Customer> customers;
    Record tmp = {0};
    Customer customer = {0};
    int month = 0;
    char s[10] = {0};
    for (int i = 0;i < num_record;++i)
    {
        tmp = {0};
        customer = {0};
        scanf("%s %d:%d:%d:%d %s", tmp.name, &month, &tmp.day, &tmp.hour, &tmp.min, s);
        if (strcmp(s, "on-line") == 0)
        {
            tmp.state = ONLINE;
        }
        else
        {
            tmp.state = OFFLINE;
        }
        int flag = 0;
        for (int i = 0;i < customers.size();++i)
        {
            if (strcmp(customers[i].name, tmp.name) == 0)
            {
                customers[i].records.push_back(tmp);
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            strcpy(customer.name, tmp.name);
            customer.records.push_back(tmp);
            customers.push_back(customer);
        }
    }

    sort(customers.begin(), customers.end(), cmp4);
    for (int i = 0;i < customers.size();++i)
    {
        sort(customers[i].records.begin(), customers[i].records.end(), cmp3);
        sort(customers[i].records.begin(), customers[i].records.end(), cmp2);
        sort(customers[i].records.begin(), customers[i].records.end(), cmp1);
        stack<Record> s;
        Record tmp = {0};
        Bill b = {0};
        float total_charge = 0.0;
        for (int j = 0;j < customers[i].records.size();++j)
        {
            if (customers[i].records[j].state == OFFLINE)
            {
                if (!s.empty())
                {
                    tmp = s.top();
                    if (tmp.state == ONLINE)
                    {
                        int duration = get_duration(tmp, customers[i].records[j]);
                        float charge = get_fee(tmp, customers[i].records[j]);

                        b = {0};
                        sprintf(b.start, "%02d:%02d:%02d", tmp.day, tmp.hour, tmp.min);
                        sprintf(b.end, "%02d:%02d:%02d", customers[i].records[j].day, customers[i].records[j].hour, customers[i].records[j].min);
                        b.duration = duration;
                        b.charge = charge / 100.0;
                        // printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", tmp.day, tmp.hour, tmp.min, customers[i].records[j].day, customers[i].records[j].hour, customers[i].records[j].min, duration, charge / 100.0);
                        total_charge += charge;
                        customers[i].bills.push_back(b);
                    }
                    s.pop();
                }
            }
            else
            {
                if (!s.empty())
                {
                    s.pop();
                    s.push(customers[i].records[j]);
                }
                else
                {
                    s.push(customers[i].records[j]);
                }
            }
        }
        // printf("Total amount: $%.2f\n", total_charge / 100.0);
        if (total_charge != 0.0)
        {
            printf("%s %02d\n", customers[i].name, month);
            for (int j = 0;j < customers[i].bills.size();++j)
            {
                printf("%s %s %d $%.2f\n", customers[i].bills[j].start, customers[i].bills[j].end, customers[i].bills[j].duration, customers[i].bills[j].charge);
            }
            printf("Total amount: $%.2f\n", total_charge / 100.0);
        }
    }

    return 0;
}

/*
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
*/