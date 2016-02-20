#include <stdio.h>

int main()
{
	float height;
	float length;
	float width;
	char name[20];

    printf("Input length of your object: ");
    scanf("%f", &length);
    printf("\n");

    printf("Input width of your object: ");
    scanf("%f", &width);
    printf("\n");

	printf("Input height of your object: ");
	scanf("%f", &height);   // узнать подробнее про значок & и как не дать сломать вводом букв
    printf("\n");

	printf("Input name of your object (no more than 20 symbols, without spaces): "); // на пробелы забил, запутался
	scanf("%20s", &name);
    printf("\n");

    //printf("The total square of your object \"%s\" is %.3f.", name, 2 * (length * height + length * width + height * width));

    FILE * output;
    if ((output = fopen("result.txt", "wt")) == 0) // открытие с проверкой на успешность выполнения
        {
    	printf("Error with opening or creating file!");
    	return 0;
        }

    fprintf(output, "Name of object: \"%s\". Length is %.3f, width is %.3f, height is %.3f.\n", name, length, width, height);
    fprintf(output, "The total square of your object \"%s\" is %.3f.\n", name, 2 * (length * height + length * width + height * width));
    fclose(output);

    return 0;
}
