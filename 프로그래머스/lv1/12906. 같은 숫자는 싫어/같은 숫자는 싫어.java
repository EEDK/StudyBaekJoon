import java.util.*;

public class Solution {
    public Stack<Integer> solution(int []arr) {
        Stack<Integer> stack = new Stack<>();
        int i;
        
        stack.push(arr[0]);
        for(i = 1; i < arr.length; i++){
            int tmp = stack.pop();
            if(tmp != arr[i]){
                stack.push(tmp);
            }
            stack.push(arr[i]);
        }
        
        return stack;
    }
}

