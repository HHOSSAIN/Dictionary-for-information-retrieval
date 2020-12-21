/*  Creating a simple dictionary based on an unsorted linked list to 
 *  store information from the City of Melbourne Census of Land Use 
 *  and Employment (CLUE).
 * 
 * Coded by student name:HASNE HOSSAIN *
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"
#include "dsup.h"

int main(int argc, char **argv){
    FILE *fp;
    FILE *output;

    char *line = NULL;  
    size_t lineBufferLength = 0;    
    
    fp= fopen(argv[1], "r");
    assert(fp);
 
	/* using getline to get rid of the headers  */
    getline(&line, &lineBufferLength, fp );
	
    node_t* nodp;     
    list_t *list = make_empty_list(); 
	
	/* PART1- going thorugh data in csv file and storing them via 
	 *  linked list*/
    do{
        nodp= make_node();  
        assert(nodp);
        read_1_line(nodp->data,fp); 

        list=insert_at_foot(list,nodp->data); 
        free(nodp);                          
            
    }while ((list->foot->data->censusYear[0]) != '\0');
    /*......................end of part1.............................*/

	/* PART2- taking the keys from stdin, searching if that key 
	 * is in the dictionary and printing the values of the key if 
	 *  the key is present in the dictionary
	 *  */
    output=fopen(argv[2], "w");
    assert(output);
    char *key =malloc(sizeof(char)*MAXKEYSIZE);
    assert(key);
    int l=0;

    char *key2=NULL;
    while (fgets(key, MAXKEYSIZE, stdin) != NULL){  
        l= strlen(key);

        /* making string with absence of '\r' or '\n' at its end */
        if(((key[l-2]) == '\r') || ((key[l-2])=='\n')){
            key2 = malloc(sizeof(char)*(l-1));
            assert(key2);
            int i;

            for(i=0; i<(l-2); i++){
                key2[i]=key[i];
            }
            key2[i]='\0';

            traverse_check(list,key2, output);
        }
		else if(((key[l-1]) == '\r') || ((key[l-1])=='\n')){
                key2 = malloc(sizeof(char)*(l));
                assert(key2);
                int i;

                for(i=0; i<(l-1); i++){
                    key2[i]=key[i];
                }
                key2[i]='\0';

                traverse_check(list,key2, output);
        }
        else{
            traverse_check(list,key, output);
			key =malloc(sizeof(char)*MAXKEYSIZE);
            assert(key); 
        }
    }
    /*.............end of part 2................*/

    /* closing the files and freeing any allocated memory left
       to be freed */
    if(key != NULL){
        free(key);
    }  
    
    fclose(fp);
    fclose(output);

    free_list(list);
    free(line);
   
    return 0;

	/*................................DONE............................... */
	/*                         ALGORITHMS ARE FUN!                        */
}