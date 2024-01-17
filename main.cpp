#include <iostream>
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main() {
    double balance = 0;
    int choice = 0;

    do{
        std::cout << "-----------------------" << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << "(1) Show Balance" << std::endl;
        std::cout << "(2) Deposit Money" << std::endl;
        std::cout << "(3) Withdraw Money" << std::endl;
        std::cout << "(4) EXIT" << std::endl;
        std::cin >> choice;

        switch(choice){
            case 1:
                showBalance(balance);
                break;

            case 2:
                balance += deposit();
                break;

            case 3:
                balance -= withdraw(balance);
                break;

            case 4:
                std::cout << "\nThanks for visiting!" << std::endl;
                break;

            default:
                std::cout << "Error Input!" << std::endl;
        }

        std::cout << "\n";

    } while(choice != 4);

    return 0;
}

void showBalance(double balance) {
    std::cout << "Balance: $" << balance << std::setprecision(2) << std::fixed << std::endl;
}

double deposit() {
    double amount;
    std::cout << "Enter the amount to deposit: " << std::endl;
    std::cin >> amount;

    std::cout << "($" << amount << std::setprecision(2) << std::fixed << ") " << "The deposit is successful!" << std::endl;

    return amount;
}

double withdraw(double balance) {
    double amount;
    std::cout << "Balance: $" << balance << std::setprecision(2) << std::fixed << std::endl;
    std::cout << "Enter the amount to withdraw: "<< std::endl;
    std::cin >> amount;

    if(amount < 0){
        std::cout << "Amount should not be less than 0";
        return 0;
    } else if(balance >= amount){
        std::cout << "($" << amount << std::setprecision(2) << std::fixed << ") " << "The withdraw is successful!" << std::endl;
        return amount;
    } else {
        std::cout << "Your balance is not enough!" << std::endl;
        return 0;
    }
}