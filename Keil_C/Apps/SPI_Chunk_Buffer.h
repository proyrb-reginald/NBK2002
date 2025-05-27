#ifndef SPI_CHUNK_BUFFER_H
#define SPI_CHUNK_BUFFER_H

#include <stdbool.h>
#include "SC_Init.h"
#include "FreeRTOS.h"
#include "semphr.h"

typedef struct {
    SemaphoreHandle_t transmit_s;
    SemaphoreHandle_t using_s;
} SPI_Chunk_Buffer;

extern SPI_Chunk_Buffer spi0;

void SPI_ChunkBuffer_Init(SPI_Chunk_Buffer *spi);

void SPI_Send_One(SPI_Chunk_Buffer *spi, uint8_t bytes);

void SPI_Send_Multi(SPI_Chunk_Buffer *spi, uint8_t *bytes, uint8_t len);

#endif // SPI_CHUNK_BUFFER_H
