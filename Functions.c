#include "DuoTrioQuatroSolution.h"
int input_degree(void) // функция проверяет и выявляет введенную степень уравнения.
{
	char input_data[100]; // Массив для введенных данных
	int degree; 
	int counter = 0;
	while (1)
	{
		printf("\nInput value of equation`s degree you want to solve (from 1 to 4) if you want use classic equation.\n");
		printf("Input 6, 8, 9 or 12 if you want to solve equation with change of variable.\n");
		printf("The equation will be solved if it possible. Input 0 to exit.\n");
		fgets(input_data, 100, stdin);
		//printf("Was written %s\n", input_data);
		int length_input = strlen(input_data) - 1;

		for (int i = 0; i < length_input; i++)
		{
			if (isdigit((int)input_data[i]))
			{
				counter++;
			}
		}
		if ((length_input != counter) || (counter > 2 ))
		{
			printf("WrongInputError. You have to input integer number from 1 to 4, 6, 8, 9, 12 or 0 to exit. This number "
				"symbolizes the degree value of your equation. It can`t consists letters or "
				"different characters other than positive integers. Please, try again your input.\n");
			counter = 0;
			continue;
		}

		degree = atoi(input_data);

		if (degree < 0 || degree > 12)
		{
			printf("WrongInputError.You can`t input values which are less than 1 or more than 12.\n");
			printf("If you want to exit input 0.\n");
			counter = 0;
			continue;
		}
		
		if (degree <= 4 || degree == 6 || degree == 8 || degree == 9 || degree == 12)
		{
			return degree;
		}
		else
		{
			printf("WrongInputError. You have to input integer number from 1 to 4, 6, 8, 9, 12 or 0 to exit. This number "
				"symbolizes the degree value of your equation. It can`t consists letters or "
				"different characters other than positive integers. Please, try again your input.\n");
			counter = 0;
			continue;
		}

	}
	
}

long double* input_coeffs(int degree, long double* unknowns) 
{
	for (int i = 0; i < degree + 1; i++)
	{
		while (1)
		{
			long double unknown_str_data[100];
			int check;
			if (i != degree)
			{
				printf("Input coefficient before the \"X\" in %d degree. \n", degree - i);
			}
			else
			{
				printf("Input free coefficient. \n");
			}

			check = scanf("%Lf", &unknown_str_data[i]);
			if (!check)
			{
				printf("ValueError. You have to input integer or float data.\n");
				getchar();
				continue;
			}
			else
			{
				unknowns[i] = unknown_str_data[i];
				break;
			}
		}
	}
	return unknowns;
}

void first_degree_equation(long double* coeff_arr)
{
	long double coef_x_1, free_coeff;
	long double answer;
	coef_x_1 = coeff_arr[0];
	free_coeff = coeff_arr[1];
	if (coef_x_1 == 0 && free_coeff != 0)
	{
		printf("SolveError. %Lf can`t be equal %Lf. \n", coef_x_1, free_coeff);
	}
	else if (coef_x_1 == 0 && free_coeff == 0)
	{
		printf("SolveError. There is nothing to solve %Lf = %Lf, it`s true.\n", coef_x_1, free_coeff);
	}
	else
	{
		if (free_coeff == 0)
		{
			printf("\nAnswer: \n");
			printf("X = %Lf\n", free_coeff/coef_x_1);
			return;
		}
		answer = (free_coeff * -1) / coef_x_1;
		printf("\nAnswer: \n");
		printf("X = %Lf\n", answer);
	}
}

void second_degree_equation(long double* coeff_arr, int counter)
{
	NUMBER answer1, answer2;
	long double diskriminant, a, b, c;
	a = coeff_arr[0];
	b = coeff_arr[1];
	c = coeff_arr[2];
	
	if (a == 0)
	{
		long double first_degree[2];
		first_degree[0] = b;
		first_degree[1] = c;
		first_degree_equation(first_degree);
		return;
	}

	diskriminant = pow(b,2) - 4 * a * c;
	if (diskriminant >= 0)
	{
		answer1.real_part = ((-1 * b) + sqrt(diskriminant)) / (2 * a);
		answer2.real_part= ((-1 * b) - sqrt(diskriminant)) / (2 * a);
		if (counter == 0)
		{
			if (answer1.real_part == answer2.real_part)
			{
				printf("X = %Lf\n", answer1.real_part);
				return;
			}
			else
			{
				printf("\nAnswer: \n");
				printf("X[1] = %Lf\n", answer1.real_part);
				printf("X[2] = %Lf\n", answer2.real_part);
				return;
			}
		}
		else
		{

			if (answer1.real_part == answer2.real_part)
			{
				printf("X = %Lf\n", answer1.real_part);
			}
			else
			{
				printf("X[%d] = %Lf\n", counter++, answer1.real_part);
				printf("X[%d] = %Lf\n", counter, answer2.real_part);
				return;
			}
		}
	}
	else
	{
		diskriminant *= -1;
		answer1.imagine_part = sqrt(diskriminant) / (2 * a);
		answer2.imagine_part = sqrt(diskriminant) / (2 * a);
		answer1.real_part = (-1 * b) / (2 * a);
		answer2.real_part = (-1 * b) / (2 * a);
		if (counter == 0)
		{
			printf("\nAnswer: \n");
			if (answer1.real_part == 0)
			{
				printf("X[1] = %Lf*i\n", answer1.imagine_part);
				printf("X[2] = %Lf*i\n", answer2.imagine_part * -1);
				return;
			}
			else
			{
				printf("X[1] = %Lf + %Lf*i\n", answer1.real_part, answer1.imagine_part);
				printf("X[2] = %Lf - %Lf*i\n", answer2.real_part, answer2.imagine_part);
				return;
			}
		}
		else
		{
			if (answer1.real_part == 0)
			{
				printf("X[%d] = %Lf*i\n", counter++, answer1.imagine_part);
				printf("X[%d] = %Lf*i\n", counter,  answer2.imagine_part * -1);
				return;
			}
			else
			{
				printf("X[%d] = %Lf + %Lf*i\n", counter++, answer1.real_part, answer1.imagine_part);
				printf("X[%d] = %Lf - %Lf*i\n", counter, answer2.real_part, answer2.imagine_part);
				return;
			}
		}
	}
}

