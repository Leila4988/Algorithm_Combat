#include <cstdio>
using namespace std;

int main(){
    long long a, b;
    int da, db;
    scanf("%lld %d %lld %d", &a, &da, &b, &db);
    long long pa = 0, pb = 0;
    while(a){
        if(da == a % 10) pa = pa * 10 + da;
        a /= 10;
    }
    while(b){
        if(db == b % 10) pb = pb * 10 + db;
        b /= 10;
    }
    /*不需要变量res存储（pa + pa）的结果
    long long res = pa + pb;
    printf("%lld\n", res);*/
    printf("%lld\n", pa + pb);
    return 0;
}