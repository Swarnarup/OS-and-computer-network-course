// import java.io.*;
// import java.net.*;

// public class UDPServer {

//     public static void main(String[] args) throws Exception {
//         DatagramSocket server = new DatagramSocket(4160);
        
// 		String capitalizedSentence;
//         while(true) {
//             byte[] buff = new byte[1024];
//             DatagramPacket packet = new DatagramPacket(buff, buff.length);
//             server.receive(packet);
//             String clientSentence = new String(packet.getData());
//             capitalizedSentence = clientSentence.toUpperCase();

//             // outToClient.writeBytes(capitalizedSentence);

//             byte[] b2 = String.valueOf(capitalizedSentence).getBytes();
//             // InetAddress ia = InetAddress.getLocalHost();
//             DatagramPacket dp1 = new DatagramPacket(b2, b2.length);

//             server.send(dp1);
//         }

//     }
	
// }

import java.io.IOException; 
import java.net.DatagramPacket; 
import java.net.DatagramSocket; 
import java.net.InetAddress; 
import java.util.Scanner; 

public class UDPServer {

    public static void main(String[] args) throws IOException 
    { 
        DatagramSocket ds = new DatagramSocket(4160); 
        byte[] receive = new byte[65535]; 
  
        DatagramPacket DpReceive = null; 
        while (true) 
        { 
  
            DpReceive = new DatagramPacket(receive, receive.length); 
  
            ds.receive(DpReceive); 
  
            System.out.println("capitalized :-" + data(receive)); 
  
            if (data(receive).toString().equals("bye")) 
            { 
                System.out.println("Client sent bye.....EXITING"); 
                break; 
            } 
  
            receive = new byte[65535]; 
        } 
    } 
  
    public static StringBuilder data(byte[] a) 
    { 
        if (a == null) 
            return null; 
        StringBuilder ret = new StringBuilder(); 
        int i = 0; 
        while (a[i] != 0) 
        { 
            ret.append((char) (a[i]+((int)'A'-(int)'a'))); 
            i++; 
        } 
        return ret; 
    }
	
}