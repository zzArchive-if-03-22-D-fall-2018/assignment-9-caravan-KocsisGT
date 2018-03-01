/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			pack_animal.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdlib.h>
#include "general.h"
#include "pack_animal.h"

#define CAMEL_MAX_SPEED 20
#define HORSE_MAX_SPEED 50

struct PackAnimalImplementation {
	AnimalType type;
	const char *name;
	int max_speed;
	int load;
	Caravan caravan;
};


static PackAnimal new_pack_animal(const char *name);
PackAnimal new_camel(const char *name, int max_speed)
{
	PackAnimal camel = new_pack_animal(name);
	if (camel == 0)
		return 0;
	camel->type = Camel;
	camel->max_speed = MIN(max_speed, CAMEL_MAX_SPEED);
	camel->max_speed = MAX(0, camel->max_speed);

	return camel;
}

static PackAnimal new_pack_animal(const char *name)
{
	PackAnimal animal = (PackAnimal) malloc(sizeof(PackAnimalImplementation));
	if (animal == 0)
		return 0;
	animal->name = name;
	animal->load = 0;
	animal->caravan = 0;

	return animal;
}

PackAnimal new_horse(const char *name, int max_speed)
{
	PackAnimal horse = new_pack_animal(name);
	if (horse == 0)
		return 0;
	horse->type = Horse;
	horse->max_speed = MIN(max_speed, HORSE_MAX_SPEED);
	horse->max_speed = MAX(0, horse->max_speed);

	return horse;
}

int get_max_speed(PackAnimal animal)
{
	return animal->max_speed;
}

int get_load(PackAnimal animal)
{
	return animal->load;
}

Caravan get_caravan(PackAnimal animal)
{
	return animal->caravan;
}

void delete_animal(PackAnimal animal)
{
	sfree(animal);
}

void add_load(PackAnimal animal, int load)
{
	animal->load += load;
}

void unload(PackAnimal animal)
{
	animal->load = 0;
}

static int speed_reduction_factor[3] = {
	1,		// camel reduces speed by 1 if added one to load
	10,		// horse reduces speed by 10 if added one to load
	1		// elephant reduces speed by 1 if added on to load
};


int get_actual_speed(PackAnimal animal)
{
	int speed_reduction = get_load(animal) * speed_reduction_factor[animal->type];
	return MAX(get_max_speed(animal) - speed_reduction, 0);
}

int get_expected_speed(PackAnimal animal, int additional_load)
{
	if (get_load(animal) + additional_load < 0)
		return get_max_speed(animal);

	int speed_reduction = (get_load(animal) + additional_load) * speed_reduction_factor[animal->type];
	return MAX(get_max_speed(animal) - speed_reduction, 0);
}

void add_to_caravan(PackAnimal animal, Caravan caravan)
{
	animal->caravan = caravan;
}

void remove_from_caravan(PackAnimal animal, Caravan caravan)
{
	animal->caravan = 0;
}
