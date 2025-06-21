// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, pair<int, int>>> items;

        for (int i = 0; i < n; i++) {
            double ratio = (double) val[i] / wt[i];
            items.push_back({ratio, {val[i], wt[i]}});
        }

        sort(items.rbegin(), items.rend());

        double totalValue = 0.0;
        int currWeight = 0;

        for (int i = 0; i < n; i++) {
            int itemWeight = items[i].second.second;
            int itemValue = items[i].second.first;

            if (currWeight + itemWeight <= capacity) {
                currWeight += itemWeight;
                totalValue += itemValue;
            } 
            else {
                int remain = capacity - currWeight;
                totalValue += (double) remain * items[i].first;
                break;
            }
        }

        return totalValue;
    }
};

