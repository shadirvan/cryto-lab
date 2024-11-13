#include<stdio.h>
#include<math.h>

void main()
{

    int p=3,q=11,m=5;
    int phi,e=7,n,d,c,M,r;
    n=p*q;
    phi=(p-1)*(q-1);
    d=1;
    while(((e*d)%phi)!=1)
    {
        (d)++;
    }
    c=(int)(pow(m,e))%n;
    r=(int)(pow(c,d))%n;
    printf("Given Input: %d\n",m);
    printf("Encrypted: %d\n",c);
    printf("Decrypted: %d\n",r);


}
