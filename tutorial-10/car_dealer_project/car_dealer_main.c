
#include <stdio.h>
#include "car_dealer.h"

int main() {

    printf("\n--------------------------------------------------------\n\n");
    printf("INITIALIZING DEALER\n");

    struct Dealer *dealer = init_dealer(100);
    print_dealer(dealer);




    printf("\n--------------------------------------------------------\n\n");
    printf("ADDING ONE CAR\n");

    add_car(dealer, "BMW", "3er", 38);
    print_dealer(dealer);
    printf("Car Count: %d\n", car_count(dealer));
    printf("Dealer Value: %d T€\n", total_dealer_value(dealer));
    printf("Mean Price: %d T€\n\n", mean_car_price(dealer));




    printf("\n--------------------------------------------------------\n\n");
    printf("ADDING TWO MORE CARS\n");

    add_car(dealer, "Audi", "A5", 42);
    add_car(dealer, "BMW", "1er", 26);
    print_dealer(dealer);
    printf("Car Count: %d\n", car_count(dealer));
    printf("Dealer Value: %d T€\n", total_dealer_value(dealer));
    printf("Mean Price: %d T€\n\n", mean_car_price(dealer));




    printf("--------------------------------------------------------\n\n");
    printf("REMOVING THE SECOND CAR - ADDING THREE MORE CARS AFTERWARDS\n");

    if (dealer != 0) {
        remove_car(dealer, dealer->cars[1]);
    }
    print_dealer(dealer);
    printf("Car Count: %d\n", car_count(dealer));
    printf("Dealer Value: %d T€\n", total_dealer_value(dealer));
    printf("Mean Price: %d T€\n\n", mean_car_price(dealer));
    add_car(dealer, "Audi", "A5", 42);
    add_car(dealer, "BMW", "1er", 22);
    add_car(dealer, "Fiat", "500", 15);

    print_dealer(dealer);
    printf("\n");




    printf("--------------------------------------------------------\n\n");
    printf("INITIALIZING THREE CUSTOMERS\n");

    struct Customer *customer_1 = init_customer(28, "BMW", "1er");
    struct Customer *customer_2 = init_customer(33, "BMW", "3er");
    struct Customer *customer_3 = init_customer(22, "Audi", "A5");
    printf("Customer 1 - "); print_customer(customer_1);
    printf("Customer 2 - "); print_customer(customer_2);
    printf("Customer 3 - "); print_customer(customer_3);




    printf("\n--------------------------------------------------------\n\n");

    printf("Customer 1 - car available: %d\n", car_available(dealer, customer_1));
    printf("Customer 2 - car available: %d\n", car_available(dealer, customer_2));
    printf("Customer 3 - car available: %d\n", car_available(dealer, customer_3));




    printf("\n--------------------------------------------------------\n\n");
    printf("CUSTOMER 1 BUYS A CAR\n");

    buy_car(dealer, customer_1);
    print_dealer(dealer);
    print_customer(customer_1);




    printf("\n--------------------------------------------------------\n\n");
    printf("CUSTOMER 2 BUYS A CAR\n");

    buy_car(dealer, customer_2);
    print_dealer(dealer);
    print_customer(customer_2);




    printf("\n--------------------------------------------------------\n\n");
    printf("CUSTOMER 3 BUYS A CAR\n");

    buy_car(dealer, customer_3);
    print_dealer(dealer);
    print_customer(customer_3);




    printf("\n--------------------------------------------------------\n\n");

    free_dealer(dealer);
    free_customer(customer_1);
    free_customer(customer_2);
    free_customer(customer_3);

    return 0;
}
