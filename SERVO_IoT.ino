
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;

char ssid[] = "CSLWiFi";                                       // Name of your network (HotSpot or Router name)
char pass[] = "enecemoci";   
char auth[] = "SF6l6XoYUKGUqDe3n9ElZ7AY6YOJszJ4"; 

int slider = 120;
void setup()

{

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servo.attach(D2); // NodeMCU D8 pin
 }

void loop(){
  Blynk.run();
}

BLYNK_WRITE(V0){
  slider=param.asInt();
  
}

BLYNK_WRITE(V1)
{if (param.asInt()==1)
  servo.write(0);
  Blynk.virtualWrite(V3,0);

}
BLYNK_WRITE(V2)
{if (param.asInt()==1)
  servo.write(120);
  Blynk.virtualWrite(V3,1023);

}
