/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			Printer Queue
 * Author:			P. Bauer
 * Due Date:		January 30, 2011
 * ----------------------------------------------------------
 * Description:
 * A simple printer queue.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "test_pack_animal.h"
#include "test_caravan.h"

int main(int argc, char *argv[])
{
	// tests for PackAnimal
	ADD_TEST(new_animal);
	ADD_TEST(new_animal_with_invalid_max_speed);
	ADD_TEST(load_and_unload);
	ADD_TEST(actual_camel_speed);
	ADD_TEST(actual_horse_speed);
	ADD_TEST(expected_speed);

	// tests for Caravan
	ADD_TEST(create_caravan);
	ADD_TEST(add_pack_animal);
	ADD_TEST(remove_pack_animal);
	ADD_TEST(add_pack_animal_twice);
	ADD_TEST(caravan_load);
	ADD_TEST(unload);
	ADD_TEST(caravan_speed);
	ADD_TEST(change_caravan);
	ADD_TEST(optimize_load);

	run_tests();
	return 0;
}
