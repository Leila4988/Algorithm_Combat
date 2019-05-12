#include <cstdio>
using namespace std;

struct student{
    char name[15], id[15];
    char gen;
    int grade;
}temp, lowMale, highFemale;

void init(){
    lowMale.gen = 'M';
    lowMale.grade = 101;
    highFemale.gen = 'F';
    highFemale.grade = -1;
}

int main(){
    init();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %c %s %d", temp.name, &temp.gen, temp.id, &temp.grade);
        if(temp.gen == 'M'){
            if(temp.grade < lowMale.grade) lowMale = temp;
        }
        if(temp.gen == 'F'){
            if(temp.grade > highFemale.grade) highFemale = temp;
        }
    }
    if(highFemale.grade == -1) printf("Absent\n");
    else printf("%s %s\n", highFemale.name, highFemale.id);
    if(lowMale.grade == 101) printf("Absent\n");
    else printf("%s %s\n", lowMale.name, lowMale.id);
    if(highFemale.grade == -1 || lowMale.grade == 101) printf("NA");
    else printf("%d", highFemale.grade - lowMale.grade);
}