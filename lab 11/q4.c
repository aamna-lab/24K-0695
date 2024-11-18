#include <stdio.h>
#include <string.h>
struct Book{
    char title[50];
    char author[50];
    int year;
    float price;
}b1,b2,b3;
void display(struct Book book){
    int i;
    printf("Book Title : %s\n", book.title);
    printf("Author : %s\n" , book.author );
    printf("Publication Year : %d\n", book.year);
    printf("Price : %.2f\n ", book.price);
    printf("\n \n");
}
void search(struct Book books[], int size){
    char t[50];
    printf("Enter title of book ");
    getchar();
    fgets(t, sizeof(t), stdin);
    for(int i=0; i<size ; i++){
        if(strcmp(t,books[i].title)==0){
            display(books[i]);
            return;
        }else 
        printf("Error! no book found");
    }
    
}
void searchAuthor(struct Book books[], int size){
    char a[50];
    printf("Enter author's name");
    getchar();
    fgets( a, sizeof(a), stdin);
    for(int i=0; i<size ; i++){
        if(strcmp(a,books[i].author)==0){
            display(books[i]);
            return;
        }
        printf("Error! no book found");
    }
}
int main(){
    int choice;
    struct Book b1[3]={
        {"My Sister's Keeper" , "Jodi Picoult" , 2007 , 2500.5},
        {"House Of Lies" , "Ian Rankins" , 2010 , 3050.0},
        {"Weirdest Book" , "Aamna Rizwan" , 2020 , 1230.5}
    };
    for(int i =0;i<3;i++){
    display(b1[i]);}
    printf("Enter '1' to search book by author or Enter '2' to search book by title");
    scanf("%d", &choice);
    if(choice==1){
        searchAuthor(b1,3);
    }else if(choice==2){
        search(b1,3);
    } 
 
}
