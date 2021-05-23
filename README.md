# Multímetro digital.

Nuestro multimetro será capaz de medir tensiones y corrientes a través del arduino, pasará los datos al ordenador y mediante un codigo de Visual guardar los datos en un fichero.

## Integrantes del equipo

Alejandro Mayor Escalada, @amayore .  
Roberto Vázquez Magdaleno.  
Inés Rico Peng.  
Raquel Roca Pereira.  
Gema Sánchez Sánchez, @gema-upm .  
Iria Touriño Villanueva.  

## Objetivos del trabajo

Diseñar y desarrollar un multímetro capaz de hacer lecturas de corriente, voltaje y resistencia de cualquier circuito o elemento (resistencias), pasar las lecturas al ordenador desde Visual Studio y que se queden guardadas en un fichero.

## Sensores y actuadores

### Convertidor analógico-digital  
### Pantalla LCD  
### Sensor de corriente ACS712  

El ACS712 es un sensor de corriente tanto alterna como continua, que permite medir la intensidad eléctrica que atraviesa un conductor. Podemos emplear el ACS712 junto con un procesador como Arduino para medir la intensidad o potencia consumida por una carga.  
Internamente el ACS712 consiste en un sensor hall de precisión y bajo offset junto con un canal de conducción localizado cerca de la superficie del integrado. Cuando la corriente fluye por el canal de cobre genera un campo magnético que es detectado por el sensor Hall y es convertido en una tensión.  
La salida del sensor es una tensión proporcional a la corriente, y altamente independiente de la temperatura. El sensor viene calibrado desde fábrica, aunque para una medición de precisión hará falta un ajuste de la calibración.  
El sensor entrega un valor de 2.5 V para una corriente de 0 A y, a partir de allí, se incrementa proporcionalmente de acuerdo a la sensibilidad del propio sensor, mediante una relación lineal entre la salida de voltaje del sensor y la corriente.  
Dicha relación es una línea recta en una gráfica V-A:  
V = sensibilidad * I + 2.5; I = (V - 2.5) / sensibilidad  
Este producto está diseñado para su uso por debajo de 30V.  
La mayor desventaja del ACS712 es que es un sensor intrusivo, es decir, es necesario insertarlo en un conductor lo cual puede suponer que tengamos que cortar un cable.  
Fuentes: https://naylampmechatronics.com/blog/48_tutorial-sensor-de-corriente-acs712.html   
         https://www.luisllamas.es/arduino-intensidad-consumo-electrico-acs712/  


### Módulo cargador de batería  
Un cargador para baterías litio, TP4056, permite conectarle una fuente de energía eléctrica a su entrada y una batería a su salida para que pueda cargarse. 
El TP4056 es un chip encapsulado en formato SOP-8, adecua la entrada de energía para el estándar 1A y también puede controlar la temperatura. Además, para su funcionamiento, hace falta un puerto miniUSB para alimentar la batería a través de cables, LEDs de carga y de completado que avisan cuando está cargado y cuando se ha terminado el proceso, y BAT+/BAT- que son bornes de salida que irán conectados a los bornes de la batería que necesitamos cargar.  
Fuente:https://www.hwlibre.com/tp4056/

### Pulsadores  
Son componentes eléctricos que permiten o no el paso de la corriente dependiendo de si están accionados o no. Al presionarlo se abrirá o cerrará, y para que vuelva a su estado original habrá que realizar el mismo procedimiento.  En nuestro caso, los pulsadores los utilizaremos para seleccionar qué magnitudes queremos que mida nuestro multímetro. Por ejemplo, si necesitamos medir amperios, presionaremos ell pulsador uno; realizando el mismo proceso para medir el voltaje y la resistencia. A parte tendremos otro pulsador que servirá para encender el multímetro, encendiendo un led cuando esté en la posición que permita el paso de corriente al circuito y así poder diferenciar los estados de on y off.  
Fuente: https://www.areatecnologia.com/electricidad/pulsador.html

