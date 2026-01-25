#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include <stdbool.h>
#include "pico/stdlib.h"

// Таймауты в миллисекундах
#define BTN_DEB   50   // антидребезг
#define BTN_HOLD  700  // удержание

// Структура кнопки
typedef struct {
    uint8_t pin;
    bool state;         // текущее стабильное состояние (true = нажата)
    bool hold;          // флаг: было ли удержание
    bool click_flag;    // флаг: произошёл клик
    bool hold_flag;     // флаг: произошло удержание
    uint64_t timer;     // время последнего изменения (в микросекундах)
} Button;

// Инициализация кнопки
void button_init(Button* btn, uint8_t pin);

// Вызывать часто (в цикле)
void button_tick(Button* btn);

// Проверка событий (флаги сбрасываются в button_tick)
bool button_click(Button* btn);
bool button_hold(Button* btn);

#endif