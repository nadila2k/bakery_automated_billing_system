#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <chrono>
#include <iomanip>

using namespace std;

// Global variables
const string &globalCompanyName = "Amber bakery";
const int &DEFAULT = 0;
const int &RED = 1;
const int &GREEN = 2;
const int &BLUE = 3;
const int &ORANGE = 4;
const int &PURPLE = 5;
const int &YELLOW = 6;
const string  &admin = "Administrator";
const string  &sysUser = "SalesPerson";
const string  &Customer = "Customer";

// Structs
struct User
{
    int id;
    string userName;
    string password;
    int role;
};

struct AuthUser
{
    string userId;
    string userName;
    int role;
    string roleName;
};

struct Item
{
    int id;
    string name;
    double price;
    int quantity;
};

struct Order {
    int id;
    int item_id;
    string name;
    double price;
    int quantity;
};

struct Sale {
    int id;
    int order_id;
    string date;
    double total_price;
};

struct FilesNextId
{
    int user_id;
    int item_id;
    int order_id;
    int sale_id;
};


// Struct objects
AuthUser authUser;
User userRecord;
Item itemRecord;
Order orderRecord;
Sale saleRecord;
FilesNextId filesNextId;

// Vector objects
vector<User> usersVector;
vector<Item> itemsVector;
vector<Order> orderVector;
vector<Order> allOrderVector;
vector<Sale> salesVector;

// Method declartion
void welcomeMenu();
void handleLogin();
bool handleAuth(const string &username, const string &password);
void mainMenu();
bool getAllUser();
bool getAllItem();
bool getAllOdrder();
bool getAllSeles();
void viewAllUser();
void viewAllItem();
void viewAllOrders();
void viewAllseles();
void displayFoundItem(const Item &foundItem);
void viewCurrentOrder();
void CreateItem();
void searchItemUpdated(Item* &foundItem);
bool savesales(const double &totalPrice);
void createOdrder();
bool addItemToOder();
bool saveOder();
void searchitem();
Item* serachByName(const string &name);
Item* getItemById(const int &id);
void clearScreen();
void terminalFontColor(const int &color);
void PrintHeader(const bool &auth, const string &title);
void backToMainMenu();
string handleDateFormat();
void viewCompanyDetails();
void logout();
void bakeryPackages ();

int main()
{
    bool getAllUserStatus, getAllItemStatus, getAllOdrderStatus, handleFetchSalesStatus;

    // Application bootstrap methods
    getAllUserStatus = getAllUser();
    getAllItemStatus = getAllItem();
    getAllOdrderStatus = getAllOdrder();
    handleFetchSalesStatus = getAllSeles();

    if(getAllItemStatus && getAllItemStatus && getAllOdrderStatus && handleFetchSalesStatus) {
        PrintHeader(false, "Welcome");
        terminalFontColor(GREEN);
        welcomeMenu();
        terminalFontColor(DEFAULT);
    }else {
        cerr << "Error encountered application going to sleep..." << endl;
    }

    return 0;
}


// Menus Methods-------------------------------------------------------start-----------------------------------------

void welcomeMenu()
{
    cout << "                                         " <<   "========================================" << endl;
    cout << "                                         " <<   "||          Main Menu                 ||" << endl;
    cout << "                                         " <<   "========================================" << endl;
    cout << "                                         " <<   "|| 1. Login                           ||" << endl;
    cout << "                                         " <<   "|| 2. Exit                            ||" << endl;
    cout << "                                         " <<   "========================================" << endl;

    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
        case 1:
            clearScreen();
            handleLogin();
            break;

        case 2:
            cout << "Exit menu";
            break;

        default:
            cout << "default";
            break;
    }

    cout << "\n";
}

void handleLogin()
{
    string username;
    string password;

    PrintHeader(false, "Login");

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    clearScreen();

    if (handleAuth(username, password)) {
        cout << "Successfully logged In" << endl;
        mainMenu();
    }
    else {
        cout << "Login failed. Please check your credentials." << endl;
        handleLogin();
    }

}
void logout(){
cout << logout << endl;
 handleLogin();

}

