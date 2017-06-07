typedef struct {
    int size;
    void** pElements;
    int reservedSize;


    int (*add)();
    int (*len)();
    int (*contains)();
    int (*set)();
    int (*remove)();
    int (*clear)();
    int (*push)();
    int (*indexOf)();
    int (*isEmpty)();
    void* (*get)();
    void* (*pop)();
    int (*containsAll)();
    int (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subList)();
    int (*deleteArrayList)();
}ArrayList;

ArrayList* al_newArrayList(void);

