#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Expense {
    string category;
    string description;
    double amount;
};

vector<Expense> expenses;

void addExpense() {
    Expense e;
    cout << "\nEnter category (Food/Transport/Shopping/Other): ";
    cin >> e.category;
    cout << "Enter description: ";
    cin.ignore();
    getline(cin, e.description);
    cout << "Enter amount: ₹";
    cin >> e.amount;
    expenses.push_back(e);
    cout << "Expense added successfully!\n";
}

void viewExpenses() {
    if (expenses.empty()) {
        cout << "\n❌ No expenses found!\n";
        return;
    }
    cout << "\n====================================\n";
    cout << "         ALL EXPENSES\n";
    cout << "====================================\n";
    double total = 0;
    for (int i = 0; i < expenses.size(); i++) {
        cout << i+1 << ". " << expenses[i].category
             << " | " << expenses[i].description
             << " | ₹" << expenses[i].amount << "\n";
        total += expenses[i].amount;
    }
    cout << "====================================\n";
    cout << "Total Expenses: ₹" << total << "\n";
    cout << "====================================\n";
}

void viewByCategory() {
    string cat;
    cout << "\nEnter category to filter: ";
    cin >> cat;
    double total = 0;
    bool found = false;
    cout << "\n====================================\n";
    for (auto& e : expenses) {
        if (e.category == cat) {
            cout << e.description << " | ₹" << e.amount << "\n";
            total += e.amount;
            found = true;
        }
    }
    if (!found) {
        cout << "No expenses in this category!\n";
    } else {
        cout << "Total: ₹" << total << "\n";
    }
    cout << "====================================\n";
}

void deleteExpense() {
    if (expenses.empty()) {
        cout << "\n No expenses to delete!\n";
        return;
    }
    viewExpenses();
    int index;
    cout << "\nEnter expense number to delete: ";
    cin >> index;
    if (index < 1 || index > expenses.size()) {
        cout << " Invalid number!\n";
        return;
    }
    expenses.erase(expenses.begin() + index - 1);
    cout << "Expense deleted!\n";
}

int main() {
    int choice;
    cout << "====================================\n";
    cout << "   Expense Tracker in C++\n";
    cout << "====================================\n";

    while (true) {
        cout << "\n1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. View by Category\n";
        cout << "4. Delete Expense\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: viewByCategory(); break;
            case 4: deleteExpense(); break;
            case 5:
                cout << "\nGoodbye! \n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
