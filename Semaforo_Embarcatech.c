#include "pico/stdlib.h"

#define RED_PIN   11  // LED VERMELHO  
#define YELLOW_PIN 12  // LED AMARELO
#define GREEN_PIN  13  // LED VERDE

// Função callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    static int state = 0;

    // Desliga todos os LEDs antes de mudar o estado
    gpio_put(RED_PIN, 0);
    gpio_put(YELLOW_PIN, 0);
    gpio_put(GREEN_PIN, 0);

    // Acende o LED correspondente ao estado atual
    if (state == 0) {
        gpio_put(RED_PIN, 1);
    } else if (state == 1) {
        gpio_put(YELLOW_PIN, 1);
    } else if (state == 2) {
        gpio_put(GREEN_PIN, 1);
    }

    // Alterar o estado para o próximo LED
    state = (state + 1) % 3;

    // Retorna true para que o temporizador continue a ser chamado
    return true;
}

// Função principal
int main() {
    // Inicializa os pinos GPIO para os LEDs
    gpio_init(RED_PIN);
    gpio_set_dir(RED_PIN, GPIO_OUT);
    gpio_init(YELLOW_PIN);
    gpio_set_dir(YELLOW_PIN, GPIO_OUT);
    gpio_init(GREEN_PIN);
    gpio_set_dir(GREEN_PIN, GPIO_OUT);

    stdio_init_all();

    // Inicializa o temporizador para chamar a função de callback a cada 3 segundos (3000ms)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        // Envia mensagem serial a cada segundo
        printf("Sistema funcionando\n");
        sleep_ms(1000);
    }

    return 0;
}
