import java.io.*;
import javax.crypto.*;
import javax.crypto.spec.*;

public class Lab05_1 {
    public static void main(String args[]) {

        System.out.println(" Encrypt/Decrypt:");
        System.out.println("1: Encrypt");
        System.out.println("2: Decrypt");
        System.out.println("3: Exit");
        String mode = System.console().readLine();
        if (Integer.parseInt(mode) == 1) {
            System.out.println("file name to be Encrypted:");
            String encryptFileName = System.console().readLine();

            System.out.println("select mode:");
            System.out.println("1: DES/ECB/PKCS5Padding.");
            System.out.println("2: DES/ECB/NoPadding.");
            System.out.println("3: DES/CBC/PKCS5Padding.");
            System.out.println("4: DES/CBC/NoPadding.");
            System.out.println("5: Exit.");
            String s = System.console().readLine();
            String instance = "";
            switch(s) {
                case "1":
                    instance = "DES/ECB/PKCS5Padding";
                    break;
                case "2":
                    instance = "DES/ECB/NoPadding";
                    break;
                case "3":
                    instance = "DES/CBC/PKCS5Padding";
                    break;
                case "4":
                    instance = "DES/CBC/NoPadding";
                    break;
                case "5":
                    System.out.println("Exit program");
		            System.exit(-1);
                    break;
                default:
                    System.out.println("Invalid mode!");
                    System.exit(-1);
            }
            System.out.println(" file name include the key:");
            String i = System.console().readLine();

            final long start = System.currentTimeMillis();
            try {
                File keyFile = new File(i);
                String keyString = "";
                try {
                    BufferedReader reader = new BufferedReader(new FileReader(keyFile));
                    keyString = reader.readLine();
                    reader.close();
                } catch(FileNotFoundException err)  {
                    System.out.println("File not found!");
                    System.exit(-1);
                }
                
                File desFile = new File("output.enc");
                FileInputStream fis;
                FileOutputStream fos;
                CipherInputStream cis;
                
                byte key[] = keyString.getBytes(); 
                SecretKeySpec secretKey = new SecretKeySpec(key,"DES");

                Cipher encrypt = Cipher.getInstance(instance);
                encrypt.init(Cipher.ENCRYPT_MODE, secretKey);

                try {
                    fis = new FileInputStream(encryptFileName);
                    cis = new CipherInputStream(fis, encrypt);
                
                    fos = new FileOutputStream(desFile);
                    byte[] c = new byte[8];
                    int k = cis.read(c);
                    while (k != -1) {
                        fos.write(c, 0, k);
                        k = cis.read(c);
                    }
                    fos.flush();
                    fos.close();
                    cis.close();
                    fis.close();
                } catch(IOException err) {
                    System.out.println("Cannot open file!");
                    System.exit(-1);
                }
            } catch(Exception e){
                e.printStackTrace();
            }
            final long end = System.currentTimeMillis();
            System.out.println("Total execution time: " + (end - start) + "ms");
        }

        if (Integer.parseInt(mode) == 2) {
            System.out.println(" File name Decrypt:");
            String decryptFileName = System.console().readLine();
        
            System.out.println("select mode:");
            System.out.println(" 1: DES/ECB/PKCS5Padding.");
            System.out.println(" 2: DES/ECB/NoPadding.");
            System.out.println(" 3: DES/CBC/PKCS5Padding.");
            System.out.println(" 4: DES/CBC/NoPadding.");
            System.out.println(" 5: Exit.");
            String s = System.console().readLine();
            String instance = "";
            switch(s) {
                case "":
                    System.out.println("Usage: java EncryptFile <file name>");
                    System.exit(-1);
                    break;
                case "1":
                    instance = "DES/ECB/PKCS5Padding";
                    break;
                case "2":
                    instance = "DES/ECB/NoPadding";
                    break;
                case "3":
                    instance = "DES/CBC/PKCS5Padding";
                    break;
                case "4":
                    instance = "DES/CBC/NoPadding";
                    break;
                case "5":
                    System.out.println("Exit program");
		            System.exit(-1);
                    break;
                default:
                    System.out.println("Invalid mode!");
                    System.exit(-1);
            }
            System.out.println(" file name key:");
            String i = System.console().readLine();
    

            final long start = System.currentTimeMillis();
            try {
                File keyFile = new File(i);
                String keyString = "";
                try {
                    BufferedReader reader = new BufferedReader(new FileReader(keyFile));
                    keyString = reader.readLine();
                    reader.close();
                } catch(FileNotFoundException err)  {
                    System.out.println("File not found!");
                    System.exit(-1);
                }
                File desFile = new File(decryptFileName);
                File desFileBis = new File("output.dec");
                FileInputStream fis;
                FileOutputStream fos;
                CipherInputStream cis;
        

                byte key[] = keyString.getBytes(); 
                SecretKeySpec secretKey = new SecretKeySpec(key,"DES");
        
                

                Cipher decrypt = Cipher.getInstance(instance);
                decrypt.init(Cipher.DECRYPT_MODE, secretKey); 
        
                fis = new FileInputStream(desFile);
                cis = new CipherInputStream(fis, decrypt); 
        
            
                fos = new FileOutputStream(desFileBis);
                byte[] c = new byte[8];
                int k = cis.read(c);
                while (k != -1) {
                    fos.write(c, 0, k);
                    k = cis.read(c);
                }
                fos.flush();    
                fos.close();    
                cis.close();
                fis.close();
                }  catch(Exception e){
                    e.printStackTrace();
            }
            final long end = System.currentTimeMillis();
            System.out.println("Total execution time: " + (end - start) + "ms");
        }
        else {
            System.out.println("Exit program");
            System.exit(-1);
        }
        
        
    }
}
