#include <cstdio>
using namespace std;

struct student{
    char name[15];
    char id[15];
    int score;
}max, min, temp;

//由于题目要求只需输出成绩最高和最低的两组，并且输出格式上也严格一致，
//所以可以只保留要输出的两组，不需要保留中间计算所需的所有数组

int main(){
    max.score = -1;
    min.score = 101;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %s %d", temp.name, temp.id, &temp.score);
        //两种if情况应该是相互独立的，而不是if-else if的组合
        if(max.score < temp.score){
            max = temp;
        }
        if(min.score > temp.score){
            min = temp;
        }
    }
    printf("%s %s\n", max.name, max.id);
    printf("%s %s\n", min.name, min.id);
}