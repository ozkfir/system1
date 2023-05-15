

#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main() {
    printf("----------------------------------------------------------------------\n");

    printf("Stormlight:\n");
    pbook book1 = creat_book("book1",2001);
    pbook book2=  creat_book("book2",2002);
    pbook book3 = creat_book("book3",2003);
    PAdptArray Stormlight = CreateAdptArray(copy_book,delete_book,print_book);

    SetAdptArrayAt(Stormlight,0,book1);
    SetAdptArrayAt(Stormlight,1,book2);
    SetAdptArrayAt(Stormlight,2,book3);
    printf("Stormlight size is %d\n\n",GetAdptArraySize(Stormlight)); // print 3


    printf("print the Stormlight-\n");
    PrintDB(Stormlight);

    SetAdptArrayAt(Stormlight,0,book3);//You can replace a new object with an old one without memory leaks
    SetAdptArrayAt(Stormlight,1,book3);
    printf("\n\n");

    printf("print the Stormlight\n");
    PrintDB(Stormlight);

    pbook book4= GetAdptArrayAt(Stormlight,0);//Gets a copy so if we delete the Stormlight and Other books it won't be deleted
    delete_book(book1);
    delete_book(book2);
    delete_book(book3);
    DeleteAdptArray(Stormlight);

    printf("\nStormlight and Other books deleted\n");
    printf("book4\n");
    print_book(book4);

    printf("----------------------------------------------------------------------\n");

    printf("\nTSA_caracters1:\n\n");
    PAdptArray TSA_caracters1 = CreateAdptArray(copy_person,delete_person,print_person);

    pperson Character1 = creat_person("Kaladin","Stormblessed", 100);
    pperson Character2 = creat_person("Shallan","Davar", 101);
    pperson Character3 = creat_person("Dalinar","Kholin", 102);

    printf("the size is %d  (TSA_caracters empty)\n",GetAdptArraySize( TSA_caracters1));//should print 0(TSA_caracters empty)


    SetAdptArrayAt(TSA_caracters1,0,Character1);
    printf("the size is %d  ( object in 0th)\n",GetAdptArraySize( TSA_caracters1));  //should print 1 The (In TSA_caracters there is an object in the 0th place)


    SetAdptArrayAt(TSA_caracters1,19,Character2);
    printf("the size is %d  ( object in 19th)\n",GetAdptArraySize( TSA_caracters1));  //should print 20 (In TSA_caracters there is an object in the 19th place)

    printf("\nprint TSA_caracters1\n");
    PrintDB(TSA_caracters1);
    printf("\n\n");
    DeleteAdptArray(TSA_caracters1);//TSA_caracters1 deleted but the caracters are not
    printf("TSA_caracters deleted but the caracters are not\n");


    printf("print caracterss\n");
    print_person(Character1);
    print_person(Character2);






    printf("----------------------------------------------------------------------\n");
    printf("\nTSA_caracters2:\n");
    PAdptArray TSA_caracters2=CreateAdptArray(copy_person,delete_person,print_person);
    SetAdptArrayAt(TSA_caracters2,9,Character1);
    SetAdptArrayAt(TSA_caracters2,5,Character3);
    SetAdptArrayAt(TSA_caracters2,3,Character3);
    SetAdptArrayAt(TSA_caracters2,10,Character3);//You can enter the same object several times


    delete_person(Character1);
    delete_person(Character2);
    delete_person(Character3);//caracters deleted but the TSA_caracters2 are not

    printf("\npcaracters deleted but the TSA_caracters2 are not");
    printf("\nprint TSA_caracters2\n");
	PrintDB(TSA_caracters2);//Prints by index and not by insertion order


    printf("\nprint TSA_caracters2 with index\n");
    for (int i = 0; i <GetAdptArraySize(TSA_caracters2) ; ++i) {//print in the same order with index
        if(GetAdptArrayAt(TSA_caracters2,i)!=NULL){
        printf("%d-",i);
        print_person(GetAdptArrayAt(TSA_caracters2,i));}
    }
    printf("----------------------------------------------------------------------\n");


    DeleteAdptArray(TSA_caracters2);
	return 0;
}





