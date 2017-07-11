vector<int> Solution::nextGreater(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int nge = -1; 
    for(int i = 0; i<A.size(); i++) {
        nge = -1; 
        
        for(int j=i+1; j<A.size();j++) {
            if(A[j]>A[i]) {
                nge = A[j];
                j=A.size();
            }
        }
        
        A[i] = nge;
        
    }
    
    return A;
}
