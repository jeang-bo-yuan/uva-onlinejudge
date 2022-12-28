#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
	uint16_t num_of_players = 0, num_of_rounds = 0, input;
	while (scanf("%hu %hu", &num_of_players, &num_of_rounds) != EOF) {
		uint16_t *points_arr = (uint16_t*) calloc(num_of_players, sizeof(uint16_t));

		while (--num_of_rounds) {  //for (num_of_rounds - 1) times
			for (uint16_t i = 0; i < num_of_players; ++i) {
				scanf("%hu", &input); //input the points he/she earned
				points_arr[i] += input; //add
			}
		}

		uint16_t max_id = 0; //the id of player who earned the most points
		for (uint16_t i = 0; i < num_of_players; ++i) { //for the last round
			scanf("%hu", &input); //input the points he/she earned
			points_arr[i] += input; //add
			max_id = (points_arr[i] >= points_arr[max_id] ? i : max_id);
		}
		printf("%hu\n", max_id + 1);

		free(points_arr);
	}
}
