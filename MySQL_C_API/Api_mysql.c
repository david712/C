#include "Api_mysql.h"

void Set_DB_User(char* id, char* pw)
{
	memset(UserID, 0, sizeof(UserID));
	memset(UserPW, 0, sizeof(UserPW));
	if(id != NULL)	memcpy(UserID, id, strlen(id));
	if(pw != NULL)	memcpy(UserPW, pw, strlen(pw));
}

void Set_Database(char* db_name)
{
	memset(Database, 0, sizeof(Database));
	if(db_name != NULL)	memcpy(Database, db_name, strlen(db_name));
}

void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);        
}

void SendQuery(char* a_query)
{
	if(Database == NULL)		printf("(!) Set 'Database' first\n");
	if(UserID == NULL)			printf("(!) Set 'User ID of DB' first\n");
	if(UserPW == NULL)			printf("(!) Set 'User PW of DB' first\n");

	MYSQL *con = mysql_init(NULL);
	if (con == NULL) 
	{
		fprintf(stderr, "%s \n", mysql_error(con));
		exit(1);
	}

	if (mysql_real_connect(con, "localhost", UserID, UserPW, Database, 0, NULL, 0) == NULL)
		finish_with_error(con);
	if (mysql_query(con, a_query))
	    finish_with_error(con);

	mysql_close(con);
}

/*
void Query_NoResult(char a_db, char* a_query)
{
	mysql_close(Single_Query(a_db, a_query));
}

void Query_Result(char a_db, char* a_query)
{
	MYSQL* con = Single_Query(a_db, a_query);
	Result_Analyze(con);
}

MYSQL* Single_Query(char* a_db, char* a_query)
{
	MYSQL* stMYSQL = mysql_Init(NULL);
	MYSQL_ST_CHK(stMYSQL);

	if(UserID != NULL && UserPW != NULL)
	{
		MYSQLCHK(stMYSQL, mysql_real_connect(stMYSQL, MYSQL_HOST, UserID, UserPW, a_db, 0, NULL, 0));
		MYSQLCHK(stMYSQL, mysql_query(stMYSQL, a_query));
		return stMYSQL;
	}
	return NULL;	
}

void Result_Analyze(MYSQL* a_stMysql)
{
	int num_fields, i;
	char** column_header;
	
	MYSQL_RES*		stMYSQL_RES;
	MYSQL_ROW		row;
	MYSQL_FIELD*	field;

	stMYSQL_RES = mysql_store_result(a_stMysql);
	MYSQL_ST_CHK(stMYSQL_RES);

//GET COLUMN HEADER
	num_fields = mysql_num_fields(stMYSQL_RES);
	column_header = (char**)malloc(sizeof(char*) * num_fields);
	for(i = 0; i < num_fields; i++)
	{
		column_header[i] = (char *)malloc(sizeof(char) * MAX_STRING_LEN);
	}
	while(field = mysql_fetch_field(stMYSQL_RES))
	{
		sprintf(column_header[num_fields - field], "%s", field->name);
	}


//TODO
	while(row = mysql_fetch_row(stMYSQL_RES))
	{
		for(i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i]:"NULL");
		}
	}
	mysql_free_result(stMYSQL_RES);
	mysql_close(a_stMysql);
}

//--------------------------------------------------------------------------------------------------
void DB_Create(char* db_name)
{
	char Query[128] = {0,};
	sprintf(Query, "CREATE DATABASE %s", db_name);
	SingleQuery(NULL, Query);
}

void DB_Delete(char* db_name)
{
	char Query[128] = {0,};
	sprintf(Query, "DROP DATABASE %s", db_name);
	SingleQuery(NULL, Query);
}

void DB_ShowList(void)
{
	char Query[128] = {0,};
	sprintf(Query, "SHOW databases");
	SingleQuery(NULL, Query);
}
//--------------------------------------------------------------------------------------------------
void Table_Create(char* db, char* table)
{
	//sprintf(Query, "CREATE TABLE %s(Id INT, Name TEXT, Price INT)", table);
}

void Table_Delete(char* db, char* table)
{
	//sprintf(Query, "DROP TABLE IF EXISTS %s", table);
}

void Table_CheckColumnInfo(char* db, char* table)
{
	
}

void Table_ShowList(char* db)
{
	//sprintf(Query, "SHOW tables");
}
*/