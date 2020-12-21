#ifndef DSUP_H
#define DSUP_H

#define SIZE 10
#define MAXKEYSIZE 128+2
#define MAXLINESIZE 512+2

typedef struct{
    char* censusYear; 
    char* BlockID;  
    char* propertyId; 
    char* basePropertyId; 
    char* ClueSmallArea; 
    char* tradingName; 
    char* industryCode; 
    char* industryDescription; 
    char* x;  
    char* y;
    char* location;  
}dict_t; 

typedef struct node node_t;

struct node {
	dict_t *data; 
	node_t *next;
};

typedef struct {
	node_t *head;
	node_t *foot;
} list_t;  

#endif

node_t* make_node();
list_t *make_empty_list(void);
list_t *insert_at_foot(list_t *list, dict_t*value);
void traverse_check(list_t *list, char *key, FILE* output);
void free_list(list_t *list);