#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"


/* Some of the functions below were taken from "listops.c" written 
 * by Alistair Moffat and was modified by Hasne Hossain accoding to need */


/* makes a node */
node_t* make_node(){
    node_t *new=malloc(sizeof(node_t));
    assert(new);
    new->data=malloc(sizeof(dict_t));
    assert(new->data);

    new->data->censusYear=NULL;
    new->data->BlockID = NULL;
    new->data->propertyId = NULL;
    new->data->basePropertyId=NULL;
    new->data->ClueSmallArea=NULL;
    new->data->tradingName=NULL;
    new->data->industryCode=NULL;
    new->data->industryDescription=NULL;
    new->data->x=NULL;
    new->data->y=NULL;
    new->data->location=NULL;

    new->next=NULL;
    return new;
}

/* makes an empty list */
list_t
*make_empty_list(void) {
    list_t *list;
    list = malloc(sizeof(list_t));
    assert(list!=NULL);
    list->head = list->foot = NULL;
    return list;
}

/* inserts data at foot of the linked list */
list_t
*insert_at_foot(list_t *list, dict_t*value) {
    node_t *new;
    new = make_node();

	free(new->data);
	
    assert(list!=NULL && new!=NULL);
    new->data = value;
    new->next = NULL;
    if (list->foot==NULL) {
        /* this is the first insertion into the list */
        list->head = list->foot = new;
    } else {
        list->foot->next = new;
        list->foot = new;
    }
    return list;
}


/* traverses through linked list and prints data to file */
void traverse_check(list_t *list, char *key, FILE* output){
	node_t *new;
	new =list->head; 
    int found=0;
	
	while((new->data->censusYear[0]) != '\0'){
        if(strcmp(new->data->tradingName, key) == 0){
            found=1;

			fprintf(output, "%s --> Census year: %s || ",key, new->data->censusYear);
			fprintf(output, "Block ID: %s || ",new->data->BlockID);
			fprintf(output, "Property ID: %s || ",new->data->propertyId);
			fprintf(output, "Base property ID: %s || ",new->data->basePropertyId);
			fprintf(output, "CLUE small area: %s || ",new->data->ClueSmallArea);
			fprintf(output, "Industry (ANZSIC4) code: %s || ",new->data->industryCode);
			fprintf(output, "Industry (ANZSIC4) description: %s || ",new->data->industryDescription);
			fprintf(output, "x coordinate: %s || ",new->data->x);
			fprintf(output, "y coordinate: %s || ",new->data->y);
			fprintf(output, "Location: %s || \n",new->data->location);

            new=new->next;
        }
        else{
            new=new->next;
        }
    }
    if(found==0){
        fprintf(output, "%s --> NOT FOUND\n", key);
    }
  
    free(key);
    key = NULL;
}

/* frees the allocated memories in the linked list */
void
free_list(list_t *list) {
	node_t *curr, *prev;
	assert(list!=NULL);
	curr = list->head; 
	while (curr) {
		prev = curr;
		curr = curr->next;
        free(prev->data->censusYear); 
        free(prev->data->BlockID); 
        free(prev->data->propertyId); 
        free(prev->data->basePropertyId);
        free(prev->data->ClueSmallArea); 
        free(prev->data->tradingName); 
        free(prev->data->industryCode);
        free(prev->data->industryDescription);
        free(prev->data->x);
        free(prev->data->y);
        free(prev->data->location); 
        free(prev->data);
		free(prev);
	}
	free(list);
}