long double third_degree_equation(long double* coeff_arr, char ch, int counter)
{
	long double a, b, c, d;
	a = coeff_arr[0];
	b = coeff_arr[1];
	c = coeff_arr[2];
	d = coeff_arr[3];
	if (a != 1 && a != 0)
	{
		b /= a;
		c /= a;
		d /= a;
		a = 1;
	}

	if (a == 0)
	{
		long double second_degree[3];
		second_degree[0] = b;
		second_degree[1] = c;
		second_degree[2] = d;
		int counter = 0;
		second_degree_equation(second_degree, counter);
		return 0;
	}
	long double p, q, x1, x2, x3;
	p = (3 * a * c  - pow(b, 2))/ (3 * a);
	q = (2 * pow(b, 3) - 9 * a * b * c + 27 * pow(a, 2) * d) / 27 * pow(a, 3);

	long double cube_diskriminant;
	cube_diskriminant = pow(q / 2, 2) + pow(p / 3, 3);
	
	long double y1, y2, y3, phi;
	if (q < 0)
	{
		phi = atan(sqrt(cube_diskriminant * -1) / (-1 * q / 2)) * 180 / PI;
	}
	else if (q > 0)
	{
		phi = atan(sqrt(cube_diskriminant * -1) / (-1 * q / 2)) * 180 / PI + 180;
	}
	else if (q == 0)
	{
		phi = 90;
	}

	if (cube_diskriminant < 0)
	{
		y1 = 2 * sqrt((-1 * p) / 3) * cos((phi / 3) * PI / 180);
		y2 = 2 * sqrt(-1 * p / 3) * cos(((phi / 3) + (2 * 180 / 3)) * PI / 180);
		y3 = 2 * sqrt(-1 * p / 3) * cos(((phi / 3) + (4 * 180 / 3)) * PI / 180);

		x1 = y1 - b / (3 * a);
		x2 = y2 - b / (3 * a);
		x3 = y3 - b / (3 * a);
		
		if (ch == 'l' && counter == 0)
		{
			printf("\nAnswer: \n");
			printf("X[1] = %Lf\n", x1);
			printf("X[2] = %Lf\n", x2);
			printf("X[3] = %Lf\n", x3);
		}
		if (counter != 0)
		{
			if (counter == 1)
			{
				printf("\nAnswer: \n");
			}
			printf("X[%d] = %Lf\n", counter, x1);
			counter++;
			printf("X[%d] = %Lf\n", counter, x2);
			counter++;
			printf("X[%d] = %Lf\n", counter, x3);
			counter++;
		}
		return x1;
	}
	else if (cube_diskriminant > 0)
	{
		NUMBER y2, y3, x2, x3;
		y1 = cbrt((q / -2) + sqrt(cube_diskriminant)) + cbrt((q / -2) - sqrt(cube_diskriminant));
		y2.real_part = -0.5 * y1;
		y2.imagine_part = (sqrt(3) / 2) * (cbrt((-1 * q / 2) + sqrt(cube_diskriminant)) - cbrt((-1 * q / 2) - sqrt(cube_diskriminant)));
		y3.real_part = -0.5 * y1;
		y3.imagine_part = -1 * y2.imagine_part;


		x1 = y1 - b / (3 * a);
		x2.real_part = y2.real_part - b / (3 * a);
		x2.imagine_part = y2.imagine_part;
		x3.real_part = y3.real_part - b / (3 * a);
		x3.imagine_part = y3.imagine_part;
		char relevant_punct_x2, relevant_punct_x3;
		if (x2.imagine_part < 0)
		{
			relevant_punct_x2 = ' ';
			relevant_punct_x3 = '+';
		}
		else
		{
			relevant_punct_x2 = '+';
			relevant_punct_x3 = ' ';
		}
		if (ch == 'l' && counter == 0)
		{
			printf("\nAnswer: \n");
			printf("X[1] = %Lf\n", x1);
			printf("X[2] = %Lf %c%Lf*i\n", x2.real_part, relevant_punct_x2, x2.imagine_part);
			printf("X[3] = %Lf%c%Lf*i\n", x3.real_part, relevant_punct_x3, x3.imagine_part);
		}
		if (counter != 0)
		{
			if (counter == 1)
			{
				printf("\nAnswer: \n");
			}
			printf("X[%d] = %Lf\n", counter, x1);
			counter++;
			printf("X[%d] = %Lf %c%Lf*i\n", counter, x2.real_part, relevant_punct_x2, x2.imagine_part);
			counter++;
			printf("X[%d] = %Lf%c%Lf*i\n", counter, x3.real_part, relevant_punct_x3, x3.imagine_part);
			counter++;
		}
		return x1;
	}
	else if (cube_diskriminant == 0 && q != 0)
	{
		y1 = 2 * cbrt(-1 * q / 2);
		y2 = -1 * cbrt(-1 * q / 2);

		x1 = y1 - b / (3 * a);
		x2 = y2 - b / (3 * a);
		if (ch == 'l' && counter == 0) // Проверка на счетчик, чтобы не писало дважды ответ на случай 6, 9, 12 степеней.
		{
			printf("\nAnswer: \n");
			printf("X[1] = %Lf\n", x1);
			printf("X[2] = %Lf\n", x2);
		}
		if (counter != 0)
		{
			if (counter == 1)
			{
				printf("\nAnswer: \n");
			}
			printf("X[%d] = %Lf\n", counter, x1);
			counter++;
			printf("X[%d] = %Lf\n", counter, x2);
			counter++;
		}
		return x1;
	}
	else if (cube_diskriminant == 0 && q == 0 && p == 0)
	{
		x1 = -1 * b / (3 * a);
		if (ch == 'l' && counter == 0)
		{
			printf("\nAnswer: \n");
			printf("X = %Lf\n", x1);
		}
		if (counter != 0)
		{
			if (counter == 1)
			{
				printf("\nAnswer: \n");
			}
			printf("X = %Lf\n", x1);
		}
		return x1;
	}
	
}

