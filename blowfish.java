import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
class blowfish{
public static void main(String args[]){

try{
String key = "mypassword";
String data = "Top secret message";
byte[] keyBytes = key.getBytes();
byte[] dataBytes = data.getBytes();
SecretKeySpec keySpec = new SecretKeySpec(keyBytes,"Blowfish");
Cipher cipher = Cipher.getInstance("Blowfish");
cipher.init(Cipher.ENCRYPT_MODE,keySpec);
byte[] encryptedBytes = cipher.doFinal(dataBytes);
String encryptedData = new String(encryptedBytes);
cipher.init(Cipher.DECRYPT_MODE,keySpec);
byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
String decryptedData = new String (decryptedBytes);

System.out.println("Original String: " + data);
System.out.println("Encrypted Message: \n" + encryptedData);
System.out.println("Encrypted Message: " + decryptedData);
} catch(Exception e){
e.printStackTrace();
}


}
}
