#include <iostream>
#include <vector>
#include <iomanip>

// Class to represent a menu item
class MenuItem {
public:
    std::string name;
    double price;

    MenuItem(const std::string& n, double p) : name(n), price(p) {}
};

// Class to represent an order
class Order {
public:
    std::vector<MenuItem> items;

    void addItem(const MenuItem& item) {
        items.push_back(item);
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.price;
        }
        return total;
    }
};

// Function to display the menu
void displayMenu(const std::vector<MenuItem>& menu) {
    std::cout << "Menu:\n";
    for (const auto& item : menu) {
        std::cout << item.name << " - $" << std::fixed << std::setprecision(2) << item.price << "\n";
    }
    std::cout << std::endl;
}

// Function to place an order
Order placeOrder(const std::vector<MenuItem>& menu) {
    Order order;

    displayMenu(menu);

    char choice;
    do {
        std::cout << "Enter the item number to add to the order (or 'q' to finish): ";
        std::cin >> choice;

        if (isdigit(choice)) {
            int itemIndex = choice - '0';
            if (itemIndex >= 0 && itemIndex < menu.size()) {
                order.addItem(menu[itemIndex]);
                std::cout << menu[itemIndex].name << " added to the order.\n";
            }
        }
    } while (choice != 'q');

    return order;
}

// Function to generate a bill
void generateBill(const Order& order) {
    std::cout << "\nBill:\n";
    for (const auto& item : order.items) {
        std::cout << item.name << " - $" << std::fixed << std::setprecision(2) << item.price << "\n";
    }

    std::cout << "Total: $" << std::fixed << std::setprecision(2) << order.calculateTotal() << "\n";
}

int main() {
    // Sample menu items
    std::vector<MenuItem> menu = {
        {"Burger", 5.99},
        {"Pizza", 8.99},
        {"Salad", 3.99},
        {"Soda", 1.99}
    };

    // Place an order
    Order customerOrder = placeOrder(menu);

    // Generate and display the bill
    generateBill(customerOrder);

    return 0;
}