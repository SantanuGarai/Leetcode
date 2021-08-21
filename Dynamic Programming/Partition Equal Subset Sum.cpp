/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100
Accepted
*/


class Solution {
public:
    int subset(vector<int> & nums,int n,int sum,int **temp){
        if(sum==0){
            return 1;
        }
        if(sum!=0 && n==0){
            return 0;
        }
        if(temp[n][sum]!=-1){
            return temp[n][sum];
        }
        if(nums[n-1]<=sum){
            return temp[n][sum]=(subset(nums,n-1,sum-nums[n-1],temp) || subset(nums,n-1,sum,temp));
        }
        else if(nums[n-1]>sum){
            return temp[n][sum]=subset(nums,n-1,sum,temp);
        }
        return temp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
       int** t = new int*[nums.size()+1];
     for (int i = 0; i < nums.size() +1; i++) {
        t[i] = new int[sum+1];
    }
    
       for(int i=0;i<nums.size()+1;i++){
           for(int j=0;j<sum+1;j++){
               t[i][j]=-1;
           }
       }
           return subset(nums,nums.size(),sum/2,t)==1?true:false;
        
    }
};



tabulation:

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        sum = sum/2;
        int n = nums.size();
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0)
                    t[i][j] = false;
                if(j==0)
                    t[i][j] = true;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};
