#include <cstdio>
using namespace std;

char str[3] = {'W', 'T', 'L'}, res[3];

int main(){
    //注意数据类型，这道题中又粗心的把数据类型设为int了
    double num, index, max = 0.0, total = 1.0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%lf", &num);
            if(num > max) {
                max = num;
                res[i] = str[j];
            }
        }
        total *= max;
        max = 0.0;
    }
    for(int i = 0; i < 3; i++) printf("%c ", res[i]);
    double ans = (total * 0.65 - 1) * 2;
    printf("%.2lf", ans);
    return 0;
}