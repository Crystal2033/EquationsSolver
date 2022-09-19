#include "DuoTrioQuatroSolution.h"


int main(int argc, char* argv[])
{
	int degree;
	long double* coeffs_arr;
	long double* dinam_arr;
	
	printf("\nHello, my name is Kulikov Paul. My programm can solve equations 1, 2, 3, 4 degrees.\n");
	printf("This programm can solve equations with 6, 8, 9, 12 degrees if it possible\n");
	printf("To start solving input value of degree (1-4, 6, 8, 9, 12) and coeffs of your equation.\n");
	printf("If you want to input float data in coeffs, please, enter a number separated by a dot <<.>>, not by a comma <<,>>.\n");
	printf("If you want to exit press <<0>> in degree inputting. For all questions, please contact with me: kulikov-pavlik@bk.ru\n");
	while (1)
	{
		

		if (argc == 1)
		{
			degree = input_degree();
			if (degree != 0)

			{
				dinam_arr = (long double*)malloc(sizeof(long double) * (degree + 1));
				coeffs_arr = input_coeffs(degree, dinam_arr);
			}
		}
		else
		{
			if (strlen(argv[1]) > 2)
			{
				printf("WrongInputError. You have to input integer number from 1 to 4, 6, 8, 9, 12. This number "
					"symbolize the degree value of your equation. It can`t consists letters or "
					"different characters other than positive integers. Please, try again your input.\n");
				return -1;
			}
			if (strlen(argv[1]) == 1)
			{

				if (isdigit(argv[1][0]))
				{
					degree = atoi(argv[1]);
					if (!(degree == 1 || degree == 2 || degree == 3 || degree == 4 || degree == 6 || degree == 8 || degree == 9))
					{
						printf("WrongInputError. You have to input integer number from 1 to 4. This number "
							"symbolize the degree value of your equation. It can`t consists letters or "
							"different characters other than positive integers. Please, try again your input.\n");
						return -1;
					}
				}
				else
					return -1;
			}
			if (strlen(argv[1]) == 2)
			{
				if (isdigit(argv[1][0]) && isdigit(argv[1][1]))
				{
					degree = atoi(argv[1]);
					if (degree != 12)
					{
						printf("WrongInputError. You have to input integer number from 1 to 4. This number "
							"symbolize the degree value of your equation. It can`t consists letters or "
							"different characters other than positive integers. Please, try again your input.\n");
						return -1;
					}

				}
			}

			if (argc - 2 != degree + 1)
			{
				printf("Value of coefficients has to be equal %d.\n", degree + 1);
				return -1;
			}

			int counter_check1 = 0, counter_check2 = 0, punct_check = 0;
			for (int i = 0; i < degree + 1; i++)
			{
				for (int j = 0; j < strlen(argv[i + 2]); j++)
				{
					if (isdigit(argv[i + 2][j]))
					{
						counter_check1++;
					}
					else if (argv[i + 2][j] == '.')
						punct_check++;
					else if (argv[i + 2][j] == '-' && j == 0)
					{
						punct_check++;
					}
				}
				if ((counter_check1 + punct_check) == strlen(argv[i + 2]) && punct_check <= 2)
				{
					counter_check2++;
				}
				punct_check = 0;
				counter_check1 = 0;
			}
			if (counter_check2 == degree + 1)
			{
				coeffs_arr = (long double*)malloc(sizeof(long double) * degree);
				for (int i = 0; i < degree + 1; i++)
				{
					coeffs_arr[i] = atof(argv[i + 2]);
				}
			}
			else
			{
				printf("ValueError. You have to input integer or float data.\n");
				return -1;
			}
		}

		switch (degree)
		{
		case 1:
		{
			if (argc == 1)
			{
				first_degree_equation(coeffs_arr);
				free(dinam_arr);
				getchar();
				
			}
			else
			{
				first_degree_equation(coeffs_arr);
				return 0;
			}
			break;
		}
		case 2:
		{
			int counter = 0;
			if (argc == 1)
			{
				second_degree_equation(coeffs_arr, counter);
				free(dinam_arr);
				getchar();
				
			}
			else
			{
				second_degree_equation(coeffs_arr, counter);
				return 0;
			}
			break;
		}
		case 3:
		{
			char loud = 'l';
			if (argc == 1)
			{
				third_degree_equation(coeffs_arr, loud, 0);
				free(dinam_arr);
				getchar();
			}
			else
			{
				third_degree_equation(coeffs_arr, loud, 0);
				return 0;
			}
			break;
		}
		case 4:
		{
			if (argc == 1)
			{
				fourth_degree_equation(coeffs_arr);
				free(dinam_arr);
				getchar();
			}
			else
			{
				fourth_degree_equation(coeffs_arr);
				return 0;
			}
			break;
		}
		case 6: 
		{
			if (argc == 1)
			{
				sixth_degree_equation(coeffs_arr);
				free(dinam_arr);
				getchar();
			}
			else
			{
				sixth_degree_equation(coeffs_arr);
				return 0;
			}
			break;
		}
		case 8:
		{
			if (argc == 1)
			{
				eighth_degree_equation(coeffs_arr);
				free(dinam_arr);
				getchar();
			}
			else
			{
				eighth_degree_equation(coeffs_arr);
				return 0;
			}
			break;
		}
		case 9:
		{
			if (argc == 1)
			{
				ninth_degree_equation(coeffs_arr);
				free(dinam_arr);
				getchar();
			}
			else
			{
				ninth_degree_equation(coeffs_arr);
				return 0;
			}
			break;
		}
		case 12:
		{
			if (argc == 1)
			{
				twelve_degree_equation(coeffs_arr);
				free(dinam_arr);
				getchar();
			}
			else
			{
				twelve_degree_equation(coeffs_arr);
				return 0;
			}
			break;
		}
		case 0:
			printf("\nThank you for using my programm. See you!\n ");
			return 0;
		}
	}
}