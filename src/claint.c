#include "claint.h"

char * initializeCLAINT(){
    char * integer = (char *)malloc(1001*sizeof(char));
    memset(integer,'0',1000*sizeof(char));
    integer[1000]='\0';

}
int compareINTALS(const char * intal_a, const char * intal_b){
    int i = 0;
    int flag  = 0;
    while(intal_a[i]!='\0' && intal_b[i]!='\0' && flag == 0){
        if(intal_a[i] == intal_b[i]) i++;
        else if(intal_a[i] > intal_b[i]) return 1;
        else return -1;
    }
    if(intal_a[i]=='\0' && intal_b[i]!='\0') return -1;
    if(intal_a[i]!='\0' && intal_b[i]=='\0') return  1;
    return 0;

} 