#include <cstdio>
using namespace std;

int main(){
    int count = 0;
    int num;
    scanf("%d", &num);
    while( num > 0 && num != 1){
        if(num % 2 == 0){
            num /= 2;
        }
        else{
            num = (3 * num + 1) / 2;
        }
        count ++;
    }
    printf("%d\n", count);
    return 0;
}