#include "sqlite3.h"
#include <iostream>
using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}
sqlite3* db;
void createVoterTable();
void createCandidateTable();
void createPersonTable();
void insertIntoTables();
void createStateTable();
void createAssemblyTable();
void createElectionTable();
int main()
{
    char* zErrMsg = 0;
    int rc;
    char* sql;
    const char* data = "Callback function called";

    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        // return(0);
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }

    //createStateTable();
    //createAssemblyTable();
    //createVoterTable();
    //createCandidateTable();
    //createPersonTable();
    createElectionTable();
    sql = (char*)"SELECT * from state";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Operation done successfully\n");
    }

    sqlite3_stmt* stmt;

    sql = (char*)"SELECT * FROM state";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        // fprintf("error: ", sqlite3_errmsg(sqlite3->db));
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int stateId = sqlite3_column_int(stmt, 0);
        string name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        int asmId = sqlite3_column_int(stmt, 2);
        cout << "StateId" << stateId << endl;
        cout << "Statename" << name << endl;
        cout << "AssemblydID" << asmId << endl;
        // e.addNewState(stateId, name, asmId);
    }
    if (rc != SQLITE_DONE)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        // fprintf("error: ", sqlite3_errmsg(db));
    }
    sqlite3_finalize(stmt);

    sql = (char*)"SELECT * from assembly";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Operation done successfully\n");
    }
    // createPersonTable();
    //insertIntoTables();
    sqlite3_close(db);
}

void createStateTable()
{
    std::cout << "State Table Code" << std::endl;
    char* zErrMsg = 0;
    int rc;
    char* sql;
    const char* data = "Callback function called";

    sql = (char*)"CREATE TABLE state("
        "stateid INTEGER PRIMARY KEY AUTOINCREMENT  ,"
        "statename        TEXT    NOT NULL UNIQUE,"
        "assemblyid            INT     NOT NULL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "State Table created successfully\n");
    }

    sql = (char*)"INSERT INTO state  "
        "VALUES (1, 'Maharashtra', 1); "
        "INSERT INTO state  "
        "VALUES (2, 'Rajasthan', 1 ); ";
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "State Records created successfully\n");
    }
}

void createAssemblyTable()
{
    char* zErrMsg = 0;
    int rc;
    char* sql;
    const char* data = "Callback function called";

    //    Assembly Table Intialization
    sql = (char*)"CREATE TABLE assembly("
        "assemblyid INTEGER PRIMARY KEY AUTOINCREMENT  ,"
        "assemblyname       TEXT    NOT NULL,"
        "population         INT     NOT NULL,"
        "eligiblevotercount   INT     NOT NULL,"
        "currentcandidateid     INT     NOT NULL,"
        "stateid            INT     NOT NULL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Assembly Table created successfully\n");
    }

    sql = (char*)"INSERT INTO assembly  "
        "VALUES (1, 'Pune', 1000,900,1,1); "
        "INSERT INTO assembly  "
        "VALUES (2, 'Baramati', 1000,800,2,1 ); ";
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Assembly Records created successfully\n");
    }
}

void createElectionTable()
{
    char* zErrMsg = 0;
    int rc;
    char* sql;
    const char* data = "Callback function called";

    //    Assembly Table Intialization
    sql = (char*)"CREATE TABLE election("
        "id INTEGER PRIMARY KEY AUTOINCREMENT  ,"
        "electionid INT     NOT NULL  ,"
        "electionname       TEXT    NOT NULL,"
        "stateid         INT     NOT NULL,"
        "electionstatus   INT     NOT NULL);";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Election Table created successfully\n");
    }

    sql = (char*)"INSERT INTO election  "
        "VALUES (null,1, 'Vidhansabha', 1,1); "
        "INSERT INTO election "
        "VALUES (null,1, 'Vidhansabha', 2,0); "
        "INSERT INTO election  "
        "VALUES (null,2, 'Loksabha', 1,0); "
        "INSERT INTO election "
        "VALUES (null,2, 'Loksabha', 4,1); ";
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Election Records created successfully\n");
    }
}

void createVoterTable()
{
    char* zErrMsg = 0;
    int rc;
    char* sql;
    const char* data = "Callback function called";

    sql = (char*)"CREATE TABLE voter("
        "voterid INTEGER PRIMARY KEY AUTOINCREMENT  ,"
        "username           varchar    NOT NULL ,"
        "password           varchar    NOT NULL,"
        "assemblyid            INT     NOT NULL,"
        "stateid            INT     NOT NULL ,"
        "personid            INT     NOT NULL ,"
        "verified            INT     NOT NULL  DEFAULT 0);";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Voter Table created successfully\n");
    }
}

void createCandidateTable()
{
    char* zErrMsg = 0;
    int rc;
    char* sql;
    const char* data = "Callback function called";

    sql = (char*)"CREATE TABLE candidate("
        "candidateid INTEGER PRIMARY KEY AUTOINCREMENT ,"
        "username           varchar    NOT NULL ,"
        "password           varchar    NOT NULL,"
        "assemblyid            INT     NOT NULL,"
        "stateid            INT     NOT NULL ,"
        "personid            INT     NOT NULL ,"
        "electionid            INT     NOT NULL ,"
        "partyname            TEXT     NOT NULL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Candidate Table created successfully\n");
    }
}

void createPersonTable()
{
    char* zErrMsg = 0;
    int rc;
    char* sql;
    const char* data = "Callback function called";

    sql = (char*)"CREATE TABLE person("
        "personid INTEGER PRIMARY KEY AUTOINCREMENT,"
        "personname           TEXT    NOT NULL,"
        "gender           TEXT    NOT NULL,"
        "age            INT     NOT NULL,"
        "dob           TEXT    NOT NULL,"
        "address           TEXT    NOT NULL,"
        "qualification            TEXT     NOT NULL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Person Table created successfully\n");
    }
}

void insertIntoTables()
{
    char* zErrMsg = 0;
    int rc;
    char* sql;
    const char* data = "Callback function called";

    sql = (char*)"INSERT INTO voter  "
        "VALUES (null, 'virat','pass',1,2,1,0); "
        "INSERT INTO voter  "
        "VALUES (null, 'ms','pass',1,2,2,0); "
        "INSERT INTO person  "
        "VALUES (null, 'virat','M',22,'01/06/99','Baramati','BE'); "
        "INSERT INTO person "
        "VALUES (null, 'ms','M',22,'01/06/99','Pune','BE'); ";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    /* Execute SQL statement */
    sql = "INSERT INTO candidate  "
          "VALUES (null, 'Amit','pass',1,2,3,1,'Asd '); "
          "INSERT INTO candidate  "
          "VALUES (null, 'Pope','pass',1,2,4,1,'Asd ');"
          "INSERT INTO person  "
          "VALUES (null, 'amit','M',22,'01/06/99','Baramati','BE'); "
          "INSERT INTO person "
          "VALUES (null, 'Pope','M',22,'01/06/99','Pune','BE'); ";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Assembly Records created successfully\n");
    }
}
