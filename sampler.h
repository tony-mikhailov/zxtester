#ifndef SAMPLER_H
#define SAMPLER_H

#include <stdint.h>
#include <hardware/pio.h>
#include <hardware/clocks.h>
#include <hardware/dma.h>

#define SIGNAL_PIN 8

typedef struct {
    uint pin; // signal pin
    PIO pio;
    uint32_t *sample_buffer;
    const uint16_t buffer_size;
} sampler_t;


void dma_handler();

double setup_sampler(sampler_t *sampler);

void start_capture(sampler_t *sampler);
void wait_capture(sampler_t *sampler);
void stop_capture(sampler_t *sampler);

#endif // !SAMPLER_H
