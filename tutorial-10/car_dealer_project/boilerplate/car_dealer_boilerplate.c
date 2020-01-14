/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 10
************************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../car_dealer.h"


/* Dealer Initialization/Manipulation -------------------------------------------- */

struct Dealer *init_dealer(int account_balance) {
    struct Dealer *pointer_to_new_dealer = calloc(sizeof(struct Dealer), 1);
    pointer_to_new_dealer->account_balance = account_balance;
    return pointer_to_new_dealer;
}

void add_car(struct Dealer *dealer, char brand[20], char model[20], int price) {
    struct Car *car = calloc(sizeof(struct Car), 1);

    strcpy(car->brand, brand);
    strcpy(car->model, model);
    car->price = price;

    for (int i=0; i<20; i++) {
        if (dealer->cars[i] == 0) {
            dealer->cars[i] = car;
            return;
        }
    }

    // Only reached if car has not been added
    free(car);
}

void remove_car(struct Dealer *dealer, struct Car *car) {
    int shifts = 0;
    for (int i=0; i<20; i++) {
        if (dealer->cars[i] == car) {
            shifts += 1;

            i--;
            // necessary because otherwise the next element will
            // be skipped. Bad scenario: Two or more successive
            // elements all have the same pointer. However duplicate
            // pointer should not be possible when regularly adding
            // cars to the dealer with 'add_car'
        }
        if (i+shifts < 20) {
            dealer->cars[i] = dealer->cars[i+shifts];
        }
    }

    // Releasing car-memory
    free(car);
}




/* Dealer Analysis --------------------------------------------------------------- */

int car_count(struct Dealer *dealer) {
    // YOUR CODE HERE
    return 0;
}

int total_dealer_value(struct Dealer *dealer) {
    // YOUR CODE HERE
    return 0;
}

int mean_car_price(struct Dealer *dealer) {
    // YOUR CODE HERE
    return 0;
}




/* Customer Initialization ------------------------------------------------------- */

struct Customer *init_customer(int account_balance, char desired_brand[20], char desired_model[20]) {
    // YOUR CODE HERE
    return 0;
}




/* Customer-Dealer Analysis ------------------------------------------------------ */

int customer_car_rating(struct Customer *customer, struct Car *car) {
    // YOUR CODE HERE
    return 0;
}

int car_available(struct Dealer *dealer, struct Customer *customer) {
    // YOUR CODE HERE
    return 0;
}

int buy_car(struct Dealer *dealer, struct Customer *customer) {
    // YOUR CODE HERE
    return 0;
}




/* Printing functions ------------------------------------------------------------ */

void print_car(struct Car *car) {
    printf("<Car(");
    printf("brand: %s, ", car->brand);
    printf("model: %s, ", car->model);
    printf("price: %d T€)>\n", car->price);
}

void print_dealer(struct Dealer *dealer) {
    printf("<Dealer(");
    printf("account_balance: %d T€, ", dealer->account_balance);
    printf("cars: [\n");
    for (int i=0; i<100; i++) {
        if (dealer->cars[i] == 0) {
            break;
        } else {
            printf("\t");
            print_car(dealer->cars[i]);
        }
    }
    printf("])>\n");
}

void print_customer(struct Customer *customer) {
    printf("<Customer(");
    printf("account_balance: %d T€, ", customer->account_balance);
    printf("desired_brand: %s, ", customer->desired_brand);
    printf("desired_model: %s, car: [", customer->desired_model);
    if (customer->car != 0) {
        printf("\n\t");
        print_car(customer->car);
    }
    printf("])>\n");
}




/* Memory Deallocation Functions ------------------------------------------------- */

void free_dealer(struct Dealer *dealer) {
    // YOUR CODE HERE
}

void free_customer(struct Customer *customer) {
    // YOUR CODE HERE
}
