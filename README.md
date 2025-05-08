# PIBICjr---Seguidor-de-Linha
Projeto de Iniciação Cientifica Junior - EMEF Edna de Mattos Ciqueira Gáudio

# 🤖 Programando Ideias: Robô Seguidor de Linha com Arduino

Este repositório reúne o material técnico, imagens, códigos e metodologia do projeto **Programando Ideias**, desenvolvido com alunos da rede pública de Vitória/ES no contexto do PIBICjr (CNPq/IFES).

## Objetivo

O projeto teve como objetivo principal introduzir estudantes do ensino fundamental aos fundamentos da robótica, eletrônica e programação através da construção colaborativa de **robôs seguidores de linha** usando Arduino.

![2](https://github.com/user-attachments/assets/d84a82a1-3afd-40b1-97d0-a3bf9bdd820f)

---

## Tecnologias Utilizadas

- **Arduino UNO**: Microcontrolador usado como "cérebro" do robô.
- **L298N**: Ponte H para controle bidirecional dos motores.
- **Motores DC com rodas**: Proporcionam o movimento.
- **Sensores infravermelhos (IR)**: Detectam a linha preta sobre fundo branco.
- **Scratch para Arduino / AppInventor**: Usado em etapas introdutórias.
- **C++ para Arduino**: Linguagem usada no código final do robô.

---

## ⚙️ Lógica de Funcionamento

O robô possui **dois sensores IR** voltados para o chão. Com base na cor lida (preto ou branco), ele decide como acionar os motores para seguir a linha preta:

| Sensor Esquerdo | Sensor Direito | Ação do Robô                     |
|------------------|------------------|----------------------------------|
| PRETO            | PRETO            | Anda em linha reta               |
| BRANCO           | PRETO            | Vira para a direita (corrige)    |
| PRETO            | BRANCO           | Vira para a esquerda (corrige)   |
| BRANCO           | BRANCO           | Para (linha perdida)             |

### Diagrama Lógico

![3](https://github.com/user-attachments/assets/16520bd6-1b1d-46d4-982b-8a77321a0ccd)

---

## Esquemático de Hardware

Todos os componentes foram conectados conforme o diagrama abaixo:

![image](https://github.com/user-attachments/assets/185cf567-9c3e-46d3-b07e-8e38c925114f)

---

## Código Fonte (Arduino/C++)

O controle dos motores foi encapsulado em uma classe chamada `DCMotor`. Sensores IR são lidos nos pinos 7 e 8. A decisão do comportamento é feita no `loop()`, baseado nas leituras dos sensores.

### Trecho principal:

```cpp
if (estadoSensor1 == 1 && estadoSensor2 == 1) {
  Motor1.Forward(); Motor2.Forward(); // Linha reta
} else if (estadoSensor1 == 1 && estadoSensor2 == 0) {
  Motor1.Stop(); Motor2.Forward(); // Vira direita
} else if (estadoSensor1 == 0 && estadoSensor2 == 1) {
  Motor1.Forward(); Motor2.Stop(); // Vira esquerda
} else {
  Motor1.Stop(); Motor2.Stop(); // Robô perdido
}
