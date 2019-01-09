/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: 2DHIF
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Kocsis Patrik
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "caravan.h"
#include "general.h"

#define HORSE_MAX_SPEED 50
#define CAMEL_MAX_SPEED 20

typedef struct Node* NodeStruct;

struct Node
{
    PackAnimal animal;
    struct Node* next;
};

struct CaravanImplementation{
    int length;
    NodeStruct head;
};

Caravan new_caravan()
{
    Caravan caravan =(Caravan)malloc(sizeof(struct CaravanImplementation));
    caravan->length = 0;
    caravan->head = 0;
    return caravan;
}

int get_length(Caravan caravan)
{
    return caravan -> length;
}

void delete_caravan(Caravan caravan)
{
    NodeStruct current = caravan->head;

    while(current != 0)
    {
        NodeStruct to_be_deleted = current;
        current = current->next;
        sfree(to_be_deleted);
    }

    sfree(caravan);

}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal != 0)
    {
        if(get_caravan(animal) != 0 && get_caravan(animal) != caravan)
        {
            remove_pack_animal(get_caravan(animal), animal);
        }

        NodeStruct current = caravan->head;
        NodeStruct node_to_add = (NodeStruct)malloc(sizeof(struct Node));
        node_to_add -> animal = animal;
        node_to_add->next = 0;

        if(caravan->head == 0)
        {
            caravan->head = node_to_add;
        }
        else
        {
            while(current->next != 0)
            {
                if(current->animal == animal) return;
                current = current->next;
            }

            if(current->animal == animal) return;
            current->next = node_to_add;
        }
            add_to_caravan(animal, caravan);
            caravan->length++;
    }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal!=0)
  {
    NodeStruct current = caravan->head;
    NodeStruct prev;

    if(current != 0 && current->animal == animal)
    {
       caravan->head = current->next;
       sfree(current);
       remove_from_caravan(animal, caravan);
       caravan->length--;
       return;
     }

     while(current != 0 && current->animal != animal)
     {
       prev = current;
       current = current->next;
     }

     if(current==0) return;

     prev->next = current->next;
     sfree(current);
     remove_from_caravan(animal, caravan);
     caravan->length--;
   }
}

int get_caravan_load(Caravan caravan)
{
    NodeStruct current = caravan->head;
    int load = 0;

    while(current!=0)
    {
        load+= get_load(current->animal);
        current = current->next;
    }

    return load;
}

void unload(Caravan caravan)
{
    NodeStruct current = caravan->head;

    while(current != 0)
    {
        unload(current->animal);
        current = current->next;
    }
}

int get_caravan_speed(Caravan caravan)
{
    NodeStruct current = caravan->head;
    int speed = HORSE_MAX_SPEED;

    while(current != 0)
    {
        if(get_actual_speed(current->animal)<speed)
        {
            speed = get_actual_speed(current->animal);
        }
        current = current->next;
    }
    return speed;
}

void optimize_load(Caravan caravan)
{
    int load = get_caravan_load(caravan);
    int lenCamels = 0;
    int lenHorses = 0;
    NodeStruct current = caravan->head;
    int fastestHorse = 0;
    int slowestHorse = HORSE_MAX_SPEED;
    int fastestCamel = 0;
    int slowestCamel = CAMEL_MAX_SPEED;
    while(current != 0)
    {
        if(get_max_speed(current->animal) == CAMEL_MAX_SPEED)
        {
            lenCamels++;
            if(get_actual_speed(current->animal) > fastestCamel)
            {
                fastestCamel = get_actual_speed(current->animal);
            }
            else if(get_actual_speed(current->animal)<slowestCamel)
            {
                slowestCamel = get_actual_speed(current->animal);
            }
        }
        else
        {
            lenCamels++;
            if(get_actual_speed(current->animal) > fastestHorse)
            {
                fastestHorse = get_actual_speed(current->animal);
            }else if(get_actual_speed(current->animal)<slowestHorse)
            {
                slowestHorse = get_actual_speed(current->animal);
            }
            lenHorses++;
        }
        current = current -> next;
    }
}
