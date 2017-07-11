#include "stdio.h"
#include "stdlib.h"

#include "main.h"
#include "resource.h"
#include "planet.h"

int main(int argc, char *argv[])
{
	
	Resource **res[] = resource_init_list();
    print_resources(res, RESOURCE_COUNT);

    return(0);
}