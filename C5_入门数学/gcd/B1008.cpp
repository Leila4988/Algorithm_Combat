#include <cstdio>
using namespace std;

int a[101];

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){
    int n, m, temp, pos, next; //temp存放临时变量，pos是当前新空出位置，next是应该填入pos中的数值所在位置
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    m = m % n; //题中没有指出m<n，所以我们应该先修正m
    if(m != 0){ //判断m=0的特殊情况
        int d = gcd(m, n);
        for(int i = n - m; i < n - m + d; i++){
            temp = a[i];
            pos = i;
            do{
                next = (pos - m + n) % n; //pos左边m位的数值为应该被填入的数值
                if(next != i) a[pos] = a[next]; //判断一轮循环是否即将结束
                else a[pos] = temp;
                pos = next;
            }while(pos != i); //循环直到回到初始位置
        }
    }
    for(int i = 0; i < n; i++){
        if(i != n - 1) printf("%d ", a[i]);
        else printf("%d", a[i]);
    }
    return 0;
}