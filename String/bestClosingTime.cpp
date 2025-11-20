#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int bestClosingTime(const string& customers) {
        int n = customers.size();
        int res = 0, missedCustomers = 0, extraOpenHours = 0;

        for (auto& i : customers) {
            if (i == 'Y') {
                missedCustomers++;
            }
        }

        int minPenalty = missedCustomers;

        for (int i = 0; i < n; ++i) {
            if (customers[i] == 'Y') {
                missedCustomers--;
            } else {
                extraOpenHours++;
            }

            int currentPenalty = missedCustomers + extraOpenHours;
            if (currentPenalty < minPenalty) {
                minPenalty = currentPenalty;
                res = i + 1;
            }
        }
        return res;
    }
};