/* Programa para el atmega esclavo
 *
 * Se usa PULL UP para todo
 * 
 * Por un tema de comodidad en el conexionado del maletin, no se usa esta declaracion de pines para probar el programa
 */
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <VarSpeedServo.h> //La libreria ya esta agregada pero me salta error(?)
#include <TimerOne.h>
#include <Wire.h>
/* Todos los pines comentados estan declarados como en la plaqueta
 * Por un tema de comodidad en el conexionado del maletin, no se usa esta declaracion de pines para probar el programa

Los servos van en los pines 3, 5 y 6
#define infra1 A1 
#define infra2 A2
#define infra3 A3
#define infra4 12
#define infra5 11

#define dataPin 8 //SER - A
#define pinLatch 9 //RCLK
#define clockPin 10 //SRCLK

#define incremento A0
#define inicio 13*/

#define infra1 A0
#define infra2 A1
#define infra3 A2
#define infra4 A3
#define infra5 4

#define pinLatch 7  //RCLK
#define clockPin 8 //SRCLK
#define dataPin 5 //SER - A

#define incremento 10
#define inicio 12 

VarSpeedServo miservo_1, miservo_2, miservo_3;

LiquidCrystal_I2C lcd(0x3F, 16, 2); //SCL--A5  SDA--A4

void setup(){
  Serial.begin(57600); 

  lcd.init();
  lcd.backlight();
  //Mensaje de bienvenida
  lcd.setCursor(0, 0);
  lcd.print("  Bienvenido a  ");
  lcd.setCursor(0, 1);
  lcd.print("  Super Guanti  ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Una creacion de:");
  lcd.setCursor(0, 1);
  lcd.print("     M.A.L.     ");
  delay(1000);

  pinMode(incremento, INPUT);
  pinMode(inicio, INPUT);

  pinMode(infra3, INPUT);
  pinMode(infra2, INPUT);
  pinMode(infra3, INPUT);
  pinMode(infra4, INPUT);
  pinMode(infra5, INPUT);

  pinMode(pinLatch, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  miservo_1.attach(9, 350, 2900); //servo base, derecha-izquierda
  miservo_1.write(grados1); 

  miservo_2.attach(6, 1000, 2000); //servo de la derecha, adelante-atras
  miservo_2.write(grados2); 

  miservo_3.attach(11, 1000, 2000); //servo de la izqueirda, abajo
  miservo_3.write(grados3);

  digitalWrite(pinLatch, LOW);              
  shiftOut(dataPin, clockPin, MSBFIRST, 0); 
  digitalWrite(pinLatch, HIGH);
}

void loop(){

}