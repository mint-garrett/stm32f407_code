//task3
void keypad27seg (uint8_t input)
{
	switch(input)
	{
	case 0:
		sevenseg_fn(0);
		return;
	case 1:
		sevenseg_fn(1);
		return;
	case 2:
		sevenseg_fn(2);
		return;
	case 3:
		sevenseg_fn(3);
		return;
	case 4:
		sevenseg_fn(4);
		return;
	case 5:
		sevenseg_fn(5);
		return;
	case 6:
		sevenseg_fn(6);
		return;
	case 7:
		sevenseg_fn(7);
		return;
	case 8:
		sevenseg_fn(8);
		return;
	case 9:
		sevenseg_fn(9);
		return;
	default:
		sevenseg_fn(10);
		return;
	}
}
