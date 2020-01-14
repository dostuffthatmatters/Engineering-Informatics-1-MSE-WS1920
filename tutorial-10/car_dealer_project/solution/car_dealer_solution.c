/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 10
************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        }
        if ((i >= 0) && (i+shifts < 20)) {
            dealer->cars[i] = dealer->cars[i+shifts];
        }
    }

    // Releasing car-memory
    free(car);
}




/* Dealer Analysis --------------------------------------------------------------- */

int car_count(struct Dealer *dealer) {
    int count = 0;
    for (int i=0; i<20; i++) {
        if (dealer->cars[i] != 0) {
            count++;
        } else {
            break;
        }
    }
    return count;
}

int total_dealer_value(struct Dealer *dealer) {
    int value = dealer->account_balance;
    for (int i=0; i<20; i++) {
        if (dealer->cars[i] != 0) {
            value += dealer->cars[i]->price;
        } else {
            break;
        }
    }
    return value;
}

int mean_car_price(struct Dealer *dealer) {
    int value = total_dealer_value(dealer) - dealer->account_balance;
    return value/car_count(dealer);
}




/* Customer Initialization ------------------------------------------------------- */

struct Customer *init_customer(int account_balance, char desired_brand[20], char desired_model[20]) {
    struct Customer *customer = calloc(sizeof(struct Customer), 1);
    customer->account_balance = account_balance;
    strcpy(customer->desired_brand, desired_brand);
    strcpy(customer->desired_model, desired_model);
    return customer;
}




/* Customer-Dealer Analysis ------------------------------------------------------ */

int customer_car_rating(struct Customer *customer, struct Car *car) {
    if (customer->account_balance < car->price) {
        return 0;
    } else if (strcmp(customer->desired_brand, car->brand)) {
        return 1;
    } else if (strcmp(customer->desired_model, car->model)) {
        return 2;
    } else {
        return 3;
    }
}

int car_available(struct Dealer *dealer, struct Customer *customer) {
    int best_rating = 0;
    for (int i=0; i<20; i++) {
        if (dealer->cars[i] != 0) {
            int rating = customer_car_rating(customer, dealer->cars[i]);
            if (rating > best_rating) {
                best_rating = rating;
            }
        } else {
            break;
        }
    }
    return best_rating;
}

int buy_car(struct Dealer *dealer, struct Customer *customer) {
    int best_rating = car_available(dealer, customer);
    if (best_rating) {
        struct Car *favorite_car = 0;

        // favorite_car should be the cheapest car at the
        // highest available match-rating
        for (int i=0; i<20; i++) {
            struct Car *car = dealer->cars[i];
            if (car == 0) {
                break;
            }

            if (favorite_car == 0 || car->price < favorite_car->price)  {
                if (customer_car_rating(customer, car) == best_rating) {
                    favorite_car = car;
                }
            }
        }

        // favorite_car has to be determined by now (because
        // car_available did not return 0)
        customer->car = calloc(sizeof(struct Car), 1);
        customer->car->price = favorite_car->price;
        strcpy(customer->car->brand, favorite_car->brand);
        strcpy(customer->car->model, favorite_car->model);

        customer->account_balance -= favorite_car->price;
        dealer->account_balance += favorite_car->price;

        // removes_car also frees the memory of the old struct
        // car - that is why we had to initialize a new car
        remove_car(dealer, favorite_car);

        return 1;
    } else {
        return 0;
    }
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
    for (int i=0; i<20; i++) {
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
    for (int i=0; i<20; i++) {
        if (dealer->cars[i] != 0) {
            free(dealer->cars[i]);
        } else {
            break;
        }
    }
    free(dealer);
}

void free_customer(struct Customer *customer) {
    if (customer->car != 0) {
        free(customer->car);
    }
    free(customer);
}