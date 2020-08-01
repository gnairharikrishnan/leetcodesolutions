/**
 * Leetcode Note:
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 *  Description: This function takes two linkedlists each of which constitutes
 *               a number, adds the numbers and saves the result into a new 
 *               a new linkedlist. This is a very interesting program, as this 
 *               could be a method to add numbers when they are bigger than the
 *               max sizes supported by the data type, cause the highest value
 *               a number can have is only capped by the amount of memory your 
 *               program has.   
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *temp=NULL;
    struct ListNode *head = NULL;
    struct ListNode *current= NULL;
    int num1=0,num2=0, carry=0;
    while(l1 != NULL || l2!=NULL || carry != 0)
    {
        if(l1==NULL){
            num1=0;
        }else{
            num1=l1->val;
            l1=l1->next;
        }
        
        if(l2==NULL){
            num2=0;
        }else{
            num2=l2->val;
            l2=l2->next;
        }
        temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        if(head==NULL){
            head=temp;
        }
        if(current==NULL){
            current=temp;
        }else{
            current->next=temp;
        }
        temp->val=num1+num2+carry;
        temp->next=NULL;

        if(temp->val > 9){
            carry=1;
            temp->val = temp->val % 10;
        }else{
            carry=0;
        }
        printf("%d ", temp->val);
        current=temp;
        
    }
    return head;
}