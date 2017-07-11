#include "stdlib.h"
#include "stdio.h"

#include "planet.h"
#include "resource.h"

Planet *planet_new()
{
	Planet *planet = malloc(sizeof(Planet));
	return planet;
}

Planet *planet_init(int id, char *name, Resource *resources)
{
	Planet *planet = planet_new();
	planet->id = id;
	planet->name = name;
	planet->resources = resources;
	return planet;
}

void *planet_init_list(char *planets, int count)
{

}

void print_planet(Planet *planets, int count)
{
	if(planets)
	{
		printf("Count: %d\n");
		for(int i = 0; i < count; i++)
		{
			if(planets[i])
			{
				print_planet(planets[i]);
			}
		}
	}
}

void print_planet(Planet *planet)
{
	printf("Planet %d: %s\n", planet->id, planet->name)
	{
		for(int i = 0; i < 5; i++)
		{
			printf("- Resource %d ID %d: %s (P%d)\n", i, planet->resources[i]->id, planet->resources[i]->name, planet->resources[i]->level);
		}
	}
}