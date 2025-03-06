#include <iostream>
#include <vector>
#include <algorithm>  // For sort()
using namespace std;

// Structure to store profit, weight, and profit/weight ratio
struct Item {
    int profit, weight;
    double ratio;
    
    // Constructor
    Item(int p, int w) {
        profit = p;
        weight = w;
        ratio = (double)p / w;
    }
};

// Comparator function to sort items in decreasing order of profit/weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Function to calculate the maximum profit
double fractionalKnapsack(vector<Item> items, int capacity) {
    // Sort items based on profit/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;

    for (auto item : items) {
        if (capacity >= item.weight) {
            // Take the whole item
            capacity -= item.weight;
            totalProfit += item.profit;
        } else {
            // Take a fraction of the item
            totalProfit += item.profit * ((double)capacity / item.weight);
            break;  // Knapsack is full
        }
    }
    return totalProfit;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        int profit, weight;
        cin >> profit >> weight;
        items.push_back(Item(profit, weight));
    }

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    double maxProfit = fractionalKnapsack(items, capacity);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
