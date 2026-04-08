//reads inputs from keypad buttons as numbers to use

uint8_t keypad_reading(void)
{
	uint8_t key_matrix[4][3] =
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
		for (uint8_t cls = 0; cls < 3; cls++)
		{
			HAL_GPIO_WritePin(colPorts[cls], colPins[cls], GPIO_PIN_SET);
		}
		HAL_GPIO_WritePin(colPorts[col], colPins[col], GPIO_PIN_RESET);
		HAL_Delay(5);
		for (uint8_t row = 0; row < 4; row++)
		{
			if (HAL_GPIO_ReadPin(rowPorts[row], rowPins[row]) == GPIO_PIN_RESET)
			{
				return keyLocations[row][col];
			}
		}
		HAL_Delay(20);
	}

	return 255;
}
