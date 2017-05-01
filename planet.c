#include "planet.h"
#include "resource.h"

struct _Planet{
	char *name;
	Resource *resources[5];
};

Planet *planet_new();
Planet *planet_init();

void print_resources(Resource *resources[], int count);
void print_resource(Resource resource);