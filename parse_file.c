#include "header.h"

int read_file(SDL_Instance *instance)
{
	FILE *file;
	char *token;
	int i;
	size_t line = 0;
	char *buffer = NULL;

	for (; getline(&buffer, &line, file) != -1; instance->xstep++)
		if (instance->xstep == 0)
		{
			token = strtok(buffer, "\n");
			for (; token; instance->ystep++)
				token = strtok(NULL, " \n");
		}
	/* create array of points */
	instance->data = malloc(sizeof(point *) * instance->xstep);

	for (i = 0; i < instance->xstep; i++)
	{
		/* populate */
		instance->data[i] = malloc(sizeof(point) * instance->ystep);
	}
	free(buffer);
	fclose(file);
	process_file(instance);
	return (0);
}

void process_file(SDL_Instance *instance)
{
	FILE *file
	char *token;
        int i, j;
        size_t line = 0;
        char *buffer = NULL;

	file = fopen(instance->elevation, "r");
	/* walk the file */
	for (i = 0; getline(&buffer, &line, file) != -1; i++)
	{
		token = strtok(buffer, " \n");
		for (j = 0; token; j++)
		{
			instance->data[i][j].x = (SCREEN_WIDTH
				/ (instance->ystep)) * (i + 1);
			instance->data[i][j].y = (SCREEN_HEIGHT 
				/ (instance->xstep)) * (j + 1);
			instance->data[i][j].z = atof(token);

			token = strtok(NULL, " \n");
		}
	}
	free(buffer);
	ferr(file);
}


void clear_data(SDL_Instance *instance)
{
	int i;

	for (i = 0; i < instance->xstep; i++)
	{
		free(instance->data[i];
	}
	free(instance->data);
}
