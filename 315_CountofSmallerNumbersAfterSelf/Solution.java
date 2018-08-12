
public class Solution {
    int[] count;
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> res = new ArrayList<Integer>();
        count = new int[nums.length];
        int[] indexes = new int[nums.length];
        for (int i = 0; i < nums.length; i++){
            indexes[i] = i;
        }
        mergeSort(nums, indexes, 0, nums.length-1);
        for (int i = 0; i < count.length; i++){
            res.add(count[i]);
        }
        return res;
    }
    
    private void mergeSort(int[] nums, int[] indexes, int start, int end){
        if (start >= end){
            return;
        }
        int mid = (start + end) / 2;
        mergeSort(nums, indexes, start, mid);
        mergeSort(nums, indexes, mid + 1, end);
        merge(nums, indexes, start, end);
    }
    
    private void merge(int[] nums, int[] indexes, int start, int end){
        int mid = (start + end) / 2;
        int left_index = start;
        int right_index = mid + 1;
        int right_count = 0;
        int[] new_indexes = new int[end - start + 1];
        
        int sort_index = 0;
        
        while (left_index <= mid && right_index <= end){
            if (nums[indexes[right_index]] < nums[indexes[left_index]]){
                new_indexes[sort_index] = indexes[right_index];
                right_count++;
                right_index++;
            }else {
                new_indexes[sort_index] = indexes[left_index];
                count[indexes[left_index]] += right_count;
                left_index++;
            }
            sort_index++;
        }
        while(left_index <= mid){
            new_indexes[sort_index] = indexes[left_index];
            count[indexes[left_index]] += right_count;
            left_index++;
            sort_index++;
        }
        while(right_index <= end){
            new_indexes[sort_index++] = indexes[right_index++];
        }
        for(int i = start; i <= end; i++){
            indexes[i] = new_indexes[i-start];
        }
    }
}
