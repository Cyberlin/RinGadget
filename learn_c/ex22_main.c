#include "dbg.h"
#include "ex22.h"
const char* MY_NAME = "colin";
void scope_demo(int count)
{
		log_info("the count is %d", count);
		if (count > 10) {
				int count = 10;
				log_info("the count in inner scope is %d", count);
		}
		log_info("the count at exist: %d",count);
		count=3000;
		log_info("the count after exist: %d",count);
}
int main(int argc, char* argv[])
{
		log_info("my name is %s and my age is %d",MY_NAME,get_age());
		set_age(100);
		log_info("my age after assign %d",get_age());
		printf("the SIZE is %d",THE_SIZE);
		THE_SIZE=80;
		log_info("the SIZE after assign %d",THE_SIZE);
		printf("the SIZE after assign %d",THE_SIZE);
		int count =4;
		scope_demo(count);
		scope_demo(count*20);
		log_info("count after scope_demo is %d",count);
		return 0;
}
