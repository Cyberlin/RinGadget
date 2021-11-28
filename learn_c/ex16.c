#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
struct Person {
		char* name;
		int age;
		int height;
		int weight;
};
struct Person person_create(char* name, int age, int height, int weight)
{
		struct Person who; 
		who.name = name;
		who.age = age;
		who.height = height;
		who.weight = weight;
		return who;
}
void person_destroy(struct Person* who)
{
		assert(who != NULL);
		free(who->name);
		free(who);
}
void person_print(struct Person who)
{
		printf("\tname is :%s \n", who.name);
		printf("\tage is :%d \n", who.age);
}
int main(int argc, char* argv[])
{
		struct Person colin = person_create("colin", 19, 183, 78);
		person_print(colin);
		return 0;
}
