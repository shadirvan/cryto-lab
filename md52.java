import java.security.*;
import java.util.Base64;

public class md52 {
    public static void main(String[] args) throws Exception {
    String text = "Hello, World!";
    byte[] bytesOfMessage = text.getBytes();
    MessageDigest md = MessageDigest.getInstance("MD5");
    byte[] theMD5digest = md.digest(bytesOfMessage);
    String hashValue = Base64.getEncoder().encodeToString(theMD5digest);
    System.out.println("Hash Value: " + hashValue);
    }
}
