typedef struct _Planet Planet;
typedef struct _Resource Resource;

struct _Planet{
	int id;
	char *name;
	Resource *resources[5];
};

Planet *planet_new();
Planet *planet_init();

void print_planets(Planet *planets[], int count);
void print_planet(Planet planet);

