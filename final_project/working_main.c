  /*/////////////
	  task1
	  for (int i = 0; i<9; i++)
	  {
		  sevenseg_fn(i);
	  }
	  */

	  /*/////////
	 	 task2 blink
	  uint8_t input = keypad_reading();
	  blink(input);

	  *///////////////
	  //task3 basic combo
	  /*
	  uint8_t input = keypad_reading();
	  keypad27seg(input);
	  */


	  //task4 precision5
	  precision5();


	//interrupt section line 331
	void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == GPIO_PIN_0)
	{
		GPIO_PinState btn = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
		while (btn == GPIO_PIN_SET)
		{
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
			for(int i = 0; i > DELAY; i++);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
			for(int i = 0; i > DELAY; i++);
// update condition
			btn = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
		}
	}
}
