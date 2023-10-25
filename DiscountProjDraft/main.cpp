#include <iostream>
#include <limits>
#include <stdio.h>
#include <string>
#include <iomanip>

// Function to compute the discount
double applyDiscount(double totalPrice, double discountPercentage) {
  return totalPrice - (totalPrice * (discountPercentage / 100));
}

// Function to get the discount || what you saved
double moneySave(double totalPrice, double discountPercentage) {
  return totalPrice * (discountPercentage / 100);
}

// Main Function
int main() {
  bool ContinueCalculation = true;

  while (ContinueCalculation) {
    // Variables
    double Total, Discount;
    double DiscountedAmount, SavedMoney;
    bool valid = false;

    // Greets the user
    std::cout << "Hello there! Thank you for choosing our DiscCalc. We appreciate your business!\nNow, let's calculate the discount for you." << std::endl;
    std::cout << "///////////////////////////////////////////////////////" << std::endl;

    // This will detect if the user typed the wrong format.
    while (!valid) {
      try {
        // Asks the user for the total price
        std::cout << "What is the total price? ";
        std::cin >> Total;

        // To ask the user to input the right format
        // The throw function throws you to the exception
        if (std::cin.fail()) {
          throw std::invalid_argument("Invalid input. Please enter a valid number.");
        }

        // Asks the user for the Discount
        std::cout << "What is the discount offered? ";
        std::cin >> Discount;

        // To ask the user to input the right format
        if (std::cin.fail()) {
          throw std::invalid_argument("Invalid input. Please enter a valid number.");
        }

        // RETURN TRUE
        valid = true;
      } catch (const std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        valid = false;
        // Clear the error state of the input stream
        std::cin.clear();
        // Discard invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }


    
    /* MATH || MATH || MATH || MATH || MATH || MATH || MATH || MATH || MATH */
    
    // Call the function
    DiscountedAmount = applyDiscount(Total, Discount);
    SavedMoney = moneySave(Total, Discount);

    // Display the discounted price || Money saved || Price comparison
    std::cout << std::fixed << std::setprecision(2) << "///////////////////////////////////////////////////////" << std::endl;
      std::cout << "The total price with the discount is: " << DiscountedAmount << " Pesos." << std::endl; // Add a new line here
    std::cout << "You saved about " << SavedMoney << " Pesos from the original price of: " << Total << std::endl;

    // To continue the calculation or terminate.
    std::cout << "\nDo you want to perform another calculation? (Y/N)" << std::endl;
    // Declare a string for the inputted choice
    std::string choice;
    std::cin >> choice;


    
    /* RETRY || RETRY || RETRY || RETRY || RETRY || RETRY || RETRY */
    
    // Checking if the inputted choice is Y or N or neither
    if (choice == "Y" || choice == "y") {
      std::cout << std::endl;
      ContinueCalculation = true;
    } else if (choice == "N" || choice == "n") {
      std::cout << "Got it! Thank you for using our program." << std::endl;
      ContinueCalculation = false;
    } else {
      std::cout << "Invalid input. Please enter Y or N." << std::endl;
      ContinueCalculation = false;
    }
  }
  return 0;
}
// End of Program