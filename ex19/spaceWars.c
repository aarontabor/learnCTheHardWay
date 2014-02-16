#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"
#include <assert.h>

int Space_init(void *self)
{

  Map *map = self;

  // set-up rooms
  Room *command = NEW(Room, "The Central Command Room");
  Room *cockpit = NEW(Room, "Front Row and Center");
  Room *sleeping = NEW(Room, "Bunk Area, You are rested up");
  Room *engineRoom = NEW(Room, "There is an alien messing with the Hyper-Drive");

  engineRoom->bad_guy = NEW(Monster, "Evil Alien");

  cockpit->south = command;
  
  command->north = cockpit;
  command->west = sleeping;
  command->east = engineRoom;

  sleeping->east = command;
  engineRoom->west = command;

  map->start = cockpit;
  map->location = cockpit;
  
  return 1;  
}


int main(int argc, char *argv[])
{

  MapProto.init = Space_init;
  Map *game = NEW(Map, "Space Shuttle Terror");

  run_game(game);
  return 0;

}
