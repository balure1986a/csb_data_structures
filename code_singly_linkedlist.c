#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
    struct node *next;
};
struct node *head;

void insert_begin();
void insert_end();
void insert_loc();
void delete_begin();
void delete_end();
void delete_loc();

void insert_begin()
{
	struct node *ptr;
    ptr = (struct node*) malloc(sizeof(struct node*));
    int item;
    scanf("%d", &item);
    if (ptr == NULL)
    	printf("Overflow");
    else
    {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("Insert DONE");
    }
}

void insert_end()
{
	struct node *ptr, *temp;
    ptr = (struct node*) malloc(sizeof(struct node*));
    int item;
    scanf("%d", &item);
    if (ptr == NULL)
    	printf("Overflow");
    else
    {
    	if (head == NULL)	// first element being added
        {
        	ptr->data = item;
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
        	temp = head;
            while (temp->next != NULL)
            	temp = temp->next;
            temp->next = ptr;
        	ptr->data = item;
            ptr->next = NULL;
        }
        printf("Insert DONE");
    }
}

void insert_loc()
{
	int loc;
    scanf("%d", &loc);
	struct node *ptr, *temp;
    ptr = (struct node*) malloc(sizeof(struct node*));
    int item;
    scanf("%d", &item);
    if (ptr == NULL)
    	printf("Overflow");
    else
    {	
    	temp = head;
    	for (int i = 0; i < loc; i++)
        {
        	temp = temp->next;
            if (temp == NULL)
            {
            	printf("CANNOT insert");
                return;
            }
        }
        ptr->data = item;
        ptr->next = temp->next;
        temp->next = ptr;
        printf("Insert DONE");
    }
}

/////////////////////////////////////////////////////////////////////////

void delete_begin()
{
	struct node *ptr;
	if (head == NULL)
    	printf("List empty");
    else
    {
    	ptr = head;
        head = ptr->next;
        free(ptr);
        printf("Deletion DONE");
    }
}

void delete_end()
{
	struct node *ptr, *temp;
	if (head == NULL)
    	printf("List empty");
    else if (head->next == NULL)	// atleast one item present
    {
    	ptr = head;
        head = NULL;
        free(ptr);
        //or
        //head = NULL;
        //free(head);
        printf("Deletion DONE");
    }
    else
    {
    	ptr = head;
        while (ptr->next != NULL)
        {
        	temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
        printf("Deletion DONE");
    }
}

void delete_loc()
{
	struct node *ptr, *temp;
    int loc;
    scanf("%d", &loc);
    ptr = head;
    for (int i = 0; i < loc; i++)
    {
    	temp = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
        	printf("Cannot delete");
			return;
        }
	}
    temp->next = ptr->next;
    free(ptr);
    printf("Deletion DONE");
}

void search()
{
	struct node *ptr;
    int loc = 0;
    int flag = 0;		// 0: not found, 1: found;
    ptr = head;
    if (ptr == NULL)
    	printf("List empty");
    else
    {
    	int item;
        scanf("%d", &item);
        while (ptr != NULL)
        {
        	if (ptr->data == item)
            {
            	flag = 1;		// found
                printf("Found");
                printf("Loc = %d", loc + 1);
            }
            ptr = ptr->next;
            loc++;
        }
        if (flag == 0)
        	printf("Not found");
    }
}

void display()
{
	struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    	printf("List empty");
    else
    {
    	while (ptr != NULL)
        {
        	printf("%d \n", ptr->data);
            ptr = ptr->next;
        }
    }
}

/////////////////////////////////////////////////////////

int main()
{
	while(1)
    {
    	printf("0. exit \n");
        printf("1. insert begin \n");
        printf("2. insert end \n");
        printf("3. insert loc \n");
        
        printf("4. delete begin \n");
        printf("5. delete end \n");
        printf("6. delete loc \n");
        
        printf("7. search \n");
        printf("8. display \n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(1)
        {
        	case 0:			// exit
            	break;
            case 1: 
                insert_begin();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                insert_loc();
                break;
            case 4: 
                delete_begin();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_loc();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;		
            default:
            	printf("Wrong choice \n");
                break;
        }
    }
    return 0;
}
