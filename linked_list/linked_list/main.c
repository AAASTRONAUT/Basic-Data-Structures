//
//  main.c
//  linked_list
//
//  Created by Shivansh Jain on 28/01/23.
//

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*first = NULL , *second = NULL;

void create(int A[] , int n){
    struct node * last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i = 1 ; i<n ; i++){
        struct node * temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void create2(int B[] , int length){
    struct node * last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = B[0];
    second->next = NULL;
    last = second;
    for(int i = 1 ; i<length ; i++){
        struct node * temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = B[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct node * iter){
    while(iter != NULL){
        printf("%d\t" , iter->data);
        iter = iter->next;
    }
    printf("\n");
}

void recursive_display(struct node * iter){
    if(iter!=NULL){
        printf("%d\t" , iter->data);
        recursive_display(iter->next);
    }
    else printf("\n");
}

int count(struct node * iter){
    int count =0;
    while(iter != NULL){
        count++;
        iter=iter->next;
    }
    return count;
}

int rSum(struct node * iter){
    if(iter != 0) return rSum(iter->next) + iter->data;
    else return 0;
}

long long Max(struct node * iter){
    static long long max = INT64_MIN;
    if(iter != 0){
        if(iter->data > max){
            max = iter->data;
        }
        return Max(iter->next);
    }
    else return max;
}

struct node * lSearch(struct node * iter , int key){
    if(iter != NULL){
        if(key == iter->data){
            return iter;
        }
        return lSearch(iter->next , key);
    }
    else return NULL;
}

//am in proved method for searching is to bring the element we searched for in thr front so that it may be found out in less time.
struct node * improved_search(struct node *iter , int key){
    static struct node * follow = NULL;
    if(iter != 0){
        if(key == iter->data){
            follow->next = iter->next;
            iter-> next= first;
            first = iter;
            return iter;
        }
        else{
            follow = iter;
            return improved_search(iter->next , key);
        }
    }
    else return NULL;
}

void insert(struct node * iter , int x , int pos){
    if(pos>0 && pos<=count(iter)+1){
        struct node * new = (struct node *)malloc(sizeof(struct node *));
        new->data = x;
            
            if(pos!=1){
                for (int i = 1 ; i<pos-1 ; i++){
                    iter = iter->next;
                }
                new->next = iter->next;
                iter->next= new;
            }
            else{
                new->next = first;
                first = new;
            }
    }
    else printf("invalid position\n");
}

void insertSorted(struct node * iter ,int x){
    struct node * trail = NULL;
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new ->data = x;
    if(first == 0){
        first = new;
    }
    else{
        while(iter!=0 && iter->data < x){
            trail = iter;
            iter = iter->next;
            
        }
        if(iter == first){
            new->next = first;
            first = new;
        }
        else{
            new->next  = iter;
            trail->next = new;
        }
    }
}

void delete(struct node * iter , int x){
    struct node * temp = first;
    struct node * trail = (struct node *)malloc(sizeof(struct node));
    if(first->data == x){
        first = first->next;
        free(temp);
    }
    else{
        while(iter != 0){
            if(iter->data == x) break;
            else {
                trail = iter;
                iter = iter->next;
            }
        }
        if(iter == 0) printf("element not in list!\n");
        else{
            trail->next = iter->next;
            free(iter);
        }
    }
}

void isSorted(struct node * iter){
    int count = 0;
    while(iter->next != 0){
        if(iter->data <= iter->next->data){
            iter = iter->next;
            continue;
        }
        else printf("list not sorted!\n"); count = 1; break;
    }
    if(count == 0) printf("list is sorted!\n");
}

void remove_duplicates(struct node * iter){
    struct node * forward = iter->next;
    while(forward !=  NULL){
        if(iter->data == forward->data){
            iter->next = forward->next;
            free(forward);
            forward = iter->next;
        }
        else{
            iter = iter->next;
            forward = forward->next;
        }
    }
}

void reverse(struct node * iter){
    int * aux = (int *)malloc(count(iter)*sizeof(int));
    int i = 0;
    while(iter != NULL){
        aux[i] = iter->data;
        i++;
        iter = iter->next;
    }
    iter = first; i--;
    for (int i = count(iter)-1 ; i>=0 ; i--){
        iter->data = aux[i];
        iter = iter->next;
    }
}

void rReverse(struct node * iter){
    struct node * trail = NULL;
    if(iter->next != 0){
        trail = iter;
        iter = iter->next;
        rReverse(iter);
        iter->next = trail;
    }
    else first = iter;
}

void concat(struct node * l1 , struct node * l2){
    while(l1->next != 0){
        l1 = l1->next;
    }
    l1->next = l2;
}

void merge(struct node * p , struct node * q){
    struct node * last=NULL , *third = NULL;
    if(p->data < q->data){
        third = p;
        last = p;
        p=p->next;
        last->next = 0;
    }
    else{
        third =  q;
        last = q;
        q = q->next;
        last->next = 0;
    }
    
    while((p!=0) && (q!=0)){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p=p->next;
            last->next = 0;
        }
        else{
            last->next = q;
            last = q;
            q=q->next;
            last->next = 0;
        }
    }
    while(p!=0){
        last->next = p;
        last = p;
        p=p->next;
        last->next = 0;
    }
    while( q!=0){
        last->next = q;
        last = q;
        q=q->next;
        last->next = 0;
    }
    first = third;
}

void isLoop(struct node * p){
    struct node * q = first;
    do{
        p=p->next;
        q=q->next;
        if(q != 0) q = q->next;
        else continue;
    }while(p && q && q!=p);
    
    if(p==q){
        printf("list have a loop\n");
    }
    else{
        printf("list dosent have a loop\n");
    }
}

int main() {
    int A[5] = {3 , 5, 7, 13, 22};
    create( A , 5);
    printf("First linked list: ");
    display(first);
    
    //DISPLAYING THE LINKED LIST RECURSIVELY
    printf("Result of recursive display:");
    recursive_display(first);
    printf("total numer of elements is: %d\n",count(first));
    printf("sum of all the eelemnts is: %d\n" , rSum(first));
    printf("maximum of all the elements is: %lld\n" , Max(first));
    
    //searching an element in the list
    printf("enter element to be searched: ");
    int key;
    scanf("%d" , &key);
    printf("result of normal search, key is found at address: %p\n", lSearch(first , key));
    
    //IMPROVED SEARCH IN A LINKED LIST
    printf("results of improved search, key is found at address: %p\n" , improved_search(first, key));
    printf("linked list after improved search: ");
    display(first);
    
    //inserting an element in a linked list
    printf("Enter element to be inserted and position: ");
    int x ,pos;
    scanf("%d %d" , &x ,&pos);
    insert(first , x , pos);
    display(first);

    //INSERTING IN A SORTED LINKED LIST
    printf("Enter element to be inserted in sorted list: ");
    int element;
    scanf("%d" , &element);
    insertSorted(first, element);
    display(first);
    
    //deleting element from the list
    printf("Enter element to be deleted: ");
    int del;
    scanf("%d" , &del);
    delete(first , del);
    display(first);
    
    //checking if the list is sorted
    isSorted(first);
    
    //removing duplicates from the list IF ANY
//    remove_duplicates(first);
//    printf("List after removal of duplicates is: ");
//    display(first);
    
    //reversing the linked list
//    reverse(first);
//    printf("result after reversing the linked list: ");
//    display(first);
    
    //RECURSIVELY REVERSING THE LINKED LIST [DOSENT WORK PROPERLY NOW]
    /// BUG BUG BUG BUG
//    rReverse(first);
//    printf("Result after recursively reversing the linked list: ");
//    display(first);
    
    // creating a second list for concat operation
    int B[4] = {8 , 9, 10, 11 };
    create2(B , 4);
    printf("second linked list for concat and merge operation is: ");
    display(second);
    
    // coancat operation
    concat(first , second);
    printf("Second linked list for concat operation: ");
    display(second);
    printf("Result after concatinating second and first list: ");
    display(first);
    
    //merging first and second and storing the resultant list in first
    printf("list after merging first and second list: ");
    merge(first , second);
    display(first);
    
    //checking of the list has loop or not
//    struct node * t1,* t2;
//
//    t1 = first->next->next;
//    t2 = first->next->next->next->next;
//    t2->next = t1;
//
//    isLoop(first);
    
    return 0;
}