void fourth_degree_equation(long double* coeff_arr)
{
	long double a, b, c, d, coeff_before_4_deg;
	coeff_before_4_deg = coeff_arr[0];
	a = coeff_arr[1];
	b = coeff_arr[2];
	c = coeff_arr[3];
	d = coeff_arr[4];

	if (coeff_before_4_deg != 1 && coeff_before_4_deg != 0)
	{
		a /= coeff_before_4_deg;
		b /= coeff_before_4_deg;
		c /= coeff_before_4_deg;
		d /= coeff_before_4_deg;
		coeff_before_4_deg = 1;
	}

	if (coeff_before_4_deg == 0)
	{
		long double third_degree[4];
		third_degree[0] = a;
		third_degree[1] = b;
		third_degree[2] = c;
		third_degree[3] = d;
		char loud = 'l';
		third_degree_equation(third_degree, loud, 0);
		return;
	}

	long double Ferrari_third_degree[4];
	Ferrari_third_degree[0] = 1;
	Ferrari_third_degree[1] = -1 * b;
	Ferrari_third_degree[2] = a * c - 4 * d;
	Ferrari_third_degree[3] = -1 * pow(a, 2) * d + 4 * b * d - pow(c, 2);

	long double y0;
	char silent = 's';
	y0 = third_degree_equation(Ferrari_third_degree, silent, 0);
	
	long double sec_degr_out_sqrt[3];
	long double sec_degr_in_sqrt[3];
	
	sec_degr_out_sqrt[0] = 1;
	sec_degr_out_sqrt[1] = a / 2;
	sec_degr_out_sqrt[2] = y0 / 2;

	sec_degr_in_sqrt[0] = pow(a, 2) / 4 - b + y0;
	sec_degr_in_sqrt[1] = (a / 2) * y0 - c;
	sec_degr_in_sqrt[2] = pow(y0, 2) / 4 - d;

	sec_degr_in_sqrt[2] = sqrt(sec_degr_in_sqrt[2]);

	if (sec_degr_in_sqrt[1] < 0)
	{
		sec_degr_in_sqrt[2] *= -1;
	}
	sec_degr_in_sqrt[1] = sqrt(sec_degr_in_sqrt[0]);

	long double first_sec_deg_equ[3];
	long double second_sec_deg_equ[3];

	first_sec_deg_equ[0] = sec_degr_out_sqrt[0];
	first_sec_deg_equ[1] = sec_degr_out_sqrt[1] + sec_degr_in_sqrt[1];
	first_sec_deg_equ[2] = sec_degr_out_sqrt[2] + sec_degr_in_sqrt[2];
	int counter = 1;
	printf("\nAnswer: \n");
	second_degree_equation(first_sec_deg_equ, counter);
	counter += 2;

	second_sec_deg_equ[0] = sec_degr_out_sqrt[0];
	second_sec_deg_equ[1] = sec_degr_out_sqrt[1] - sec_degr_in_sqrt[1];
	second_sec_deg_equ[2] = sec_degr_out_sqrt[2] - sec_degr_in_sqrt[2];
	second_degree_equation(second_sec_deg_equ, counter);
	return;
}

void sixth_degree_equation(long double* coeffs_arr)
{
	int change_degree = 0;
	int check_counter = 0;

	if (coeffs_arr[0] == 0 && coeffs_arr[1] == 0)
	{
		long double fourth_degree_arr[5];
		for (int i = 0; i < 5; i++)
		{
			fourth_degree_arr[i] = coeffs_arr[i + 2];
		}
		fourth_degree_equation(fourth_degree_arr);
		return;
	}

	for (int i = 0; i <= 6; i++)
	{
		if (i % 2 == 0)
		{
			if (coeffs_arr[i] != 0)
			{
				check_counter++;
			}
		}
		else
		{
			if (coeffs_arr[i] != 0)
			{
				break;
			}
		}
	}

	if (check_counter == 4)
	{
		change_degree = 2;
	}
	else
	{
		check_counter = 0;
	}


	if (!change_degree)
	{
		for (int i = 0; i <= 6; i++)
		{
			if (i % 3 == 0)
			{
				if (coeffs_arr[i] != 0)
				{
					check_counter++;
				}
			}
			else
			{
				if (coeffs_arr[i] != 0)
				{
					break;
				}
			}
		}

		if (check_counter == 3)
		{
			change_degree = 3;
		}
	}
	check_counter = 0;

	if (!change_degree)
	{
		printf("Its impossible to solve your equation. Because i can`t make change of variable x^2 or x^3.\n");
		return;
	}

	if (change_degree == 2)
	{
		long double* change_equ_coeff = (long double*)malloc(sizeof(long double) * 4);
		change_equ_coeff[0] = coeffs_arr[0];
		change_equ_coeff[1] = coeffs_arr[2];
		change_equ_coeff[2] = coeffs_arr[4];
		change_equ_coeff[3] = coeffs_arr[6];
		second_change_sixth_degree(change_equ_coeff, change_degree);
		free(change_equ_coeff);
		return;
	}
	else if (change_degree == 3)
	{
		long double* change_equ_coeff = (long double*)malloc(sizeof(long double) * 3);
		change_equ_coeff[0] = coeffs_arr[0];
		change_equ_coeff[1] = coeffs_arr[3];
		change_equ_coeff[2] = coeffs_arr[6];
		third_change_sixth_degree(change_equ_coeff, change_degree);
		free(change_equ_coeff);
		return;
	}
}

