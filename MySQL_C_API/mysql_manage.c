#include <stdbool.h>
#include <unistd.h>
#include "Api_mysql.h"

bool IsLogIn;
char LogInID[32] = {0,};
char LogInPW[32] = {0,};

bool Login_Message(void)
{
	if(!IsLogIn)
	{
		printf("(!) 로그인 후 이용\n");
		sleep(3);
		return true;
	}
	else
	{
		return false;
	}
}

int SelectMenu(void)
{
	int menu_num;
	system("clear");
	printf("# MySQL #\n");
	if(IsLogIn)		printf("0 / 로그아웃 \n");
	else			printf("0 / 로그인 \n");
	printf("1 / 데이터베이스 관리 \n");
    printf("2 / 데이터 삽입(Create) \n");
	printf("3 / 데이터 조회(Read) \n");
    printf("4 / 데이터 갱신(Update) \n");
	printf("5 / 데이터 삭제(Delete) \n");	
	scanf("%d", &menu_num);
	return menu_num;
}

void Menu_LogIn(void)
{
	int Sel;
	char DB[16] = {0,};
	char ID[16] = {0,};
	char PW[16] = {0,};

	if(IsLogIn)		printf(" 0 / 로그아웃 \n");
	else			printf(" 0 / 로그인 \n");
	printf("   1. 계정 추가\n");
	if(IsLogIn)		printf("   2. 로그아웃\n");
	else			printf("   2. 로그인\n");
	scanf("%d", &Sel);

	system("clear");
	switch(Sel)
	{
		case 1:
		//	TODO > DB 리스트 디스플레이
			printf("(?) DB : "); scanf("%s", DB);
			printf("(?) ID : "); scanf("%s", ID);
			printf("(?) PW : "); scanf("%s", PW);
			printf("(!) Type in below Queries...\n");
			printf(" > CREATE USER %s@%s IDENTIFIED BY '%s';\n", ID, MYSQL_HOST, PW);
			printf(" > GRANT ALL ON %s.* to %s@%s;\n", DB, ID, MYSQL_HOST);
			system("mysql");
			break;

		case 2:
			if(IsLogIn)
			{
				memset(LogInID, 0, sizeof(LogInID));
				memset(LogInPW, 0, sizeof(LogInPW));
				IsLogIn = false;
			}
			else
			{
				printf("ID : "); scanf("%s", LogInID);
				printf("PW : "); scanf("%s", LogInPW);
				IsLogIn = true;
			}
			break;
	}
}

void Menu_CreateDB(void)
{
	if(Login_Message())		return;

	char dbname[32] = {0,};
	char tablename[32] = {0,};
	char answer;			

	printf("1 / 데이터베이스 관리	\n");
	printf("   1. 데이터베이스 생성\n");
	printf("   2. 데이터베이스 삭제\n");
	printf("   3. 테이블 생성\n");
	printf("   4. 테이블 삭제\n");
	scanf("%c", &answer);

	system("clear");
	switch(answer)
	{
		case '1':
			printf("	(?) 생성할 데이터베이스 이름(영문) : ");
			scanf("%s", dbname);
			Mysql_CreateDB(dbname);
			break;

		case '2':
			printf("	(?) 삭제할 데이터베이스 이름(영문) : ");
			scanf("%s", dbname);
			Mysql_DeleteDB(dbname);
			break;

		case '3':
			// DB 선택 -> dbname;
			printf("	(?) 생성할 테이블 이름(영문) : ");
			scanf("%s", tablename);
			Mysql_CreateTable(dbname, tablename);
			break;

		case '4':
			// DB 선택 -> dbname;
			printf("	(?) 삭제할 테이블 이름(영문) : ");
			scanf("%s", tablename);
			Mysql_DeleteTable(dbname, tablename);
			break;

	}
}

void Menu_Create(void)
{
	if(Login_Message())		return;

	char tablename[32] = {0,};

    printf("2 / 데이터 삽입(Create)\n");
	/*
	printf("(?) 삭제할 테이블 이름(영문) : ");
	scanf("%s", tablename);
	Mysql_INSERT(dbname, tablename, ...);
	*/
}

void Menu_Read(void)
{
	if(Login_Message())		return;

	printf("3 / 데이터 조회(Read)\n");
	/*
	Mysql_SELECT(dbname, tablename, ...);
	*/
}

void Menu_Update(void)
{
	if(Login_Message())		return;

    printf("4 / 데이터 갱신(Update)\n");
	/*
	Mysql_UPDATE(dbname, tablename, ...);
	*/
}

void Menu_Delete(void)
{
	if(Login_Message())		return;

	printf("5 / 데이터 삭제(Delete)\n");
	/*
	Mysql_DELETE(dbname, tablename, ...);
	*/
}

int main(int argc, char** argv)
{
	IsLogIn = false;
	while(1)
	{
		int Sel = SelectMenu();

		system("clear");
		switch(Sel)
		{
			case 0:		Menu_LogIn();		break;
			case 1:		Menu_CreateDB();	break;
			case 2:		Menu_Create();		break;	//INSERT
			case 3:		Menu_Read();		break;	//SELECT
			case 4:		Menu_Update();		break;	//UPDATE
			case 5:		Menu_Delete();		break;	//DELETE
			case 6:		break;
			case 7:		break;
		}
	}

	return 0;
}
