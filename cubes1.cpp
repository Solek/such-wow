#include <stdio.h>
#include <string.h>

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
	scanf("%f", &height);   // узнать поподробнее про значок & и сканф
    printf("\n");

	printf("Input name of your object (no more than 20 symbols, without spaces): ");
	scanf("%20s", &name);
    printf("\n");

    printf("The sum of squares of your object \"%s\" is %.3f.", name, (2 * length * height + 2 * length * width + 2 * height * width));

    return 0;
}
