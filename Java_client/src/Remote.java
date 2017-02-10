import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Remote {
	static final String DEFAULT_HOST = "localhost";
	  static final int DEFAULT_PORT = 3331;
	  private Socket sock;
	  private BufferedReader input;
	  private BufferedWriter output;

	public Remote(String host, int port) throws UnknownHostException, IOException {
		
		//First create a socket connection to the set-top box
	    try {sock = new java.net.Socket(host, port);}
	    catch (java.net.UnknownHostException e) {
	        System.err.println("Client: Couldn't find host "+host+":"+port);
	        throw e;
	    } catch (java.io.IOException e) {
	        System.err.println("Client: Couldn't reach host "+host+":"+port);
	        throw e;
	    }
	    
	    //Then create the IO streams to communicate with it
	    try {
	        input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
	        output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
	    } catch (java.io.IOException e) {
	        System.err.println("Client: Couldn't open input or output streams");
	        throw e;
	    }
	}
	
	public String query(String request) {
	    try {
	      request += "\n";
	      output.write(request, 0, request.length());
	      output.flush();
	    } catch (java.io.IOException e) {
	      System.err.println("Client: Couldn't send message: " + e);
	      return null;
	    }
	    
	    // return the server response
	    try {return input.readLine();}
	    catch (java.io.IOException e) {
	      System.err.println("Client: Couldn't receive message: " + e);
	      return null;
	    }
	}

}
