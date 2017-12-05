/*
  www.diymakers.es
  by A.García
  Arduino + Processing: Primeros Pasos
  Tutorial en: http://diymakers.es/arduino-processing-primeros-pasos/
*/
 
int led=9;
int temp;// Variable sensor de temperaura
boolean status=LOW; //Estado del led
 
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}
 
void loop()
{
  temp = analogRead(A1); //Lee los datos del sensor LM35
  
  temp = (5.0 * temp * 100)/1023.0;//Formula para convertir a ºC
  Serial.write(temp); //Enviamos los datos en forma de byte
  delay(100);
 
  if(Serial.available()>0)//Si el Arduino recibe datos a través del puerto serie
  {
    byte dato = Serial.read(); //Los almacena en la variable "dato"
    if(dato==65)  //Si recibe una "A" (en ASCII "65")
    {
      status=!status; //Cambia el estatus del led
    }
    digitalWrite(led,status);
  }
}
