/******************** MOINEAU PUMP: GUI for Motor Testing ************************ 
 * Ligorio Cosimo, University of Pisa, School of Engineering, 2015
 * Last modified date 02/05/2015;
 * 
 * The stepper motor follows the commands received through the serial communication.
 * Every button in the GUI sends a value (char val, in ASCII code) to Arduino Uno. 
 * Arduino reads the value and controls the rotation and speed of the motor. Arduino 
 * Uno board and FE Motor Shield were used. 
 * 
 * This example code is in the public domain.
 

 /* Libraries used */
 import g4p_controls.*; 
 import processing.serial.*; 

 /* Declaration */
  Serial myPort;  
  int val; 
  PImage sfondo; 
  int tempoiniziale;
  int tempoaccumulato;
  int tempotoshow;
  boolean running = false;
  PFont myFont; 
  GLabel label1; 
  GButton btnStart1, btnStart2, btnStart3, btnStart4, btnStart5, btnStart6, btnStart7, btnStart8, btnStart9, btnStart10, btnStop; //creo 2 tipi di tasti: start e stop;
  
 public void setup(){
  size(700, 462, JAVA2D); 
  sfondo = loadImage("moineau_sfondo.png"); 
  smooth();
  frameRate(20);
  myFont = loadFont("LiquidCrystal-128.vlw");
  textFont(myFont);  
  textSize(28);
  textAlign(CENTER);
  fill(4, 20, 255);
   
  
  String portName = Serial.list()[0];  
  myPort = new Serial(this, portName, 9600);
  
  /* Definition of buttons: position, name and title
   * Two types of buttons: Start and Stop;
   */
  btnStart1 = new GButton(this, 60, 60, 100, 40,  "ω: 0.5 rad/s");
  btnStart2 = new GButton(this, 60, 110, 100, 40, "ω: 1 rad/s");
  btnStart3 = new GButton(this, 60, 160, 100, 40, "ω: 1.5 rad/s");
  btnStart4 = new GButton(this, 60, 210, 100, 40, "ω: 2 rad/s");
  btnStart5 = new GButton(this, 60, 260, 100, 40, "ω: 2.5 rad/s");
  btnStart6 = new GButton(this, 60, 310, 100, 40, "ω: 3 rad/s");
  btnStart7 = new GButton(this, 60, 360, 100, 60, "Trial Button (now set for 20 rad/s)");
  btnStart8 = new GButton(this, 180, 110, 100, 40, "60 RPM");
  btnStart9 = new GButton(this, 180, 160, 100, 40, "120 RPM");
  btnStart10 = new GButton(this, 180, 210, 100, 40, "180 RPM");
  btnStop = new GButton(this, 380, 70, 100, 40,  "Motor Stop!");
  
  G4P.setGlobalColorScheme(GCScheme.BLUE_SCHEME);
  
  /* Declaration of label for the blue stopwatch*/
  label1 = new GLabel(this, 320, 110, 200, 100);
  /* Definition of label: text and aspect */
  label1.setText("---------------------------------------------   Press: s or S to START the counter;" + "                      f or F to FREEZE the counter;" + "                   r or R to RESET the counter         (after FREEZE)" 
                 + "                         -------------------------------------------");
  label1.setOpaque(false);
  
  /* If the stream is ok, I define the title on the top of the window */
  if (frame != null) 
   frame.setTitle("Moineau Motor Tester GUI");
   }

  public void draw(){
   background(sfondo); 
   int hours, mins, secs; 
   
  /************************** STOPWATCH: description and functionality ******************************/  
  /* Keys you have to use on the keyboard: 
    - S/s = Start, the stopwatch begins to count;
    - R/r = Reset, the stopwatch resets the previous count 00:00:00 
    - F/f = Freeze, the time is frozen to the current count (ex: 00:12:03);
  */

  if(keyPressed){ 
  /* If r or R is pressed the stopwatch resets the previous count and the
   * variables 'tempoaccumulato' (saved time) and 'tempotoshow' (the time 
   * the stopwatch is going to show on the screen) are set zero. 
   */  
    if((key == 'r') || (key == 'R')){
      tempoaccumulato = 0;
        tempotoshow = 0;
        }
    
 /* If s or S is pressed the stopwatch begins to count. Initial time (tempoiniziale) is the time 
  * counted by the machine and the boolean running is set true because the stopwath is counting.  
  * Now I can 'freeze' the time and display the current time (pressing f or F) or I can stop the 
  * count and resets it to 00:00:00 (pressing r or R).
  
  * ***************************** IMPORTANT NOTE *******************************************
  * You cannot stop the stopwatch directly using r or R, this version of code cannot do it.
  * So to stop the stopwatch you have to press f or F to freeze the time and then you can 
  * reset it pressing r or R, so to reset the count you have to press first f or F.  
  * ***************************************************************************************
  */
    if((key == 's') || (key == 'S')){
      if(running == false){ 
       tempoiniziale = millis();
        running = true;
      }
    }      
      
 
 /* If f or F is pressed boolean running is set false (because I have stopped the time for a while) 
  * and the accumulated time (tempoaccumulato) is calculated as the interval between the current time
  * of the machine (the output of millis()) and the time at the beginning, when stopwatch started.
  */
  
  if(key == 'f' || key == 'F'){
    if(running == true){
      running = false; 
    tempoaccumulato = tempoaccumulato + millis() - tempoiniziale;
     }
    }
   }
 
  if(running == true){
  tempotoshow =  tempoaccumulato + millis() - tempoiniziale;}
  secs = (tempotoshow / 1000) % 60;
  mins = (tempotoshow / 1000 / 60) % 60;
  hours = (tempotoshow / 1000 / 60 / 60);
  text(nf(hours,2) + ":" + nf(mins, 2) + ":" + nf(secs, 2), 420, 230);
   } 
  
 
 /* A function is dedicated to the event of mouse click: when a button is clicked 
  * its state changes and a char is sent via serial communication to the hardware 
  * (Arduino Uno). Every button has its name and its related state i.e. clicked
  * or not clicked.
  */ 
  
 public void handleButtonEvents(GButton button, GEvent event){
 if(button == btnStop && event == GEvent.CLICKED)
   myPort.write(65); 
  
   if(button == btnStart1 && event == GEvent.CLICKED){
    myPort.write(97);
    }
    
  if(button == btnStart2 && event == GEvent.CLICKED){
    myPort.write(98);
     }
     
  if(button == btnStart3 && event == GEvent.CLICKED){
   myPort.write(99);  
    }
    
   if(button == btnStart4 && event == GEvent.CLICKED){
    myPort.write(100);
    }
    
    if(button == btnStart5 && event == GEvent.CLICKED){
    myPort.write(101);
    }
    
    if(button == btnStart6 && event == GEvent.CLICKED){
    myPort.write(102);
     }
     
     if(button == btnStart7 && event == GEvent.CLICKED){
    myPort.write(103);
     } 
     
      if(button == btnStart8 && event == GEvent.CLICKED){
    myPort.write(104);
     }
     
      if(button == btnStart9 && event == GEvent.CLICKED){
    myPort.write(105);
     }
     
      if(button == btnStart10 && event == GEvent.CLICKED){
    myPort.write(106);
     }
   }

