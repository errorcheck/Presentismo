#include <SoftwareSerial.h> // Primero se importa la biblioteca que permite la comunicación serie con el módulo Bluetooth.

SoftwareSerial hc06(2, 3); //Luego se define un objeto hc06 de la clase SoftwareSerial con los pines 2 y 3 como argumentos para la función constructora.

void setup() {
  //Inicializa el Monitor Serial
  Serial.begin(9600);    //En el método setup(), se inicializa el monitor serial y se establece la velocidad de transmisión en 9600 baudios.
  Serial.println("ENTER Comandos AT:"); //Monitor Serial que coloca mensaje en pantalla de ingreso de Comandos AT para config el dispositivo de comunicación
  hc06.begin(9600); //Inicializa el Puerto Serial a velocidad default de fábrica del módulo
}

void loop() //En el método loop(), se verifica si hay datos disponibles en el puerto serial del módulo Bluetooth y si es así, se leen y escriben en el monitor serial. 
            //Luego, se verifica si hay datos disponibles en el monitor serial y si es así, se leen y escriben en el puerto serial del módulo Bluetooth.
{
  //Escribe en el módulo HC06 al Monitor Serial
  if (hc06.available()) {
    Serial.write(hc06.read());
  }

  //Escribe del Monitor Serial al HC06
  if (Serial.available()) {
    hc06.write(Serial.read());
  }
}
