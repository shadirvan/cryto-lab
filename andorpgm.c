#include<stdio.h>
void main(){
char input[] ="This is a test String";
char resand[sizeof(input)];
char resor[sizeof(input)];
for (int i =0 ; i< sizeof(input)-1; i++){
resand[i] = input[i] & 127;
resor[i] = input[i] ^ 127;
}
printf("The input String: %s\n",input);
printf("String after and: %s\n",resand);
printf("String after or: %s\n",resor);
}
