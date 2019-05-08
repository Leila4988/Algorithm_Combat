#include <cstdio>
using namespace std;

int main(){
    int t, count = 0;
    scanf("%d", &t);
    while(t--){
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        count ++;
        if(a + b > c) printf("Case #%d: true\n", count);
        else printf("Case #%d: false\n", count);
    }
    return 0;
}