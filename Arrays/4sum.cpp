// BRUTE FORCE SOLUTION
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;
        for(int i = 0 ; i < n ; i ++){
            for(int j = i + 1 ; j < n ; j++){
                for(int k = j + 1 ; k < n ; k++){
                    for(int l = k + 1 ; l < n ; l++){
                        if(nums[i] + nums[j] + nums[k] + nums[l] == target){
                            vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[l]};
                            sort(temp.begin(), temp.end());
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans (s.begin(), s.end());
        return ans;
    }
};

// BETTER SOLUTION
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;
        for(int i = 0 ; i < n ; i ++){
            for(int j = i + 1 ; j < n ; j++){
                set <int> hash;
                for(int k = j + 1 ; k < n ; k++){
                    int num = target -(nums[i] + nums[j] + nums[k]);
                    if(hash.find(num) != hash.end()){
                        vector<int> temp = {num, nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                    hash.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans (s.begin(), s.end());
        return ans;
    }
};

// OPTIMAL SOLUTION
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < n ; i++){
            if(i != 0 && nums[i]==nums[i-1]) continue;

            for(int j = i + 1; j < n ; j ++){
                if( j!= i + 1 && nums[j-1] == nums[j]) continue;

                int k = j + 1;
                int l = n - 1;

                while( k < l){
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if( sum > target){
                        l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while( k < l && nums[k]==nums[k-1]) k++;
                        while( k < l && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};
