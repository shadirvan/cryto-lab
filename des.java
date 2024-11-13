import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

class des{
public static void main(String args[]){
try{
String message = "Hello World";
byte[] messageBytes = message.getBytes();
KeyGenerator keyGenerator = KeyGenerator.getInstance("DES");
SecretKey desKey = keyGenerator.generateKey();
Cipher cipher = Cipher.getInstance("DES");
cipher.init(Cipher.ENCRYPT_MODE,desKey);
byte[] encryptedBytes = cipher.doFinal(messageBytes);
cipher.init(Cipher.DECRYPT_MODE,desKey);
byte[] decryptedBytes = cipher.doFinal(encryptedBytes);
String encryptedData = new String(encryptedBytes);
String decryptedData = new String (decryptedBytes);

System.out.println("Key: " + desKey);
System.out.println("Encrypted Message: " + encryptedData);
System.out.println("Decrypted Message: " + decryptedData);
}catch (Exception e){
e.printStackTrace();
}
}
}
