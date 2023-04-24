
/* POTENCIOMETER SCHEME
 
5V  ------- .   .  
          .       . 
A0  -----.    O    .  R = 100K Ohms
          .       .
GND ------- .   .

*/


//INT -Variables

int desired_rpm = 0;
int tooth = 0;

//FLOAT - Variables

float rpm_physical = 0;
float tooth_time = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);                      //Configure Pin 13 as digital output 
}

void loop() {
  // put your main code here, to run repeatedly:

  desired_rpm = analogRead(A0);             //Ready analog pin A0
  rpm_physical = ((desired_rpm * 10) + 20); //Escale: 20 ~ 10.250 RPMs
  tooth_time = (2/rpm_physical);            //time tooth calculed

  tooth=0;                                  //To start the counter loop
  
  while(tooth < 60)                         //Start loop
  {
    if(tooth < 58)                          //Verify if toothe count istill bellow of 58
    {
      digitalWrite(13, HIGH);               //High level Signal
      delay(tooth_time);                    //Time to wait
      digitalWrite(13, LOW);                //Low level Signal
      delay(tooth_time);                    //Time to wait
    }
    else
    {
      for(int a = 0; a<4; a++)              //Used to simulet the two missing tooth 
      {
        digitalWrite(13, LOW);              //Configure digital output as ZERO 
        delay(tooth_time);                  //Time to wait
      }
    }
    tooth++;                                //Sum one more to count (While loop accumulator)
  }
}
