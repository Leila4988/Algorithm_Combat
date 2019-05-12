/*
对本题来说，每个人的记录应该被放在一起，然后每一对on-off时间应该被放在一起
所以可以先对记录进行排序，分块放置，然后再操作，否则记录太过松散，无法操作
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int rate[24];
struct Record{
    char name[25];
    int mo, dd, hh, mm;
    bool isOnline;
}temp, record[1005];

bool cmp(Record a, Record b){
    //char数组的比较，绝不能直接使用==，或者会出错
    //错误的：if(a.name != b.name) return strcmp(a.name, b.name);
    int s = strcmp(a.name, b.name);
    if(s) return s < 0;
    else if(a.mo != b.mo) return a.mo < b.mo;
    else if(a.dd != b.dd) return a.dd < b.dd;
    else if(a.hh != b.hh) return a.hh < b.hh;
    else return a.mm < b.mm;
}

//注意在函数中要改变一个变量的值的话，要使用引用传递
void compute(int on, int off, int& time, int& money){
    temp = record[on];
    //不断增加初始时间，直到等于结束时间
    while(temp.dd < record[off].dd || temp.hh < record[off].hh || temp.mm < record[off].mm){
        time ++;
        money += rate[temp.hh];
        temp.mm ++;
        if(temp.mm >= 60){
            temp.mm = 0;
            temp.hh ++;
        }
        if(temp.hh >= 24){
            temp.hh = 0;
            temp.dd ++;
        }
    }
}

int main(){
    for(int i = 0; i < 24; i++) scanf("%d", &rate[i]);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char sta[10];
        scanf("%s %d:%d:%d:%d %s", record[i].name, &record[i].mo, &record[i].dd, &record[i].hh, &record[i].mm, sta);
        if(strcmp(sta, "on-line") == 0) record[i].isOnline = true;
        else record[i].isOnline = false;
    }
    sort(record, record + n, cmp);
    int on = 0, off, next;
    while(on < n){
        int needprint = 0;
        next = on;
        while(next < n && strcmp(record[on].name, record[next].name) == 0){
            //if-else的判断：至少找到一对on-off
            if(needprint == 0 && record[next].isOnline){
                needprint = 1;
            }
            else if(needprint == 1 && !record[next].isOnline){
                needprint = 2; 
            }
            next ++;
        }
        //没有找到配对
        if(needprint < 2){
            on = next;
            continue;
        }
        int totalMoney = 0;
        printf("%s %02d\n", record[on].name, record[on].mo);
        while(on < next){
            //找到该用户的所有配对
            while(on < next - 1 && !(record[on].isOnline && !record[on + 1].isOnline)){
                on ++;
            }
            off = on + 1;
            //已经输出了所有的配对
            if(off == next){
                on = next;
                break;
            }
            int time = 0, money = 0;
            compute(on, off, time, money);
            totalMoney += money;
            printf("%02d:%02d:%02d ", record[on].dd, record[on].hh, record[on].mm);
            printf("%02d:%02d:%02d %d $%.2f\n", record[off].dd, record[off].hh, record[off].mm, time, money / 100.0);
            on = off + 1; //寻找下一对
        }
        printf("Total amount: $%.2f\n", totalMoney / 100.0 );
    }
    return 0;
}