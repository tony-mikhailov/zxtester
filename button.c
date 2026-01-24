#include "button.h"

void button_init(Button* btn, uint8_t pin) {
    btn->pin = pin;
    btn->state = false;
    btn->hold = false;
    btn->click_flag = false;
    btn->hold_flag = false;
    btn->timer = 0;

    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);  // кнопка подключена к GND
}

void button_tick(Button* btn) {
    bool level = gpio_get(btn->pin);
    bool state = !level;  // активный уровень — LOW

    btn->click_flag = false;
    btn->hold_flag = false;

    uint64_t now = time_us_64();

    // Антидребезг: проверка изменения состояния
    if (btn->state != state && (now - btn->timer) >= BTN_DEB * 1000ULL) {
        btn->state = state;
        btn->timer = now;

        if (state) {
            btn->click_flag = true;  // клик при нажатии
        }
        btn->hold = false;  // сброс удержания при новом нажатии
    }

    // Проверка удержания
    if (btn->state && !btn->hold && (now - btn->timer) >= BTN_HOLD * 1000ULL) {
        btn->hold = true;
        btn->hold_flag = true;
    }
}

bool button_click(Button* btn) {
    return btn->click_flag;
}

bool button_hold(Button* btn) {
    return btn->hold_flag;
}