/*
题目中是根据试机座位号来查询信息，所以索引应该是试机座位号
而试机座位号是顺序排列，并且不会重复，所以可以用数据下标实现试机座位号的索引
由于题目输出中包含了准考证号和考试座位号，所以数组需要存储两个信息，可以用结构体来存储
*/

#include <cstdio>
using namespace std;

struct student{
    //此处用的long long，而不是cstring，为什么？
    long long stu_id;
    int seat_id;
}students[1010];

int main(){
    int n, m, seat_id, test_id;
    long long stu_id;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld %d %d", &stu_id, &test_id, &seat_id);
        students[test_id].stu_id = stu_id;
        students[test_id].seat_id = seat_id;
    }
    scanf("%d", &m);
    int inq_id;
    for(int i = 0; i < m; i++){
        scanf("%d", &inq_id);
        if(inq_id > 0 && inq_id <= 1000){
            printf("%lld %d\n", students[inq_id].stu_id, students[inq_id].seat_id);
        }
    }
    return 0;
}