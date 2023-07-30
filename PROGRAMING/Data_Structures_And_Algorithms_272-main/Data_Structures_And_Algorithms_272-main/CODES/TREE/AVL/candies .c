#include<stdio.h>
#include<stdlib.h>

struct node
{
    int candies;
    struct node *rlink;
    struct node *llink;
};

struct node *create_node()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        printf("Memory not allocated\n");
    else
    {
        printf("Enter the number of candies: ");
        scanf("%d", &newnode->candies);
        newnode->rlink = NULL;
        newnode->llink = NULL;
    }
    return newnode;
}

struct node *insert_end_dll(struct node *head)
{
    struct node *cur = head;
    struct node *newnode = create_node(); // Create a new node

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        while (cur->rlink != NULL)
        {
            cur = cur->rlink;
        }
        cur->rlink = newnode;
        newnode->llink = cur;
    }
    return head;
}

void eat_candies(struct node *head, int k, int D)
{
    struct node *cur = head;
    int alice = k / 2;
    int bob = k / 2;
    int totalCandiesRemaining = 0;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (head != NULL)
    {
        head->candies = head->candies - D;
        totalCandiesRemaining += head->candies;
        head = head->rlink;
    }

    head = cur;
    printf("Candies left in Alice's jar: ");
    for (int i = 0; i < alice; i++)
    {
        printf("%d ", head->candies);
        head = head->rlink;
    }

    head = cur;
    printf("\nCandies left in Bob's jar: ");
    for (int i = 0; i < bob; i++)
    {
        printf("%d ", head->candies);
        head = head->llink;
    }
    printf("\n");

    printf("Total candies remaining: %d\n", totalCandiesRemaining);
}

int main()
{
    struct node *head = NULL;
    int k, D;
    printf("Enter the even number of jars: ");
    scanf("%d", &k);

    if (k % 2 == 0)
    {
        for (int i = 0; i < k; i++)
            head = insert_end_dll(head);

        printf("Enter the value of D: ");
        scanf("%d", &D);

        eat_candies(head, k, D);
    }
    else
    {
        printf("Number of jars should be even\n");
    }
    return 0;
}
