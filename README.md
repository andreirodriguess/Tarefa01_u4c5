# Semáforo com RP2040  

## Descrição  
Este repositório contém um programa para o **Raspberry Pi Pico (RP2040)** que controla um **semáforo de LEDs** usando **interrupções de timer**.  

O funcionamento é o seguinte:  
- Um **LED vermelho** acende primeiro.  
- A cada **3 segundos**, o LED muda de cor seguindo a sequência: **vermelho → amarelo → verde → vermelho**.  
- O programa exibe mensagens no terminal indicando a passagem do tempo e a mudança de cor dos LEDs.  
