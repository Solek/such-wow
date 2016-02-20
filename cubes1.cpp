#include <stdio.h>

int main()
{
	int cycle;
	float height;
	float length;
	float width;
	char name[20];

	printf("How many objects do you plan to calculate? ");
	scanf("%i", &cycle);
	printf("\n");
	if (cycle <= 0)
	    {
		printf("Okay, bye.");
		return 0;
	    }

    FILE * output;
    if ((output = fopen("result.txt", "wt")) == 0) // открытие с проверкой на успешность выполнения
        {
    	printf("Error with opening or creating file!");
    	return 0;
        }

	for (int i = 0; i < cycle; i++)
	    {
			printf("Input name of your %i object (no more than 20 symbols, without spaces): ", i + 1); // на пробелы забил, запутался
			scanf("%20s", &name);
			printf("\n");

			printf("Input length of your object: ");
			scanf("%f", &length);
			printf("\n");

			printf("Input width of your object: ");
			scanf("%f", &width);
			printf("\n");

			printf("Input height of your object: ");
			scanf("%f", &height);   // узнать подробнее про значок & и как не дать сломать вводом букв
			printf("\n");

			fprintf(output, "Name of object: \"%s\". Length is %.3f, width is %.3f, height is %.3f.\n", name, length, width, height);

			if (length > 0 && width > 0 && height > 0)
				fprintf(output, "The total square of your object \"%s\" is %.3f.\n\n", name, 2 * (length * height + length * width + height * width));

			else
				fprintf(output, "Object \"s\" doesn't exist!\n\n", name);
		}

    fclose(output);
    return 0;
}
