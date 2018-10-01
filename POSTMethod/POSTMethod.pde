import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.io.OutputStream;
import java.net.URL;
import java.util.LinkedHashMap;

void setup(){
  String POST_PARAMS = "Volante=0";
  try{
  URL url = new URL("http://192.168.1.69:3000/testing");
  HttpURLConnection httpCon = (HttpURLConnection) url.openConnection();
  httpCon.setDoOutput(true);
  httpCon.setRequestMethod("POST");
  
  httpCon.setDoOutput(true);
  OutputStream os = httpCon.getOutputStream();
  os.write(POST_PARAMS.getBytes());
  os.flush();
  os.close();
  
  OutputStreamWriter out = new OutputStreamWriter(
      httpCon.getOutputStream());
  System.out.println(httpCon.getResponseCode());
  System.out.println(httpCon.getResponseMessage());
  out.close();
   }catch(IOException e){
     e.printStackTrace();
   }
}

void draw(){
 
}
