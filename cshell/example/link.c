#include <stdio.h>
#include <malloc.h>


struct linkobj{
    int value;
};

struct linklist{
    struct linkobj *item;
    struct linklist *next;
    struct linklist *prev;
    int key;
};


//int linkCreate( struct link *p_list )
//{
//    struct link *p = NULL;
//    p_list = (struct link *)malloc( sizeof(struct link) );
//    return 1;
//}


struct linklist *linkCreate( struct linkobj *obj )
{
    struct linklist *node = (struct linklist*) malloc( sizeof(struct linklist) );
    node->item = obj;
    node->next = NULL;
    node->prev = NULL;
    node->key = 0;
    return  node;
}
struct linklist *linkInsert( struct linklist *link_prev, struct linkobj *obj )
{
    struct linklist *node = (struct linklist*) malloc( sizeof(struct linklist) );
    node->next = link_prev->next;
    node->prev = link_prev;
    node->key  = link_prev->key++;
    node->item = obj;

    link_prev->next = node;

    if( node->next ) {
        struct linklist *step = node->next;
        step->prev = node;
        while( step ) {
            step->key++;
            step = step->next;
        }
    }

    return  node;
}
struct linklist *linkAppend( struct linklist *link_prev, struct linkobj *obj )
{
    while( link_prev->next ){
        link_prev = link_prev->next;
        continue;
    }
    struct linklist *node = (struct linklist*) malloc( sizeof(struct linklist) );
    link_prev->next = node;
    node->item = obj;
    node->next = NULL;
    return  node;
}

struct linklist *linkReset( struct linklist *link )
{

}

struct linklist *linkNext( struct linklist *link_prev )
{
}

struct linklist *linkLast( struct linklist *link_prev )
{
}

struct linklist *linkCurrent( struct linklist *link_prev )
{
}






int main() 
{
    struct linkobj *obj1 = (struct linkobj *)malloc( sizeof(struct linkobj) );
    struct linkobj *obj2 = (struct linkobj *)malloc( sizeof(struct linkobj) );

    obj1->value = 1;
    struct linklist *node_p = linkCreate( obj1 );
    printf( "%d\n", node_p->item->value );

    obj2->value = 2;
    struct linklist *node_q = linkInsert( node_p, obj2 );
    printf( "%d\n", node_q->item->value );
    printf( "%d\n", node_p->item->value );

    return 0;
}
