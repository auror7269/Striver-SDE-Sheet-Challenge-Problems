#include<bits/stdc++.h>

int bs(vector<int> &nums, int x){

    int low=0, high=nums.size()-1;

    int index=nums.size();

    while (low<=high){

        int mid=low+(high-low)/2;

        if (nums[mid]>=x){

            high=mid-1;

            index=mid;

        }

        else{

            low=mid+1;

        }

    }

    return index;

}

 

int longestIncreasingSubsequence(int nums[], int n)

{

    // Write Your Code hereint n=nums.size();

    vector<int> vec;

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int prev=nums[0];

    vec.push_back(prev);

    for (int i=1; i<n; i++){

        if (nums[i]>prev){

            vec.push_back(nums[i]);

            prev=nums[i];

        }else{

            int index=bs(vec, nums[i]);

            if (index==vec.size()){

                vec.push_back(nums[i]);

            }else{

                vec[index]=nums[i];

            }

        }

    }

    return vec.size();

}

 