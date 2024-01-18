/*
import java.io.*;
import java.net.*;

public class UDPClient {

    public static void main(String[] args) throws Exception {
        DatagramSocket socket = new DatagramSocket();
        
        String str = "Hello World";
        byte[] buff = str.getBytes();
        DatagramPacket p = new DatagramPacket(buff, buff.length, "169.254.148.112", 4160);
        socket.send(p);

        byte[] b1 = new byte[1024];
        DatagramPacket dp1 = new DatagramPacket(b1, b1.length, address, 4160);
        socket.send(dp1);

        String str2 = new String(dp1.getData());
        System.out.println(str2);
    }
	
}

*/

import java.io.IOException; 
import java.net.DatagramPacket; 
import java.net.DatagramSocket; 
import java.net.InetAddress; 
import java.util.Scanner; 


import java.io.*;
import java.net.*;

public class UDPClient {

public static void main(String args[]) throws IOException 
    { 
        Scanner sc = new Scanner(System.in); 
  
        // Step 1:Create the socket object for 
        // carrying the data. 
        DatagramSocket ds = new DatagramSocket(); 
  
        InetAddress ip = InetAddress.getLocalHost();
        InetAddress ip_add=InetAddress.getByName("192.168.56.1");
        byte buf[] = null; 
  
        // loop while user not enters "bye" 
        while (true) 
        { 
            String inp = sc.nextLine(); 
  
            // convert the String input into the byte array. 
            buf = inp.getBytes(); 
  
            // Step 2 : Create the datagramPacket for sending 
            // the data. 
            DatagramPacket DpSend = 
                  new DatagramPacket(buf, buf.length,ip_add, 4160); 
  
            // Step 3 : invoke the send call to actually send 
            // the data. 
            ds.send(DpSend); 
  
            // break the loop if user enters "bye" 
            if (inp.equals("bye")) 
                break; 
        } 
    }
    
    }