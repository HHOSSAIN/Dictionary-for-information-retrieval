#ifndef DSUP_H
#define DSUP_H

#define SIZE 50
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

void read_cyear(dict_t *line, FILE* fp);
void read_block_id(dict_t *line, FILE* fp);
void read_property_id(dict_t *line, FILE* fp);
void read_base_property_id(dict_t *line, FILE* fp);
void read_clue_area(dict_t *line, FILE* fp);
void read_trading_name(dict_t *line, FILE* fp);
void read_industry_code(dict_t *line, FILE* fp);
void read_industry_description(dict_t* line, FILE* fp);
void read_x(dict_t *line, FILE* fp);
void read_y(dict_t *line, FILE* fp);
void read_location(dict_t* line, FILE* fp);
void read_1_line(dict_t* line, FILE*fp);
void print_1_line(dict_t* line, FILE* fp); 