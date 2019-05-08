#include <cstdio>
using namespace std;

int main(){
    int count, drink1, drink2;
    drink1 = drink2 = 0;
    scanf("%d", &count);
    while(count--){
        int say1, do1, say2, do2;
        scanf("%d %d %d %d", &say1, &do1, &say2, &do2);
        /*
        一开始不知道判断条件要怎么设置，看完解析后，发现这道题只要分别把条件限制到甲胜出和乙胜出的情况就行
        不用把所有条件组合的情况列出来，然后再判断在每个组合，分别是甲乙谁胜出
        */
        if(do1 == say1 + say2 && do2 != say1 + say2){
            drink2++;
         }
        else if(do2 == say1 + say2 && do1 != say1 + say2){
            drink1++;
        }
    }
    printf("%d %d\n", drink1, drink2);
    return 0;
}