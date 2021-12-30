import processing.serial.*;
Serial myPort;
PFont fnt;
int xPos;
int oldXpos=30;
int oldxtint;
int dx=30;

int xPos2;
int oldXpos2=30;
int oldxtint2;
int dx2=30;


int latitude=1260;

void init_graph() {
  background(255, 255, 255);
  stroke(0);
  line(30, 640, 1260, 640);
  line(30, 760, 30, 10);
   stroke(0,250,250);
  line(30,760,30,640);
  stroke(0,250,0);
  line(30,760,1260,760);
  textSize(12);
  fill(50,250,250);
  stroke(220,220,220);
 // 
 for ( int i=0; i<121; i++ ) { 
    text( ( i*2), 30+20*i, 750 );
    line(30+10*i,40,30+10*i,760);
    line(30,640-12*i,1260,640-12*i);
  }
  stroke(0,250,0);
  line(30,700,1260,700);
  for ( int i=0; i<121; i++ ) { 
    text( ( i*2), 30+20*i, 710 ); 
  }
 stroke(0,250,0);
  line(30,580,1260,580);
  for ( int i=0; i<121; i++ ) { 
    text( ( i*2), 30+20*i, 590 ); 
 //   text ("|", 30+30*i, 580);
  }
  stroke(0,250,0);
  line(30,520,1260,520);
  for ( int i=0; i<121; i++ ) { 
    text( ( i*2), 30+20*i, 530 ); 
  //  text ("|", 30+30*i, 520);
  }
  stroke(220,220,220);
  line(30,460,1260,460);
  fill(150,150,150);
  for ( int i=0; i<121; i++ ) { 
    text( ( i*2), 30+20*i, 470 ); 
  //  text ("|", 30+30*i, 460);
  }
  stroke(220,220,220);
  line(30,400,1260,400);
  fill(150,150,150);
  for ( int i=0; i<121; i++ ) { 
    text( ( i*2), 30+20*i, 410 ); 
  //  text ("|", 30+30*i, 400);
  }
  textSize(14);                  //textSize(14);///////////////////////////////////////////////
  fill(40);
 
  for ( int i=0; i<11; i++ ) { 
    text( ( i*30), 30, 640-60*i );       //new  // text( ( i*5), 30, 640-60*i );  
  }
  textSize(11);
  for ( int i=0; i<121; i++ ) { 
    text( ( i*2), 30+20*i, 650 ); 
  //  text ("|", 30+30*i, 640);
  }
  
  fill(0,250,250);
  for ( int i=0; i<3; i++ ) { 
    text( (-i*10), 30, 640+60*i );                    //text( (-i*5), 30, 640+60*i );
  }
  textSize(16);
  fill(0,0,0);
  text(" ALTITUDE (DEG) ", 31, 30);         // text(" [Y]-SPEED1 (M/MIN) ", 31, 30);
  fill(250,0,0);
  text(" AZIMUTH (DEG) ", 41, 44);          // text(" [Y]-SPEED2 (M/MIN) ", 41, 44);
  text(" [X]-TIME (SEC) ", 1080, 630);
  fill(0,250,0);
         // text(" S=DISTANCE (M)",42,300);
                           //fill(0,0,250);
          //text("YAW (DEGREES)*10^-2",42,350);
}   
  

void setup()
{
  
 size(1260,760);
 init_graph();
 xPos=dx;
 xPos2=dx2;

   fnt = createFont("Arial", 16, true);
 myPort=new Serial(this,"COM20",9600);
}
void draw()

{
  
  int ixt=0,n=0;
  int ixt2=0,n2=0;
 
 //println("aaaa");
  String inString=myPort.readStringUntil('\n');
  if(inString!=null){
  String oldinString=""; 
  if (inString!=oldinString)
  {
    fill(255);
    rect(240,20,195,20);
    fill(0);
    stroke(0,0,0);
     text(inString,250,36);
     oldinString=inString;
    // fill(255);                                     //...................................................
     //rect(85,738,40,738);//
     fill(0);//
     text("ΝΕΚΤΑΡΙΟΣ ΚΟΥΡΑΚΗΣ",3,730);//.................
  } 
 
 
  String[] motors=splitTokens(inString,",");
  print(inString);
  String[] num=splitTokens(motors[0],".");
   n=Integer.parseInt(num[0]);
   ixt=(n); //maybe * up //ixt=(n*6);    //NEW   //ixt=(n*6); //maybe * up
   println(n);
   stroke(0,0,0);
   smooth();
  line(oldXpos,640-2*oldxtint,xPos,640-2*ixt);         //line(oldXpos,640-2*oldxtint,xPos,640-2*ixt);
  
  oldXpos=xPos;
  oldxtint=ixt;
  if (xPos >= width-dx)
  { xPos = dx;
    oldXpos=30;
    save("lineWIDTH.png");
    init_graph();
  }
  else { xPos+=10; }
  
  
  String[] num2=splitTokens(motors[1],".");
   n2=Integer.parseInt(num2[0]);
   ixt2=(n2); //maybe * up  //NEW //ixt2=(n2*3);
   println(n2);
   stroke(250,0,0);
   smooth();
   line(oldXpos2,640-2*oldxtint2,xPos2,640-2*ixt2);
    oldXpos2=xPos2;
    oldxtint2=ixt2;
  if (xPos2 >= width-dx2)
  { xPos2 = dx2;
    oldXpos2=30;  
  }
  else { xPos2+=10; }
  
 
  
 
}
saveFrame("output/TEST_####.PNG"); ////////////////////////////////////
}

void mousePressed() {
  save("line.png");
 init_graph();
}
