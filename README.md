# 🚗 Carrinho Autónomo Arduino - Desvio de Obstáculos (Varredura 360°)

Projeto de um robô móvel autónomo desenvolvido com **Arduino Uno**, capaz de navegar desviando-se de obstáculos através do mapeamento de ambiente em 360°, utilizando um **Sensor Ultrassónico HC-SR04** montado num **Micro Servomotor SG90** e controlo de motores através da ponte H **L293D**.

---
## 👥 Participantes e Contribuidores

| Foto | Nome | Função / Contribuição | GitHub |
| :---: | :--- | :--- | :---: |
| <img src="https://github.com/GabrielAmaralLuiz.png" width="50px;" style="border-radius:50%"> | **Gabriel Amaral** | Programador & Motor Driver | [@GabrielAmaralLuiz](https://github.com/GabrielAmaralLuiz) |
| <img src="https://github.com/ailaoliveira.png" width="50px;" style="border-radius:50%"> | **Aila Michelle** | Programação & Circuito do Servo/Sensor | [@ailaoliveira](https://github.com/ailaoliveira) |
| <img src="https://github.com/snowyaccount.png" width="50px;" style="border-radius:50%"> | **Otávio Dâmaceno** | Montagem do Chassis & Motor Driver | [@snowyaccount](https://github.com/snowyaccount) |
| <img src="https://github.com/github.png" width="50px;" style="border-radius:50%"> | **Nathanael Soares** | Montagem do Chassis & Motor Driver | [@NATHANAEL_USUARIO](https://github.com/NATHANAEL_USUARIO) |
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
| ----- | ----- | ----- | 
| **Arduino Uno** | 1 | Microcontrolador principal | 
| **Kit Chassi 4WD Robô** | 1 | Estrutura acrílica 4WD com 4 Motores DC e Rodas | 
| **Motor DC 3-6V + Roda 68mm** | 4 | Conjunto de motor TT com caixa de redução (3-6V) e roda emborrachada de 68mm para tração do chassi |
| **Driver L293D** | 1 | CI / Módulo Ponte H para controlo dos motores | 
| **HC-SR04** | 1 | Sensor de distância ultrassónico | 
| **Micro Servo SG90** | 1 | Servomotor para rotação do sensor | 
| **Bateria / Fonte Externa** | 1 | Alimentação dedicada para os motores (ex: suporte de pilhas 18650 / bateria 9V) | 
| **Breadboard & Jumpers** | 1 | Estrutura de conexões e fios | 

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
### 3. Driver de Motores L293D (CI 16 Pinos)

| Pino do L293D | Nome do Pino | Ligação / Destino | Descrição |
| :---: | :--- | :--- | :--- |
| **1** | `1-2EN` | Pino Digital `5` do Arduino (PWM) | Ativação/Velocidade do Motor Esquerdo |
| **2** | `1A` | Pino Digital `3` do Arduino | Controlo de Direção 1 (Motor Esquerdo) |
| **3** | `1Y` | Terminal (+) do Motor Esquerdo | Saída 1 para o Motor Esquerdo |
| **4** | `GND` | GND Geral / `BAT1-` | Massa / Ground de Lógica e Motores[cite: 1] |
| **5** | `GND` | GND Geral / `BAT1-` | Massa / Ground de Lógica e Motores[cite: 1] |
| **6** | `2Y` | Terminal (-) do Motor Esquerdo | Saída 2 para o Motor Esquerdo[cite: 1] |
| **7** | `2A` | Pino Digital `4` do Arduino | Controlo de Direção 2 (Motor Esquerdo)[cite: 1] |
| **8** | `VCC2` | Positivo da Bateria (`BAT1+`) | Alimentação de Potência dos Motores (Ex: 6V - 9V)[cite: 1] |
| **9** | `3-4EN` | Pino Digital `6` do Arduino (PWM) | Ativação/Velocidade do Motor Direito[cite: 1] |
| **10** | `3A` | Pino Digital `7` do Arduino | Controlo de Direção 1 (Motor Direito)[cite: 1] |
| **11** | `3Y` | Terminal (+) do Motor Direito | Saída 3 para o Motor Direito[cite: 1] |
| **12** | `GND` | GND Geral / `BAT1-` | Massa / Ground de Lógica e Motores[cite: 1] |
| **13** | `GND` | GND Geral / `BAT1-` | Massa / Ground de Lógica e Motores[cite: 1] |
| **14** | `4Y` | Terminal (-) do Motor Direito | Saída 4 para o Motor Direito[cite: 1] |
| **15** | `4A` | Pino Digital `8` do Arduino | Controlo de Direção 2 (Motor Direito)[cite: 1] |
| **16** | `VCC1` | 5V do Arduino (`U1_5V`) | Alimentação Lógica do CI (5V)[cite: 1] |
## 💻 Como Executar o Projeto

---
1. Faça o download ou clone este repositório:
   ```bash
   git clone https://github.com/GabrielAmaralLuiz/CARRINHO-ARDUINO---HC-SR04-E-CONTROLO-S-RIE.git
