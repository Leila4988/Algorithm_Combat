#include <cstdio>
using namespace std;

//一开始没有注意到系数的数据类型应该是double
//可以考虑只开一个数组，然后把第二个多项式加到第一个多项式上
double p1[1005], p2[1005], res[1005];

int main(){
    int n1, n2, e, count = 0;
    double k;
    scanf("%d", &n1);
    for(int i = 0; i < n1; i++){
        scanf("%d %lf", &e, &k);
        p1[e] = k;
    }
    scanf("%d", &n2);
    for(int i = 0; i < n2; i++){
        scanf("%d %lf", &e, &k);
        p2[e] = k;
    }
    for(int i = 0; i <= 1000; i++){
        if(p1[i] != 0 || p2[i] != 0){
            //注意如果res[i]计算得0，那么count不应该加1
            res[i] = p1[i] + p2[i];
            if(res[i]) count ++;
        }
    }
    printf("%d", count);
    for(int i = 1000; i >= 0; i--){
        if(res[i] != 0){
            printf(" %d %.1lf", i, res[i]);
        }
    }
}