void second_change_sixth_degree(long double* change_equ_coeff, int change_degree)
{
	long double a, b, c, d;
	a = change_equ_coeff[0];
	b = change_equ_coeff[1];
	c = change_equ_coeff[2];
	d = change_equ_coeff[3];
	if (a != 1 && a != 0)
	{
		b /= a;
		c /= a;
		d /= a;
		a = 1;
	}

	
	long double p, q, t1, t2, t3;
	p = (3 * a * c - pow(b, 2)) / (3 * a);
	q = (2 * pow(b, 3) - 9 * a * b * c + 27 * pow(a, 2) * d) / 27 * pow(a, 3);

	long double cube_diskriminant;
	cube_diskriminant = pow(q / 2, 2) + pow(p / 3, 3);

	long double y1, y2, y3, phi;
	if (q < 0)
	{
		phi = atan(sqrt(cube_diskriminant * -1) / (-1 * q / 2)) * 180 / PI;
	}
	else if (q > 0)
	{
		phi = atan(sqrt(cube_diskriminant * -1) / (-1 * q / 2)) * 180 / PI + 180;
	}
	else if (q == 0)
	{
		phi = 90;
	}

	if (cube_diskriminant < 0)
	{
		y1 = 2 * sqrt((-1 * p) / 3) * cos((phi / 3) * PI / 180);
		y2 = 2 * sqrt(-1 * p / 3) * cos(((phi / 3) + (2 * 180 / 3)) * PI / 180);
		y3 = 2 * sqrt(-1 * p / 3) * cos(((phi / 3) + (4 * 180 / 3)) * PI / 180);

		t1 = y1 - b / (3 * a);
		t2 = y2 - b / (3 * a);
		t3 = y3 - b / (3 * a);
		int counter = 1;
		long double* second_degree_with_t = (long double*)malloc(sizeof(long double) * 3);
		second_degree_with_t[0] = 1;
		second_degree_with_t[1] = 0;
		second_degree_with_t[2] = -1* t1;
		second_degree_equation(second_degree_with_t, counter);
		counter += 2;

		second_degree_with_t[0] = 1;
		second_degree_with_t[1] = 0;
		second_degree_with_t[2] = -1 *t2;
		second_degree_equation(second_degree_with_t, counter);
		counter += 2;

		second_degree_with_t[0] = 1;
		second_degree_with_t[1] = 0;
		second_degree_with_t[2] = -1 *t3;
		second_degree_equation(second_degree_with_t, counter);
		counter += 2;
		counter = 0;
		free(second_degree_with_t);
		return;
	}
	else if (cube_diskriminant > 0)
	{
		NUMBER y2, y3, t2, t3;
		y1 = cbrt((q / -2) + sqrt(cube_diskriminant)) + cbrt((q / -2) - sqrt(cube_diskriminant));
		y2.real_part = -0.5 * y1;
		y2.imagine_part = (sqrt(3) / 2) * (cbrt((-1 * q / 2) + sqrt(cube_diskriminant)) - cbrt((-1 * q / 2) - sqrt(cube_diskriminant)));
		y3.real_part = -0.5 * y1;
		y3.imagine_part = -1 * y2.imagine_part;


		t1 = y1 - b / (3 * a);
		t2.real_part = y2.real_part - b / (3 * a);
		t2.imagine_part = y2.imagine_part;
		t3.real_part = y3.real_part - b / (3 * a);
		t3.imagine_part = y3.imagine_part;

		
		int counter = 1;
		long double* second_degree_with_t = (long double*)malloc(sizeof(long double) * 3);
		second_degree_with_t[0] = 1;
		second_degree_with_t[1] = 0;
		second_degree_with_t[2] = -1 * t1;
		second_degree_equation(second_degree_with_t, counter);
		counter += 2;
		free(second_degree_with_t);
		compl_root_finder(t2, change_degree, counter);
		counter += 2;
		compl_root_finder(t3, change_degree, counter);
	
	}
	else if (cube_diskriminant == 0 && q != 0)
	{
		y1 = 2 * cbrt(-1 * q / 2);
		y2 = -1 * cbrt(-1 * q / 2);

		t1 = y1 - b / (3 * a);
		t2 = y2 - b / (3 * a);
		
		int counter = 1;
		long double* second_degree_with_t = (long double*)malloc(sizeof(long double) * 3);
		second_degree_with_t[0] = 1;
		second_degree_with_t[1] = 0;
		second_degree_with_t[2] = -1 * t1;
		second_degree_equation(second_degree_with_t, counter);
		counter += 2;

		second_degree_with_t[0] = 1;
		second_degree_with_t[1] = 0;
		second_degree_with_t[2] = -1 * t2;
		second_degree_equation(second_degree_with_t, counter);
		counter += 2;
		counter = 0;
		free(second_degree_with_t);
		return;

	}
	else if (cube_diskriminant == 0 && q == 0 && p == 0)
	{
		t1 = -1 * b / (3 * a);

		int counter = 1;
		long double* second_degree_with_t = (long double*)malloc(sizeof(long double) * 3);
		second_degree_with_t[0] = 1;
		second_degree_with_t[1] = 0;
		second_degree_with_t[2] = -1 * t1;
		second_degree_equation(second_degree_with_t, counter);
		counter = 1;
		free(second_degree_with_t);
		return;
		
	}
}


