#include <malloc.h>


//struct linkobj{
//    int value;
//};

typedef struct linklist{
    struct linkobj *item;
    struct linklist *next;
    struct linklist *prev;
    int key;
} Link_List;

Link_List *linkReset( Link_List *link_node )
{
    Link_List *first = link_node;
    while( first->prev ) {
        first = first->prev;
    }
    return first;
}

Link_List *linkNext( Link_List *link_node )
{
    Link_List *next = ( link_node->next ) ? link_node->next : NULL;
    return next;
}

Link_List *linkLast( Link_List *link_node )
{
    Link_List *last = link_node;
    while( last->next ) {
        last = last->next;
    }
    return last;
}

int linkCurrent( Link_List *link_node )
{
    return link_node->key;
}

int linkLength( Link_List *link_node )
{
    Link_List *last = linkLast(link_node);
    return last->key + 1;
}

Link_List *linkInit()
{
    Link_List *node = (Link_List*) malloc( sizeof(Link_List) );
    node->item = NULL;
    node->next = NULL;
    node->prev = NULL;
    node->key = 0;
    return  node;
}

//Link_List *linkCreate( NULL, struct linkobj *obj )
Link_List *linkCreate( Link_List *node, struct linkobj *obj )
{
    if( node ) {
        Link_List *node = linkInit();
    }
    node->item = obj;
    node->next = NULL;
    node->prev = NULL;
    node->key = 0;
    return  node;
}

Link_List *linkInsert( Link_List *link_prev, struct linkobj *obj )
{
    Link_List *node = (Link_List*) malloc( sizeof(Link_List) );
    node->next = link_prev->next;
    node->prev = link_prev;
    node->key  = link_prev->key + 1;
    node->item = obj;

    link_prev->next = node;

    if( node->next ) {
        Link_List *step = node->next;
        step->prev = node;
        while( step ) {
            step->key++;
            step = step->next;
        }
    }

    return  node;
}

Link_List *linkAppend( Link_List *link_node, struct linkobj *obj )
{
    Link_List *last = linkLast( link_node );
    Link_List *node = (Link_List*) malloc( sizeof(Link_List) );
    last->next = node;

    node->item = obj;
    node->key  = last->key + 1;
    node->prev = link_node;
    node->next = NULL;
    return  node;
}

//int main() 
//{
//    struct linkobj *obj1 = (struct linkobj *)malloc( sizeof(struct linkobj) );
//    struct linkobj *obj2 = (struct linkobj *)malloc( sizeof(struct linkobj) );
//
//    obj1->value = 1;
//    struct linklist *node_1 = linkCreate( obj1 );
//    printf( "%d\n", node_1->key );
//
//    obj2->value = 2;
//    struct linklist *node_2 = linkAppend( node_1, obj2 );
//    printf( "%d\n", node_2->key );
//    printf( "%d\n", node_1->key );
//
//    int length = linkLength(node_2);
//    printf( "%d\n", length );
//
//    Link_List *node_first = linkReset( node_2 );
//    printf( ">>>%d\n", node_first->key );
//
//
//    return 0;
//}
