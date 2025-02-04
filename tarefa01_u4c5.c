#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"


#define green 11
#define yellow 12
#define red 13
volatile int state = 1;
bool repeatig_timer_callback(struct repeating_timer *t)
{
    printf("mudando a cor do led\n");
    switch (state) {
    case 0:
        gpio_put(red, 1);
        gpio_put(yellow, 0);
        gpio_put(green, 0);
        state = 1;
        break;
    case 1:
        gpio_put(red, 0);
        gpio_put(yellow, 1);
        gpio_put(green, 0);
        state = 2;
        break;
    case 2:
        gpio_put(red, 0);
        gpio_put(yellow, 0);
        gpio_put(green, 1);
        state = 0;
        break;
    }
    return true;
}
int main()
{
    struct repeating_timer t;
    //chama a funcao que muda a cor do led a cada 3 segundos
    add_repeating_timer_ms(3000, repeatig_timer_callback, NULL, &t);
    //inicializacao do stdio
    stdio_init_all();
    //inicializacoes dos pinos
    gpio_init(green);
    gpio_init(yellow);
    gpio_init(red);
    //configuracao dos pinos
    gpio_set_dir(green, GPIO_OUT);
    gpio_set_dir(yellow, GPIO_OUT);
    gpio_set_dir(red, GPIO_OUT);
    //seta o led vermelho como inicial
    gpio_put(red, 1);
    while (true) {
        printf("1 segundo passou\n");
        sleep_ms(1000);
    }
}
