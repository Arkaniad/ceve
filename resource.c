#include "stdlib.h"
#include "stdio.h"

#include "resource.h"
#include "planet.h"

#define RESOURCE_COUNT = 83

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

// Initialize the entire list of resources and return a pointer to caller
void **resource_init_list()
{
    Resource **res[RESOURCE_COUNT] = malloc(RESOURCE_COUNT * sizeof(Resource));
	
	//p0
    res[0] 	= resource_init(0, 	"Aqueous Liquids", 					0, 	NULL, 	NULL, 	NULL);
    res[1] 	= resource_init(1, 	"Autotrophs", 						0, 	NULL, 	NULL, 	NULL);
    res[2] 	= resource_init(2, 	"Base Metals", 						0, 	NULL, 	NULL, 	NULL);
    res[3] 	= resource_init(3, 	"Carbon Compounds", 				0, 	NULL, 	NULL, 	NULL);
	res[4] 	= resource_init(4, 	"Complex Organisms", 				0, 	NULL, 	NULL, 	NULL);
	res[5] 	= resource_init(5, 	"Felsic Magma",						0, 	NULL, 	NULL, 	NULL);
	res[6] 	= resource_init(6, 	"Heavy Metals",						0, 	NULL, 	NULL, 	NULL);
	res[7] 	= resource_init(7, 	"Ionic Solutions",					0, 	NULL, 	NULL, 	NULL);
	res[8] 	= resource_init(8, 	"Micro Organisms",					0, 	NULL, 	NULL, 	NULL);
	res[9] 	= resource_init(9, 	"Noble Gas",						0, 	NULL, 	NULL, 	NULL);
	res[10]	= resource_init(10, "Noble Metals",						0, 	NULL, 	NULL, 	NULL);
	res[11] = resource_init(11, "Non-CS Crystals",					0, 	NULL, 	NULL, 	NULL);
	res[12] = resource_init(12, "Planktic Colonies",				0, 	NULL, 	NULL, 	NULL);
	res[13] = resource_init(13, "Reactive Gas",						0, 	NULL, 	NULL, 	NULL);
	res[14] = resource_init(14, "Suspended Plasma",					0, 	NULL, 	NULL, 	NULL);

	//p1			
	res[15] = resource_init(15, "Bacteria",							1, 	res[8],	NULL,	NULL);
	res[16] = resource_init(16, "Biofuels",							1,	res[3],	NULL,	NULL);
	res[17] = resource_init(17, "Biomass",							1,	res[12],NULL,	NULL);
	res[18] = resource_init(18, "Chiral Structures",				1,	res[11],NULL,	NULL);
	res[19] = resource_init(19, "Electrolytes", 					1,	res[7],	NULL,	NULL);
	res[20] = resource_init(20, "Industrial Fibers",				1,	res[1],	NULL,	NULL);
	res[21] = resource_init(21, "Oxidizing Compound", 				1,	res[13],NULL,	NULL);
	res[22] = resource_init(22, "Oxygen",							1,	res[9],	NULL,	NULL);
	res[23] = resource_init(23, "Plasmoids",						1,	res[14],NULL,	NULL);
	res[24] = resource_init(24, "Precious Metals",					1,	res[10],NULL,	NULL);
	res[25] = resource_init(25, "Proteins",							1, 	res[4],	NULL,	NULL);
	res[26] = resource_init(26, "Reactive Metals",					1,	res[2],	NULL,	NULL);
	res[27] = resource_init(27, "Silicon",							1,	res[5],	NULL,	NULL);
	res[28] = resource_init(28, "Toxic Metals",						1,	res[6],	NULL,	NULL);
	res[29] = resource_init(29, "Water", 							1,	res[0],	NULL,	NULL);

	//p2			
	res[30] = resource_init(30, "Biocells",							2,	res[16],res[24],NULL);
	res[31] = resource_init(31, "Construction Blocks",				2,	res[28],res[26],NULL);
	res[32] = resource_init(32, "Consumer Electronics",				2,	res[18],res[28],NULL);
	res[33] = resource_init(33,	"Coolant",							2,	res[29],res[19],NULL);
	res[34] = resource_init(34, "Enriched Uranium",					2,	res[28],res[24],NULL);
	res[35] = resource_init(35, "Fertilizer",						2,	res[25],res[17],NULL);
	res[36] = resource_init(36, "Livestock",						2,	res[16],res[25],NULL);
	res[37] = resource_init(37, "Mechanical Parts",					2,	res[24],res[26],NULL);
	res[38] = resource_init(38, "Microfiber Shielding",				2,	res[27],res[20],NULL);
	res[39] = resource_init(39, "Miniature Electronics",			2,	res[27],res[18],NULL);
	res[40] = resource_init(40, "Nanites",							2,	res[26],res[15],NULL);
	res[41] = resource_init(41, "Oxides",							2,	res[22],res[21],NULL);
	res[42] = resource_init(42, "Polyaramids",						2,	res[20],res[21],NULL);
	res[43] = resource_init(43, "Polytextiles",						2,	res[20],res[16],NULL);
	res[44] = resource_init(44, "Rocket Fuel",						2,	res[19],res[23],NULL);
	res[45] = resource_init(45, "Silicate Glass",					2,	res[27],res[21],NULL);
	res[46] = resource_init(46, "Superconductors",					2,	res[29],res[23],NULL);
	res[47] = resource_init(47, "Supertensile Plastics",			2,	res[19],res[22],NULL);
	res[48] = resource_init(48, "Synthetic Oil",					2,	res[22],res[19],NULL);
	res[49] = resource_init(48, "Test Cultures",					2,	res[29],res[15],NULL);
	res[50] = resource_init(50, "Transmitter",						2,	res[23],res[18],NULL);
	res[51] = resource_init(51, "Viral Agent",						2,	res[15],res[17],NULL);
	res[52] = resource_init(52, "Water-Cooled CPU",					2,	res[29],res[26],NULL);
	res[53] = resource_init(53, "Genetically Enhanced Livestock",	2,	res[17],res[25],NULL);
	
	//p3
	res[54] = resource_init(54, "Biotech Research Reports",			3,	res[40],res[36],res[31]);
	res[55] = resource_init(55, "Camera Drones",					3,	res[45],res[44],NULL);
	res[56] = resource_init(56, "Condensates",						3,	res[41],res[33],NULL);
	res[57] = resource_init(57, "Cryoprotectant Solution",			3,	res[49],res[48],res[35]);
	res[58] = resource_init(58, "Data Chips",						3,	res[47],res[38],NULL);
	res[59] = resource_init(59, "Gel-Matrix Biopaste",				3,	res[41],res[30],res[46]);
	res[60] = resource_init(60, "Guidance Systems",					3,	res[52],res[50],NULL);
	res[61] = resource_init(61, "Hazmat Detection Systems",			3,	res[43],res[51],res[50]);
	res[62] = resource_init(62, "Hermetic Membranes",				3,	res[42],res[53],NULL);
	res[63] = resource_init(63, "High Tech Transmitters",			3,	res[42],res[50],NULL);
	res[64] = resource_init(64, "Industrial Explosives",			3, 	res[43],res[35],NULL);
	res[65] = resource_init(65, "Neocoms",							3,	res[30],res[45],NULL);
	res[66] = resource_init(66, "Nuclear Reactors", 				3,	res[38],res[34],NULL);
	res[67] = resource_init(67, "Planetary Vehicles",				3,	res[47],res[37],res[39]);
	res[68] = resource_init(68, "Robotics",							3,	res[32],res[37],NULL);
	res[69] = resource_init(69, "Smartfab Units",					3,	res[31],res[39],NULL);
	res[70] = resource_init(70, "Supercomputers",					3,	res[52],res[33],res[46]);
	res[71] = resource_init(71, "Synthetic Synapses",				3,	res[47],res[49],NULL);
	res[72] = resource_init(72, "Transcranial Microcontrollers",	3, 	res[30],res[40],NULL);
	res[73] = resource_init(73, "Ukomi Superconductors",			3,	res[48],res[46],NULL);
	res[74] = resource_init(74, "Vaccines",							3,	res[36],res[51],NULL);

	//p4
	res[75] = resource_init(75, "Broadcast Node",					4,	res[65],res[58],res[63]);
	res[76] = resource_init(76, "Integrity Response Drones",		4,	res[59],res[61],res[67]);
	res[77] = resource_init(77, "Nano-Factory", 					4,	res[64],res[73],res[26]);
	res[78] = resource_init(78, "Organic Mortar Applicators",		4,	res[56],res[68],res[15]);
	res[79] = resource_init(79, "Recursive Computing Module",		4,	res[71],res[60],res[72]);
	res[80] = resource_init(80, "Self-Harmonizing Power Core",		4,	res[55],res[66],res[62]);
	res[81] = resource_init(81, "Sterile Conduits",					4,	res[69],res[74],res[29]);
	res[82] = resource_init(82, "Wetware Mainframe",				4,	res[70],res[54],res[57]);
    return res;
}

void print_resources(Resource *resources[], int count)
{
    if(resources)
    {
        printf("Count: %d\n", count);
        
        for(int i = 0; i < count; i++)
        {
            if(resources[i])
            {
                //Resource current_resource = *resources[i];
                print_resource(resources[i]);
            }
            
        }	
    }
}

void print_resource(Resource *resource)
{
    printf("P%d: %s\n", resource->level, resource->name);
    if(resource->ingredient1)
    {
        printf("- Requires %s (P%d)\n", resource->ingredient1->name, resource->ingredient1->level);
    }

     if(resource->ingredient2)
    {
        printf("- Requires %s (P%d)\n", resource->ingredient2->name, resource->ingredient2->level);
    }

    if(resource->ingredient3)
    {
        printf("- Requires %s (P%d)\n", resource->ingredient3->name, resource->ingredient3->level);
    }
}