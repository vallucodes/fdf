#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    int     fd[3];
    char    *line;

    fd[0] = open("10-2.fdf", O_RDONLY);
    if (fd[0] == -1)
    {
        perror("Error opening file");
        return 1;
    }

	fd[1] = open("10-70.fdf", O_RDONLY);
    if (fd[1] == -1)
    {
        perror("Error opening file");
        return 1;
    }

	fd[2] = open("elem.fdf", O_RDONLY);
    if (fd[2] == -1)
    {
        perror("Error opening file");
        return 1;
    }

	int i = 20;
	int j = 0;
	while (i > 0)
    {
        printf("round %i\n", i);
		line = get_next_line(fd[j]);
        printf("Line %s", line);
		j++;
		if (j == 3)
			j = 0;
        free(line);
        i--;
    }
    i = 2;
    while (i >= 0)
        close(fd[i]);
    return 0;
}

