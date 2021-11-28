#ifndef _ex19_h
#define _ex19_h
#include "object.h"
struct Monster {
		Object proto;
		int hit_points;
};
typedef struct Monster Monster;
int Monster_attack(void* self, int damage);
int Monster_init(void* self);
struct Room {
		Object proto;
		Monster* bad_guy;
		struct Room* east;
		struct Room* west;
		struct Room* north;
		struct Room* south;
};
typedef struct Room Room;
struct Map {
		Object proto;
		struct Room* start;
		struct Room* location;
};
typedef struct Map Map;
void* Map_move(void* self, Direction direction);
int Map_attack(void* self, int damage);
int Map_init(void* self);
#endif
