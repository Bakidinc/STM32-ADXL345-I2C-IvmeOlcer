#include "main.h"
#include "adxl345.h"
#include <stdio.h>
#include <string.h>

/* Private variables */
I2C_HandleTypeDef hi2c1;
UART_HandleTypeDef huart2;

/* Private function prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART2_UART_Init(void);

char buffer[64];

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();

  adxl_init();  // ADXL345 baslat

  while (1)
  {
    int16_t x = adxl_readx();
    int16_t y = adxl_ready();
    int16_t z = adxl_readz();

    // UART'a veriyi gonder
    sprintf(buffer, "X: %d | Y: %d | Z: %d\r\n", x, y, z);
    HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);

    HAL_Delay(500);
  }
}
