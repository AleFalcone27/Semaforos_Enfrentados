// Declaramos variables e inicializamos los pinMode
#define LED_GREEN 2
#define LED_RED 3
#define LED_YELLOW 4
#define buzzerPin 8
#define PULSADOR 12

int presiono;

void setup()
{
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(PULSADOR, INPUT); // pull down 
  
    leerPulsador;
 
    secuenciaBu;
  
    secuenciaSem;
  
    Serial.begin(9600); // Inicializamos el monitor en serie
}

int leerPulsador (){
    
// Esta funcion lee el estado del pulsador
  
    presiono = digitalRead(PULSADOR);
  
    return presiono;
}


void secuenciaBu(int pin, int potencia, int repeticiones, int d1, int d2)
{
    // Esta funcion hace sonar buzzer
    // Recbie como parametros:
    // pin: numero de pin en donde se encuentra conectado el buzzer al arduino
    // potencia: potencia que queremos que tengan los pitidos
    // repeticiones: cantidad de veces que va a sonar el buzzer
    // d1: delay 1
    // d2: delay 2
    
    for (int i = 0; i < repeticiones; i++)
    {
        if (presiono == LOW)
        {
            int presiono = leerPulsador();
        }
        
        tone(buzzerPin, potencia);
        Serial.println("zumbador");
        delay(d1);
        noTone(buzzerPin);
        delay(d2);
        
        }
    }

void titilar(int led, int cantidad)
{
    // Esta funcion se encarga de hacer titilar a las luces cuando corresponda 
    // Recibe como parametros:
    // led: número de led el cual queremos operar
    // cantidad de veces que queremos que titile
    
    for (int i = 0; i < cantidad; i++)
    {
        digitalWrite(led, HIGH);
        
        delay(200);
        
      	if (presiono == LOW)
        {
            int presiono = leerPulsador();
        }
        
        digitalWrite(led, LOW);
        
        delay(200);
    }
}

void secuenciaSem(int led)
    {
        
        // Esta funcion se encarga de la ejecucion de nuestro programa
        // Recibe como parametro:
        // led: Numero de led con el cual queremos operar
        
        if (led == 2)
        {
            if (presiono == LOW)
            {
                int presiono = leerPulsador();
            }
            
          	Serial.println("VERDE -- ROJO");
            digitalWrite(led, HIGH);
            
            if (presiono == HIGH)
            {
             	Serial.println("--TIEMPO EXTRA--");
              	secuenciaBu(8,1000,20,350,200);
              	titilar(led,3);
            }
            else
            {
                  secuenciaBu(8,1000,10,350,200);
                  titilar(led,3);
            }
       
            presiono = LOW;
            digitalWrite(led, LOW);
        }
      
        if (led == 3)
        {
          	if (presiono == LOW)
            {
                int presiono = leerPulsador();
            }
            
          	Serial.println("ROJO -- VERDE");
            digitalWrite(led, HIGH);
            if (presiono == HIGH)
            {
             	Serial.println("--TIEMPO EXTRA--");
              	secuenciaBu(8,1000,20,350,200);
              	titilar(led,3);
            }
            else
            {
                secuenciaBu(8,1000,10,350,200);
                titilar(led,3);
            }
           
                presiono = LOW;
                digitalWrite(led, LOW);
        }
          
        if (led == 4)
        {
            if (presiono == LOW)
            {
                int presiono = leerPulsador();
          	}
          	
        	Serial.println("Luz amarilla");
        	
            digitalWrite(led, HIGH);
            
            secuenciaBu(8,180,3,750,250);
            
            titilar(led,3);
            
            digitalWrite(led, LOW);
        }
    }


void loop()
{
    // Esta funcion se encarga de ejecucion de nuestro programa
    
    secuenciaSem(LED_GREEN);
    secuenciaSem(LED_YELLOW);
	secuenciaSem(LED_RED);
    secuenciaSem(LED_YELLOW);
  
}



