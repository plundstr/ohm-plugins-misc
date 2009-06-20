#ifndef __DBUS_LIST_H__
#define __DBUS_LIST_H__

/*
 * a doubly-linked list
 */

typedef struct list_hook_s list_hook_t;
struct list_hook_s {
    list_hook_t *prev;
    list_hook_t *next;
};



/********************
 * list_init
 ********************/
static inline void
list_init(list_hook_t *hook)
{
    hook->prev = hook->next = hook;
}


/********************
 * list_empty
 ********************/
static inline int
list_empty(list_hook_t *list)
{
    return (list->prev == list && list->next == list);
}


/********************
 * list_append
 ********************/
static inline void
list_append(list_hook_t *list, list_hook_t *elem)
{
    list_hook_t *prev;

    if (list_empty(list)) {
        list->next = elem;
        elem->prev = list;
        list->prev = elem;
        elem->next = list;
    }
    else {
        prev = list->prev;
        prev->next = elem;
        elem->next = list;
        list->prev = elem;
        elem->prev = prev;
    }
}


/********************
 * list_delete
 ********************/
static inline void
list_delete(list_hook_t *elem)
{
    list_hook_t *prev, *next;
    
    if (!list_empty(elem)) {
        prev = elem->prev;
        next = elem->next;
        prev->next = next;
        next->prev = prev;
        elem->prev = elem->next = elem;
    }
}


/********************
 * list_foreach
 ********************/
#define list_foreach(list, p, n) \
    for (p = (list)->next, n = p->next; p != (list); p = n, n = n->next)


/********************
 * list_entry
 ********************/
#define MEMBER_OFFSET(type, member) ((int)(&(((type *)NULL)->member)))
#define list_entry(ptr, type, member) \
    (type *)(((void *)ptr) - MEMBER_OFFSET(type, member))



#endif /* __DBUS_LIST_H__ */


/* 
 * Local Variables:
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 * vim:set expandtab shiftwidth=4:
 */

