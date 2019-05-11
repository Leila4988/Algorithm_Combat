/*
没仔细读题，也就没注意到对“零多项式”的特判
并且在输出的末尾不能是空格，所以也需要记录输入、输出情况
综上，这个程序不应该是简单的输入一对、计算一对、输出结果，而应该对多项式进行保存
PS: 以后开始写代码前，首先考虑下可行性，在大脑里模拟下算法流程，是否有考虑到所有情况，是否能够满足所有要求
*/

/*原始错误代码如下：
没有考虑到特判情况，没有考虑到结尾输出格式问题
#include <cstdio>
using namespace std;

int main(){
    int in_xi, in_pow;
    int res_xi, res_pow;
    while(scanf("%d %d", &in_xi, &in_pow) != EOF){
        res_xi = in_xi * in_pow;
        res_pow = in_pow - 1;
        if(res_xi) printf("%d %d ", res_xi, res_pow);
    }

}*/

#include <cstdio>
using namespace std;

//如果有多个数组都是一样的大小，那么可以把这个固定大小保存成一个常量，就像在图中常用的顶点数常量
int a[1005] = {0};

//可以用一个数组同时保存原始值和计算结果，这时要注意顺序，不能让有用的原始值被结果覆盖
int main(){
    int k, e, count = 0;
    while(scanf("%d %d", &k, &e) != EOF){
        a[e] = k;
    }
    a[0] = 0;
    for(int i = 1; i <= 1000; i++){
        a[i - 1] = a[i] * i;
        a[i] = 0; //不可省略，应该如果没有指数为i+1的项数，那么a[i]的系数就是0
        if(a[i - 1]) count++;
    }
    if(count == 0) printf("0 0");
    else{
        //应该是递减输出 -> 注意题目中的每一个细节
        for(int i = 1000; i >= 0; i--){
            if(a[i]){
            printf("%d %d", a[i], i);
            count--;
            if(count) printf(" ");
            }
        }
    }
    return 0;
}