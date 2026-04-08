//reads inputs from keypad buttons as numbers to use
#define R 4
#define C 3

uint8_t keypad_READ(void){
uint8_t keyLocations[ROWS][COLS] = {
{1, 2, 3},
{4, 5, 6},
{7, 8, 9},
{10, 0, 11}
};
GPIO_TypeDef* colPorts[] = {GPIOD, GPIOD, GPIOD};
GPIO_TypeDef* rowPorts[] = {GPIOB, GPIOB, GPIOB, GPIOB};
uint16_t colPins[] = {GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10};
uint16_t rowPins[] = {GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};
for (uint8_t col = 0; col < C; col++){
for (uint8_t cls = 0; cls < C; cls++){
HAL_GPIO_WritePin(colPorts[cls], colPins[cls], GPIO_PIN_SET);
}
HAL_GPIO_WritePin(colPorts[col], colPins[col], GPIO_PIN_RESET);
HAL_Delay(5);
for (uint8_t row = 0; row < R; row++){
if (HAL_GPIO_ReadPin(rowPorts[row], rowPins[row]) == GPIO_PIN_RESET){
return keyLocations[row][col];
}
}
HAL_Delay(20);
}

return 255;
}