void compl_root_finder(NUMBER t, int change_degree, int counter) //Функция ищет значение x по t, если t = x^2 или t = x^3, если t имеет комлексные числа
{
	NUMBER w1, w2, w3;
	long double r;
	long double fi;
	char relevant_punct_w1, relevant_punct_w2, relevant_punct_w3;
	r = sqrt(pow(t.real_part, 2) + pow(t.imagine_part, 2));
	fi = atan(t.imagine_part / t.real_part) * 180 / PI;

	if (change_degree == 2)
	{
		w1.real_part = sqrt(r) * cos((fi / change_degree) * PI / 180);
		w1.imagine_part = sqrt(r) * sin((fi / change_degree) * PI / 180);

		w2.real_part = sqrt(r) * cos(((fi + 2 * PI * 1) / change_degree) * PI / 180);
		w2.imagine_part = sqrt(r) * sin(((fi + 2 * PI * 1) / change_degree) * PI / 180);

		if (w1.imagine_part < 0)
		{
			relevant_punct_w1 = ' ';
		}
		else
		{
			relevant_punct_w1 = '+';
		}

		if (w2.imagine_part < 0)
		{
			relevant_punct_w2 = ' ';
		}
		else
		{
			relevant_punct_w2 = '+';
		}

		printf("X[%d] = %Lf %c%Lf*i\n", counter, w1.real_part, relevant_punct_w1, w1.imagine_part);
		counter++;
		printf("X[%d] = %Lf %c%Lf*i\n", counter, w2.real_part, relevant_punct_w2, w2.imagine_part);
		return;
	}

	else if (change_degree == 3)
	{

		w1.real_part = cbrt(r) * cos((fi / change_degree) * PI / 180);
		w1.imagine_part = cbrt(r) * sin((fi / change_degree) * PI / 180);

		w2.real_part = cbrt(r) * cos(((fi + 2 * PI * 1) / change_degree) * PI / 180);
		w2.imagine_part = cbrt(r) * sin(((fi + 2 * PI * 1) / change_degree) * PI / 180);

		w3.real_part = cbrt(r) * cos(((fi + 2 * PI * 2) / change_degree) * PI / 180);
		w3.imagine_part = cbrt(r) * sin(((fi + 2 * PI * 2) / change_degree) * PI / 180);


		if (w1.imagine_part < 0)
		{
			relevant_punct_w1 = ' ';
		}
		else
		{
			relevant_punct_w1 = '+';
		}

		if (w2.imagine_part < 0)
		{
			relevant_punct_w2 = ' ';
		}
		else
		{
			relevant_punct_w2 = '+';
		}

		if (w3.imagine_part < 0)
		{
			relevant_punct_w3 = ' ';
		}
		else
		{
			relevant_punct_w3 = '+';
		}

		printf("X[%d] = %Lf %c%Lf*i\n", counter, w1.real_part, relevant_punct_w1, w1.imagine_part);
		counter++;
		printf("X[%d] = %Lf %c%Lf*i\n", counter, w2.real_part, relevant_punct_w2, w2.imagine_part);
		counter++;
		printf("X[%d] = %Lf %c%Lf*i\n", counter, w3.real_part, relevant_punct_w3, w3.imagine_part);
		return;
	}
	
}

void third_change_sixth_degree(long double* change_equ_coeff, int change_degree) // Если выяснилось что замена в уравнении 6 степени x^3
{
	NUMBER t1, t2;
	long double diskriminant, a, b, c;
	int counter = 1;
	a = change_equ_coeff[0];
	b = change_equ_coeff[1];
	c = change_equ_coeff[2];

	diskriminant = pow(b, 2) - 4 * a * c;
	if (diskriminant >= 0)
	{
		t1.real_part = ((-1 * b) + sqrt(diskriminant)) / (2 * a);
		t2.real_part = ((-1 * b) - sqrt(diskriminant)) / (2 * a);
		long double* third_degree_with_t = (long double*)malloc(sizeof(long double) * 4);
		third_degree_with_t[0] = 1;
		third_degree_with_t[1] = 0;
		third_degree_with_t[2] = 0;
		third_degree_with_t[3] = -1 * t1.real_part;
		char loud = 'l';
		third_degree_equation(third_degree_with_t, loud, counter);
		counter += 3;

		third_degree_with_t[0] = 1;
		third_degree_with_t[1] = 0;
		third_degree_with_t[2] = 0;
		third_degree_with_t[3] = -1 * t2.real_part;
		third_degree_equation(third_degree_with_t, loud, counter);
		counter = 0;
		free(third_degree_with_t);
		return;
	}
	else
	{
		diskriminant *= -1;
		t1.imagine_part = sqrt(diskriminant) / (2 * a);
		t2.imagine_part = -1 *sqrt(diskriminant) / (2 * a);
		t1.real_part = (-1 * b) / (2 * a);
		t2.real_part = (-1 * b) / (2 * a);
		compl_root_finder(t1, change_degree, counter);
		counter += 3;
		compl_root_finder(t2, change_degree, counter);
		return;
	}
}

