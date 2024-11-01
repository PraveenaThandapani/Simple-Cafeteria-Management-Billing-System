#include <stdio.h>
#include <time.h>

// Function to display the morning menu
void displayMorningMenu() {
    printf("------Morning Menu------\n\n");
    printf("1. Coffee - ₹12.50\n");
    printf("2. Tea - ₹10.00\n");
    printf("3. Breakfast Sandwich - ₹35.00\n");
    printf("4. Muffin - ₹55.50\n");
    printf("5. Exit\n");
}

// Function to display the evening menu
void displayEveningMenu() {
    printf("------Evening Menu------\n\n");
    printf("1. Coffee - ₹12.50\n");
    printf("2. Tea - ₹10.00\n");
    printf("3. Chicken Sandwich - ₹90.00\n");
    printf("4. Cake - ₹30.50\n");
    printf("5. Exit\n");
}

// Function to calculate the total bill
float calculateTotal(int coffeeQty, int teaQty, int sandwichQty, int cakeQty, float coffeePrice, float teaPrice, float sandwichPrice, float cakePrice) {
    return (coffeeQty * coffeePrice) + (teaQty * teaPrice) + (sandwichQty * sandwichPrice) + (cakeQty * cakePrice);
}

int main() {
    int choice, coffeeQty = 0, teaQty = 0, sandwichQty = 0, cakeQty = 0;
    float coffeePrice, teaPrice, sandwichPrice, cakePrice;

    printf("Welcome to the Coffee Shop Billing Program!\n");

    while (1) {
        // Get current time
        time_t now;
        struct tm *local;
        now = time(NULL);
        local = gmtime(&now);  // Use GMT time
        local->tm_hour = (local->tm_hour + 5) % 24;  // Adjust for IST (5 hours ahead)
        local->tm_min = (local->tm_min + 30) % 60;   // Adjust for IST (30 minutes ahead)

        int hour = local->tm_hour;

        // Set menu based on the time of the day
        if (hour >= 6 && hour < 12) {
            // Morning menu
            coffeePrice = 12.50;
            teaPrice = 10.00;
            sandwichPrice = 35.00;
            cakePrice = 55.50;

            while (1) {
                displayMorningMenu();
                printf("Enter your choice (1-5): ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter the quantity of coffee: ");
                        scanf("%d", &coffeeQty);
                        break;
                    case 2:
                        printf("Enter the quantity of tea: ");
                        scanf("%d", &teaQty);
                        break;
                    case 3:
                        printf("Enter the quantity of breakfast sandwich: ");
                        scanf("%d", &sandwichQty);
                        break;
                    case 4:
                        printf("Enter the quantity of muffin: ");
                        scanf("%d", &cakeQty);
                        break;
                    case 5:
                        printf("Thank you for ordering!\n");
                        goto end;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
        } else {
            // Evening menu
            coffeePrice = 12.50;
            teaPrice = 10.00;
            sandwichPrice = 90.00;
            cakePrice = 30.50;

            while (1) {
                displayEveningMenu();
                printf("Enter your choice (1-5): ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter the quantity of coffee: ");
                        scanf("%d", &coffeeQty);
                        break;
                    case 2:
                        printf("Enter the quantity of tea: ");
                        scanf("%d", &teaQty);
                        break;
                    case 3:
                        printf("Enter the quantity of chicken sandwich: ");
                        scanf("%d", &sandwichQty);
                        break;
                    case 4:
                        printf("Enter the quantity of cake: ");
                        scanf("%d", &cakeQty);
                        break;
                    case 5:
                        printf("Thank you for ordering!\n");
                        goto end;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
        }

    end:
        // Calculate the total bill and display
        float totalBill = calculateTotal(coffeeQty, teaQty, sandwichQty, cakeQty, coffeePrice, teaPrice, sandwichPrice, cakePrice);
        float gst = totalBill * 0.05;

        char customerName[100];
        printf("Enter customer name: ");
        scanf("%s", customerName);
        char p[100];
        printf("Enter payment method: ");
        scanf("%s", p);

        printf("\n\n***** Bill Receipt *****\n");
        printf("Customer Name: %s\n", customerName);
        printf("Payment mode: %s\n", p);
        printf("Time: %02d:%02d\n", local->tm_hour, local->tm_min);
        printf("Items bill: %.2f\n", totalBill);
        printf("GST: %.2f\n", gst);
        printf("Total bill: %.2f\n", totalBill + gst);
        printf("**************\n");

        // Reset quantities for the next bill
        coffeeQty = 0;
        teaQty = 0;
        sandwichQty = 0;
        cakeQty = 0;

        // Ask the user if they want to continue or exit
        printf("Do you want to continue with the next bill? (y/n): ");
        char nextBillChoice;
        scanf(" %c", &nextBillChoice);

        if (nextBillChoice == 'n' || nextBillChoice == 'N') {
            printf("Thank you. Have a great day!\n");
            break; // Exit the loop and end the program
        }
    }

    return 0;
}
