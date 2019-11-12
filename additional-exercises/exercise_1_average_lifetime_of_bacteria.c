#include <stdio.h>
#include <stdlib.h>



float random_float(float min, float max) {
    if (max == min) {
        return min;
    } else if (max < min) {
        float new_min = max;
        max = min;
        min = new_min;
    }

    return (max - min) * (rand()/(float)RAND_MAX) + min;
}

char simulation_step(float p) {
    unsigned char t = 0;

    for (; t<255; t++) {
        float r = random_float(0.0, 1.0);
        if (r <= p) {
            break;
        }
    }

    return t;
}

int main() {
    float probability_of_dying = 0;
    int number_of_simulations = 0;
    int accumulated_lifetime = 0;
    float average_lifetime;

    // Important: This Data input is by no means error proof
    // -> e.g. if you enter letter instead of numbers

    printf("Possibility of dying in a particular time step? (Enter numbers in [0.0, 1.0])\n");
    scanf("%f", &probability_of_dying);
    printf("You entered: %.1f percent.\n", (probability_of_dying * 100));

    printf("How many simulations?\n");
    scanf("%d", &number_of_simulations);

    for (int i=0; i<number_of_simulations; i++) {
        accumulated_lifetime += simulation_step(probability_of_dying);
    }

    average_lifetime = accumulated_lifetime / (number_of_simulations * 1.0);

    printf("The average bacterium survives %.3f time steps.", average_lifetime);
}
