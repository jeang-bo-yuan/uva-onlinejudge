/* blocks problem */
#include <stdio.h>
#include <stdlib.h> //malloc

typedef struct _Block_t {
	unsigned id;
	struct _Block_t* above;
	struct _Block_t* below;
} block_t;

// global variables
block_t* all_blocks;
block_t** block_world;

void call_cmd(char* cmd, block_t* block1_p, char* sub_cmd, block_t* block2_p);

int main() {
	unsigned num_of_blocks = 0;
	scanf("%u", &num_of_blocks);

	// array of ( all the blocks )
	all_blocks = (block_t*) malloc(num_of_blocks * sizeof(block_t));
	// initiate each block
	for (unsigned id = 0; id < num_of_blocks; ++id) {
		all_blocks[id].id = id;
		all_blocks[id].above = NULL;
		all_blocks[id].below = NULL;
	}
	// array that record all the stacks
	// it's an array of block_t*
	block_world = (block_t**) malloc(num_of_blocks * sizeof(block_t*));
	// initiate block_world
	for (unsigned id = 0; id < num_of_blocks; ++id) {
		block_world[id] = &all_blocks[id];
	}

	// read and run command
	char cmd[5] = {'\0'}, sub_cmd[5] = {'\0'};
	unsigned block1 = 0, block2 = 0;
	while (scanf("%4s", cmd) != EOF) {
		if (cmd[0] == 'q') break; //quit

		scanf("%u %4s %u", &block1, sub_cmd, &block2);
		call_cmd(cmd, &all_blocks[block1], sub_cmd, &all_blocks[block2]);
	}

	// print
	for (unsigned id = 0; id < num_of_blocks; ++id) {
		printf("%u:", id);
		for (block_t* bp = block_world[id]; bp != NULL; bp = bp -> above) {
			printf(" %u", bp -> id);
		}
		putchar('\n');
	}

	// end
	free(all_blocks);
	free(block_world);
	return 0;
}

//helper functions for call_cmd
block_t* top_of_stack(block_t*);
void return_blocks_above(block_t*);


void call_cmd(char* cmd, block_t* block1_p, char* sub_cmd, block_t* block2_p) {
	if (block1_p == block2_p) return;
	block_t *top1 = top_of_stack(block1_p), *top2 = top_of_stack(block2_p);
	if (top1 == top2) return;

	if (cmd[0] == 'm') // move
		return_blocks_above(block1_p);

	// remove block1 from stack
	if (block1_p -> below == NULL)
		block_world[block1_p->id] = NULL;
	else
		block1_p -> below -> above = NULL;

	// onto or over
	if (sub_cmd[1] == 'n') {  // onto
		return_blocks_above(block2_p);
		block2_p -> above = block1_p;
		block1_p -> below = block2_p;
	} else {  // over
		top2 -> above = block1_p;
		block1_p -> below = top2;
	}
}

block_t* top_of_stack(block_t* bp) {
	while (bp->above != NULL)
		bp = bp -> above;
	return bp;
}

void return_blocks_above(block_t* bp) {
	block_t* up = bp -> above;
	bp -> above = NULL;
	bp = up; // move up
	while (bp != NULL) {
		up = bp -> above;
		// "return" bp
		bp -> above = NULL;
		bp -> below = NULL;
		block_world[bp->id] = bp;
		// move up
		bp = up;
	}
}
