#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student{
    char id[10];
    int virtue, talent, sum;
    int flag; 
}stu[100005];

bool cmp(Student a, Student b){
    if(a.flag != b.flag) return a.flag < b.flag;
    else if(a.sum != b.sum) return a.sum > b.sum;
    else if(a.talent != b.talent) return a.virtue > b.virtue;
    //strcmp的用法？？
    else return strcmp(a.id, b.id) < 0;

}

int main(){
    int n, l, h, m;
    scanf("%d %d %d", &n, &l, &h);
    m = n;
    for(int i = 0; i < n; i++){
        scanf("%s %d %d", stu[i].id, &stu[i].virtue, &stu[i].talent);
        stu[i].sum = stu[i].virtue + stu[i].talent;
        if(stu[i].virtue < l || stu[i].talent < l) {
            stu[i].flag = 5;
            m--;
        }
        else if(stu[i].virtue >= h && stu[i].talent >= h) stu[i].flag = 1;
        else if(stu[i].virtue >= h && stu[i].talent < h) stu[i].flag = 2;
        else if(stu[i].virtue < h && stu[i].talent < h && stu[i].virtue >= stu[i].talent) stu[i].flag = 3;
        else stu[i].flag = 4;
    }
    sort(stu, stu + n, cmp);
    printf("%d\n", m);
    for(int i = 0; i < m; i++){
        printf("%s %d %d\n", stu[i].id, stu[i].virtue, stu[i].talent);
    }
    return 0;
}