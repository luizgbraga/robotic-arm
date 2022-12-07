#include <Servo.h>

const float c = 5.6833333;
const int dt = 20;
const int t = 5000;

int nol = 0;
float posServoBase[9];
float posServoPA[10];
float posServoPB[10];
float posServoGarra[10];


// instansicação dos Servos

Servo servoBase;
Servo servoPA;
Servo servoPB;
Servo servoGarra;

// declaração dos valores dos potenciômetros

int posBase = 0;
int posPA = 0;
int posPB = 0;
int posGarra = 0;

// declaração dos LEDs de controle

const int LED1 = 12;
const int LED2 = 13;

// declaração dos botões 

const int BUT1 = 2;
const int BUT2 = 4;

int valBut1 = 1;
int valBut2 = 1;

// declaração dos valores lidos pelos potenciômetros

const int POTBase = 0;
const int POTPA = 1;
const int POTPB = 2;
const int POTGarra = 3;

// ângulos de início e fim de cada servo

int theta0_Base;
int thetaf_Base;

int theta0_PA;
int thetaf_PA;
int theta0_PB;
int thetaf_PB;

int theta0_Garra;
int thetaf_Garra;

void setup() {
  pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(BUT1, INPUT_PULLUP);
    pinMode(BUT2, INPUT_PULLUP);
  
    servoBase.attach(6);
    servoPA.attach(3);
    servoPB.attach(9);
    servoGarra.attach(10);
  
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  
  while(valBut1) {
    valBut1 = digitalRead(BUT1);
    
    if(!valBut1) {
      digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
      
        thetaf_Base = posBase/c;
        thetaf_PA = posPA/c;
        thetaf_PB = posPB/c;
        thetaf_Garra = posGarra/c;
      
        break;
    }
    
    posBase = analogRead(POTBase);
    
    posPA = analogRead(POTPA);
    posServoPA[nol] = posPA/c;
    
    posPB = analogRead(POTPB);
    posServoPB[nol] = posPB/c;
    
    posGarra = analogRead(POTGarra);
    posServoGarra[nol] = posGarra/c;

    servoBase.write(posBase/c);
    servoPA.write((posServoPA[0] + posServoPA[1] + posServoPA[2] + posServoPA[3] + posServoPA[4] + posServoPA[5] + posServoPA[6] + posServoPA[7] + posServoPA[8] + posServoPA[9])/10);
    servoPB.write((posServoPB[0] + posServoPB[1] + posServoPB[2] + posServoPB[3] + posServoPB[4] + posServoPB[5] + posServoPB[6] + posServoPB[7] + posServoPB[8] + posServoPB[9])/10); 
    servoGarra.write((posServoGarra[0] + posServoGarra[1] + posServoGarra[2] + posServoGarra[3] + posServoGarra[4] + posServoGarra[5] + posServoGarra[6] + posServoGarra[7] + posServoGarra[8] + posServoGarra[9])/10);

    nol++;
    if(nol > 9) nol = 0;
  }
  
  while(valBut2) {
  valBut2 = digitalRead(BUT2);
    
  if(!valBut2) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
      
    theta0_Base = posBase/c;
        theta0_PA = posPA/c;
        theta0_PB = posPB/c;
        theta0_Garra = posGarra/c;
      
        break;
   }
    
   posBase = analogRead(POTBase);
    
   posPA = analogRead(POTPA);
   posServoPA[nol] = posPA/c;
    
   posPB = analogRead(POTPB);
   posServoPB[nol] = posPB/c;
    
   posGarra = analogRead(POTGarra);
   posServoGarra[nol] = posGarra/c;
    
   servoBase.write(posBase/c);
   servoPA.write((posServoPA[0] + posServoPA[1] + posServoPA[2] + posServoPA[3] + posServoPA[4] + posServoPA[5] + posServoPA[6] + posServoPA[7] + posServoPA[8] + posServoPA[9])/10);
   servoPB.write((posServoPB[0] + posServoPB[1] + posServoPB[2] + posServoPB[3] + posServoPB[4] + posServoPB[5] + posServoPB[6] + posServoPB[7] + posServoPB[8] + posServoPB[9])/10); 
   servoGarra.write((posServoGarra[0] + posServoGarra[1] + posServoGarra[2] + posServoGarra[3] + posServoGarra[4] + posServoGarra[5] + posServoGarra[6] + posServoGarra[7] + posServoGarra[8] + posServoGarra[9])/10);

   nol++;
   if(nol > 9) nol = 0;
 }
  
}

void loop() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);

  if(thetaf_PA > theta0_PA) {
    for(int i = theta0_PA; i < thetaf_PA; i++) {
      servoPA.write(i);
      delay(dt);
    }
  } else {
    for(int i = theta0_PA; i > thetaf_PA; i--) {
      servoPA.write(i);
      delay(dt);
    }
  }

      
  

   if(thetaf_PB > theta0_PB) {
    for(int i = theta0_PB; i < thetaf_PB; i++) {
      servoPB.write(i);
      delay(dt);
    }
   } else {
      for(int i = theta0_PB; i > thetaf_PB; i--) {
        servoPB.write(i);
        delay(dt);
      }
   }

   if(thetaf_Base > theta0_Base) {
      for(int i = theta0_Base; i < thetaf_Base; i++) {
        servoBase.write(i);
        delay(dt);
      }
   } else {
      for(int i = theta0_Base; i > thetaf_Base; i--) {
        servoBase.write(i);
        delay(dt);
      }
   }
      
   delay(t);
  
   if(thetaf_Garra > theta0_Garra) {
      for(int i = theta0_Garra; i < thetaf_Garra; i++) {
        servoGarra.write(i);
        delay(dt);
      }
   } else {
      for(int i = theta0_Garra; i > thetaf_Garra; i--) {
        servoGarra.write(i);
        delay(dt);
      }
   }
  
   delay(t);
  
  
   if(thetaf_Base > theta0_Base) {
      for(int i = thetaf_Base; i > theta0_Base; i--) {
        servoBase.write(i);
        delay(dt);
      }
   } else {
      for(int i = thetaf_Base; i < theta0_Base; i++) {
        servoBase.write(i);
        delay(dt);
      }
   }

   if(thetaf_PB > theta0_PB) {
      for(int i = thetaf_PB; i > theta0_PB; i--) {
        servoPB.write(i);
        delay(dt);
      }
   } else {
      for(int i = thetaf_PB; i < theta0_PB; i++) {
        servoPB.write(i);
        delay(dt);
      }
   }

  
      
  if(thetaf_PA > theta0_PA) {
      for(int i = thetaf_PA; i > theta0_PA; i--) {
        servoPA.write(i);
        delay(dt);
      }
  } else {
    for(int i = thetaf_PA; i < theta0_PA; i++) {
      servoPA.write(i);
      delay(dt);
    }
  }
 
  delay(t);
  
  if(thetaf_Garra > theta0_Garra) {
      for(int i = thetaf_Garra; i > theta0_Garra; i--) {
        servoGarra.write(i);
        delay(dt);
      }
   } else {
      for(int i = thetaf_Garra; i < theta0_Garra; i++) {
        servoGarra.write(i);
        delay(dt);
    }
  }
  
  delay(dt);

  
}
