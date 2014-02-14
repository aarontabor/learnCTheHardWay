#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "game_mechanics.h"

int Map_init(void *self)
{
  Map *map = self;

  // make some rooms for a small map
  Room *hall = NEW(Room, "The Great Hall");
  Room *throne = NEW(Room, "The throne room");
  Room *arena = NEW(Room, "The arena, with the minotaur");
  Room *kitchen = NEW(Room, "Kitchen, you have the knife now");

  // put the bad guy in the arena
  arena->bad_guy = NEW(Monster, "The evil minotaur");

  // setup the map rooms
  hall->north = throne;

  throne->west = arena;
  throne->east = kitchen;
  throne->south = hall;

  arena->east = throne;
  kitchen->west = throne;

  // start the map and character off in the hall
  map->start = hall;
  map->location = hall;

  return 1;
}

Object MapProto = {
  .init = Map_init,
  .move = Map_move,
  .attack = Map_attack
};


int main(int argc, char *argv[])
{
  // simple way to setup randomness
  srand(time(NULL));
  assert(!errno); // ensure everything went according to plan

  // make our map to work with
  Map *game = NEW(Map, "The Hall of the Minotaur.");

  printf("You enter the ");
  game->location->_(describe)(game->location);

  while(process_input(game)) {
  }

  return 0;

}
