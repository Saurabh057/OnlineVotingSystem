//main driver file
#include <iostream>
#include "ElectionCommision.h"
#include <sqlite3.h>
#include "Voter.h"
#include <sstream>
using namespace std;

sqlite3 *db;

int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}
void adminFuntions();
Voter *voterLogin(string username, string password);
void voterFunctions();
int rc = sqlite3_open("test.db", &db);
ElectionCommision e;

int main()
{
    char *zErrMsg = 0;
    // int rc;
    char *sql;
    const char *data = "Callback function called";

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        // return(0);
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_stmt *stmt;

    sql = "SELECT * FROM state";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        // fprintf("error: ", sqlite3_errmsg(sqlite3->db));
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int stateId = sqlite3_column_int(stmt, 0);
        string name = std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        int asmId = sqlite3_column_int(stmt, 2);
        cout << "StateId" << stateId << endl;
        cout << "Statename" << name << endl;
        cout << "AssemblydID" << asmId << endl;
        e.addNewState(stateId, name, asmId);
    }
    if (rc != SQLITE_DONE)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        // fprintf("error: ", sqlite3_errmsg(db));
    }
    sqlite3_finalize(stmt);

    cout << "details printed" << endl;
    e.showStates();
    int ch;
    // cout << "\n1.Register as New Voter\n2.Already Registered  ";
    // cin >> ch;

    // switch (ch)
    // {
    // case 1:
    //     Voter *v1 = e.registerNewVoter();

    // case 2:
    //     Voter
    //     v1->registerAsCandidate();
    // }
    // Voter *v1 = e.registerNewVoter();
    // v1->registerAsCandidate();

    // e.showOngoingElectionDetails();
    // //----------------------------------------------------------------------------------------------------------------------------

    cout << "\n\n************************Online Voting System*******************************" << endl;

    cout << "\nWho you are?\n1.Admin\n2.Voter\n3.Candidate\n"
         << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        adminFuntions();
        break;
    case 2:
        voterFunctions();
        break;
    case 3:
        voterFunctions();
        break;
    default:
        break;
    }

    return 0;
}

void adminFuntions()
{
    int ch;
    cout << "\n\t1.Create Election \n2.Show Election Details\n3 Show All States Details" << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        e.createElection();
        break;
    case 2:
        e.showOngoingElectionDetails();
        break;
    case 3:
        e.showOngoingElectionDetails();
        break;
    default:
        cout << "\nInvalid Choice" << endl;
        break;
    }
}

void voterFunctions()
{
    int ch, ch2;
    cout << "\n\t1.New Voter? \n2.Already Registered\n3 Show All States Details" << endl;
    cin >> ch;
    Voter *v1;
    string username, password;
    switch (ch)
    {
    case 1:
        v1 = e.registerNewVoter();
        break;
    case 2:
        cout << "\nEnter Username" << endl;
        cin >> username;
        cout << "\nEnter Password" << endl;
        cin >> password;
        v1 = voterLogin(username, password);
        if (v1 != NULL)
        {
            cout << "**************" << endl;
            cout << "\n1.Vote For Election\n2.Register as New Candidate" << endl;
            cin >> ch2;
            switch (ch2)
            {
            case 1:
                v1->vote();
                break;
            case 2:
                v1->registerAsCandidate();
                break;
            default:
                cout << "INvalid Choice" << endl;
            }
        }
        else
        {
            cout << "\nInvalid Credentials" << endl;
        }

        break;
    default:
        cout << "\nInvalid Choice" << endl;
        break;
    }
}

Voter *voterLogin(string username, string password)
{
    char *zErrMsg = 0;
    const char *sql;
    int rc;
    const char *data = "Callback function called";
    int callback(void *data, int argc, char **argv, char **azColName);

    stringstream ss, ss2;
    string query, query2;

    sqlite3_stmt *stmt;

    // ss2 << "select * from voter where username =   " << username;
    ss2 << "select * from voter where username = 'saurabh' and password = 'pass'";

    query = ss2.str();

    std::string sql2 = "select * from voter where username ='" + username + "' and password = '" + password + "'";
    cout << sql2 << endl;
    sql = sql2.c_str();
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        // fprintf("error: ", sqlite3_errmsg(sqlite3->db));
    }
    Voter *voterObj = NULL;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int voterid = sqlite3_column_int(stmt, 0);
        int assemblyid = sqlite3_column_int(stmt, 3);
        int stateid = sqlite3_column_int(stmt, 4);
        cout << "Voter id and assembly id" << voterid;
        voterObj = e.states[stateid]->assemblyList[assemblyid]->getVoterList()[voterid];

        //e.getMapStateNameStateId()[stateName]->assemblyNameAssemblyId[stateObj->getName()] = i;
    }

    sqlite3_finalize(stmt);

    return voterObj;
}