# 🚗 Carrinho Autónomo Arduino - Desvio de Obstáculos (Varredura 360°)

Projeto de um robô móvel autónomo desenvolvido com **Arduino Uno**, capaz de navegar desviando-se de obstáculos através do mapeamento de ambiente em 360°, utilizando um **Sensor Ultrassónico HC-SR04** montado num **Micro Servomotor SG90** e controlo de motores através da ponte H **L293D**.

---
## 👥 Participantes e Contribuidores

| Foto | Nome | Função / Contribuição | GitHub |
| :---: | :--- | :--- | :---: |
| <img src="https://github.com/OUTRO_USUARIO.png" width="50px;" style="border-radius:50%"> | **Gabriel Amaral** | Montagem do Chassis & Motor Driver | [@OUTRO_USUARIO](https://github.com/GabrielAmaralLuiz) |
| <img src="https://github.com/SEU_USUARIO.png" width="50px;" style="border-radius:50%"> | **Aila Michelle** | Programação & Circuito do Servo/Sensor | [@SEU_USUARIO](https://github.com/SEU_USUARIO) |
| <img src="https://github.com/OUTRO_USUARIO.png" width="50px;" style="border-radius:50%"> | **Otávio Dâmaceno** | Montagem do Chassis & Motor Driver | [@OUTRO_USUARIO](https://github.com/OUTRO_USUARIO) |
| <img src="https://github.com/OUTRO_USUARIO.png" width="50px;" style="border-radius:50%"> | **Natthanael Soares** | Montagem do Chassis & Motor Driver | [@OUTRO_USUARIO](https://github.com/OUTRO_USUARIO) |

---
## 📌 Funcionalidades

* **Navegação Autónoma:** Movimento contínuo para a frente com monitorização constante de distância em tempo real.
* **Mapeamento 360° Combinado:** 
  * Varredura em leque de 0° a 180° realizada pelo servomotor.
  * Complemento de rotação de 180° no próprio eixo do chassis quando a frente se encontra totalmente bloqueada.
* **Algoritmo de Tomada de Decisão:** Avalia todas as leituras da varredura e escolhe automaticamente a direção com maior espaço livre para continuar o trajeto.
* **Suporte a Controlo Manual:** Estrutura pronta para receber comandos via Monitor Serial ou módulo Bluetooth (HC-05 / HC-06).

---

## 🛠️ Componentes Utilizados

| Componente | Quantidade | Descrição |
| :--- | :---: | :--- |
| **Arduino Uno** | 1 | Microcontrolador principal |
| **Driver L293D** | 1 | CI Ponte H para controlo de motores DC |
| **HC-SR04** | 1 | Sensor de distância ultrassónico |
| **Micro Servo SG90** | 1 | Servomotor para rotação do sensor |
| **Motores DC** | 4 | Motores de tração das rodas |
| **Bateria / Fonte Externa** | 1 | Alimentação dedicada para os motores (ex: bateria 9V ou pack de pilhas) |
| **Breadboard & Jumpers** | 1 | Estrutura de conexões |

---

## 🔌 Tabela de Conexões e Pinos

### 1. Sensor Ultrassónico (HC-SR04)
* **VCC** -> 5V da Breadboard
* **GND** -> GND da Breadboard
* **Trig** -> Pino Digital `10` do Arduino
* **Echo** -> Pino Digital `11` do Arduino

### 2. Micro Servo Motor (SG90)
* **VCC (Vermelho)** -> 5V da Breadboard
* **GND (Castanho/Preto)** -> GND da Breadboard
* **Sinal (Laranja/Amarelo)** -> Pino Digital `9` (PWM) do Arduino

### 3. Driver de Motores L293D
* **Motor Esquerdo (Canal A):**
  * `ENA` (PWM) -> Pino Digital `5` do Arduino
  * `IN1` -> Pino Digital `3` do Arduino
  * `IN2` -> Pino Digital `4` do Arduino
* **Motor Direito (Canal B):**
  * `ENB` (PWM) -> Pino Digital `6` do Arduino
  * `IN3` -> Pino Digital `7` do Arduino
  * `IN4` -> Pino Digital `8` do Arduino

---

## 💻 Como Executar o Projeto

1. Faça o download ou clone este repositório:
   ```bash
   git clone [https://github.com/SEU_USUARIO/CARRINHO-ARDUINO---HC-SR04-E-CONTROLO-S-RIE.git](https://github.com/SEU_USUARIO/CARRINHO-ARDUINO---HC-SR04-E-CONTROLO-S-RIE.git)
