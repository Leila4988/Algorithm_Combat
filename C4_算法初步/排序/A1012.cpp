/*
这道题是排名题，排名题是在排序的基础上，为每一个元素再加上一个排名
排名题要注意并列排名，在并列排名之后的元素名次增加数量不等
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int ranker[1000005][4] = {0};
char sub[4] = {'A', 'C', 'M', 'E'}; 

struct Student{
    int id;
    int score[4];
}stu[2010];

int kind;

bool cmp(Student a, Student b){
    return a.score[kind] > b.score[kind];
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = stu[i].score[1] + stu[i].score[2] + stu[i].score[3];
    }
    for(kind = 0; kind < 4; kind++){
        sort(stu, stu + n, cmp);
        ranker[stu[0].id][kind] = 1;
        for(int i = 1; i < n; i++){
            if(stu[i].score[kind] == stu[i - 1].score[kind]) 
               ranker[stu[i].id][kind] = ranker[stu[i - 1].id][kind];
            else ranker[stu[i].id][kind] = i + 1;
        }
    }
    int inq;
    for(int i = 0; i < m; i++){
        scanf("%d", &inq);
        int high = 10000000, k;
        for(int i = 0; i < 4; i++){
            if(ranker[inq][i] < high){
                high = ranker[inq][i];
                k = i;
            }
        }
        if(high != 0) printf("%d %c\n", high, sub[k]);
        else printf("N/A\n");
    }
    return 0;
}