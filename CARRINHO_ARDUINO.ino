// =============================================================
// CÓDIGO DO CARRINHO ARDUINO - HC-SR04 + SERVO (VARREDURA 360°)
// =============================================================

#include <Servo.h>

// --- PINOS DO SENSOR ULTRASSÓNICO HC-SR04 ---
#define TRIG_PIN 10 // Pino Trig do HC-SR04
#define ECHO_PIN 11 // Pino Echo do HC-SR04

// --- PINO E OBJETO DO SERVO MOTOR ---
#define SERVO_PIN 9 // Pino do Sinal do Servo (PWM)
Servo meuServo;

// --- PINOS DO MOTOR ESQUERDO (L293D) ---
#define ENA 5  // Ativar 1 e 2 (PWM)
#define IN1 3  // Entrada 1
#define IN2 4  // Entrada 2

// --- PINOS DO MOTOR DIREITO (L293D) ---
#define ENB 6  // Ativar 3 e 4 (PWM)
#define IN3 7  // Entrada 3
#define IN4 8  // Entrada 4

// Velocidade dos motores (0 a 255)
int velocidade = 200; 
char comando;

void setup() {
  // Configuração dos pinos do driver L293D como saída
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Configuração dos pinos do Sensor HC-SR04
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Inicializa o Servo Motor e alinha para a frente (90°)
  meuServo.attach(SERVO_PIN);
  meuServo.write(90);

  // Inicializa a comunicação Serial
  Serial.begin(9600);
  
  // Garante que o carrinho começa parado
  parar();
  delay(1000);
}

void loop() {
  // 1. Verifica comandos manuais via Monitor Serial
  if (Serial.available() > 0) {
    comando = Serial.read();
    processarComando(comando);
  }

  // 2. Medição contínua com o sensor virado para a frente
  long distanciaFrente = medirDistancia();

  Serial.print("Distância Frente: ");
  Serial.print(distanciaFrente);
  Serial.println(" cm");

  // 3. Lógica Autónoma de Desvio de Obstáculos
  if (distanciaFrente > 0 && distanciaFrente < 25) { // Obstáculo a menos de 25cm
    parar();
    delay(200);

    // Mapeia a área de 0° a 180° com o servo
    int melhorAngulo = escanear180();

    // Decisão de movimento
    if (melhorAngulo < 70) {
      // Maior espaço à direita
      direita();
      delay(400);
      parar();
    } else if (melhorAngulo > 110) {
      // Maior espaço à esquerda
      esquerda();
      delay(400);
      parar();
    } else {
      // Frente bloqueada: o carrinho recua e faz rotação de 180° no próprio eixo
      tras();
      delay(300);
      direita(); 
      delay(800); // Ajusta este tempo se o carrinho girar mais/menos de 180°
      parar();
    }
  } else {
    // Caminho livre
    frente();
  }

  delay(50);
}

// =============================================================
// FUNÇÃO DE VARREDURA 180° COM O SERVO
// =============================================================
int escanear180() {
  int maiorDistancia = 0;
  int melhorAngulo = 90;

  for (int angulo = 0; angulo <= 180; angulo += 30) {
    meuServo.write(angulo);
    delay(150); // Aguarda o servo estabilizar
    long dist = medirDistancia();

    if (dist > maiorDistancia) {
      maiorDistancia = dist;
      melhorAngulo = angulo;
    }
  }

  meuServo.write(90); // Reposiciona para a frente
  return melhorAngulo;
}

// =============================================================
// FUNÇÃO DE LEITURA DO SENSOR HC-SR04
// =============================================================
long medirDistancia() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH);
  long distancia = duracao * 0.034 / 2;
  return distancia;
}

// =============================================================
// PROCESSAMENTO DOS COMANDOS MANUAIS
// =============================================================
void processarComando(char c) {
  switch (c) {
    case 'W': case 'w': case 'F': case 'f': frente(); break;
    case 'S': case 's': case 'B': case 'b': tras(); break;
    case 'A': case 'a': case 'L': case 'l': esquerda(); break;
    case 'D': case 'd': case 'R': case 'r': direita(); break;
    case 'P': case 'p': case ' ': case 'X': case 'x': parar(); break;
  }
}

// =============================================================
// FUNÇÕES DE MOVIMENTO DOS MOTORES
// =============================================================
void frente() {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tras() {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void esquerda() {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void direita() {
  analogWrite(ENA, velocidade);
  analogWrite(ENB, velocidade);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void parar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}