bool handleAuth(const string &username, const string &password)
{
    for (const User &user : usersVector) {
        if (username == user.userName && password == user.password) {
            authUser.userId = user.id;
            authUser.userName = user.userName;
            authUser.role = user.role;
            authUser.roleName = authUser.role == 1 ? admin : (authUser.role == 2 ? sysUser : Customer);
            return true;
        }
    }
    return false;
}

void mainMenu()
{
    PrintHeader(true, "Main Menu");
       terminalFontColor(PURPLE);
        cout <<"                                        " <<"____________________________________" << endl;
        cout <<"                                        " <<"| Press 1 |for View Items Details  |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;


    if (authUser.role == 1) {
        // Admin menu items
        cout <<"                                        " <<"| Press 2 |for View Order Details  |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| Press 3 |for View Sales Details  |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| Press 4 |for Create New Item     |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| Press 5 |for Create New Order    |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| Press 6 |for  Manage item        |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| press 7 |for View Package        |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| Press 8 |for View Company Details|" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| Press 9 |for Logout              |" << endl;
        cout <<"                                        " <<"____________________________________" << endl;
    }
    else if (authUser.role == 2) {
        // System user menu items
        cout <<"                                        " <<"| Press 2 |for View Order Details  |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| Press 3 |for View Sales Details  |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| Press 9 |for Logout              |" << endl;
        cout <<"                                        " <<"____________________________________" << endl;
    }
    else if (authUser.role == 3) {
        // Customer menu items
        cout <<"                                        " <<"| Press 5 |for Create New Order    |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| press 7 |for View Package        |" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| Press 8 |for View Company Details|" << endl;
        cout <<"                                        " <<"|                                  |" << endl;
        cout <<"                                        " <<"| Press 9 |for Logout              |" << endl;
        cout <<"                                        " <<"____________________________________" << endl;
    }

    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    clearScreen();

    switch (choice)
    {
        case 1:
            PrintHeader(true, "Sub Menu | View All Items");
            terminalFontColor(YELLOW);
            viewAllItem();
            backToMainMenu();
            break;

        case 2:
            if (authUser.role == 1 || authUser.role == 2) {
                PrintHeader(true, "Sub Menu | View All Orders");
                terminalFontColor(BLUE);
                viewAllOrders();
                backToMainMenu();
            }
            else {
                cerr << "Invalid choice for your role." << endl;
                backToMainMenu();
            }
            break;

        case 3:
            if (authUser.role == 1 || authUser.role == 2) {
                PrintHeader(true, "Sub Menu | View All Sales");
                terminalFontColor(GREEN);
                viewAllseles();
                backToMainMenu();
            }
            else {
                cerr << "Invalid choice for your role." << endl;
                backToMainMenu();
            }
            break;

        case 4:
            if (authUser.role == 1){
                terminalFontColor(RED);
                CreateItem();
                backToMainMenu();
            }
            else {
                cerr << "Invalid choice for your role." << endl;
                backToMainMenu();
            }
            break;

        case 5:
            if (authUser.role == 1 || authUser.role == 2 || authUser.role == 3){
                orderVector.clear();
                salesVector.clear();
                terminalFontColor(ORANGE);
                createOdrder();
                getAllOdrder();
                getAllSeles();
                backToMainMenu();
            }
            else {
                cerr << "Invalid choice for your role." << endl;
                backToMainMenu();
            }
            break;

        case 6:
            if (authUser.role == 1) {
                terminalFontColor(GREEN);
                searchitem();
                backToMainMenu();
            }
            else {
                cerr << "Invalid choice for your role." << endl;
                backToMainMenu();
            }
            break;

        case 7 :
             PrintHeader(true, "Sub Menu | View Package");
             terminalFontColor(GREEN);
             bakeryPackages ();
              backToMainMenu();


        case 8:

                PrintHeader(true, "Sub Menu | Bakery Details");
                terminalFontColor(PURPLE);
                viewCompanyDetails();
                backToMainMenu();

            break;

        case 9:

            logout();
            break;

        default:
            cout << "Invalid choice." << endl;
            mainMenu();
            break;
    }
}
// Menus Methods-------------------------------------------------------end-------------------------------------------


