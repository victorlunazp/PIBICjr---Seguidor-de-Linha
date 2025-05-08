class DCMotor {  
  int spd = 255, pin1, pin2;
  
  public:  
  
    void Pinout(int in1, int in2){ // Pinout é o método para a declaração dos pinos que vão controlar o objeto motor
      pin1 = in1;
      pin2 = in2;
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      }   
    void Speed(int in1){ // Speed é o método que irá ser responsável por salvar a velocidade de atuação do motor
      spd = in1;
      }     
    void Forward(){ // Forward é o método para fazer o motor girar para frente
      analogWrite(pin1, spd);
      digitalWrite(pin2, LOW);
      }   
    void Backward(){ // Backward é o método para fazer o motor girar para trás
      digitalWrite(pin1, LOW);
      analogWrite(pin2, spd);
      }
    void Stop(){ // Stop é o metodo para fazer o motor ficar parado.
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      }
   };


DCMotor Motor1, Motor2; // Criação de dois objetos motores, já que usaremos dois motores, e eles já estão prontos para receber os comandos já configurados acima.

#define pinSensor1 7
#define pinSensor2 8

void setup(){
  
  Motor1.Pinout(6,5); // Seleção dos pinos que cada motor usará, como descrito na classe.
  Motor2.Pinout(9,10); 

  Motor1.Speed(80); // A velocidade do motor pode variar de 0 a 255, onde 255 é a velocidade máxima.
  Motor2.Speed(80);

  pinMode (pinSensor1, INPUT); // Definição dos pinos dos sensores como entradas.
  pinMode (pinSensor2, INPUT);

  Serial.begin(9600); // Inicialização da comunicação serial.
}
void loop(){
bool estadoSensor1 = digitalRead(pinSensor1);
bool estadoSensor2 = digitalRead(pinSensor2);
if (estadoSensor1 == 1 & estadoSensor2 == 1) { // Condição onde os dois sensores estão sobre a linha.
  Motor1.Forward(); // Comando para o motor ir para frente
  Motor2.Forward();
  // Serial.println("sensor 1: Preto");
  // Serial.println("sensor 2: Preto");
  // Serial.println(estadoSensor1);
  // Serial.println(estadoSensor2);
  // digitalWrite(M1,HIGH);
  // digitalWrite(M2,HIGH);
}
if (estadoSensor1 == 1 & estadoSensor2 == 0){ // Condição onde apenas o sensor esquerdo está sobre a linha.
  Motor1.Stop(); // Comando para o motor parar
  Motor2.Forward(); // Comando para o motor ir para frente
  // Serial.println("sensor 1: Preto");
  // Serial.println("sensor 2: Branco");
  // digitalWrite(M1,LOW);
  // digitalWrite(M2,HIGH);
}
if (estadoSensor1 == 0 & estadoSensor2 == 1) { // Condição onde apenas o sensor direito está sobre a linha.
  Motor1.Forward(); // Comando para o motor ir para frente
  Motor2.Stop(); // Comando para o motor parar
  // Serial.println("sensor 1: Branco");
  // Serial.println("sensor 2: Preto");
  // digitalWrite(M1,HIGH);
  // digitalWrite(M2,LOW);
}
else if (estadoSensor1 == 0 & estadoSensor2 == 0) {
  Motor1.Stop(); // Comando para o motor parar
  Motor2.Stop();
  // Serial.println("ROBÔ PERDIDO");
  // digitalWrite(M1,LOW);
  // digitalWrite(M2,LOW);
  // Serial.println(estadoSensor1);
  // Serial.println(estadoSensor2);
}
}
