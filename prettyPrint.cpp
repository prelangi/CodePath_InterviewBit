vector<vector<int> > Solution::prettyPrint(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector< vector<int> > sol(2*A-1, vector<int>(2*A-1));

    // printf(sol);
    for(int i=0;i<A;i++) {
        for(int j=0;j<A;j++) {
            if(i-j>0) 
                sol[i][j] = A - j;
            else
                sol[i][j] = A - i;
                
        }
    }
    
  int idx = 1;
  
    for(int i=0;i<A;i++) {
        idx = 1; 
        for(int j=A;j<2*A-1;j++) {
            sol[i][j] = sol[i][j-2*idx];
            idx++;
        }
      
    }
    
    idx = 1;
    for(int i=A;i<2*A-1;i++) {
        for(int j=0;j<2*A-1;j++) {
            sol[i][j] = sol[i-2*idx][j];
            
        }
      idx++;
    }
    
    return sol;

}
