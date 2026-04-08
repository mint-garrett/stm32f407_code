//blinks inputs as prof wants them in accordance with keypad inputs

void blink (uint8_t input){
if (input == 0){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
HAL_Delay(300);
}
else if (input == 1){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
HAL_Delay(250);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
HAL_Delay(300);
}
else if (input == 2){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
HAL_Delay(300);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
HAL_Delay(300);
}
else if (input == 3){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
HAL_Delay(300);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
HAL_Delay(300);
}
else if (input == 4){
for (uint32_t i = 0; i < 2; i++){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
HAL_Delay(300);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
HAL_Delay(300);
}
}
else if (input == 5){
for (uint32_t i = 0; i < 2; i++){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
HAL_Delay(300);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
HAL_Delay(300);
}
}
else if (input == 6){
for (uint32_t i = 0; i < 2; i++){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
HAL_Delay(300);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
HAL_Delay(300);
}
}
else if (input == 7){
for (uint32_t i = 0; i < 4; i++){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
HAL_Delay(300);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
HAL_Delay(300);
}
}
else if (input == 8){
for (uint32_t i = 0; i < 4; i++){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
HAL_Delay(300);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
HAL_Delay(300);
}
}
else if (input == 9){
for (uint32_t i = 0; i < 4; i++){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
HAL_Delay(300);
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
HAL_Delay(300);
}
}
else {
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}
}
