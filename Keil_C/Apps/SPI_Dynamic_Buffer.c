#include "SPI_Dynamic_Buffer.h"
#include "sc32f1xxx_dma.h"

SPI_Chunk_Buffer spi0;

void SPI_ChunkBuffer_Init(SPI_Chunk_Buffer *spi) {
    spi->using_s = xSemaphoreCreateMutex();
    if (spi->using_s == NULL) {
        while (1);
    }
    
    spi->transmit_s = xSemaphoreCreateBinary();
    if (spi->transmit_s == NULL) {
        while (1);
    }
    xSemaphoreGive(spi->transmit_s);
}

void SPI_Send_One(SPI_Chunk_Buffer *spi, uint8_t bytes) {
    if (xSemaphoreTake(spi->using_s, portMAX_DELAY) == pdTRUE) {
        if (xSemaphoreTake(spi->transmit_s, portMAX_DELAY) == pdTRUE) {
            SPI_SendData(SPI0, bytes);
        }
        xSemaphoreGive(spi->using_s);
    }
}

void SPI_Send_Multi(SPI_Chunk_Buffer *spi, uint8_t *bytes, uint8_t len) {
    if (xSemaphoreTake(spi->using_s, portMAX_DELAY) == pdTRUE) {
        if (xSemaphoreTake(spi->transmit_s, portMAX_DELAY) == pdTRUE) {
            DMA_SetSrcAddress(DMA1, (uint32_t)bytes);
            DMA_SetCurrDataCounter(DMA1, len);
            DMA_SoftwareTrigger(DMA1);
        }
        xSemaphoreGive(spi->using_s);
    }
}

void DMA1_IRQHandler(void) {
	DMA_ClearFlag(DMA1, DMA_FLAG_GIF|DMA_FLAG_TCIF|DMA_FLAG_HTIF|DMA_FLAG_TEIF);
    
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(spi0.transmit_s, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void SPI0_IRQHandler(void) {
	SPI_ClearFlag(SPI0, SPI_Flag_SPIF|SPI_Flag_RINEIF|SPI_Flag_TXEIF|SPI_Flag_RXFIF|SPI_Flag_RXHIF|SPI_Flag_TXHIF|SPI_Flag_WCOL);
    
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(spi0.transmit_s, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
