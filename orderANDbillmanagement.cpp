#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Base class for common attributes and behaviors
class RestaurantEntity {
private:
    string name;

public:
    // Constructor
    RestaurantEntity(string entityName) : name(entityName) {}

    // Getter for name
    string getName() const {
        return name;
    }

    // Virtual function to display entity details
    virtual void displayDetails() const {
        cout << "Entity: " << getName() << endl;
    }
};

// Derived class for MenuItem
class MenuItem : public RestaurantEntity {
private:
    double price;

public:
    // Constructor
    MenuItem(string itemName, double itemPrice) : RestaurantEntity(itemName), price(itemPrice) {}

    // Getter for price
    double getPrice() const {
        return price;
    }

    // Override displayDetails for MenuItem
    void displayDetails() const override {
        cout << "Menu Item: " << getName() << " - $" << fixed << setprecision(2) << getPrice() << endl;
    }
};

// Derived class for Menu
class Menu : public RestaurantEntity {
private:
    vector<MenuItem> items;

public:
    // Constructor
    Menu(string entityName) : RestaurantEntity(entityName) {}

    // Function to display the menu
    void displayMenu() const {
        cout << "Menu:\n";
        for (const MenuItem& item : items) {
            item.displayDetails();
        }
        cout << endl;
    }

    // Add item to menu
    void addItem(const MenuItem& item) {
        items.push_back(item);
    }

    // Getter for items
    const vector<MenuItem>& getItems() const {
        return items;
    }
};

// Derived class for Order
class Order : public RestaurantEntity {
private:
    vector<MenuItem> items;

public:
    // Constructor
    Order(string entityName) : RestaurantEntity(entityName) {}

    // Function to take customer orders
    void takeOrder(const Menu& menu) {
        string itemName;
        char addMore;

        do {
            cout << "Enter the item name to add to your order: ";
            cin >> itemName;

            // Search for the item in the menu
            for (const MenuItem& item : menu.getItems()) {
                if (item.getName() == itemName) {
                    items.push_back(item);
                    break;
                }
            }

            cout << "Do you want to add more items? (y/n): ";
            cin >> addMore;

        } while (addMore == 'y' || addMore == 'Y');
    }

    // Getter for items
    const vector<MenuItem>& getItems() const {
        return items;
    }
};

// Derived class for Bill
class Bill : public RestaurantEntity {
private:
    vector<MenuItem> items;

public:
    // Constructor
    Bill(string entityName) : RestaurantEntity(entityName) {}

    // Function to generate and display the bill
    void generateBill(const Order& order) const {
        double total = 0.0;

        cout << "Your Order:\n";
        for (const MenuItem& item : order.getItems()) {
            item.displayDetails();
            total += item.getPrice();
        }

        cout << "\nTotal Bill: $" << fixed << setprecision(2) << total << endl;
    }
};

// Derived class for Reservation
class Reservation : public RestaurantEntity {
private:
    string reservationDate;
    int tableNumber;

public:
    // Constructor
    Reservation(string name, string date, int table) : RestaurantEntity(name), reservationDate(date), tableNumber(table) {}

    // Getter for reservationDate
    string getReservationDate() const {
        return reservationDate;
    }

    // Getter for tableNumber
    int getTableNumber() const {
        return tableNumber;
    }

    // Override displayDetails for Reservation
    void displayDetails() const override {
        cout << "Reservation Details:\n";
        cout << "Name: " << getName() << "\nDate: " << getReservationDate() << "\nTable: " << getTableNumber() << endl;
    }
};

// Derived class for Table
class Table : public RestaurantEntity {
private:
    int capacity;

public:
    // Constructor
    Table(string name, int tableCapacity) : RestaurantEntity(name), capacity(tableCapacity) {}

    // Getter for capacity
    int getCapacity() const {
        return capacity;
    }

    // Override displayDetails for Table
    void displayDetails() const override {
        cout << "Table Details:\n";
        cout << "Name: " << getName() << "\nCapacity: " << getCapacity() << endl;
    }
};

// Derived class for Waiter
class Waiter : public RestaurantEntity {
private:
    int employeeId;

public:
    // Constructor
    Waiter(string name, int id) : RestaurantEntity(name), employeeId(id) {}

    // Getter for employeeId
    int getEmployeeId() const {
        return employeeId;
    }

    // Override displayDetails for Waiter
    void displayDetails() const override {
        cout << "Waiter Details:\n";
        cout << "Name: " << getName() << "\nEmployee ID: " << getEmployeeId() << endl;
    }
};

// Derived class for Chef
class Chef : public RestaurantEntity {
private:
    int employeeId;

public:
    // Constructor
    Chef(string name, int id) : RestaurantEntity(name), employeeId(id) {}

    // Getter for employeeId
    int getEmployeeId() const {
        return employeeId;
    }

    // Override displayDetails for Chef
    void displayDetails() const override {
        cout << "Chef Details:\n";
        cout << "Name: " << getName() << "\nEmployee ID: " << getEmployeeId() << endl;
    }
};

// Derived class for Customer
class Customer : public RestaurantEntity {
private:
    int customerId;

public:
    // Constructor
    Customer(string name, int id) : RestaurantEntity(name), customerId(id) {}

    // Getter for customerId
    int getCustomerId() const {
        return customerId;
    }

    // Override displayDetails for Customer
    void displayDetails() const override {
        cout << "Customer Details:\n";
        cout << "Name: " << getName() << "\nCustomer ID: " << getCustomerId() << endl;
    }
};

int main() {
    // Initialize the menu
    Menu menu("Our Restaurant");
    menu.addItem(MenuItem("Burger", 5.99));
    menu.addItem(MenuItem("Pizza", 8.99));
    menu.addItem(MenuItem("Salad", 3.99));
    menu.addItem(MenuItem("Drink", 1.99));

    // Display the menu
    menu.displayMenu();

    // Take customer orders
    Order order("Customer Order");
    order.takeOrder(menu);

    // Generate and display the bill
    Bill bill("Customer Bill");
    bill.generateBill(order);

    // Initialize a reservation
    Reservation reservation("KALI", "2023-01-01", 1);

    // Display the reservation details
    reservation.displayDetails();

    // Initialize a table
    Table table("Table 1", 4);

    // Display table details
    table.displayDetails();

    // Initialize a waiter
    Waiter waiter("SHRIKANT", 101);

    // Display waiter details
    waiter.displayDetails();

    // Initialize a chef
    Chef chef("Chef SOHAIB", 201);

    // Display chef details
    chef.displayDetails();

    // Initialize a customer
    Customer customer("DHRUV", 301);

    // Display customer details
    customer.displayDetails();

    return 0;
}
