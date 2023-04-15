class Solution {
    public String solution(int[] food) {
        String answer = "";
        
        String left = "";

        int i, j;
        
        for(i = 1; i < food.length; i++){
            for(j = 0; j < food[i] / 2; j++){
                left += i;
            }
        }
        StringBuffer right = new StringBuffer(left);
        right.reverse();

        answer += left;
        answer += "0";
        answer += right;
        
                
        return answer;
    }
}