#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"
#include <assert.h>



int Monster_attack(void *self, int damage)
{
  assert(self != NULL);
  assert(damage >= 0);

  Monster *monster = self;
  assert(monster->hit_points); // ensure it's indeed a monster
  // not a sure fire guarantee (but at least will check to see that an iteger has been allocated i.e. "looks like a monster")

  printf("You attack %s!\n", monster->_(description));

  monster->hit_points -= damage;

  if(monster->hit_points > 0) {
    printf("It is still alive.\n");
    return 0;
  } else { // this could be broken by integer underflow (hit-points goes down and down)
    printf("It is dead!\n");
    return 1;
  }
}

int Monster_init(void *self)
{
  assert(self != NULL);

  Monster *monster = self;
  monster->hit_points = 10;
  return 1;
}

Object MonsterProto = {
  .init = Monster_init,
  .attack = Monster_attack
}; // TODO look this syntax up in ECE textbook


void *Room_move(void *self, Direction direction)
{
  assert(self != NULL);
  Room *room = self;
  Room *next = NULL;

  if(direction == NORTH && room->north) {
    printf("You go north, into:\n");
    next = room->north;
  } else if(direction == SOUTH && room->south) {
    printf("You go south, into:\n");
    next = room->south;
  } else if(direction == EAST && room->east) {
    printf("You go east, into:\n");
    next = room->east;
  } else if(direction == WEST && room->west) {
    printf("You go west, into:\n");
    next = room->west;
  } else {
    printf("You can't go that direction.");
    next = NULL;
  }

  if(next) {
    next->_(describe)(next);
  }

  return next;
}

int Room_attack(void *self, int damage)
{
  assert(self != NULL);
  assert(damage >= 0);

  Room *room = self;
  Monster *monster = room->bad_guy;

  if(monster) {
    monster->_(attack)(monster,damage);
    return 1;
  } else {
    printf("You flail in the air at nothing. Idiot.\n");
    return 0;
  }
}


Object RoomProto = {
  .move = Room_move,
  .attack = Room_attack
};


void *Map_move(void *self, Direction direction)
{
  assert(self != NULL);

  Map *map = self;
  Room *location = map->location;
  assert(location != NULL);

  Room *next = NULL;

  next = location->_(move)(location, direction);

  if(next) {
    map->location = next;
  } else {
    // cannot move in that direction
  }

  return next;
}

int Map_attack(void *self, int damage)
{
  assert(self != NULL);
  Map *map = self;
  Room *location = map->location;
  assert(location != NULL);

  return location-> _(attack)(location, damage);
}

int Map_init(void *self)
{
  // leave the map initialization up to the individual games

  return 1;
}

Object MapProto = {
  .init = Map_init,
  .move = Map_move,
  .attack = Map_attack
};

int process_input(Map *game)
{
  printf("\n> ");
  char ch = getchar();
  assert(ch != EOF);
  assert(getchar() != EOF); // eat ENTER

  int damage = rand() % 4;
  assert(damage >= 0 && damage <= 4);

  switch(ch) {
    case -1:
      printf("Giving up? You suck.\n");
      return 0;
      break;

    case 'n':
      game->_(move)(game, NORTH);
      break;

    case 's':
      game->_(move)(game, SOUTH);
      break;

    case 'e':
      game->_(move)(game, EAST);
      break;

    case 'w':
      game->_(move)(game, WEST);
      break;

    case 'a':
      game->_(attack)(game, damage);
      break;

    case 'l':
      printf("You can go:\n");
      if(game->location->north) printf("NORTH\n");
      if(game->location->south) printf("SOUTH\n");
      if(game->location->east) printf("EAST\n");
      if(game->location->west) printf("WEST\n");
      break;

    default:
      printf("What?: %d\n", ch);
  }

  return 1;
}

int run_game(Map *game) {
  srand(time(NULL));

  printf("You enter the ");
  game->location->_(describe)(game->location);

  while(process_input(game)) {
  }

  return 1;
}



