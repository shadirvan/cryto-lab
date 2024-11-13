#include <stdio.h>
void main(){
char input[] = "hello";
char t[] = "qwertyuiopasdfghjklzxcvbnm";
int len = sizeof(input)-1;
char enc[len];
char dec[len];
for(int i =0 ; i< len;i++){
int index = input[i] - 'a';
enc[i] = t[index];
}
enc[len] = '\0';
printf("Encrypted : %s \n",enc);
for (int i =0;i<len;i++){
for (int j =0;j<26;j++){
if (enc[i]==t[j]){
dec[i] = j + 'a';
}
}
}
dec[len] = '\0';
printf("Decrypted : %s \n",dec);
}
