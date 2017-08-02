#include <my_global.h>
#include <mysql.h>

#define MAX_STRING_LEN  32

//VARIABLES
char UserID[16];
char UserPW[16];
char database[32];
char** table_name = {"Temperature", "Humidity"};

void Set_DB_User(char* id, char* pw);

/*
typedef enum
{
    NO_ERROR = 0,
    INIT_ERROR,
    FUNC_ERROR,
}   MYSQL_STATUS;

#define MYSQL_ST_CHK(con) \
{   \
    if (con == NULL) {  \
        fprintf(stderr, "%s \n", mysql_error(con));    \
        return NULL;    \
    }  \
}

#define MYSQLCHK(con, func) \
{   \
    if (func == NULL) {  \
        fprintf(stderr, "%s \n", mysql_error(con));    \
		mysql_close(con);	\
        return NULL;    \
    }  \
}
*/