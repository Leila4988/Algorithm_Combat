/*
本题不需要非得把与今天日期的相差天数算出来，只需按照年、月、日的顺序依次比较大小即可
依然是使用一边输入一边判断的方法
*/

#include <cstdio>
using namespace std;

struct person{
    char name[10];
    int yy, mm, dd;
}min, max, left, right, temp;

bool lessThan(person a, person b){
    if(a.yy != b.yy) return a.yy <= b.yy;
    else if(a.mm != b.mm) return a.mm <= b.mm;
    else return a.dd <= b.dd;
}

bool moreThan(person a, person b){
    if(a.yy != b.yy) return a.yy >= b.yy;
    else if(a.mm != b.mm) return a.mm >= b.mm;
    else return a.dd >= b.dd;
}

void init(){
    min.yy = left.yy = 1814;
    max.yy = right.yy = 2014;
    min.mm = left.mm = max.mm = right.mm = 9;
    min.dd = left.dd = max.dd = right.dd = 6;
}
int main(){
    init();
    int n, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        //利用scanf函数的格式技巧的把年月日分开
        //使用整数输入方法把"06"转化为6，具体规则？？？
        scanf("%s %d/%d/%d", temp.name, &temp.yy, &temp.mm, &temp.dd);
        if(lessThan(temp, right) && moreThan(temp, left)){
            count ++;
            //最大日期和最小日期可能同时更新，所以不能使用if-else结构
            if(lessThan(temp, max)){
                max = temp;
            }
            if(moreThan(temp, min)){
                min = temp;
            }
        }
    }
    //特殊情况不能忘记
    if(count == 0) printf("0\n");
    printf("%d ", count);
    printf("%s ", max.name);
    printf("%s ", min.name);
}