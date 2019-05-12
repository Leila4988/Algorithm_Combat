#include <cstdio>
using namespace std;

int schools[100010];

int main(){
    //使用max暂存最大成绩，节约数组访问的时间
    int n, num, score, k, max = -1;
    scanf("%d", &n);
    //注意从1开始编号
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &num, &score);
        schools[num] += score;
        if(schools[num] > max){
            k = num;
            max = schools[num];
        }
    }

    printf("%d %d", k, max);

}