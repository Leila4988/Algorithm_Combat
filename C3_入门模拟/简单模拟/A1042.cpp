#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

int init[55], res[55], order[55];
char pix[5] = {'S', 'H', 'C', 'D', 'J'};

int main(){
    int rep;
    // FILE *fpRead=fopen("/Users/paopao/Documents/保研/程序/simple/test.txt","r");
    // ifstream fin("/Users/paopao/Documents/保研/程序/simple/test.txt", ios::out | ios::in);
    // if(!fin) printf("error");
    scanf("%d", &rep);
    // fin >> rep;
    // fscanf(fpRead,"%d ",&rep);
    for(int i = 1; i <= 54; i++){
        scanf("%d", &order[i]);
        // fin >> order[i];
        init[i] = i;
    }
    // fin.close();
    while(rep--){
        for(int i = 1; i <= 54; i++){
            res[order[i]] = init[i];
        }
        for(int i = 1; i <= 54; i++){
            init[i] = res[i];
        }
    }
    for(int i = 1; i <= 54; i++){
        //此情况下，13/13应该是0，13%13应该是13
        res[i] --;
        printf("%c%d", pix[res[i] / 13], res[i] % 13 + 1);
        if(i < 54) printf(" ");
    }
    // printf("\n");
    return 0;
}

