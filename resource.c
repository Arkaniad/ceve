#include "resource.h"
#include "stdio.h"

Resource *resource_new() 
{
    Resource *res = malloc(sizeof(Resource));
    return res;
}

Resource *resource_init(int id, char *name, int level, Planet *found_on[], Resource *ingredient1, Resource *ingredient2, Resource *ingredient3)
{
    Resource *res = resource_new();
    res->id = id;
    res->name = name;
    res->level = level;
    res->found_on = found_on;
    switch(level)
    {
        case 1:
            res->unit_size = 0.38f;
            res->batch_units = 20;
            if(ingredient1)
            {
                res->ingredient1_count = 3000;
            }
            break;
        case 2:
            res->unit_size = 1.5f;
            res->batch_units = 5;
            if(ingredient1)
            {
                res->ingredient1_count = 40;
            }
            if(ingredient2)
            {
                res->ingredient2_count = 40;
            }
            break;
        case 3:
            res->unit_size = 6.0f;
            res->batch_units = 3;
            if(ingredient1)
            {
                res->ingredient1_count = 10;
            }
            if(ingredient2)
            {
                res->ingredient2_count = 10;
            }
            if(ingredient3)
            {
                res->ingredient3_count = 10;
            }
            break;
        case 4:
            res->unit_size = 100.0f;
            res->batch_units = 1;
            if(ingredient1)
            {
                res->ingredient1_count = 6;
            }
            if(ingredient2)
            {
                res->ingredient2_count = 6;
            }
            if(ingredient3)
            {
                if(ingredient3->level == 1)
                {
                    res->ingredient3_count = 40;
                }
                else
                {
                    res->ingredient3_count = 6;
                }
            }
            break;
        default:
            res->unit_size = 0.1f;
            res->batch_units = 0;
            break;
    }

    if(ingredient1 != NULL)
    {
        res->ingredient1 = ingredient1;
    }
    if(ingredient2 != NULL)
    {
        res->ingredient2 = ingredient2;
    }
    if(ingredient3 != NULL)
    {
        res->ingredient3 = ingredient3;
    }
    return res;
}

void print_resources(Resource *resources[], int count)
{
    if(resources != NULL)
    {
        printf("Count: %d\n", count);
        
        for(int i = 0; i < count; i++)
        {
            if(resources[i] != NULL)
            {
                //Resource current_resource = *resources[i];
                print_resource(*resources[i]);
            }
            
        }	
    }
}

void print_resource(Resource resource)
{
    printf("P%d: %s\n", resource.level, resource.name);
    if(resource.ingredient1)
    {
        printf("- Requires %s (P%d)\n", resource.ingredient1->name, resource.ingredient1->level);
    }

     if(resource.ingredient2)
    {
        printf("- Requires %s (P%d)\n", resource.ingredient2->name, resource.ingredient2->level);
    }

    if(resource.ingredient3)
    {
        printf("- Requires %s (P%d)\n", resource.ingredient3->name, resource.ingredient3->level);
    }
}