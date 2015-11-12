#define DATABASE "database.dat"
#define TEMP_DATABASE "database_temp.dat"
#define TEST_SIZE 53
#define NUMBER_SIZE 6
#define FIRSTNAME_SIZE 31
#define LASTNAME_SIZE 31
#define ADDRESS_SIZE 51
#define DEPARTMENT_SIZE 11
#define DURATION_SIZE 3
#define OPTION_SIZE 2
#define KEY_SIZE 6
#define SEARCH_SIZE 31


/* Template for the header record */
struct header_rec
{
	int total;
	int active;
	int deleted;
	long int cur_number;
} header;



/* Template for the employee record */
struct record
{
	char number[NUMBER_SIZE];
	char firstName[FIRSTNAME_SIZE];
	char lastName[LASTNAME_SIZE];
	char address[ADDRESS_SIZE];
	char department[DEPARTMENT_SIZE];
	char duration[DURATION_SIZE];
} employee;



/* PROTOTYPES */
char menu(FILE*);
void pause();
void read_header(FILE*);
int write_header(FILE*);
int add_employee(FILE*);
int get_input(char*, int, FILE*);
void clear_stdin();
void delete_employee(FILE*);
void list_employees(FILE*);
void compact_records(FILE*);
void quick_sort(struct record[], int, int);
int partition(struct record[], int, int);