#include<stdio.h>

#define MAX_NAME_LENGHT 100

typedef struct node{
    char firstname[MAX_NAME_LENGHT + 1];
    struct node * father;
    struct node * mother;
    struct node * marriedto;
} Node;

void print_tree(Node *person){
    if (person == NULL)               
        return;

    printf("\n");
    printf("Name  : %s\n", person->firstname);
    printf("Mother: %s\n", person->mother ? person->mother->firstname : "-");
    printf("Father: %s\n", person->father ? person->father->firstname : "-");
    printf("\n");

    
    print_tree(person->mother);
    print_tree(person->father);
}


int main(){

    Node zhelyazko = {"zhelyazko", NULL, NULL, NULL};
    Node tinka = {"tinka", NULL, NULL, NULL};

    zhelyazko.marriedto = &tinka;
    tinka.marriedto = &zhelyazko;
    
    Node nikola = {"nikola", NULL, NULL, NULL};
    Node zlatka = {"zlatka", NULL, NULL, NULL};

    nikola.marriedto = &zlatka;
    zlatka.marriedto = &nikola;
    
    Node krustyo = {"krustyo", NULL, NULL, NULL};
    Node vanya = {"vanya", &nikola, &zlatka, NULL};

    krustyo.marriedto = &vanya;
    vanya.marriedto = &krustyo;
    
    Node rumen = {"rumen", &zhelyazko, &tinka, NULL};
    Node kapka = {"kapka", NULL, NULL, NULL};

    rumen.marriedto = &kapka;
    kapka.marriedto = &rumen;

    Node nikolay = {"nikolay", &krustyo, &vanya, NULL};
    Node tanya = {"tanya", &rumen, &kapka, NULL};

    nikolay.marriedto = &tanya;
    tanya.marriedto = &nikolay;

    Node kaloyan = {"kaloyan", &nikolay, &tanya, NULL};

    kaloyan.marriedto = NULL;
    
    Node *ptr = &kaloyan;

    print_tree(ptr);
}