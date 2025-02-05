# Simulação de Semáforo com Temporizador Periódico
Yasmin Damasceno Cruz - TIC370101610  
Unidade 4 - Capítulo 5

Este projeto implementa a simulação de um semáforo utilizando um temporizador periódico de 3 segundos, empregando a função add_repeating_timer_ms() do Pico SDK. A cada 3 segundos, o semáforo alterna entre os sinais vermelho, amarelo e verde. Além disso, a rotina principal exibe mensagens na porta serial a cada 1 segundo.

O código é escrito em C e executado no microcontrolador Raspberry Pi Pico W. A simulação pode ser realizada por meio da ferramenta educacional Wokwi e integrada ao VS Code.

## Componentes Utilizados

- 1x Microcontrolador Raspberry Pi Pico W
- 3x LEDs (vermelho, amarelo e verde)
- 3x Resistores de 330 Ω

## Configuração Inicial

1. Clone o repositório para sua máquina local:
   ```bash
   git clone <https://github.com/YasminCruz001/Temporizador-Periodico.git>
   ```
2. Abra o projeto no VS Code.
3. Abra o arquivo `diagram.json` no Wokwi para visualizar a simulação dos componentes.

## Execução

- O código inicia com o LED vermelho aceso.
- A cada 3 segundos, o LED aceso muda para a próxima cor na sequência: vermelho → amarelo → verde.
- A função repeating_timer_callback() gerencia a troca de estados dos LEDs.
- A cada 1 segundo, uma mensagem é impressa na porta serial informando o status do sistema