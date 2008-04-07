/*
	This program is used to generate the memory data for the time-memory tradeoff attacks
	Used parameters:
	Key	= 4F 4E 4D 49 4B 52
	Serial	= 49 43 57 69
	Random	= 65 6E 45 72
	
	"D7 23 7F CE 8C D0 37 A9 57 49 C1 E6 48 00 8A B6"
*/	

#include <stdio.h>
#include "hitag2.c"

int main()
{
	// Prepare the memory
	memory_setup();
}	

int memory_setup()
{
	u64 state = 0;
			
	u64 iterations = 65536;	// 268435456 = 2^28
	u64 i = 0;
	
	u64 prefix = 0;
	
	FILE *fp;
	
	// Initialize the state. This can be done also by randomly assigning a value to the state.
	
	state = hitag2_init (rev64 (0x524B494D4E4FULL), rev32 (0x69574349), rev32 (0x72456E65));
	printf("Initial State: %llx\n", state);
	
	fp = fopen("memory.txt","w"); 
	
	for(i = 0; i < iterations; i++)
	{
		//call hitag function - get 48 bits prefix (in u64 format)
		prefix = hitag2_prefix(&state);
		
		//save prefix and state in the file
		fprintf(fp, "%llx %llx\n", prefix, state);
	
		state = state + 1048528;
	}
	fclose(fp);
}


u64 find_state(u64 prefix)
{


}
