/*
根据石头剪刀布的循环相克规律，可以得到一个胜出圈，在箭头出发端的节点会赢过被箭头指向的节点
根据这种规律，可以使用循环队列里的求模计算得到甲胜、平局和乙胜三种情况下，两个元素的相对位置
*/
#include <cstdio>
using namespace std;

//把每个字母映射到数字上，这种思想经常会用到
int change(char a){
    if(a == 'B') return 0;
    else if(a == 'C') return 1;
    else return 2;
}

//分别存储甲、乙三种手势获胜的次数
int hand_a[3] = {0}, hand_b[3] = {0};
//分别存储甲、乙的胜、平、输次数
int times_a[3] = {0}, times_b[3] = {0};

int main(){
    //数字到字母的映射可以简单的用数组实现
    char map[3] = {'B', 'C', 'J'};
    int n;
    scanf("%d", &n);
    char a, b;
    int k1, k2;
    for(int i = 0; i < n; i++){
        //因为scanf读入char时会读入转行符，所以需要getchar()来吸收空格
        getchar();
        scanf("%c %c", &a, &b);
        k1 = change(a);
        k2 = change(b);
        if((k1 + 1) % 3 == k2){
            hand_a[k1]++;
            times_a[0]++;
            times_b[2]++; 
        }
        else if(k1 == k2){
            times_a[1]++;
            times_b[1]++;
        }
        else{
            hand_b[k2]++;
            times_a[2]++;
            times_b[0]++;
        }
    }
    int max1 = 0, max2 = 0;
    for(int i = 0; i < 3; i ++){
        if(hand_a[i] > max1) max1 = i;
        if(hand_b[i] > max2) max2 = i;
    }
    printf("%d %d %d\n", times_a[0], times_a[1], times_a[2]);
    printf("%d %d %d\n", times_b[0], times_b[1], times_b[2]);
    printf("%c %c\n", map[max1], map[max2]);
    return 0;
}