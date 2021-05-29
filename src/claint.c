#include "claint.h"

char * initializeCLAINT(){
    char * integer = (char *)malloc(1001*sizeof(char));
    memset(integer,'0',1001*sizeof(char));
    integer[1000]='\0';
    return integer;
}

int length(  char * claint_a){
    int claint_a_len = 0;
    while(claint_a[claint_a_len]!='\0')
        claint_a_len++;
    return claint_a_len;
}

void printCLAINT(  char * claint_a){
    int len = length(claint_a);
    // printf("%s",claint_a);
    for(int i=0;i<len;i++) printf("%d",(claint_a[i]-'0'));
    // for(int i=0;i<len;i++) printf("%c",(claint_a[i]));
    printf("\n");
}

int compareCLAINTS(  char * claint_a,   char * claint_b){
    int i = 0;
    int flag  = 0;
    while(claint_a[i]!='\0' && claint_b[i]!='\0' && flag == 0){
        if(claint_a[i] == claint_b[i]) i++;
        else if(claint_a[i] > claint_b[i]) return 1;
        else return -1;
    }
    if(claint_a[i]=='\0' && claint_b[i]!='\0') return -1;
    if(claint_a[i]!='\0' && claint_b[i]=='\0') return  1;
    return 0;

} 

char * addCLAINTS( char* claint_a,  char * claint_b){
    
    // printf("\n");
    int len_a = length(claint_a), len_b = length(claint_b);
    char *reversed_a = initializeCLAINT();
    char *reversed_b = initializeCLAINT();
    int itr_rev_a = 0, itr_rev_b = 0;
    while(len_a){
        reversed_a[itr_rev_a] = claint_a[len_a-1];
        len_a--;
        itr_rev_a++;
    }
    reversed_a[itr_rev_a] = '\0';
    while(len_b){
        reversed_b[itr_rev_b] = claint_b[len_b-1];
        len_b--;
        itr_rev_b++;
    } 
    reversed_b[itr_rev_b] = '\0';
    claint_a = reversed_a;
    claint_b = reversed_b;
    char * claint_sum_rev = initializeCLAINT() ; 
    char * claint_sum = initializeCLAINT();
    int claint_a_pos = 0, claint_b_pos = 0 , rev_sum_pos = 0;
    int sum = 0, rem = 0;
    while((claint_a[claint_a_pos] != '\0') && (claint_b[claint_b_pos] != '\0')){
        sum = rem + (claint_a[claint_a_pos]-'0') + (claint_b[claint_b_pos] - '0');
        rem = sum/10;
        sum = sum%10;
        claint_sum_rev[rev_sum_pos] = (char)(sum+'0');
        rev_sum_pos++;
        claint_a_pos++;
        claint_b_pos++;
    }
    while(claint_a[claint_a_pos]!='\0'){
        sum = rem + (claint_a[claint_a_pos]-'0') ;
        rem = sum/10;
        sum = sum%10;
        claint_sum_rev[rev_sum_pos] = (char)(sum+'0');
        rev_sum_pos++;
        claint_a_pos++;
    }
    while(claint_b[claint_b_pos]!='\0'){
        sum = rem + (claint_b[claint_b_pos]-'0') ;
        rem = sum/10;
        sum = sum%10;
        claint_sum_rev[rev_sum_pos] = (char)(sum+'0');
        rev_sum_pos++;
        claint_b_pos++;
    }
    while(rem){
        claint_sum_rev[rev_sum_pos] = (char)((rem%10)+'0') ;
        rev_sum_pos++;
        rem/=10;
    }
    claint_sum_rev[rev_sum_pos]='\0';
    //tsting
    // printCLAINT(claint_sum_rev);
    // return claint_sum_rev;
    //
    rev_sum_pos--;
    int claint_sum_pos = 0;
    while(rev_sum_pos >= 0){
        claint_sum[claint_sum_pos] = claint_sum_rev[rev_sum_pos];
        rev_sum_pos--;
        claint_sum_pos++;
    }
    // printCLAINT(claint_a),printCLAINT(claint_b);
    claint_sum[claint_sum_pos]='\0';
    // printCLAINT(claint_sum);
    return claint_sum;
          
}

void dummy(){
    printf("I worked!\n");
}