// Fetch Methods-------------------------------------------------------start-----------------------------------------

bool getAllUser()
{
    // Clear vector
    usersVector.clear();

    // Read items file
    ifstream userFile("users_data.dat");
    if (!userFile.is_open())
    {
        cerr << "Error: Unable to open the user data userFile." << endl;
    }

    //Loop userFile data and put data into users vector
    string recordLine;
    while (getline(userFile, recordLine)) {
        istringstream ss(recordLine);
        char comma;
        if (ss >> userRecord.id >> comma && getline(ss, userRecord.userName, ',') && getline(ss, userRecord.password, ',') && ss >> userRecord.role) {
            usersVector.push_back(userRecord);
        }
    }

    userFile.close();

    // Return true false based on vector status
    if (usersVector.empty()) {
        filesNextId.user_id = 1;
        return false;
    } else {
        // Update user file last id
        filesNextId.user_id = usersVector.size() + 1;
        return true;
    }

}

bool getAllItem()
{
    // Clear vector
    itemsVector.clear();

    // Read items file
    ifstream itemsFile("items_data.dat");
    if (!itemsFile.is_open())
    {
        cerr << "Error: Unable to open the items file." << endl;
    }

    // Loop itemsFile data and put data into items vector
    string recordLine;
    while (getline(itemsFile, recordLine))
    {
        stringstream ss(recordLine);
        char comma;
        if (ss >> itemRecord.id >> comma && getline(ss, itemRecord.name, ',') &&  ss >> itemRecord.price >> comma && ss >> itemRecord.quantity) {
            itemsVector.push_back(itemRecord);
        }
    }

    itemsFile.close();

    // return true false based on vector status
    if (itemsVector.empty()) {
        filesNextId.item_id = 1;
        return false;
    } else {
        // Update item file last id
        filesNextId.item_id = itemsVector.size() + 1;
        return true;
    }
}

bool getAllOdrder()
{
    // Clear vector
    allOrderVector.clear();

    // Read items file
    ifstream ordersFile("orders_data.dat");
    if (!ordersFile.is_open())
    {
        cerr << "Error: Unable to open the orders file." << endl;
    }

    // Loop ordersFile data and put data into items vector
    int lastLoopedId;
    string recordLine;
    while (getline(ordersFile, recordLine))
    {
        stringstream ss(recordLine);
        char comma;
        if (ss >> orderRecord.id >> comma && ss >> orderRecord.item_id >> comma && getline(ss, orderRecord.name, ',') &&  ss >> orderRecord.price >> comma && ss >> orderRecord.quantity) {
            allOrderVector.push_back(orderRecord);
            lastLoopedId = orderRecord.id;
        }
    }

    ordersFile.close();

    // return true false based on vector status
    if (allOrderVector.empty()) {
        filesNextId.order_id = 1;
        return false;
    } else {
        // Update item file last id
        filesNextId.order_id = lastLoopedId + 1;
        return true;
    }
}

bool getAllSeles()
{
    // Clear vector
    salesVector.clear();

    // Read items file
    ifstream saleFile("sales_data.dat");
    if (!saleFile.is_open())
    {
        cerr << "Error: Unable to open the sales file." << endl;
    }

    // Loop saleFile data and put data into items vector
    string recordLine;
    while (getline(saleFile, recordLine))
    {
        stringstream ss(recordLine);
        char comma;
        if (ss >> saleRecord.id >> comma && ss >> saleRecord.order_id >> comma && getline(ss, saleRecord.date, ',') &&  ss >> saleRecord.total_price) {
            salesVector.push_back(saleRecord);
        }
    }

    saleFile.close();

    // return true false based on vector status
    if (salesVector.empty()) {
        filesNextId.sale_id = 1;
        return false;
    } else {
        // Update item file last id
        filesNextId.sale_id = salesVector.size() + 1;
        return true;
    }
}
// Fetch Methods-------------------------------------------------------end-------------------------------------------


