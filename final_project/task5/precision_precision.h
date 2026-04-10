// little buggy but it works
void precision_precision (void)
{
		sevenseg_fn(10);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12, GPIO_PIN_RESET);

		HAL_Delay(500);
		int max_number = keypad_reading();
		sevenseg_fn(max_number);
		HAL_Delay(1000);
		sevenseg_fn(10);

		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13, GPIO_PIN_SET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13, GPIO_PIN_RESET);

		HAL_Delay(500);
		int win_num = keypad_reading();
		sevenseg_fn(win_num);
		HAL_Delay(1000);
		sevenseg_fn(10);

		for (int number = 0; number<=max_number; number++)
		{
			sevenseg_fn(number);
			HAL_Delay(1000);
				GPIO_PinState btn = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

				if(btn == GPIO_PIN_SET)
				{

					if (number == win_num)
					{
						while (btn == GPIO_PIN_SET)
						{
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
							HAL_Delay(500);

							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
							HAL_Delay(500);

							btn = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
							if(btn == GPIO_PIN_RESET)
							{
								HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
								HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
								HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
								HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
								HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
								sevenseg_fn(10);
								break;
							}
						}//while
						break;
					}//little if

				}//big if
		}//first for
}
