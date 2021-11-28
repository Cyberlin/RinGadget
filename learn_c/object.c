#include "object.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Object_destory(void* self)
{
		Object* obj = self;
		if (obj) {
				if (obj->discription)
						free(obj->discription);
				free(obj);
		}
}
void Object_describe(void* self)
{
		Object* obj = self;
		if (obj) {
				printf("%s\n", obj->discription);
		}
}
int Object_init(void* self)
{
		return 1;
}
char* Object_move(void* self, Direction direction)
{
		printf("you cant go this direction\n");
		return NULL;
}
int Obeject_attack(void* self, int damage)
{
		printf("you can't attack this\n ");
		return 1;
}
void* Object_new(size_t size, Object proto, char* discription)
{
		if (!proto.init)
				proto.init = Object_init;
		if (!proto.describe)
				proto.describe = Object_describe;
		if (!proto.destory)
				proto.destory = Object_destory;
		if (!proto.attack)
				proto.attack = Object_attack;
		if (!proto.move)
				proto.move = Object_move;

		Object* e1 = calloc(1, size);
		*e1 = proto;
		e1->discription = strdup(discription);

		return NULL;
}
int main(int argc, char* argv[])
{

		return 0;
}
