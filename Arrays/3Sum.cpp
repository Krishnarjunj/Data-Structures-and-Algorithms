//BRUTE FORCE SOLUTIO N
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1;  j < n ; j++){
                for(int k = j + 1 ; k < n ; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};

// OPTIMIZED SOLUTION
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        for(int i = 0 ; i < n ; i++){
            set<int> hash;
            for(int j = i + 1;  j < n ; j++){
                int third = -(nums[i] + nums[j]);
                if(hash.find(third)!=hash.end()){
                    vector<int> temp = {third, nums[i], nums[j]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                hash.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};

// OPTIMAL SOLUTION
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n ; i++){
            if (i!=0 && nums[i]==nums[i-1]) continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while( j < k && nums[j]==nums[j-1]) j++;
                    while(j < k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
