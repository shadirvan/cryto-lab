import java.util.Scanner;
import java.security.MessageDigest;
import java.math.BigInteger;
public class md5 {
public static void main(String args[]){
try{
String s;
Scanner sc = new Scanner(System.in);
System.out.println("Enter the text to find md5 : ");
s = sc.nextLine();
MessageDigest md = MessageDigest.getInstance("MD5");
byte[] messageDigest = md.digest(s.getBytes());
BigInteger no = new BigInteger(1,messageDigest);
String hashtext = no.toString(16);
while(hashtext.length()< 32)
{
hashtext = "0"+hashtext;
}
System.out.println("Generated Hash: " + hashtext);
}
catch(Exception e){
e.printStackTrace();
}

}

}
