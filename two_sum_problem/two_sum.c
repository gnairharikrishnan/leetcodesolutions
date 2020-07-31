/*  Author:      Hari Nair
 *  Description: This is a O(n) solution for the two sum question on 
 *               leetcode. It saves the elements of the array into a
 *               hash table and then for each element computes a possible
 *               pair and searches for it in the hashmap. The code is 
 *               written for the leetcode IDE and would require additional 
 *               work for it to be run on other IDEs (Doesnt contain a main).
 */

/**
 * Leet-code Note: The returned array must be malloced, assume caller calls free().
 */

struct hashtable_entry{
    int data;
    int index;
    struct hashtable_entry *next;
};

//global hash table
struct hashtable_entry *key[10];

/*
 *    Description: Function takes a number and its index as input, 
 *                 computes the hash and saves it in the hasmap
 */
int hash_entry(int number, int in)
{
    struct hashtable_entry *temp=NULL;
    temp=(struct hashtable_entry *)malloc(sizeof(struct hashtable_entry));
    temp->data=number;
    temp->index=in;
    temp->next=NULL;
    if(key[abs(number%10)]==NULL){
        key[abs(number%10)]=temp;
    }else{
        struct hashtable_entry *traverser;
        traverser=key[abs(number%10)];
        while(traverser->next!=NULL){
            traverser=traverser->next;
        }
        traverser->next=temp;
    }
    return 0;
}

/*
 *    Description: Function takes the number to be searched and
 *                 the index of the corresponding pair (to check 
 *                 for duplicates) and returns the value and its 
 *                 index if its found. If a match is not found, 
 *                 it returns NULL 
 */

struct hashtable_entry *search_entry(int tar, int duplicate)
{
    if(key[abs(tar%10)]==NULL){
        return NULL;
    }else{
        struct hashtable_entry *traverser;
        traverser=key[abs(tar%10)];
        while(traverser!=NULL){
            if(traverser->data == tar && traverser->index != duplicate){
                return traverser;
            }
            traverser=traverser->next;
        }
        return NULL;
    }
}

/*
 *   Description: Function that checks if there are two numbers
 *                in an array that add up to a target.   
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    memset(key,0x00,sizeof(key));
    struct hashtable_entry *result;
    *returnSize=2;
    int *ret_type;
    ret_type=(int *)malloc(sizeof(int)*2);
    for(int i=0;i<numsSize;i++){
        hash_entry(nums[i],i);
    }
    for(int i=0;i<numsSize;i++){
        result=search_entry((target-nums[i]),i);
        if(result!=NULL){
            if(i!=result->index){
                ret_type[0]=i;
                ret_type[1]=result->index;
                return(ret_type);
            }
        }
    }
    return NULL;
}