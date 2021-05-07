//Roberto Vázquez Magdaleno y Gema Sánchez Sánchez
//Iria Touriño = función calcular resistencia entre otras cosas
//Alejandro Mayor = pantalla lcd entre otras cosas
//Ines Rico y Raquel Roca = funcion calcular voltaje entre otras cosas

#include <LiquidCrystal_I2C.h>
#include<Wire.h>

#define Sensibilidad 0.185; //sensibilidad en Voltios/Amperio para sensor de 5A
//ESCALAS 200uA; 2mA; 20mA; 200mA; 10A;

//Varios pulsadores para elegir lo que se mide
int boton_mv=3;
int boton_mi=4;
int boton_mr=5;
//para mentener el estado
bool estado1 = false;
bool estado2 = false;
bool estado3 = false;

LiquidCrystal_I2C lcd(0x27, 16, 2); //direccion 0x20 || 0x27
                                    // 16 columnas 2 filas
                                    
void mode(void);
void medir_corriente(float);
void medir_resistencia(void);

void setup()
{
  pinMode(boton_mv,INPUT);
  pinMode(boton_mi,INPUT);
  pinMode(boton_mr,INPUT);

  lcd.init();              //inicializar        
  lcd.backlight();          //la luz pantalla se encienda
  lcd.setCursor(0, 0);      //posicion inicial pantalla
  lcd.print("MULTIMETRO");
  lcd.setCursor(0, 1);
  lcd.print("DIGITAL");
  delay(4000);
  lcd.clear();

  Serial.begin(9600);
}

void loop() 
{
  mode();
}

void mode()
{
  
  
  if (digitalRead(boton_mv)==HIGH)
  {
    estado1 = !estado1;
    estado2 = false;
    estado3 = false;
    if(estado1==true)
    {
      //funcion de voltaje
    }
  }
  if (digitalRead(boton_mi)==HIGH)
  {
    float voltajecorriente = analogRead(A0)* (5.0 / 1023.0);
    estado2 = !estado2;
    estado1 = false;
    estado3 = false;
    if(estado2==true)
    {
      medir_corriente(voltajecorriente);
    }
  }
  if (digitalRead(boton_mr)==HIGH)
  {
    estado3 = !estado3;
    estado1 = false;
    estado2 = false;
    if(estado3==true)
    {
        medir_resistencia();      //funcion de resistencia
    }
  }
}

void medir_corriente(float v)
{
  float corriente;

  corriente=(v-2.5)/Sensibilidad;

  Serial.print("Corriente: ");
  Serial.println(corriente);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CORRIENTE: ");
  lcd.print(corriente,2);     //se imprimi en la lcd con dos decimales
  lcd.setCursor(0,1);                  
  lcd.print("amperios");
  
  delay(200);  
}

void medir_resistencia(void)      
{
  float R1 = 10000;
  float R2;
  int Ve = 5; //tension arduino
  float VR2;

  float lectura = analogRead(A1);
  if(lectura)
  {
  VR2 = (lectura * Ve) / 1024.0;
  R2 = R1 * (Ve / VR2) - 1;
  
  Serial.print("VR2: ");
  Serial.println(VR2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("VR2: ");
  lcd.print(VR2,2);     //se imprimi en la lcd con dos decimales
  lcd.print("VR2: ");
  
  Serial.print("R2: ");
  Serial.println(R2);
  Serial.print("Ω");
  lcd.setCursor(0,1);
  lcd.print("R2: ");
  lcd.print(R2,2);     //se imprime en la lcd con dos decimales
  lcd.print("OHM");
  
  delay(1000);
  }
  
  
void medir_voltaje(void)
{ 
  float voltaje_entrada = 5;
  float voltaje_final;
  float resistencia1 = 10000;
  float resistencia2 = 0;
  float VR2;

  float lectura = analogRead(A2);

  void setup() {

  pinMode(pin_lectura, INPUT);
  lcd.begin(0,0);

  }

  void loop() {

  VR2 = (lectura * voltaje_entrada) / 1024;  //Lee el voltaje de entrada
  voltaje_final = VR2 / (resistencia2 / (resistencia1 + resistencia2));  //Fórmula para el voltaje final

  lcd.setCursor(0,0);
  lcd.print("Voltaje DC:");

  lcd.setCursor(0,1);
  lcd.print(voltaje_final);  //Imprime el voltaje final
  delay(500);
  }
  
  }
    
}

