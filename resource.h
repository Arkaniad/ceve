typedef struct _Resource Resource;
typedef struct _Planet Planet;

struct _Resource{
	int id;
	char *name;
	int level;

	float unit_size;
	float unit_sell;
	float unit_buy;

	int batch_units;

	Planet *found_on;

	Resource *ingredient1;
	Resource *ingredient2;
	Resource *ingredient3;

	int ingredient1_count;
	int ingredient2_count;
	int ingredient3_count;	
};

Resource *resource_new();
Resource *resource_init(int id, char *name, int level, Planet *found_on[], Resource *ingredient1, Resource *ingredient2, Resource *ingedient3);
void *resource_init_list();

void print_resources(Resource *resources[], int count);
void print_resource(Resource resource);