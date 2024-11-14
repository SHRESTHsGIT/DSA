#include <stdio.h>
#include <string.h>
typedef struct TV_showes
{
    char name[15];
    int fdate;
    int tepi;
    int odate;
    char pro[20];
    char cast[20][20];
    char producer[15];
    char writer[15];
} tvs;
int main()
{
    char i[5];
    scanf("%s",i);
    printf("%s \n",i);
    scanf("%s",i);
    printf("%s\n",i);
}