void eighth_degree_equation(long double* coeffs_arr)
{
	int change_degree = 0;
	int check_counter = 0;

	if (coeffs_arr[0] == 0 && coeffs_arr[1] == 0)
	{
		long double sixth_degree_arr[7];
		for (int i = 0; i < 7; i++)
		{
			sixth_degree_arr[i] = coeffs_arr[i + 2];
		}
		sixth_degree_equation(sixth_degree_arr);
		return;
	}

	for (int i = 0; i <= 8; i++)
	{
		if (i % 2 == 0)
		{
			if (coeffs_arr[i] != 0)
			{
				check_counter++;
			}
		}
		else
		{
			if (coeffs_arr[i] != 0)
			{
				break;
			}
		}
	}

	if (check_counter == 5)
	{
		change_degree = 2;
	}


	if (!change_degree)
	{
		printf("Its impossible to solve your equation. Because i can`t make change of variable x^2 or x^3.\n");
		return;
	}
	if (change_degree == 2)
	{
		long double* change_equ_coeff = (long double*)malloc(sizeof(long double) * 5);
		for (int i = 0; i < 5; i++)
		{
			change_equ_coeff[i] = coeffs_arr[2 * i];
		}
		change_eighth_and_twelve_degree(change_equ_coeff, change_degree);
		free(change_equ_coeff);
		return;
	}
	
}

void second_degree_for_eighth_and_tw(long double* change_equ_coeff, int counter, NUMBER* arr_t)
{
	NUMBER answer1, answer2;
	long double diskriminant, a, b, c;
	a = change_equ_coeff[0];
	b = change_equ_coeff[1];
	c = change_equ_coeff[2];

	answer1.real_part = 0;
	answer1.imagine_part = 0;
	answer2.real_part = 0;
	answer2.imagine_part = 0;

	diskriminant = pow(b, 2) - 4 * a * c;
	if (diskriminant >= 0)
	{
		answer1.real_part = ((-1 * b) + sqrt(diskriminant)) / (2 * a);
		answer2.real_part = ((-1 * b) - sqrt(diskriminant)) / (2 * a);
	}
	else
	{
		diskriminant *= -1;
		answer1.imagine_part = sqrt(diskriminant) / (2 * a);
		answer2.imagine_part = -1 * sqrt(diskriminant) / (2 * a);
		answer1.real_part = (-1 * b) / (2 * a);
		answer2.real_part = (-1 * b) / (2 * a);

	}
	arr_t[0] = answer1;
	arr_t[1] = answer2;
	return;
}

