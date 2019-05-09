/*
（题目范围很可能存在错误，应该如果ABC能够取到2的63次方的话，那么超出了long long所能表示的数据范围，必须使用大整数运算
题目只是简单的进行了大小的比较，而没有要求算出具体的数字，所以可以根据溢出的情况来判断大小
1. A>0,B>0,A+B<0：正溢出，>C
2. A<0,B<0,A+B>=0：负溢出，<C
3. 没有溢出的情况下，正常判断大小
*/

#include <cstdio>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    long long a, b, c;
    for(int i = 1; i <= t; i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a > 0 && b > 0 && a + b < 0){
            printf("Case #%d: true\n", i);
        }
        else if(a < 0 && b < 0 && a + b > 0){
            printf("Case #%d: false\n", i);
        }
        else{
            if(a + b > c) printf("Case #%d: true\n", i);
            else printf("Case #%d: false\n", i);
        }
    }
    return 0;
}