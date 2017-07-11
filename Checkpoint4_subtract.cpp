/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> valArray;
    ListNode *head = A; 
    int linkedListSize; 
    int newVal; 
    
    while(head) {
        valArray.push_back(head->val);
        head = head->next;
    }
    
    linkedListSize = valArray.size(); 
    head = A;
    for(int i=0; i<valArray.size()/2; i++) {
        newVal = valArray[linkedListSize-i-1]-valArray[i];
        head->val = newVal;
        
        //cout << newVal << endl;
        
        head = head->next;
        
    }
    
    return A;
    
}
