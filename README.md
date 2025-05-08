## 🤖 Programando ideias: A idealização, prototipagem e desenvolvimento de um robô autônomo por alunos da rede pública de Vitória.

Este repositório reúne o material técnico, imagens, códigos e metodologia do projeto **Programando Ideias**, desenvolvido com alunos da rede pública de Vitória/ES no contexto do PIBICjr (CDTIV - Vitória/ES).

## Objetivo

O projeto teve como objetivo principal introduzir estudantes do ensino fundamental aos fundamentos da robótica, eletrônica e programação através da construção colaborativa de **robôs seguidores de linha** usando Arduino.

- Introdução à lógica de programação
- Eletrônica básica com Arduino
- Sensores infravermelhos (IR)
- Controle de motores com ponte H (L298N)
- Pensamento computacional e resolução de problemas
- Criatividade e personalização de projetos

---

## Tecnologias Utilizadas

- **Arduino UNO**: Microcontrolador usado como "cérebro" do robô.
- **L298N**: Ponte H para controle bidirecional dos motores.
- **Motores DC com rodas**: Proporcionam o movimento.
- **Sensores infravermelhos (IR)**: Detectam a linha preta sobre fundo branco.
- **Chassi 2WD**: Chassi com suporte para duas rodas.
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

A lógica de controle foi implementada em C++ no Arduino IDE. O projeto conta com uma classe `DCMotor` que abstrai o controle de cada motor, com métodos para:

- `Pinout()` – definição dos pinos de controle
- `Speed()` – ajuste da velocidade
- `Forward()` – movimentação para frente
- `Backward()` – movimentação para trás (não utilizada neste projeto)
- `Stop()` – parada do motor

Sensores IR são lidos nos pinos 7 e 8. A decisão do comportamento é feita no `loop()`, baseado nas leituras dos sensores, definindo qual motor deve parar ou continuar girando, promovendo um movimento de correção quando o robô sai da linha. 

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
```

## Impacto Educacional

- Oficinas realizadas com dezenas de alunos da rede pública
- Participação em eventos como a **INOVAVIX**
- Fortalecimento da aprendizagem prática em robótica e tecnologia
- Desenvolvimento de habilidades como criatividade, colaboração, pensamento crítico e resolução de problemas

## Equipe do Projeto

Este projeto foi idealizado e conduzido com a colaboração de uma equipe dedicada de estudantes e educadores que acreditam no poder transformador da educação prática e acessível:

**Orientador:**  
- Prof. Victor de Luna Zottis Pierobom

**Equipe de Alunos Bolsistas (PIBIC-Jr):**  
- Ana Luiza Amorim  
- Katheyne Gabriele S. Amaral  
- Kevin Correa Amorim  
- Mariana Valentim Meireles  
- Nicolas Oliveira Venceslau

**Equipe Voluntária:**  
- Ana Isabela da Silva  
- Arthur Nascimento  
- Gabriel Amaral  
- Paulo Henrique A. de Oliveira

Agradeço a todos os envolvidos pelo entusiasmo, comprometimento e criatividade ao longo de todas as etapas do projeto. Cada robô construído representa não apenas uma conquista técnica, mas também o despertar de novas possibilidades para o futuro desses jovens.

https://vitoria.es.gov.br/noticia/pibic-jr-2023-programa-para-estudantes-seleciona-10-projetos-47750
