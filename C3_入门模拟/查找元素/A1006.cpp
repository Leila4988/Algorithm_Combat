/*
如果在main函数中，数据的比较有点复杂（不能简单的用小于或大于符号比较），最好先写比较函数
*/

#include <cstdio>
using namespace std;

struct person{
    char id[20];
    int hh, mm, ss;
}temp, early, late;

bool greater(person a, person b){
    if(a.hh != b.hh) return a.hh >= b.hh;
    else if(a.mm != b.mm) return a.mm >= b.mm;
    else return a.ss >= b.ss;
}

//初始签到时间应该最大，签离时间应该最小（不要设反了！！）
void init(){
    late.hh = late.mm = late.ss = 0;
    //不需要考虑真实时间的合法性，只需把每个数字设置到最大即可
    early.hh = 24;
    early.mm = early.ss = 60;
}

int main(){
    int m;
    init();
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        //%s对应的数据前不需要加&
        scanf("%s %d:%d:%d", temp.id, &temp.hh, &temp.mm, &temp.ss);
        if(!greater(temp, early)) early = temp;
        scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
        if(greater(temp, late)) late = temp;
    }
    printf("%s %s", early.id, late.id);
    return 0;
}