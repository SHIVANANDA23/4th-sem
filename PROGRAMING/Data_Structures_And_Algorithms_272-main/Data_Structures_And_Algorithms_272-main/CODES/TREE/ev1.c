#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    char name[10];
    int numc, time;
    struct node* r_link;
    struct node* l_link;
};


struct node* create_node()
{
    struct node* newn = (struct node*)malloc(sizeof(struct node));
    if (newn == NULL) {
        printf("Memory not allocated");
    } else {
        scanf("%s%d%d", newn->name, &newn->numc, &newn->time);
        newn->r_link = NULL;
        newn->l_link = NULL;
    }
    return newn;
}

struct node* insert_end(struct node* head)
{
    struct node* cur = NULL;
    struct node* newn = create_node();
    if (head == NULL)
        {
        head = newn;
    } else {
        cur = head;
        while (cur->r_link != NULL) {
            cur = cur->r_link;
        }
        cur->r_link = newn;
        newn->l_link = cur;
    }
    return head;
}

int candies_alice(struct node* head, int n) {
    struct node* cur = NULL;
    int d, i, A = 0;
    d = n / 2;
    if (head == NULL) {
        printf("error in count");
    } else {
        cur = head;
        for (i = 1; i < d; i++) {
            A = A + (cur->numc);
            cur = cur->r_link;
        }
    }
    return A;
}

int candies_bob(struct node* head, int n)
 {
    struct node* cur = NULL;
    struct node* tem = NULL;
    int d, i, B = 0;
    d = n / 2;
    if (head == NULL) {
        printf("error in count");
    } else {
        cur = head;
        while (cur->r_link != NULL)
            cur = cur->r_link;
        tem = cur->r_link;
        for (i = 1; i < d; i++) {
            B = B + (tem->numc);
            tem = tem->l_link;
        }
    }
    return B;
}

void remain_c(struct node* head, int n, int A, int B) {
    struct node* cur = NULL;
    struct node* tem = NULL;
    struct node* tem1 = NULL;
    int RA = 0, RB = 0, T = 0, R = 0, d;
    d = n / 2;
    if (head == NULL) {
        printf("error in count");
    } else {
        cur = head;
        tem = cur;
        for (int i = 1; i < d; i++) {
            RA = A - cur->numc;
            cur = cur->r_link;
        }
        while (tem->r_link != NULL)
            tem = tem->r_link;
        tem1 = tem->r_link;
        for (int i = 1; i < d; i++) {
            RB = B - tem->numc;
            tem = tem->l_link;
        }
        printf("remain candies of alice: %d\n", RA);
        printf("remain candies of BOB: %d\n", RB);
        T = A + B;
        R = T - (RA + RB);
        printf("total remaining candies in the jar: %d\n", R);
    }
}

int main() {
    struct node* head = NULL;
    int n, A, B;
    printf("enter the total number of candies: ");
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("enter the , name,number, time to eat: \n");
        for (int i = 0; i < n; i++)
            head = insert_end(head);
        A = candies_alice(head, n);
        B = candies_bob(head, n);
        remain_c(head, n, A, B);
    } else {
        printf("invalid input");
    }
    return 0;
}