void change_eighth_and_twelve_degree(long double* change_equ_coeff, int ans_value)
{
	NUMBER* arr_t;
	arr_t = (NUMBER*)malloc(sizeof(NUMBER) * 3);
	long double a, b, c, d, coeff_before_4_deg;
	coeff_before_4_deg = change_equ_coeff[0];
	a = change_equ_coeff[1];
	b = change_equ_coeff[2];
	c = change_equ_coeff[3];
	d = change_equ_coeff[4];

	if (coeff_before_4_deg != 1 && coeff_before_4_deg != 0)
	{
		a /= coeff_before_4_deg;
		b /= coeff_before_4_deg;
		c /= coeff_before_4_deg;
		d /= coeff_before_4_deg;
		coeff_before_4_deg = 1;
	}


	long double Ferrari_third_degree[4];
	Ferrari_third_degree[0] = 1;
	Ferrari_third_degree[1] = -1 * b;
	Ferrari_third_degree[2] = a * c - 4 * d;
	Ferrari_third_degree[3] = -1 * pow(a, 2) * d + 4 * b * d - pow(c, 2);

	long double y0;
	char silent = 's';
	y0 = third_degree_equation(Ferrari_third_degree, silent, 0);

	long double sec_degr_out_sqrt[3];
	long double sec_degr_in_sqrt[3];

	sec_degr_out_sqrt[0] = 1;
	sec_degr_out_sqrt[1] = a / 2;
	sec_degr_out_sqrt[2] = y0 / 2;

	sec_degr_in_sqrt[0] = pow(a, 2) / 4 - b + y0;
	sec_degr_in_sqrt[1] = (a / 2) * y0 - c;
	sec_degr_in_sqrt[2] = pow(y0, 2) / 4 - d;

	sec_degr_in_sqrt[2] = sqrt(sec_degr_in_sqrt[2]);

	if (sec_degr_in_sqrt[1] < 0)
	{
		sec_degr_in_sqrt[2] *= -1;
	}
	sec_degr_in_sqrt[1] = sqrt(sec_degr_in_sqrt[0]);

	long double first_sec_deg_equ[3];
	long double second_sec_deg_equ[3];

	first_sec_deg_equ[0] = sec_degr_out_sqrt[0];
	first_sec_deg_equ[1] = sec_degr_out_sqrt[1] + sec_degr_in_sqrt[1];
	first_sec_deg_equ[2] = sec_degr_out_sqrt[2] + sec_degr_in_sqrt[2];
	int counter = 1;

	long double* coeff_arr = (long double*)malloc(sizeof(long double) * 4);
	printf("\nAnswer: \n");
	second_degree_for_eighth_and_tw(first_sec_deg_equ, counter, arr_t);
	NUMBER* pointer = arr_t;
	if (pointer->imagine_part != 0)
	{
		compl_root_finder(arr_t[0], ans_value, counter);
		counter += ans_value;
		compl_root_finder(arr_t[1], ans_value, counter);
	}
	else
	{
		if (ans_value == 2)
		{
			coeff_arr[0] = 1;
			coeff_arr[1] = 0;
			coeff_arr[2] = -1 * pointer->real_part;
			second_degree_equation(coeff_arr, counter);
			counter += ans_value;
			pointer++;
			coeff_arr[0] = 1;
			coeff_arr[1] = 0;
			coeff_arr[2] = -1 * pointer->real_part;
			second_degree_equation(coeff_arr, counter);
		}
		else if (ans_value == 3)
		{
			char loud = 'l';
			coeff_arr[0] = 1;
			coeff_arr[1] = 0;
			coeff_arr[2] = 0;
			coeff_arr[3] = -1 * pointer->real_part;
			third_degree_equation(coeff_arr, loud, counter);
			counter += ans_value;
			pointer++;
			coeff_arr[0] = 1;
			coeff_arr[1] = 0;
			coeff_arr[2] = 0;
			coeff_arr[3] = -1 * pointer->real_part;
			third_degree_equation(coeff_arr, loud, counter);
		}
	}

	counter += ans_value;

	second_sec_deg_equ[0] = sec_degr_out_sqrt[0];
	second_sec_deg_equ[1] = sec_degr_out_sqrt[1] - sec_degr_in_sqrt[1];
	second_sec_deg_equ[2] = sec_degr_out_sqrt[2] - sec_degr_in_sqrt[2];
	second_degree_for_eighth_and_tw(second_sec_deg_equ, counter, arr_t);
	pointer = arr_t;

	if (pointer->imagine_part != 0)
	{
		compl_root_finder(arr_t[0], ans_value, counter);
		counter += ans_value;
		compl_root_finder(arr_t[1], ans_value, counter);
	}
	else
	{
		if (ans_value == 2)
		{
			coeff_arr[0] = 1;
			coeff_arr[1] = 0;
			coeff_arr[2] = -1 * pointer->real_part;
			second_degree_equation(coeff_arr, counter);
			counter += ans_value;
			pointer++;
			coeff_arr[0] = 1;
			coeff_arr[1] = 0;
			coeff_arr[2] = -1 * pointer->real_part;
			second_degree_equation(coeff_arr, counter);
		}
		else if (ans_value == 3)
		{
			char loud = 'l';
			coeff_arr[0] = 1;
			coeff_arr[1] = 0;
			coeff_arr[2] = 0;
			coeff_arr[3] = -1 * pointer->real_part;
			third_degree_equation(coeff_arr, loud, counter);
			counter += ans_value;
			pointer++;
			coeff_arr[0] = 1;
			coeff_arr[1] = 0;
			coeff_arr[2] = 0;
			coeff_arr[3] = -1 * pointer->real_part;
			third_degree_equation(coeff_arr, loud, counter);
		}
	}
	free(coeff_arr);
	free(arr_t);
	return;
}

void ninth_degree_equation(long double* coeffs_arr)
{
	int change_degree = 0;
	int check_counter = 0;

	if (coeffs_arr[0] == 0)
	{
		long double eighth_degree_arr[9];
		for (int i = 0; i < 9; i++)
		{
			eighth_degree_arr[i] = coeffs_arr[i + 1];
		}
		eighth_degree_equation(eighth_degree_arr);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (i % 3 == 0)
		{
			if (coeffs_arr[i] != 0)
			{
				check_counter++;
			}
		}
		else
		{
			if (coeffs_arr[i] != 0)
			{
				break;
			}
		}
	}

	if (check_counter == 4)
	{
		change_degree = 3;
	}

	if (!change_degree)
	{
		printf("Its impossible to solve your equation. Because i can`t make change of variable x^2 or x^3.\n");
		return 0;
	}


	long double* change_equ_coeff = (long double*)malloc(sizeof(long double) * 4);
	for (int i = 0; i < 4; i++)
	{
		change_equ_coeff[i] = coeffs_arr[3 * i];
	}
	third_change_ninth_degree(change_equ_coeff);
	free(change_equ_coeff);
	return;
}

