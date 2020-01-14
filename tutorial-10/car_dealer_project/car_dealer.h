/************************************************************************************
* Author: Moritz Makowski
* Lecture: MSE Informatik I - WS19/20
* Session: Tutorial 10
************************************************************************************/


#ifndef TUTORIAL_REPOSITORY_CAR_DEALER_H
#define TUTORIAL_REPOSITORY_CAR_DEALER_H


/* Structs ----------------------------------------------------------------------- */

struct Car {
    char brand[20];
    char model[20];

    // The price at which a dealers
    // sells this car to a customer
    int price;
};

struct Dealer {
    int account_balance;
    struct Car *cars[20];
};

struct Customer {
    char desired_brand[20];
    char desired_model[20];
    int account_balance;
    struct Car *car;
};




/* Dealer Initialization/Manipulation -------------------------------------------- */

/**
 * Initializes a car dealer (malloc/calloc) with an empty list
 * cars (only NULL pointers) and the given account_balance.
 *
 * @param account_balance
 *
 * @return Pointer to newly created struct
 */
struct Dealer *init_dealer(int account_balance);

/**
 * Initializes an instance of struct Car (malloc/calloc) and adds
 * the pointer to that instance to the dealer's list cars. The
 * dealers account_balance is ignored.
 *
 * @param dealer
 * @param brand
 * @param model
 * @param price
 */
void add_car(struct Dealer *dealer, char brand[20], char model[20], int price);

/**
 * Removes a given car instance from a dealers inventory. The
 * methods frees up the cars memory and shifts all cars inside
 * the dealers car list so that there is no null-pointer
 * inbetween two cars inside the array.
 *
 * @param dealer
 * @param car
 */
void remove_car(struct Dealer *dealer, struct Car *car);




/* Dealer Analysis --------------------------------------------------------------- */

/**
 * @param dealer
 *
 * @return The number of cars inside the dealers inventory
 */
int car_count(struct Dealer *dealer);

/**
 * @param dealer
 *
 * @return A dealers account_balance if he were to sell all of his cars
 */
int total_dealer_value(struct Dealer *dealer);

/**
 * @param dealer
 *
 * @return The average selling price for the cars of a given dealer
 */
int mean_car_price(struct Dealer *dealer);




/* Customer Initialization ------------------------------------------------------- */

/**
 * Initializes a customer (malloc/calloc) with a null-pointer as its car.
 *
 * @param account_balance
 * @param desired_brand
 * @param desired_model
 *
 * @return Pointer to newly created struct
 */
struct Customer *init_customer(int account_balance, char desired_brand[20], char desired_model[20]);




/* Customer-Dealer Analysis ------------------------------------------------------ */

/**
 * Returns the highest possible match rating of a customer-car combination.
 * 3 = model and brand matches and the customer can afford the car
 * 2 = brand matches and the customer can afford the car
 * 1 = The customer can afford the car
 * 0 = The customer can't afford the car
 *
 * @param customer
 * @param car
 *
 * @return Match rating of that customer-car combination
 */
int customer_car_rating(struct Customer *customer, struct Car *car);

/**
 * Returns the highest possible match rating for any car belonging
 * to a specific dealer regarding a given customer.
 *
 * @param dealer
 * @param customer
 *
 * @return Match rating of that customer-dealer combination
 */
int car_available(struct Dealer *dealer, struct Customer *customer);

/**
 * Transfers the most favorable car from a dealer to a customer
 * (most favorable = The cheapest car among the car with the
 * (same) highest match rating). Update The customers car-pointer
 * as well as the dealers cars-list as well as both account balances.
 *
 * @param dealer
 * @param customer
 *
 * @return The match rating of the car being bought.
 */
int buy_car(struct Dealer *dealer, struct Customer *customer);




/* Printing Functions ------------------------------------------------------------ */

/**
 * Prints out a car in a representational format.
 *
 * @param car
 */
void print_car(struct Car *car);

/**
 * Prints out a dealer in a representational format. May reuse print_car.
 *
 * @param dealer
 */
void print_dealer(struct Dealer *dealer);

/**
 * Prints out a customer in a representational format. May reuse print_car.
 *
 * @param customer
 */
void print_customer(struct Customer *customer);




/* Memory Deallocation Functions ------------------------------------------------- */

/**
 * Frees up the memory of a dealer and all its contents.
 *
 * @param dealer
 */
void free_dealer(struct Dealer *dealer);

/**
 * Free up the memory of a customer and all its contents.
 *
 * @param customer
 */
void free_customer(struct Customer *customer);


#endif
