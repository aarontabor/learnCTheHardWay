#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "ex19.h"
#include <assert.h>

int Hall_init(void *self)
{
  Map *map = self;

  // make some rooms for a small map
  Room *hall = NEW(Room, "The Great Hall");
  Room *throne = NEW(Room, "The throne room");
  Room *arena = NEW(Room, "The arena, with the minotaur");
  Room *kitchen = NEW(Room, "Kitchen, you have the knife now");

  Room *arena2 = NEW(Room, "Another arena, with another boss");

  // put the bad guy in the arena
  arena->bad_guy = NEW(Monster, "The evil minotaur");
  arena2->bad_guy = NEW(Monster, "Another boss");


  // setup the map rooms
  hall->north = throne;

  throne->west = arena;
  throne->east = kitchen;
  throne->south = hall;

  arena->east = throne;
  kitchen->west = throne;

  arena->west = arena2;
  arena2->east = arena;

  // start the map and character off in the hall
  map->start = hall;
  map->location = hall;

  return 1;
}

int main(int argc, char *argv[])
{
  MapProto.init = Hall_init;
  Map *game = NEW(Map, "The Hall of the Minotaur.");

  run_game(game);
  return 0;
}

