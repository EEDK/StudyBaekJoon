import java.util.*;

class Solution {
    public int solution(int k, int m, int[] score) {
        int answer = 0;
        int cnt = score.length / m;
        
        Arrays.sort(score);
        
        for(int i = score.length - 1; i > 0; i -= m){
            if(i - m + 1 < 0){
                break;
            }
            else{
                answer += (score[i - m + 1] * m);
            }
        }    

        return answer;
    }
    
    public void printArr(int[] arr){
        int i;
        int length = arr.length;
        
        for (i = 0; i < length; i += 1) {
            System.out.printf("%d ", arr[i]);
        }
        System.out.println();

    }
}