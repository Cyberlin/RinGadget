#ifndef _object_h
#define _object_h
#include <stddef.h>
typedef enum {
		WEST,
		EAST,
		NORTH,
		SOUTH
} Direction;

typedef struct {
		char* discription;
		int (*init)(void* self);
		void (*destory)(void* self);
		void (*describe)(void* self);
		int (*attack)(void* self, int damage);
		void* (*move)(void* self, Direction direction);
} Object;
int Object_init(void* self);
void Object_destory(void* self);
void Object_describe(void* self);
char* Object_move(void* self, Direction direction);
int Object_attack(void* self, int damage);
void* Object_new(size_t size, Object proto, char* discription);
//T##Proto means attaching the Proto to the T(the arg you give)
#define NEW(T, N) Object_new(sizeof(T), T##Proto, N);
//_(N)just a sugar for less typing.i.e:obj->proto.discription==obj->_discription
#define _(N) proto.N
#endif
