import processing.serial.*;

Serial myPort;    // The serial port
String inString = "";  // Input string from serial port
int lf = 10;      // ASCII linefeed

boolean dataRx = false;

String[] list;

void setup() {
  size(400,400);
  // List all the available serial ports:
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  //You will need to change the index of the serial that the LaunchPad is connected to
  myPort = new Serial(this, Serial.list()[1], 9600);
  myPort.bufferUntil(lf);
}

void draw() {
  
  if(dataRx){
  println("received: " + inString);
  
  if(list[0].equals("back")){
    int R = int(list[1]);
    int G = int(list[2]);
    int B = int(list[3]);
    color c = color(R, G, B);
    background(c);    
  }
 
  if(list[0].equals("line")){
    int x1 = int(list[1]);
    int y1 = int(list[2]);
    int x2 = int(list[3]);
    int y2 = int(list[4]);
    stroke(255);
    line(x1, y1, x2, y2);
  }
      if(list[0].equals("rect")){
    stroke(255);
    int x = int(list[1]);
    int y = int(list[2]);
    int w = int(list[3]);
    int h = int(list[4]);
    rect(x, y, w, h);
  }
    if(list[0].equals("circle")){
    stroke(255);
    int x = int(list[1]);
    int y = int(list[2]);
    int w = int(list[3]);
    int h = int(list[4]);
    ellipse(x, y, w, h);
  }
  dataRx = false;
  }
}

void serialEvent(Serial myPort) {
  inString = myPort.readString();
  list = splitTokens(inString, ",\r");
  dataRx = true;
}