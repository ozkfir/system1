
#include <stdio.h>
#include <stdlib.h>
#include "AdptArray.h"

int increase_arr(PAdptArray adpt,int i)
{
    adpt->arr=(PElement*)realloc(adpt->arr,(i+1)* sizeof(PElement));
    if (adpt->arr == NULL){
        printf("problem with memory");
        return FAIL;
    }
    for (int j = adpt->size; j <=i ; j++) {
        adpt->arr[j]=NULL;
    }
    adpt->size=i+1;
    return SUCCESS;
}




PAdptArray CreateAdptArray(COPY_FUNC copyFunc, DEL_FUNC delFunc,PRINT_FUNC printFunc){
    PAdptArray adpt = NULL;
    adpt = (PAdptArray)calloc(1, sizeof(AdptArray));
    if (adpt == NULL) {
        printf("problem with memory");
        exit(1);
    }
    adpt->size=0;
    adpt->arr = (PElement*)calloc(1, sizeof(PElement));
    if (adpt->arr == NULL) {
        printf("problem with memory");
        free(adpt);
        exit(1);
    }
    adpt->f_del=delFunc;
    adpt->f_copy=copyFunc;
    adpt->f_print=printFunc;
    return adpt;
}


void DeleteAdptArray(PAdptArray adpt){
    if(adpt!=NULL) {
        if (adpt->arr != NULL) {
            for (int i = 0; i < adpt->size; i++) {
                if (adpt->arr[i] != NULL)
                    adpt->f_del(adpt->arr[i]);
            }
            free(adpt->arr);
        }
    free(adpt);
    }
}


Result SetAdptArrayAt(PAdptArray adpt, int i, PElement pElement){////how can fail
    if(adpt->size<=i)
        if(!increase_arr(adpt,i))
            return FAIL;
    if((adpt->arr[i])!=NULL)
        free(adpt->arr[i]);
    adpt->arr[i]=adpt->f_copy(pElement);
    return SUCCESS;
}



PElement GetAdptArrayAt(PAdptArray adpt, int i)
{
    if(adpt->size <= i)
    {
     return NULL;
    }
    if((adpt->arr)[i]==NULL)
        return NULL;
    return adpt->f_copy(adpt->arr[i]);
}



int GetAdptArraySize(PAdptArray adpt)
{
    return adpt->size;
}


void PrintDB(PAdptArray adpt){
    for (int i = 0; i < adpt->size; i++)
        if (adpt->arr[i] != NULL)
            adpt->f_print(adpt->arr[i]);
}

