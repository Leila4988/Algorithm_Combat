/*没有深入思考题意，分析题目
忘记int在做除法时，原本就是四舍五入的，不需要自己先得到double，再去四舍五入

*/
#include <cstdio>
using namespace std;

int main(){
    int c1, c2, CLK_TCK = 100;
    scanf("%d %d", &c1, &c2);
    int dura = c2 - c1;
    if(dura % CLK_TCK >= 50){
        dura = dura / CLK_TCK + 1;
    }else{
        dura = dura / CLK_TCK;
    }
    /*习惯在printf结尾加上\n
    printf("%02d:%02d:%02d", dura / 3600, dura % 3600 / 60, dura % 60);*/
    printf("%02d:%02d:%02d\n", dura / 3600, dura % 3600 / 60, dura % 60);
    return 0;
}
