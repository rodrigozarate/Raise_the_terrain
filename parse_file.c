#include "terrain.h"

int read_file(SDL_Instance *instance)
{
	FILE *file;
	char *token;
	int i;
	size_t line = 0;
	char *buffer = NULL;

	printf("in read\n");
	file = fopen(instance->elevation, "r");
	if (!file)
	{
		fprintf(stderr, "File error\n");
		return (1);
	}

	for (; getline(&buffer, &line, file) != -1; instance->xstep++)
		if (instance->xstep == 0)
		{
			printf("init tok\n");
			token = strtok(buffer, "\n");
			for (; token; instance->ystep++)
				token = strtok(NULL, " \n");
			printf("is token: %s \n", token);
		}
	/* create array of points */
	instance->data = malloc(sizeof(point *) * instance->xstep);
	if (!instance->data)
	{
		fprintf(stderr, "Malloc failed, sorry\n");
		return(1);
	}

	for (i = 0; i < instance->xstep; i++)
	{
		/* populate */
		instance->data[i] = malloc(sizeof(point) * instance->ystep);
		if (!instance->data[i])
		{
			fprintf(stderr, "Malloc failed, y axis sorry\n");
			return(1);
		}
	}
	free(buffer);
	fclose(file);
	process_file(instance);
	return (0);
}

void process_file(SDL_Instance *instance)
{
	FILE *file;
	char *token;
        int i, j;
        size_t line = 0;
        char *buffer = NULL;

	file = fopen(instance->elevation, "r");
	/* walk the file */
	printf("in process\n");
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
	free(file);
}


void clear_data(SDL_Instance *instance)
{
	int i;

	printf("in clear\n");
	for (i = 0; i < instance->xstep; i++)
	{
		free(instance->data[i]);
	}
	free(instance->data);
}
