int Solution::longestConsecutive(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_set<int> S;
    int ans = 0;
    int n = A.size();
 
    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(A[i]);
 
    // check each possible sequence from the start
    // then update optimal length
    for (int i=0; i<n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(A[i]-1) == S.end())
        {
            // Then check for next elements in the
            // sequence
            int j = A[i];
            while (S.find(j) != S.end())
                j++;
 
            // update  optimal length if this length
            // is more
            ans = max(ans, j - A[i]);
        }
    }
    return ans;
}