void third_change_ninth_degree(long double* change_equ_coeff)
{
	long double a, b, c, d;
	a = change_equ_coeff[0];
	b = change_equ_coeff[1];
	c = change_equ_coeff[2];
	d = change_equ_coeff[3];
	if (a != 1 && a != 0)
	{
		b /= a;
		c /= a;
		d /= a;
		a = 1;
	}


	long double p, q, t1, t2, t3;
	p = (3 * a * c - pow(b, 2)) / (3 * a);
	q = (2 * pow(b, 3) - 9 * a * b * c + 27 * pow(a, 2) * d) / 27 * pow(a, 3);

	long double cube_diskriminant;
	cube_diskriminant = pow(q / 2, 2) + pow(p / 3, 3);

	long double y1, y2, y3, phi;
	if (q < 0)
	{
		phi = atan(sqrt(cube_diskriminant * -1) / (-1 * q / 2)) * 180 / PI;
	}
	else if (q > 0)
	{
		phi = atan(sqrt(cube_diskriminant * -1) / (-1 * q / 2)) * 180 / PI + 180;
	}
	else if (q == 0)
	{
		phi = 90;
	}

	if (cube_diskriminant < 0)
	{
		y1 = 2 * sqrt((-1 * p) / 3) * cos((phi / 3) * PI / 180);
		y2 = 2 * sqrt(-1 * p / 3) * cos(((phi / 3) + (2 * 180 / 3)) * PI / 180);
		y3 = 2 * sqrt(-1 * p / 3) * cos(((phi / 3) + (4 * 180 / 3)) * PI / 180);

		t1 = y1 - b / (3 * a);
		t2 = y2 - b / (3 * a);
		t3 = y3 - b / (3 * a);

		int counter = 1;
		char loud = 'l';
		long double* third_degree_with_t = (long double*)malloc(sizeof(long double) * 4);
		third_degree_with_t[0] = 1;
		third_degree_with_t[1] = 0;
		third_degree_with_t[2] = 0;
		third_degree_with_t[3] = -1 * t1;
		third_degree_equation(third_degree_with_t, loud, counter);
		counter += 3;

		third_degree_with_t[0] = 1;
		third_degree_with_t[1] = 0;
		third_degree_with_t[2] = 0;
		third_degree_with_t[3] = -1 * t2;
		third_degree_equation(third_degree_with_t, loud, counter);
		counter += 3;

		third_degree_with_t[0] = 1;
		third_degree_with_t[1] = 0;
		third_degree_with_t[2] = 0;
		third_degree_with_t[3] = -1 * t3;
		third_degree_equation(third_degree_with_t, loud, counter);
		counter += 3;
		counter = 0;
		free(third_degree_with_t);
		return;
	}


	else if (cube_diskriminant > 0)
	{
		NUMBER y2, y3, t2, t3;
		y1 = cbrt((q / -2) + sqrt(cube_diskriminant)) + cbrt((q / -2) - sqrt(cube_diskriminant));
		y2.real_part = -0.5 * y1;
		y2.imagine_part = (sqrt(3) / 2) * (cbrt((-1 * q / 2) + sqrt(cube_diskriminant)) - cbrt((-1 * q / 2) - sqrt(cube_diskriminant)));
		y3.real_part = -0.5 * y1;
		y3.imagine_part = -1 * y2.imagine_part;


		t1 = y1 - b / (3 * a);
		t2.real_part = y2.real_part - b / (3 * a);
		t2.imagine_part = y2.imagine_part;
		t3.real_part = y3.real_part - b / (3 * a);
		t3.imagine_part = y3.imagine_part;

		int counter = 1;
		char loud = 'l';
		long double* third_degree_with_t = (long double*)malloc(sizeof(long double) * 4);
		third_degree_with_t[0] = 1;
		third_degree_with_t[1] = 0;
		third_degree_with_t[2] = 0;
		third_degree_with_t[3] = -1 * t1;
		third_degree_equation(third_degree_with_t, loud, counter);
		counter += 3;

		NUMBER t = t2;
		compl_root_finder(t, 3, counter);
		counter += 3;

		t = t3;
		compl_root_finder(t, 3, counter);
		free(third_degree_with_t);
		return;
	}
	else if (cube_diskriminant == 0 && q != 0)
	{
		y1 = 2 * cbrt(-1 * q / 2);
		y2 = -1 * cbrt(-1 * q / 2);

		t1 = y1 - b / (3 * a);
		t2 = y2 - b / (3 * a);

		int counter = 1;
		char loud = 'l';
		long double* third_degree_with_t = (long double*)malloc(sizeof(long double) * 4);
		third_degree_with_t[0] = 1;
		third_degree_with_t[1] = 0;
		third_degree_with_t[2] = 0;
		third_degree_with_t[3] = -1 * t1;
		third_degree_equation(third_degree_with_t, loud, counter);
		counter += 3;

		third_degree_with_t[0] = 1;
		third_degree_with_t[1] = 0;
		third_degree_with_t[2] = 0;
		third_degree_with_t[3] = -1 * t2;
		third_degree_equation(third_degree_with_t, loud, counter);
		counter += 3;
		free(third_degree_with_t);
		return;

	}
	else if (cube_diskriminant == 0 && q == 0 && p == 0)
	{
		t1 = -1 * b / (3 * a);

		int counter = 1;
		char loud = 'l';
		long double* third_degree_with_t = (long double*)malloc(sizeof(long double) * 4);
		third_degree_with_t[0] = 1;
		third_degree_with_t[1] = 0;
		third_degree_with_t[2] = 0;
		third_degree_with_t[3] = -1 * t1;
		third_degree_equation(third_degree_with_t, loud, counter);
		counter += 3;
		free(third_degree_with_t);
		return;
	}
}

long double twelve_degree_equation(long double* coeffs_arr)
{
	int change_degree = 0;
	int check_counter = 0;

	if (coeffs_arr[0] == 0 && coeffs_arr[1] == 0 && coeffs_arr[2] == 0)
	{
		long double nineth_degree_arr[10];
		for (int i = 0; i < 10; i++)
		{
			nineth_degree_arr[i] = coeffs_arr[i + 3];
		}
		ninth_degree_equation(nineth_degree_arr);
		return;
	}

	for (int i = 0; i <= 12; i++)
	{
		if (i % 3 == 0)
		{
			if (coeffs_arr[i] != 0)
			{
				check_counter++;
			}
		}
		else
		{
			if (coeffs_arr[i] != 0)
			{
				break;
			}
		}
	}

	if (check_counter == 5)
	{
		change_degree = 3;
	}

	if (!change_degree)
	{
		printf("Its impossible to solve your equation. Because i can`t make change of variable x^2 or x^3.\n");
		return 0;
	}

	long double* change_equ_coeff = (long double*)malloc(sizeof(long double) * 5);
	for (int i = 0; i < 5; i++)
	{
		change_equ_coeff[i] = coeffs_arr[3 * i];
	}
	change_eighth_and_twelve_degree(change_equ_coeff, 3);
	free(change_equ_coeff);
	return;
}