// View Methods-------------------------------------------------------start-----------------------------------------

void viewAllUser()
{
    // Users table headers
    cout << left << setw(5) << "ID" << setw(20) << "Username" << setw(10) << "Password" << endl;
    // Users table hr line
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    // Loop UsersVector and list as table body
    for (const User &user : usersVector) {
        cout << left << setw(5) << user.id << setw(20) << user.userName << setw(10) << fixed << setprecision(2) << user.password << endl;
    }
}

void viewAllItem()
{
    // Items table headers
    cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
    // Items table hr line
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    // Loop itemsVector and list as table body
    for (const Item &item : itemsVector) {
        cout << left << setw(5) << item.id << setw(20) << item.name << setw(10) << fixed << setprecision(2) << item.price << setw(10) << item.quantity << endl;
    }
}

void viewAllOrders() {
    // Orders table headers
    std::cout << std::left << std::setw(5) << "ID" << std::setw(10) << "Item ID" << std::setw(20) << "Name" << std::setw(10) << "Price" << std::setw(10) << "Quantity" << std::setw(15) << "Total" << std::endl;
    // Orders table hr line
    std::cout << std::setfill('-') << std::setw(70) << "-" << std::setfill(' ') << std::endl;

    int currentOrderId = -1;
    double currentOrderTotal = 0.0;

    // Loop through the orders vector and list as a table body
    for (const Order& order : allOrderVector) {
        if (order.id != currentOrderId) {
            // Print total for the previous order (if there was one)
            if (currentOrderId != -1) {
                std::cout << std::left << std::setw(55) << "Order Total: " << std::fixed << std::setprecision(2) << currentOrderTotal << std::endl;
                std::cout << std::setfill('-') << std::setw(70) << "-" << std::setfill(' ') << std::endl;
            }

            // Start a new order
            currentOrderId = order.id;
            currentOrderTotal = 0.0;
        }

        double itemTotal = order.price * order.quantity;
        currentOrderTotal += itemTotal;

        std::cout << std::left << std::setw(5) << order.id << std::setw(10) << order.item_id << std::setw(20) << order.name << std::setw(10) << std::fixed << std::setprecision(2) << order.price << std::setw(10) << order.quantity << std::setw(15) << itemTotal << std::endl;
    }

    // Print total for the last order
    if (currentOrderId != -1) {
        std::cout << std::left << std::setw(55) << "Order Total: " << std::fixed << std::setprecision(2) << currentOrderTotal << std::endl;
    }
}


void viewCurrentOrder() {
    // Orders table headers
    std::cout << std::left << std::setw(5) << "ID" << std::setw(10) << "Item ID" << std::setw(20) << "Name" << std::setw(10) << "Price" << std::setw(10) << "Quantity" << std::endl;
    // Orders table hr line
    std::cout << std::setfill('-') << std::setw(55) << "-" << std::setfill(' ') << std::endl;

    // Loop through the orders vector and list as a table body
    for (const Order& order : orderVector) {
        std::cout << std::left << std::setw(5) << order.id << std::setw(10) << order.item_id << std::setw(20) << order.name << std::setw(10) << std::fixed << std::setprecision(2) << order.price << std::setw(10) << order.quantity << std::endl;
    }
}

void viewAllseles() {
    // Sales table headers
    std::cout << std::left << std::setw(5) << "ID" << std::setw(10) << "Order ID" << std::setw(15) << "Date" << std::setw(15) << "Total Price" << std::endl;
    // Sales table hr line
    std::cout << std::setfill('-') << std::setw(45) << "-" << std::setfill(' ') << std::endl;

    // Loop through the sales vector and list as a table body
    for (const Sale& sale : salesVector) {
        std::cout << std::left << std::setw(5) << sale.id << std::setw(10) << sale.order_id << std::setw(15) << sale.date << std::setw(15) << std::fixed << std::setprecision(2) << sale.total_price << std::endl;
    }
}

