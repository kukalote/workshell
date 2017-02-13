#include <malloc.h>


//struct linkobj{
//    int value;
//};

struct linklist{
    struct linkobj *item;
    struct linklist *next;
    struct linklist *prev;
    int key;
};


struct linklist *linkCreate( struct linkobj *obj )
{
    struct linklist *node = (struct linklist*) malloc( sizeof(struct linklist) );
    node->item = obj;
    node->next = NULL;
    return  node;
}
struct linklist *linkInsert( struct linklist *link_prev, struct linkobj *obj )
{
    struct linklist *node = (struct linklist*) malloc( sizeof(struct linklist) );
    node->next = link_prev->next;
    link_prev->next = node;
    node->item = obj;
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

//int main() 
//{
//    struct linkobj *obj1 = (struct linkobj *)malloc( sizeof(struct linkobj) );
//    struct linkobj *obj2 = (struct linkobj *)malloc( sizeof(struct linkobj) );
//
//    obj1->value = 1;
//    struct linklist *node_p = linkCreate( obj1 );
//    printf( "%d\n", node_p->item->value );
//
//    obj2->value = 2;
//    struct linklist *node_q = linkInsert( node_p, obj2 );
//    printf( "%d\n", node_q->item->value );
//    printf( "%d\n", node_p->item->value );
//
//    return 0;
//}
