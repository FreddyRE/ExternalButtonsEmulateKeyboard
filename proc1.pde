import processing.serial.*;

Serial myPort;
String val;
char frenoMano; //n Freno Mano 

 
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
