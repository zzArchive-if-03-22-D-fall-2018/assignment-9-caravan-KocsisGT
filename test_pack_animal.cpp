/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			test_pack_animal.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "general.h"
#include "pack_animal.h"
#include "test_pack_animal.h"

/******************************************************************************
 * test_init_animal
 *
 * Tests initializing an animal
 ******************************************************************************/
TEST(new_animal)
{
	init_free_list();

	PackAnimal willi = new_camel("Willi", 5);

	ASSERT_EQUALS(5, get_max_speed(willi));
	ASSERT_EQUALS(0, get_load(willi));
	ASSERT_TRUE(get_caravan(willi) == 0, "Willi's caravane expected to be 0");

	delete_animal(willi);
	ASSERT_TRUE(get_free_list()[0] == willi, "Willi expected to be in free list");

	PackAnimal mitzi = new_horse("Mitzi", 5);
	ASSERT_EQUALS(5, get_max_speed(mitzi));
	ASSERT_EQUALS(0, get_load(mitzi));
	ASSERT_TRUE(get_caravan(mitzi) == 0, "Mitzi's caravane expected to be 0");

	delete_animal(mitzi);
	ASSERT_TRUE(get_free_list()[1] == mitzi, "Mitzi expected to be in free list");
}

#define MAX_CAMEL_SPEED 20
#define MAX_HORSE_SPEED 50
TEST(new_animal_with_invalid_max_speed)
{
	init_free_list();

	PackAnimal quick_willi = new_camel("Willi", MAX_CAMEL_SPEED + 1);

	ASSERT_EQUALS(MAX_CAMEL_SPEED, get_max_speed(quick_willi));
	delete_animal(quick_willi);
	ASSERT_TRUE(get_free_list()[0] == quick_willi, "Willi expected to be in free list");

	PackAnimal willi = new_camel("Willi", -1);

	ASSERT_EQUALS(0, get_max_speed(willi));
	delete_animal(willi);
	ASSERT_TRUE(get_free_list()[1] == willi, "Willi expected to be in free list");

	PackAnimal quick_mitzi = new_horse("Mitzi", MAX_HORSE_SPEED + 1);

	ASSERT_EQUALS(MAX_HORSE_SPEED, get_max_speed(quick_mitzi));
	delete_animal(quick_mitzi);
	ASSERT_TRUE(get_free_list()[2] == quick_mitzi, "Mitzi expected to be in free list");

	PackAnimal mitzi = new_horse("Mitzi", -1);

	ASSERT_EQUALS(0, get_max_speed(mitzi));
	delete_animal(mitzi);
	ASSERT_TRUE(get_free_list()[3] == mitzi, "Mitzi expected to be in free list");
}

TEST(load_and_unload)
{
	PackAnimal willi = new_camel("Willi", 10);

	add_load(willi, 5);
	ASSERT_EQUALS(5, get_load(willi));

	add_load(willi, 3);
	ASSERT_EQUALS(8, get_load(willi));

	unload(willi);
	ASSERT_EQUALS(0, get_load(willi));
	delete_animal(willi);
}

/******************************************************************************
 * test_actual_camel_speed
 *
 *
 ******************************************************************************/
TEST(actual_camel_speed)
{
	PackAnimal willi = new_camel("Willi", 5);
	ASSERT_EQUALS(5, get_actual_speed(willi));

	add_load(willi, 3);
	ASSERT_EQUALS(2, get_actual_speed(willi));

	add_load(willi, 2);
	ASSERT_EQUALS(0, get_actual_speed(willi));

	add_load(willi, 1);
	ASSERT_EQUALS(0, get_actual_speed(willi));

	unload(willi);
	ASSERT_EQUALS(5, get_actual_speed(willi));

	delete_animal(willi);
}

/******************************************************************************
 * test_actual_horse_speed
 *
 *
 ******************************************************************************/
TEST(actual_horse_speed)
{
	PackAnimal mitzi = new_horse("Mitzi", 50);
	ASSERT_EQUALS(50, get_actual_speed(mitzi));

	add_load(mitzi, 2);
	ASSERT_EQUALS(30, get_actual_speed(mitzi));

	add_load(mitzi, 3);
	ASSERT_EQUALS(0, get_actual_speed(mitzi));

	add_load(mitzi, 1);
	ASSERT_EQUALS(0, get_actual_speed(mitzi));

	unload(mitzi);
	ASSERT_EQUALS(50, get_actual_speed(mitzi));

	delete_animal(mitzi);

}
//
// /******************************************************************************
//  * test_expected_speed
//  *
//  *
//  ******************************************************************************/
TEST(expected_speed)
{
	PackAnimal mitzi = new_horse("Mitzi", 50);

	ASSERT_EQUALS(20, get_expected_speed(mitzi, 3));
	ASSERT_EQUALS(50, get_expected_speed(mitzi, 0));
	ASSERT_EQUALS(0, get_expected_speed(mitzi, 5));
	ASSERT_EQUALS(0, get_expected_speed(mitzi, 6));
	ASSERT_EQUALS(50, get_expected_speed(mitzi, -1));

	add_load(mitzi, 3);
	ASSERT_EQUALS(40, get_expected_speed(mitzi, -2));
	ASSERT_EQUALS(50, get_expected_speed(mitzi, -3));
	ASSERT_EQUALS(50, get_expected_speed(mitzi, -4));

	delete_animal(mitzi);
}
