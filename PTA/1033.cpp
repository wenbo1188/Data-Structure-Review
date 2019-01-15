#include <bits/stdc++.h>
using namespace std;
#define INF 99999999
 
struct GasStation{
 
    double price;
    double dis;
 
    GasStation(double _p, double _d) : price(_p), dis(_d) {}
 
};
 
int compare(GasStation a, GasStation b){
 
    return a.dis < b.dis;
 
}
 
int main()
{
    int cons,gasCnt;
    double cap;
    double dis;
    double price;
    double dist;
    vector<GasStation> stations;
    cin >> cap >> dis >> cons >> gasCnt;
    double maxToGo = cap * cons;
    for(int i = 0; i < gasCnt; i++){
        scanf("%lf %lf",&price,&dist);
        stations.push_back(GasStation(price,dist));
    }
    sort(stations.begin(),stations.end(),compare);
 
    if(stations[0].dis > 0){
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
 
    int cur = 0;
    double now_cap = 0;
    double sumPrice = 0;
    int curEnd = stations.size();
    double stationPrice = 0;
    double stationDis = 0;
    int hasStation = 0;
    int dest = 0;

    int minPrice = stations[0].price;
    for(int i = 0; i < stations.size(); i++){
        if(stations[i].dis == 0){
            if(minPrice > stations[i].price){
                cur = i;
            }
        }else break;
    }
 
    while(cur < curEnd){
        stationPrice = stations[cur].price;
        stationDis = stations[cur].dis;
        dest = -1;
        hasStation = 0;
 
        for(int i = cur + 1; i < stations.size(); i++){
            if((stations[i].dis - stationDis) <= maxToGo){
                hasStation = 1;
                if(stationPrice > stations[i].price){
                    dest = i;
                    break;
                }
            }else{
                break;
            }
        }
        if(hasStation != 1){
            if((dis - stationDis) <= maxToGo){
                double need = dis - stationDis;
                if(now_cap * cons >= need){
                    break;
                }else{
                    double last = (need - now_cap * cons);
                    sumPrice += (last / cons) * stationPrice;
                    break;
                }
            }else{
                double sumDis = stationDis + cap * cons;
                printf("The maximum travel distance = %.2lf\n",sumDis);
                return 0;
            }
        }else{
            if(dest != -1){
                double need = stations[dest].dis - stationDis;
                if(need <= now_cap * cons){
                    now_cap -= need / cons;
                }else{
                    sumPrice += (need - now_cap * cons) / cons * stationPrice;
                    now_cap = 0;
                }
                cur = dest;
            }else{
                if((dis - stationDis) <= maxToGo){
                    double need = dis - stationDis;
                    if(now_cap * cons < need){
                        sumPrice += (need - now_cap * cons) / cons * stationPrice;
                    }
                    break;
                }
 
 
                int minPrice = INF;
                int minCur = -1;
                for(int i = cur + 1; i < stations.size(); i++){
                    if((stations[i].dis - stationDis) < maxToGo){
                        if(stations[i].price < minPrice){
                            minPrice = stations[i].price;
                            minCur = i;
                        }
                    }else{
                        break;
                    }
                }
                cur = minCur;
                sumPrice += (cap - now_cap) * stationPrice;
                now_cap = cap - (stations[cur].dis - stationDis) / cons;
            }
        }
 
 
    }
    printf("%.2lf\n",sumPrice);
 
    return 0;
}
