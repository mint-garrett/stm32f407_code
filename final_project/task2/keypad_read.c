//reads inputs from keypad buttons as numbers to use

#define R 4
#define C 3

uint8_t keypad_reading(void)
{
	uint8_t key_matrix[R][C] =
	{
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9},
			{10, 0, 11}
	};
	GPIO_TypeDef* column_ports[] = {GPIOE, GPIOD, GPIOD};

	GPIO_TypeDef* row_ports[] = {GPIOB, GPIOB, GPIOB, GPIOB};
	uint16_t column_pins[] = {GPIO_PIN_0, GPIO_PIN_9, GPIO_PIN_10};
	uint16_t row_pins[] = {GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15};
	for (uint8_t col = 0; col < C; col++)
	{
		for (uint8_t cls = 0; cls < C; cls++)
		{
			HAL_GPIO_WritePin(column_ports[cls], column_pins[cls], GPIO_PIN_SET);
		}
		HAL_GPIO_WritePin(column_ports[col], column_pins[col], GPIO_PIN_RESET);
		HAL_Delay(5);
		for (uint8_t row = 0; row < R; row++)
		{
			if (HAL_GPIO_ReadPin(row_ports[row], row_pins[row]) == GPIO_PIN_RESET)
			{
				return key_matrix[row][col];
			}
		}
		HAL_Delay(20);
	}

	return 255;
}