void displayFoundItem(const Item &foundItem)
{
    cout << "Item ID    :   " << foundItem.id << endl;
    cout << "Name       :   " << foundItem.name << endl;
    cout << "Price      :   " << foundItem.price << endl;
    cout << "Quantity   :   " << foundItem.quantity << endl;
}

// View Methods-------------------------------------------------------end-------------------------------------------


// CRUD Methods-------------------------------------------------------start-----------------------------------------

void CreateItem()
{
    clearScreen();
    PrintHeader(true, "Sub Menu | Create New Item(s)");

    cout << "Item ID: " << filesNextId.item_id << endl;
    itemRecord.id = filesNextId.item_id;

    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, itemRecord.name);

    cout << "Enter the price: ";
    cin >> itemRecord.price;

    cout << "Enter the quantity: ";
    cin >> itemRecord.quantity;


    ofstream outputFile("items_data.dat", ios::app);

    if (!outputFile) {
        cerr << "Error opening the file for writing." << endl;
    } else {
        outputFile << itemRecord.id << "," << itemRecord.name << "," << itemRecord.price << "," << itemRecord.quantity << "\n";
        outputFile.close();
        cout << "New item added:\n";
        cout << "ID: " << itemRecord.id << ", Name: " << itemRecord.name << ", Price: " << itemRecord.price << ", Quantity: " << itemRecord.quantity << endl;
        itemsVector.push_back(itemRecord);
    }

    cout << endl;

    cout << "Press 1 to Create new item" << endl;
    cout << "Click 0 to back Main Menu : " << endl;
    cout << "Enter your choice: ";

    int choice;

    cin >> choice;

    switch (choice)
    {
        case 1:
            CreateItem();
            break;

        default:
            system("cls");
            mainMenu();
            break;
    }
}

void searchItemUpdated(Item* &foundItem)
{
    cout << endl;
    cout << "Press 1 for update name" << endl;
    cout << "Press 2 for update price" << endl;
    cout << "Press 3 for update quantity" << endl;
    cout << "Press 0 for exit from update" << endl;
    cout << endl;

    int choice;
    cout << "Enter your choice : ";
    cin >> choice;

    string updatedName;
    double updatePrice;
    int updatedQuantity;

    switch (choice)
    {
        case 1:
            cout << "Enter value for name : ";
            cin >> updatedName;
            foundItem->name = updatedName;
            break;

        case 2:
            cout << "Enter value for price : ";
            cin >> updatePrice;
            foundItem->price = updatePrice;
            break;

        case 3:
            cout << "Enter value for quantity : ";
            cin >> updatedQuantity;
            foundItem->quantity = updatedQuantity;
            break;

        default:
            searchitem();
            break;
    }

    // create temp file
    ofstream outFile("temp_items_data.dat");
    if (!outFile.is_open()) {
        cerr << "Error: Unable to create a temporary file." << endl;
    }

    for (const Item &item : itemsVector) {
        outFile << item.id << ',' << item.name << ',' << item.price << ',' << item.quantity << endl;
    }

    outFile.close();

    if (remove("items_data.dat") != 0) {
        cerr << "Error: Unable to remove the old file." << endl;
    }

    if (rename("temp_items_data.dat", "items_data.dat") != 0) {
        cerr << "Error: Unable to rename the temporary file." << endl;
    }

    cout << "Item updated in the file." << endl;

}

