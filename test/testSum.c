#include "../src/claint.h"

void main(int argc, char * args[]){
    char  a[] = {'1','5','3','5','3','5','3','5','3','5','3','5','3','5','3','5','3','5','3','5','3','5','5','\0'};
    char  b[2];
    b[0] = '5';
    b[1] = '\0';
    char * sum = addCLAINTS(a,b);
    printCLAINT(sum);

    return ;
}