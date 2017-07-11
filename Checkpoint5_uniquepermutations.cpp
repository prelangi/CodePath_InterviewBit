bool containsDuplicate(vector<int> A, int start, int end) {
    for (int i = start; i <= end-1; i++) {
        if(A[i] == A[end]) {
            return false;
        }
    }
    return true; 
}
 
void swap(vector<int> &a, int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void permuteUnique(vector<int> num, int start,  vector<vector<int> > &result) {
 
	if (start >= num.size() ) {
		result.push_back(num);
	}
 
	for (int j = start; j <= num.size()-1; j++) {
		if (containsDuplicate(num, start, j)) {
			swap(num, start, j);
			permuteUnique(num, start + 1, result);
			swap(num, start, j);
		}
	}
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > result;
    permuteUnique(A,0, result);
    return result;
}