void createOdrder()
{
    clearScreen();
    PrintHeader(true, "Sub Menu | Create Order");
    cout << endl;
    viewAllItem();
    cout << endl;

    // Keep adding items to the order
    int choice;
    bool itemAddStatus;
    bool orderSaveStatus;
    double totalBill = 0.0; // Initialize total bill

    while (true) {
        cout << "Enter [1] to add items || Enter [2] to save order || Enter [0] to discard order" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                itemAddStatus = addItemToOder();
                if (itemAddStatus) {
                    cout << "Item added successfully." << endl;
                    // Calculate total bill after adding each item
                    totalBill += orderRecord.price * orderRecord.quantity;
                    cout << "Total Bill: " << fixed << setprecision(2) << totalBill << endl;
                } else {
                    cerr << "Error while adding item to order..." << endl;
                    orderVector.clear();
                }
                break;
            case 2:
                if (!orderVector.empty()) {
                    viewCurrentOrder();
                    orderSaveStatus = saveOder();
                    if (orderSaveStatus) {
                        filesNextId.order_id = filesNextId.order_id + 1;
                        cout << "Order saved." << endl;
                        cout << "Total Bill: " << fixed << setprecision(2) << totalBill << endl; // Display total bill
                    } else {
                        cerr << "Error while saving order..." << endl;
                        orderVector.clear();
                    }
                } else {
                    cerr << "Error while saving order..." << endl;
                }
                return; // Exit the function after saving the order
            case 0:
                cout << "Discard order." << endl;
                orderVector.clear();
                return; // Exit the function without saving the order
            default:
                cout << "Invalid choice. Please enter 0, 1, or 2." << endl;
                orderVector.clear();
                break;
        }
    }
}

bool addItemToOder()
{
    int enteredItemId;
    int enteredItemQty;
    Item *foundItem = nullptr;

    cout << "Enter item id : ";
    cin >> enteredItemId;
    cout << "Enter item qty : ";
    cin >> enteredItemQty;

    foundItem = getItemById(enteredItemId);

    if(foundItem != nullptr) {
        orderRecord.id = filesNextId.order_id;
        orderRecord.item_id = foundItem->id;
        orderRecord.name = foundItem->name;
        orderRecord.price = foundItem->price;
        orderRecord.quantity = enteredItemQty;
        orderVector.push_back(orderRecord);
    }

    return true;
}

bool saveOder()
{
    int qty;
    double price, totalPrice;
    bool salesSaveStatus = false;

    ofstream outputFile("orders_data.dat", ios::app);

    if (!outputFile) {
        cerr << "Error opening the file for writing." << endl;
    } else {
        for (const Order& order : orderVector) {
            qty = order.quantity;
            price = order.price;
            totalPrice = totalPrice + (qty * price);
            outputFile << order.id << "," << order.item_id << "," << order.name << "," << order.price << "," << order.quantity << "\n";
        }
        outputFile.close();
        salesSaveStatus = savesales(totalPrice);
        if (salesSaveStatus) {
            return true;
        }else {
            return false;
        }
    }
    return false;
}

bool savesales(const double &totalPrice)
{
    string date = handleDateFormat();
    ofstream outputFile("sales_data.dat", ios::app);

    if (!outputFile) {
        cerr << "Error opening the file for writing." << endl;
    } else {
        outputFile << filesNextId.sale_id << "," << filesNextId.order_id << "," << date << "," << totalPrice << "\n";
        outputFile.close();
        return true;
    }
    return false;
}

// CRUD Methods-------------------------------------------------------END-------------------------------------------


// Search Methods-------------------------------------------------------start-----------------------------------------

void searchitem()
{
    clearScreen();
    PrintHeader(true, "Sub Menu | Search Item");

    Item *foundItem = nullptr;

    string itemName;

    cout << "Enter item name for search ( first letter should be capital) : ";
    cin >> itemName;

    foundItem = serachByName(itemName);

    if (foundItem) {
        cout << "Item found : Success... " << endl;
        displayFoundItem(*foundItem);
        searchItemUpdated(foundItem);
    }
    else {
        cout << "Item not found : Faild... " << endl;
        backToMainMenu();
    }
}

Item* serachByName(const string &name)
{
    for (Item &item : itemsVector)
    {
        if (item.name == name)
        {
            return &item;
        }
    }
    return nullptr;
}

Item* getItemById(const int &id)
{
    for (Item &item : itemsVector)
    {
        if (item.id == id)
        {
            return &item;
        }
    }
    return nullptr;
}

// Search Methods-------------------------------------------------------end-------------------------------------------


