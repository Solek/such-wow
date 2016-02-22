#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	float height;
	float length;
	float width;
	char name[20];



	FILE * input;
	input = fopen("input.txt", "rt");

	// Что-то нашёл и утащил, что-то правил, чистый си сам не смог реализовать.
	// Посимвольное считывание в char[] было самым многообещающим, но нет.
	// number_lines используется для подсчёта линий в файле.

	// Основывается это на том, что на каждый объект вводится стабильное число строк + одна пустая.
	// В случае отсутствия данных шаблон для обозначения отсутствующих данных должен быть на месте.

    char *line_check = new char [30];
    int number_lines = 0;
    ifstream base("input.txt");
    while (!base.eof())
    	{
        base.getline(line_check, 30, '\n');
        number_lines++;
    	}
    base.close();
    delete line_check;

    printf("Number of lines in input file is %i.\n", number_lines);
    printf("Quantity of objects is %i.\n\n", (number_lines-1)/5); // по 5 строк, включая пробел для разделения минус нулевая строка.

    //Хотел по-хитрому, не осилил переходы на новую строку через чисто си.
    /*char str[20];
    for (int i = 0; i < number_lines; i++)
    	{
    	fscanf(input, "%[^\n]", str);
    	printf(str);
    	}
	*/

	const int len = 30;
	const char ch = '\n';
	char mass[len][number_lines];
	char mass2[len - 8][number_lines];
	char mass3[len - 8][number_lines];


	ifstream file("input.txt", ios::in | ios::binary);

	if(!file) return 1;

	for (int r = 0; r < number_lines; r++)
	{
		file.getline(mass[r], len-1,ch); //Считываем строки в массив
		cout << "String " << r+1 << " = "<< mass[r] << endl; //Выводим сырую строку из массива
		// переработка? scanf не тянет. выдает не то, что ожидается.

		/*if (int isdigit(int mass2[r]))
			{
			mass3[r] = atof(mass2[r]);
			}*/

	// + удалить пустые строки между данными

	}

	// здесь уже по идее можно считать, но пока нечего :)




/*
    FILE * output;
    if (output = fopen("result.txt", "wt") == 0) // открытие с проверкой на успешность выполнения
        {
    	printf("Error with opening or creating output file!");
    	return 0;
        }



			printf("Input name of your %i object: ", i + 1);
			scanf("%20s", &name);
			printf("\n");

			printf("Input length of your object: ");
			scanf("%f", &length);
			printf("\n");

			printf("Input width of your object: ");
			scanf("%f", &width);
			printf("\n");

			printf("Input height of your object: ");
			scanf("%f", &height);   // узнать подробнее про значок & и как не дать сломать вводом букв. %[0-9] ?
			printf("\n");

			fprintf(output, "Name of object: \"%s\". Length is %.3f, width is %.3f, height is %.3f.\n", name, length, width, height);

			if (length > 0 && width > 0 && height > 0)
				fprintf(output, "The total square of your object \"%s\" is %.3f.\n\n", name, 2 * (length * height + length * width + height * width));

			else
				fprintf(output, "Object \"%s\" doesn't exist!\n\n", name);

*/
    file.close();
    //fclose(output);

    return 0;
}
