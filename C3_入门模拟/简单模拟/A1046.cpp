/*
一开始只想到了把总路程sum计算出来，然后每次比较的时候直接先统计顺时针的距离，再用sum去减
没有想到dist数组可以保存距统一起点的距离，然后通过“作差”的方法简略快速的求两点间的距离
*/

#include <cstdio>
#include <fstream>
using namespace std;

int dist[100010];

int main(){
    ifstream fin("/Users/paopao/Documents/保研/程序/simple/test.txt", ios::out | ios::in);
    if(!fin) printf("error");
    int n, m, dis, sum = 0;
    // scanf("%d", &n);
    fin >> n;
    //注意应该从i=1开始存储，当i=0时，dist[0]表示的是1到1的位置，无意义
    //如果不是从i=1开始存储，dist[i-2]才是i到1的距离
    for(int i = 1; i <= n; i++){
        // scanf("%d", &dis);
        fin >> dis;
        sum += dis;
        dist[i] = sum;
    }
    // scanf("%d", m);
    fin >> m;
    int left, right;
    for(int i = 0; i < m; i++){
        // scanf("%d %d", &left, &right);
        fin >> left >> right;
        int temp;
        //应该要处理left>right的情况，直接反向求
        //最后一个点到起点的距离dist不会被用到（会被反向），所以不会对结果产生影响
        if(left > right) temp = dist[left - 1] - dist[right - 1];
        else temp = dist[right - 1] - dist[left - 1];

        if(temp < sum - temp) printf("%d\n", temp);
        else printf("%d\n", sum - temp);
    }

    return 0;
}
