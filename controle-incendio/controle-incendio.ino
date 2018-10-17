int LED_VERMELHO = 8;
int LED_VERDE = 9;
int BUZZER = 10;

// definicoes dos pinos ligados ao sensor
int pin_d0 = 7;
int pin_a0 = A0;

int nivel_sensor = 200;

void setup()
{
  // define os pinos de leitura do sensor como entrada
  pinMode(pin_d0, INPUT);
  pinMode(pin_a0, INPUT);
  // define pinos leds e buzzer como saida
  pinMode(pin_led_verm, OUTPUT);
  pinMode(pin_led_verde, OUTPUT);
  pinMode(pin_buzzer, OUTPUT);
  // inicializa a serial
  Serial.begin(9600);
}

void loop()
{
  // le os dados do pino digital D0 do sensor
  int valor_digital = digitalRead(pin_d0);
  // le os dados do pino analogico A0 do sensor
  int valor_analogico = analogRead(pin_a0);
  // mostra os dados no serial monitor
  Serial.print("Pino D0 : ");
  Serial.print(valor_digital);
  Serial.print(" Pino A0 : ");
  Serial.println(valor_analogico);
  // verifica o nivel de gas/fumaca detectado
  if (valor_analogico > nivel_sensor)
  {
    // Liga o buzzer e o led vermelho, e
    // desliga o led verde
    //    digitalWrite(LED_VERMELHO, HIGH);
    //    digitalWrite(LED_VERDE, LOW);
    digitalWrite(BUZZER, HIGH);
  }
  else
  {
    // Desliga o buzzer e o led vermelho, e
    // liga o led verde
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(BUZZER, LOW);
  }
  delay(100);
}
