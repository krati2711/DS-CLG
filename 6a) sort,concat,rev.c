#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

void insert_end(int val, struct node** head) {
    struct node* new = malloc(sizeof(struct node));
    new->val = val;
    new->next = NULL;
    if (*head == NULL) {
        *head = new;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

void del(struct node** head) {
    if (*head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void display(struct node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

struct node* sort(struct node* head) {
    if (head == NULL || head->next == NULL) return head;
    int temp;
    for (struct node* i = head; i->next != NULL; i = i->next) {
        for (struct node* j = i->next; j != NULL; j = j->next) {
            if (i->val > j->val) {
                temp = i->val;
                i->val = j->val;
                j->val = temp;
            }
        }
    }
    return head;
}

struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node* concat(struct node* head1, struct node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    struct node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    while (1) {
        int ch, val, c;
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Sort\n5.Reverse\n6.Concat\n7.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert_end(val, &head1);
                break;

            case 2:
                del(&head1);
                break;

            case 3:
                display(head1);
                break;

            case 4:
                head1 = sort(head1);
                display(head1);
                break;

            case 5:
                head1 = reverse(head1);
                display(head1);
                break;

            case 6:
                head2 = NULL;
                printf("Enter 2nd list\n");
                do {
                    printf("Enter value: ");
                    int n;
                    scanf("%d", &n);
                    insert_end(n, &head2);
                    printf("More? (1/0): ");
                    scanf("%d", &c);
                } while (c == 1);
                head1 = concat(head1, head2);
                printf("Concatenated list: ");
                display(head1);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
