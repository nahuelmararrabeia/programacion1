#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#define AL_INITIAL_VALUE  10

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}

int al_add(ArrayList* pList,void* pElement)
{
    if(pList!=NULL||pElement!=NULL)
    {
        pList->pElements[pList->size]=pElement;
        pList->size++;
    }else{
        return -1;
    }
    if(pList->size=>pList->reservedSize)
    {
        void** pAux;
        pList->reservedSize+=10;
        pAux = (void**)realloc(pList->lista,sizeof(void*)*pList->reservedSize);
        if(pAux==NULL)
        {
            printf("No hay espacio en memoria");
            return -1;
        }else{
            pList->pElements=pAux;
        }
    }
    return 0;
}

int al_len(ArrayList* pList)
{
    int retorno;
    if(pList==NULL)
    {
        retorno= -1;
    }else{
        retorno=pList->size;
    }
    return retorno;
}
