#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode=NULL;
    if(this!=NULL&&nodeIndex>=0&&this->size>nodeIndex){

        int pSize=0;
        int indexNodoActual=0;
        pNode = this->pFirstNode;
        pSize = this->size;


        while(indexNodoActual<pSize)
        {
            if(indexNodoActual==nodeIndex)
            {
                break;
            }

            if(pNode!=NULL)
            {
                pNode = pNode->pNextNode;
                indexNodoActual++;
            }
        }


    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux=-1;

    if(this!=NULL&&nodeIndex>=0&&ll_len(this)>=nodeIndex){
    //int pFirstNode = this->pFirstNode;
    Node* auxNode=NULL;
    Node* node= (Node*)malloc(sizeof(Node));
    node->pElement=pElement;

    if(nodeIndex==0){
       node->pNextNode=this->pFirstNode;
       this->pFirstNode=node;
       this->size++;
       returnAux=0;
    }else{
       auxNode=getNode(this,nodeIndex-1);
       node->pNextNode=auxNode->pNextNode;
       auxNode->pNextNode=node;
       this->size++;
       returnAux=0;
        }

    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL){
        addNode(this,ll_len(this),pElement);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* node=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this)){
        node=getNode(this,index);
        returnAux=node->pElement;
    }


    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* node;
    if(this!=NULL && index>=0 && index<ll_len(this)){
        node=getNode(this,index);
        node->pElement=pElement;
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodeAEliminar;
    Node* nodeAux;
    if(this!=NULL && index>=0 && index<ll_len(this)){
        if(index==0){
            nodeAEliminar=this->pFirstNode;
            this->pFirstNode=nodeAEliminar->pNextNode;
            free(nodeAEliminar);
            this->size--;
            returnAux=0;
        }else{
            nodeAEliminar=getNode(this,index);
            nodeAux=getNode(this,index-1);
            nodeAux->pNextNode=nodeAEliminar->pNextNode;
            free(nodeAEliminar);
            this->size--;
            returnAux=0;
        }

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* nodeAEliminar;
    Node* nodeAux;
    int i;
    int len=ll_len(this);
    if(this!=NULL){
        for(i=0;i<len;i++){
            nodeAEliminar=getNode(this,i);
            free(nodeAEliminar);
            this->size--;
        }
    returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        ll_clear(this);
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodeAux;
    int len=ll_len(this);
    int i;
    if(this!=NULL){
        for(i=0;i<len;i++){
            nodeAux=getNode(this,i);
            if(nodeAux->pElement==pElement){
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len= ll_len(this);
    if(this!=NULL){
        returnAux=1;
        if(len>0){
        returnAux=0;
        }

    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    if(this!=NULL && index>=0 && index<=len){
        returnAux=addNode(this,index,pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);
    if(this!=NULL && index>=0 && index<=len){
        returnAux=ll_get(this,index);
        ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;
    if(this!=NULL){
        returnAux=0;
        index=ll_indexOf(this,pElement);
        if(index!=-1){
            returnAux=1;
        }

    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len1=ll_len(this);
    int len2=ll_len(this2);
    int i;
    int aux;
    if(this!=NULL && this2!=NULL){
        returnAux=0;
        for(i=0; i<len1; i++){
            aux=ll_contains(this,ll_get(this2,i));
            if(aux==0){
                break;
            }else{
               if(aux==1){
                 returnAux=1;
               }

            }


        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* auxNode;
    void* pElement;
    int len=ll_len(this);
    int flag=0;
    int i;
    if(this!=NULL && from>=0 && to>=from && to<=len){
    int from2=from;
        for(i=0; i<len; i++){
                if(flag==0){
                cloneArray=ll_newLinkedList();
                auxNode=getNode(this,from);
                pElement=auxNode->pElement;
                addNode(cloneArray,0,pElement);
                flag++;
            }else{
                from2++;
                auxNode=getNode(this,from2);
                pElement=auxNode->pElement;
                addNode(cloneArray,i,pElement);
            }

        }

    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL){
    int len=ll_len(this);
    cloneArray=ll_subList(this,0,len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int len = ll_len(this);
    void* pElement;
    void* pElement2;
    void* pElementAux;
    int i;
    int flag=1;
    if(this!=NULL && pFunc!=NULL && (order==1 || order ==0)){
    while(flag==1){
        flag=0;
        for(i=0;i<len-1;i++){
            pElement=ll_get(this,i);
            pElement2=ll_get(this,i+1);
          if((order==0 && pFunc(pElement,pElement2)<0)||( order==1 && pFunc(pElement,pElement2)>0)){
                pElementAux=pElement;
                ll_set(this,i,pElement2);
                ll_set(this,i+1,pElementAux);
                returnAux=0;
                flag=1;

          }



        }


    }

}


    return returnAux;

}



LinkedList* ll_filter (LinkedList*this,int (*pFunc)(void*)){
    LinkedList* cloneArray = NULL;
    void* pElemente;
    void* pAux;
    int len = ll_len(this);
    int i;

    if(this!=NULL && pFunc!=NULL){
        cloneArray=ll_newLinkedList();
        for(i=0;i<len;i++){

        pElemente=ll_get(this,i);

        if(pFunc(pElemente)==1){
            pAux=pElemente;
            ll_add(cloneArray,pAux);
        }


        }

    }


    return cloneArray;
}

LinkedList* ll_map(LinkedList* this, int (*pFunc)(void*)){
    int ret=-1;
    void* pElemente;
    int len = ll_len(this);
    int i;

    if(this!=NULL && pFunc!=NULL){
        for(i=0;i<len;i++){
        pElemente=ll_get(this,i);
        pFunc(pElemente);
        ret=0;

        }


    }



    return ret;

}

