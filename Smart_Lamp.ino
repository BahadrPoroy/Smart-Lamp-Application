#define switch 3  //switch pin
#define relay 4   //relay pin
#define esp 5     //esp pin

int lamp, switchIn; //lamp variable for the last state of the lamp - The SwitchIn variable is for the state of the switch.

void setup() {
//Serial settings and begin  
Serial.begin(9600);
//pinMode settings  
pinMode(switch, INPUT); 
pinMode(relay, OUTPUT);
//first pin readings and writings
switchIn = digitalRead(switch);
digitalWrite(relay, switchIn);
}

void loop() {
  switchIn = digitalRead(switch);
  digitalWrite(relay, switchIn);
  if(!switchIn){  //If the switch is off switching to smart mode
    smart();
  }
}

void smart(){
 switchIn = digitalRead(switch);
 if(switchIn){  //If the switch is on switching to normal mode 
  loop();
 }
 lamp = switchIn;
 if(digitalRead(esp)){
  lamp = !lamp;
  digitalWrite(relay, lamp);
 }
}
