#include <stdio.h>
void main(){
char input[] = "Hello World";
char result[sizeof(input)];
for (int i =0 ; i < sizeof(input)-1;i++){
result[i] = input[i] ^ 0;
}
printf("The String before xor : %s \n",input);
printf("The String after xor: %s \n",result);
}
