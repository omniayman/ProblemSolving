import java.util.*;  
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();   
        int[]sumsIndex=new int[2];
        for(int i=0;i<nums.length;i++)
        {
            int x=target-nums[i];
            if(ht.containsKey(nums[i]))
            {
               sumsIndex[0]=ht.get(nums[i]);
                sumsIndex[1]=i;
                return sumsIndex;
            }
            ht.put(x,i);
        }
    return sumsIndex;
    }
}