// Helper Methods-------------------------------------------------------start-------------------------------------------

void clearScreen()
{
    system("cls");
}

void terminalFontColor(const int &colorCode)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (colorCode)
    {
        case 1:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            break;

        case 2:
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            break;

        case 3:
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            break;

        case 4:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            break;

        case 5:
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED);
            break;

        case 6:
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
            break;

        default:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
    }
}

void PrintHeader(const bool &auth, const string &title)
{
    terminalFontColor(YELLOW);
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    if (auth) {
        cout << "                    " << globalCompanyName << " | " << title << " | Logged In as : " << authUser.userName << " (" << authUser.roleName <<  ")"  << endl;
    }
    else {
        cout << "                                          " << globalCompanyName << " | " << title << endl;
    }
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    terminalFontColor(DEFAULT);
}

void backToMainMenu() {
    int choice;
    cout << endl;
    cout << "Click 0 to back Main Menu : " ;
    cin >> choice;
    switch (choice)
    {
        case 0:
            clearScreen();
            mainMenu();
            break;

        default:
            backToMainMenu();
            break;
    }
}

string handleDateFormat()
{
    // Get the current system time
    auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());

    // Create a string stream to format the date
    ostringstream oss;

    // Format the date as "YYYY-MM-DD"
    oss << put_time(localtime(&currentTime), "%Y-%m-%d");

    // Get the formatted date as a string
    string currentDate = oss.str();

    return currentDate;
}
void viewCompanyDetails(){
        cout << "Amber Bakery Details" << endl;
        cout << "---------------------" << endl;
        cout << "Name    : Amber Bakery" << endl;
        cout << "Address : 123 Main Street, London, UK" << endl;
        cout << "Phone   : +44 1234 567890" << endl;
        cout << "Website : www.amberbakery.co.uk" << endl;
    }



#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void bakeryPackages() {

    string packageNames[] = {"Holiday Package", "Party Package", "Wedding Package", "Cookie Package", "Kids Package", "Seasonal Package"};
    string packageItems[][4] = {
        {"Assorted Cookies", "Festive Cupcakes", "Mini Fruitcakes", "Hot Cocoa Mix"},
        {"Savory Pastries", "Mini Sandwiches", "Bite-sized Desserts", "Beverages"},
        {"Wedding Cake", "Miniature Desserts", "Bride & Groom Cupcakes", "Champagne"},
        {"Assorted Plain Cookies", "Decorating Kits", "Cookie Cutters", "Baking Instructions"},
        {"Themed Birthday Cake", "Cupcakes", "Mini Pizza Kits", "Party Favors"},
        {"Seasonal Pies", "Flavored Bread", "Seasonal Cookies/Cupcakes", "Spiced Hot Cider"}
    };


    int packageQuantity[][4] = {
        {12, 8, 4, 2},
        {20, 16, 24, 10},
        {1, 24, 2, 3},
        {24, 1, 1, 1},
        {1, 12, 4, 8},
        {8, 6, 12, 10}
    };

    double packagePrice[][4] = {
        {12.99, 14.99, 19.99, 8.99},
        {18.99, 24.99, 29.99, 12.99},
        {299.99, 49.99, 19.99, 39.99},
        {9.99, 5.99, 3.99, 2.99},
        {39.99, 19.99, 14.99, 9.99},
        {24.99, 6.99, 14.99, 8.99}
    };

    // Print the table header
    cout << left << setw(20) << "Package Name" << setw(25) << "Package Items" << setw(12) << "    "<< setw(10) << "Price" << endl;
    cout << string(75, '-') << endl;

    // Print package names, items, quantity, and price
    for (int i = 0; i < 6; ++i) {
        cout << setw(20) << packageNames[i] << " ";
        for (int j = 0; j < 4; ++j) {
            if (j > 0) {
                cout << setw(25) << " ";
            }
            cout << packageItems[i][j] << setw(12) << packageQuantity[i][j] << setw(10) << packagePrice[i][j] << endl;
        }
        cout << string(75, '-') << endl;
    }
}
