typedef char string[256];
typedef struct{
    int run;
    int wait;
    int end;
}condition;
typedef struct p{
    string processName;
    int processTime;
    condition pStatus;
    int priority;
    struct p *next;
}pro;
typedef struct{
    pro *front;
    int length;
}scheduler;
scheduler* create();
typedef int compFunc(void* , void*);
int insert(scheduler *queue,pro *process,compFunc* compare);	
int removeProcess(scheduler *queue);