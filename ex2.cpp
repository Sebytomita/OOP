#include <stdio.h>
#include <stdlib.h>

int string_to_number(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }

    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + str[i] - '0';
        }
        ++i;
    }

    return sign * result;
}

int main()
{
    FILE *file;
    char line[100];
    int sum = 0;

    file = fopen("in.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file))
    {
        sum += string_to_number(line);
    }

    fclose(file);

    printf("%d\n", sum);

    return 0;
}
