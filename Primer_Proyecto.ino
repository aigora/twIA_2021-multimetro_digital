
#define Sensibilidad 0.185; //sensibilidad en Voltios/Amperio para sensor de 5A

//Varios pulsadores para elegir lo que se mide
int boton_mv=3;
int boton_mi=4;
int boton_mr=5;
//para mentener el estado
bool estado1 = false;
bool estado2 = false;
bool estado3 = false;

void mode(void);
void medir_corriente(float);
void medir_resistencia(float);
void medir_volt(float);

void setup()
{
  pinMode(boton_mv,INPUT);
  pinMode(boton_mi,INPUT);
  pinMode(boton_mr,INPUT);

  Serial.begin(9600);
}

void loop() 
{
  mode();
}

void mode()
{
  float Sensor_corriente;
  float VR2;
  float Vin;
  
  Sensor_corriente = analogRead(A0) * (5.0 / 1023.0);
  VR2 = analogRead(A1) * (5.0 / 1023.0);
  Vin=analogRead(A2)*(5.0/1023.0);
  

  if (digitalRead(boton_mv)==HIGH)
  {
    estado1 = !estado1;
    estado2 = false;
    estado3 = false;
    if(estado1==true)
    {
      //funcion de voltaje
      medir_volt(Vin);
      //pantalla lcd
    }
  }
  if (digitalRead(boton_mi)==HIGH)
  {
    estado2 = !estado2;
    estado1 = false;
    estado3 = false;
    if(estado2==true)
    {
      medir_corriente(Sensor_corriente);
      //Mostrar en pantalla lcd
    }
  }
  if (digitalRead(boton_mr)==HIGH)
  {
    estado3 = !estado3;
    estado1 = false;
    estado2 = false;
    if(estado3==true)
    {
      //funcion de resistencia
      medir_resistencia(VR2);
    }
  }
}

void medir_corriente(float Sensor_corriente)
{
  float corriente;

  corriente=(Sensor_corriente-2.5)/Sensibilidad;

  Serial.print("Corriente: ");
  Serial.println(corriente);

  delay(200);  
}

void medir_resistencia(float VR2){
//int PinA0 = 0;  
//int lectura = 0;
//int Ve = 5; // Tensión en el Arduino.
//float VR2 = 0;
float R1 = 10000;
float R2 = 0;
//lectura = analogRead(PinA0);
    
        //VR2 = (lectura * Ve) / 1024.0;
        R2 = R1 * (5.0 / VR2) - 1;
        Serial.print("VR2: ");
        Serial.println(VR2);
        Serial.print("R2: ");
        Serial.println(R2);
        Serial.print("Ω");
        delay(1000);
    

  
}

void medir_volt(float Vin){
  
  float R1 = 100000; //Resistencia de 100K
  float R2=0;
  float Vout;


  

  Vout=(R2/R1+R2)*Vin;

  Vin=Vout/(R2/(R1+R2));

     Serial.println("Voltaje ");
     Serial.print(Vin);
     

  //lcd.setCursor(0,0);
  //lcd.print("Voltaje DC:");

  //lcd.setCursor(0,1);
  //lcd.print(voltaje_final);  //Muestra el voltaje final
  //lcd.print(voltaje_final);  //Imprime el voltaje final
  delay(500);
  
}
