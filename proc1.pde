import processing.serial.*;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.io.OutputStream;
import java.net.URL;
import java.util.LinkedHashMap;


Serial myPort;
String val;
char frenoMano; //n Freno Mano 
int wasSentVolante = 0;
 
import processing.serial.*;
import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.KeyEvent;
import java.io.IOException;


int keyInput[] = {
  KeyEvent.VK_N, KeyEvent.VK_M, KeyEvent.VK_J, KeyEvent.VK_K, KeyEvent.VK_Z, KeyEvent.VK_X, KeyEvent.VK_L, KeyEvent.VK_H
};



void setup()
{

  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
 
  try {
    Runtime.getRuntime().exec("notepad");
  } catch (Exception e) {
    e.printStackTrace();
    exit();
  }
    
}
void draw()
{
  
  if(myPort.available() > 0)
   {
     val = myPort.readStringUntil('\n');
     if(val == null) {
      val = "value is null"; 
      //print("value is null");
      //wasSentVolante = 0;
     }
     
     int myTest = val.charAt(0);
     
     int valueToPrint = 100;
     
      switch (myTest) {
       case 110: valueToPrint = 0; //n Freno Mano 
       break;//n Freno de mano
       case 109: valueToPrint = 1; //m Reversa
       break;
       case 106: valueToPrint = 2; // j Intermitentes
       break;
       case 107: valueToPrint = 3; // k Encendido Luces
       break;
       case 122: valueToPrint = 4; // z Direccional Izquierda
       break;
       case 104: sendDataPOST(); //h means Arduino 1 
       break;
      }
     
     frenoMano = val.charAt(0);
          
     if(valueToPrint >= 0 && valueToPrint <= 20 ){
       
       try {
         Robot robot = new Robot();
         
           robot.delay(1);
           robot.keyPress(keyInput[valueToPrint]);
           robot.delay(1);
           robot.keyRelease(keyInput[valueToPrint]);
           robot.delay(1);
          
        } catch (Exception e) {
          e.printStackTrace();
          exit();
         }
      }  
     } else {
       
       try {
         Robot robot = new Robot();
         for (int i = 0; i < keyInput.length; i++) {
           robot.delay(1);
           robot.keyRelease(keyInput[i]);
          }
        } catch (Exception e) {
          e.printStackTrace();
          exit();
         }
       
     }  
}

void sendDataPOST(){
  if(wasSentVolante == 0){  
    print("entrando cambio volante");
    String POST_PARAMS = "Volante=0";
    /*
    try{
      URL url = new URL("http://192.168.1.69:3000/testing");
      HttpURLConnection httpCon = (HttpURLConnection) url.openConnection();
      httpCon.setDoOutput(true);
      httpCon.setRequestMethod("POST");
  
      httpCon.setDoOutput(true);
      OutputStream os = httpCon.getOutputStream();
      os.write(POST_PARAMS.getByte());
      os.flush();
      os.close();
  
      OutputStreamWriter out = new OutputStreamWriter(
        httpCon.getOutputStream());
        System.out.println(httpCon.getResponseCode());
        System.out.println(httpCon.getResponseMessage());
        out.close();
      } catch(IOException e){
         e.printStackTrace();
      }*/
    }
    wasSentVolante = 1; 
}
