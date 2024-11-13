#include<stdio.h>
void main(){
char input[] = "helloworld";
int len = sizeof(input)-1;
char enc[len];
char dec[len];

for(int i =0 ; i< len; i++){
enc[i] = ((input[i] - 'a') +3) % 26 + 'a';
dec[i] = ((enc[i] - 'a') -3) % 26 + 'a';
}

// null terminator is added at the end represent end of string.
enc[len] = '\0';
dec[len] = '\0';

printf("Original String: %s\n", input);
printf("encrypted String: %s\n",enc);
printf("decrypted String: %s\n",dec);
}
