import java.util.Scanner;
import java.lang.Math;
class diffie {
public static void main(String args[]){
int P,G,a,b,x,y,ka,kb;
Scanner sc = new Scanner(System.in);
System.out.println("Enter a prime: ");
P = sc.nextInt();
System.out.println("Enter a primitive root of the Prime: ");
G = sc.nextInt();

System.out.println("Enter private key of alice: ");
a = sc.nextInt();
System.out.println("Enter private key of bob: ");
b = sc.nextInt();
x = (int)(Math.pow(G,a)) % P;
y = (int)(Math.pow(G,b)) % P;
System.out.println("Pub key of alice: " + x);
System.out.println("Pub key of bob: "+ y);

ka = (int)(Math.pow(y,a)) % P;
kb = (int )(Math.pow(x,b)) % P;

System.out.println("Alce shared key: " + ka);
System.out.println("Bob shared key: "+ kb);

}
}
