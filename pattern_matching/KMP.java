// time complexity ave and worst case:O(n+m); space complexity: O(m)
// https://www.youtube.com/watch?v=GTJr8OvyEVQ
// https://github.com/mission-peace/interview/blob/259077bacabdbb5b6a0e918cd8dfe5eabca3300f/src/com/interview/string/SubstringSearch.java
package com.interview.string;

/**
 * Date 09/22/2014
 * @author tusroy
 * 
 * Do pattern matching using KMP algorithm
 * 
 * Runtime complexity - O(m + n) where m is length of text and n is length of pattern
 * Space complexity - O(n)
 */
public class SubstringSearch {

    /**
     * Slow method of pattern matching
     */
    public boolean hasSubstring(char[] text, char[] pattern){
        int i=0;
        int j=0;
        int k = 0;
        while(i < text.length && j < pattern.length){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }else{
                j=0;
                k++;
                i = k;
            }
        }
        if(j == pattern.length){
            return true;
        }
        return false;
    }
    
    /**
     * Compute temporary array to maintain size of suffix which is same as prefix
     * Time/space complexity is O(size of pattern)
     */
    private int[] computeTemporaryArray(char pattern[]){
        /*
        The value in the lps means that when the next element in the pattern miss-match with the search string
        which will be the index we are going too check/compare in the pattern with the current value in the search string.
        */
        int [] lps = new int[pattern.length];
        int index =0;
        for(int i=1; i < pattern.length;){
            if(pattern[i] == pattern[index]){
                lps[i] = index + 1;
                index++;
                i++;
            }else{
                if(index != 0){
                    /* actually, this backtracking can be view as we are comparing a sub string (start from the closest zero with this mis-match)
                    with the pattern string itself.
                    i.e. we have a mismatch, so we see the value in previous index in lps, which tells us,
                    where should we start to compare again with current value.(this can go sevaral time if we again have mismatch.)
                    */
                    index = lps[index-1];
                }else{
                    lps[i] =0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    /**
     * KMP algorithm of pattern matching.
     */
    public boolean KMP(char []text, char []pattern){
        
        int lps[] = computeTemporaryArray(pattern);
        int i=0;
        int j=0;
        while(i < text.length && j < pattern.length){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }else{
                if(j!=0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        if(j == pattern.length){
            return true;
        }
        return false;
    }
        
    public static void main(String args[]){
        
        String str = "abcxabcdabcdabcy";
        String subString = "abcdabcy";
        SubstringSearch ss = new SubstringSearch();
        boolean result = ss.KMP(str.toCharArray(), subString.toCharArray());
        System.out.print(result);
        
    }
}
