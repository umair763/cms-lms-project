#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<string.h>
#include<string>
#include<cstdio>
#include<windows.h>
#include<iomanip>

#pragma warning(disable : 4996)

using namespace std;
void showdate()
{
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    cout << "Date: " << t.tm_mday << "-" << t.tm_mon + 1 << "-" << t.tm_year + 1900;
}
void showtime()
{
    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    cout << "Time: " << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec;
}
//////////////////////////////////////////////////////////////////////////////////

float theory_duration = 0, lab_duration = 0;
string theorycourse_title[5], labcourse_title[2];

    int thdate[5], labdate[2], month, year;
    int thhours[5], labhours[2], minutes, seconds;

///////////////////////////////////Exam dpt//////////////////////////////////////////////


class Exam_department
{
private:
protected:

    float tfee = theory_duration * 20;
    string theory_invigilator[5];
    float lfee = lab_duration * 10;
    string lab_invigilator[2];
public:
    void set_date_time()
    {
        cout << "Set time for Theory exam :" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "\nSet Time (Hours) for : " << theorycourse_title[i] << " : ";
            cin >> thhours[i];
        }
        cout << "Set time for Lab exam :" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "\nSet Time (Hours) for : " << labcourse_title[i] << " : ";
            cin >> labhours[i];
        }
        float x, y;
        cout << "\nSet Theory Exam Duration : ";
        cin >> x;
        cout << "Set Lab Exam Duration : ";
        cin >> y;
        set_theorytime(x);
        set_labtime(y);
        cout << "\nSet Date for Theory Exam : " << endl;

        for (int i = 0; i < 5; i++)
        {
            cout << "\nSet Date : " << theorycourse_title[i] << " : ";
            cin >> thdate[i];
        }
        cout << "\nSet Date for Lab Exam : " << endl;
        for (int j = 0; j < 2; j++)
        {
            cout << "\nSet Date : " << labcourse_title[j] << " : ";
            cin >> labdate[j];
        }
        cout << "\nSet Month : ";
        cin >> month;
        cout << "Set Year : ";
        cin >> year;
        ofstream myfile;
        myfile.open("Exam Details.txt", ios::out | ios::app);
        myfile << "\n Date\t\t\t       Time\t\tTheory exam duration" << endl;
        for (int i = 0; i < 5; i++)
        {
            myfile << "\n" << thdate[i] << " / " << month << " / " << year << "\t\t\t" << thhours[i] << " : " << 00 << " : " << 00 << "\t\t\t" << theory_duration << endl;
        }
        myfile << "\n Date\t\t\t        Time\t\tlab exam duration" << endl;
        for (int i = 0; i < 2; i++)
        {
            myfile << "\n" << labdate[i] << " / " << month << " / " << year << "\t\t\t" << labhours[i] << " : " << 00 << " : " << 00 << "\t\t\t" << lab_duration << endl;
        }
        myfile.close();
    }
    void show_date_time_duration()
    {
        cout << "\n Date\t\t\t       Time\t\tTheory exam duration" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "\n" << thdate[i] << " / " << month << " / " << year << "\t\t\t" << thhours[i] << " : " << 00 << " : " << 00 << "\t\t\t" << theory_duration << endl;
        }
        cout << "\n Date\t\t\t       Time\t\tlab exam duration" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "\n" << labdate[i] << " / " << month << " / " << year << "\t\t\t" << labhours[i] << " : " << 00 << " : " << 00 << "\t\t\t" << lab_duration << endl;
        }
        system("pause");

    }
    void set_theorytime(float a)
    {
        theory_duration = a;
    }
    void set_labtime(float b)
    {
        lab_duration = b;
    }
    float get_theorytime()
    {
        return theory_duration;
    }
    float get_labtime()
    {
        return lab_duration;
    }
};
int hallno[5] = {};
class theory_exam :public Exam_department
{
private:
protected:

public:
    void set_theory_course_hallno()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "\nEnter Theory Course title (as: theory of Automata(cII123)) : ";
            cin >> theorycourse_title[i];
        }
        for (int i = 0; i < 5; i++)
        {
            cout << "\nEnter Hall no for : " << theorycourse_title[i] << " : ";
            cin >> hallno[i];
        }
        ofstream myfile;
        myfile.open("Exam Details.txt", ios::out | ios::app);
        myfile << "\nCourse Title\t\t\tHall no" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "\n" << setw(28) << left << theorycourse_title[i] << "\t " << setw(10) << left << hallno[i];
        }
        myfile.close();
    }
    void show_theory_course_hallno()
    {
        cout << "\nCourse Title\t\t\tHall no" << endl;

        for (int i = 0; i < 5; i++)
        {
            cout << "\n" << setw(28) << left << theorycourse_title[i] << "\t " << setw(10) << left << hallno[i];
        }
        system("pause");
    }
};
int labno[2] = {};
class practical_exam :public Exam_department
{
private:
protected:

public:
    void set_lab_course_labno()
    {
        for (int i = 0; i < 2; i++)
        {
            cout << "\nEnter lab Course title (as: theory of Automata(cII123)) : ";
            cin >> labcourse_title[i];
        }
        for (int i = 0; i < 2; i++)
        {
            cout << "\nEnter lab no for : " << labcourse_title[i] << " : ";
            cin >> labno[i];
        }
        ofstream myfile;
        myfile.open("Exam Details.txt", ios::out | ios::app);
        myfile << "\nCourse Title\t\t\tlab no" << endl;
        for (int i = 0; i < 2; i++)
        {
            myfile << "\n" << setw(28) << left << labcourse_title[i] << "\t " << setw(10) << left << labno[i];
        }
        myfile.close();
    }
    void show_labno()
    {
        cout << "\nCourse Title\t\t\tlab no" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "\n" << setw(28) << left << labcourse_title[i] << "\t " << setw(10) << left << labno[i];
        }
        system("pause");
    }
};

class inviglators_info :public Exam_department
{
private:
protected:
public:
    inviglators_info() {}
    void set_theory_lab_invigilator()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "\nEnter names for Theory paper Invigilator : ";
            cin >> theory_invigilator[i];
        }
        for (int j = 0; j < 2; j++)
        {
            cout << "\nEnter names for Lab paper Invigilator : ";
            cin >> lab_invigilator[j];
        }
    }
    void show_theory_lab_invigilators()
    {
        ofstream myfile;
        myfile.open("Exam Details.txt", ios::out | ios::app);
        cout << "\n\nTheory invigilators ------- \tCourse" << endl;
        myfile << "\n\nTheory invigilators ------- \tCourse" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << theory_invigilator[i] << "\t--------------- \t" << theorycourse_title[i] << endl;
            myfile << theory_invigilator[i] << "\t--------------- \t" << theorycourse_title[i] << endl;
        }
        cout << "\n\nLab invigilators ------- \tCourse" << endl;
        myfile << "\n\nLab invigilators ------- \tCourse" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << lab_invigilator[i] << "\t --------------- \t" << labcourse_title[i] << endl;
            myfile << lab_invigilator[i] << "\t --------------- \t" << labcourse_title[i] << endl;
        }
        myfile.close();
        system("pause");

    }
    void show_invig_fee()
    {
        float tfee, lfee;
        tfee = get_theorytime() * 20;
        lfee = get_labtime() * 10;

        cout << "\nTheory Invigilator fee" << endl;
        ofstream myfile;
        myfile.open("Exam Details.txt", ios::out | ios::app);
        myfile << "\nTheory Invigilator fee" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "\n" << setw(10) << left << theory_invigilator[i] << " : " << tfee;
            myfile << "\n" << setw(10) << left << theory_invigilator[i] << " : " << tfee;
        }
        cout << "\nLab Invigilator fee" << endl;
        myfile << "\n\nLab Invigilator fee" << endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "\n" << setw(10) << left << lab_invigilator[i] << " : " << lfee;
            myfile << "\n" << setw(10) << left << lab_invigilator[i] << " : " << lfee;
        }
        myfile.close();
        system("pause");

    }
};
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
class Admin :public Exam_department
{
private:
protected:

    char student_atten_mark[10] = {};

    char fname[30] = {};
    char fid[10] = {};
    char fqualification[30] = {};
    char fspecialization[30] = {};
    char fdob[30] = {};
    char fhiredate[30] = {};

    char stname[30] = {};
    char stid[10] = {};
    char stqualification[30] = {};
    char stcurrent_deg[30] = {};
    char stdob[30] = {};
    char stud_pd[30] = {};

public:

    Exam_department E1;
    theory_exam t1;
    practical_exam p1;
    inviglators_info i1;

    ///////////////////////////////////////////////
    void enterexamdpt()
    {
        system("cls");
        t1.set_theory_course_hallno();
        system("cls");
        p1.set_lab_course_labno();
        system("cls");
        i1.set_theory_lab_invigilator();
        system("cls");
        E1.set_date_time();
        system("cls");
    }
    void Examdepartmentmainn()
    {
        system("cls");
        system("color a0");
        PlaySound(TEXT("welcom to exam managment system.wav"), NULL, SND_ASYNC | SND_LOOP == 1 | SND_FILENAME);
    level5:
        system("cls");
        int ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>    WELCOME TO EXAM MANAGMENT SYSTEM   <<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t||...>>>  "; showdate(); cout << " \t\t\t          "; showtime(); cout << "   <<<...||";
        cout << "\n\t\t||...>>>\t    ---------------------------------------------          <<<...||";
        cout << "\n\t\t||...>>>\t    : 0 :->   To Enter Exam Detail                         <<<...||";
        cout << "\n\t\t||...>>>\t    ---------------------------------------------          <<<...||";
        cout << "\n\t\t||...>>>\t    : 1 :->   To View Exam Date And Time                   <<<...||";
        cout << "\n\t\t||...>>>\t    ---------------------------------------------          <<<...||";
        cout << "\n\t\t||...>>>\t    : 2 :->   To View Theory course Hall no                <<<...||";
        cout << "\n\t\t||...>>>\t    ---------------------------------------------          <<<...||";
        cout << "\n\t\t||...>>>\t    : 3 :->   To View Lab course Lab no                    <<<...||";
        cout << "\n\t\t||...>>>\t    ---------------------------------------------          <<<...||";
        cout << "\n\t\t||...>>>\t    : 4 :->   To View Theory and lab invigilator           <<<...||";
        cout << "\n\t\t||...>>>\t    ---------------------------------------------          <<<...||";
        cout << "\n\t\t||...>>>\t    : 5 :->   To View invigilator fee                      <<<...||";
        cout << "\n\t\t||...>>>\t    ---------------------------------------------          <<<...||";
        cout << "\n\t\t||...>>>\t    : 6 :->   Back to Admin manu                           <<<...||";
        cout << "\n\t\t___________________________________________________________________________________";
        cout << "\n\n\t\t||...>>>                                                                   <<<...||";
        cout << "\n\t\t                      ENTER YOUR CHOICE :   ";
        cin >> ch;
        cout << "\n\t\t||...>>>                                                                   <<<...||";
        cout << "\n\t\t___________________________________________________________________________________" << endl;
        _sleep(1000);
        switch (ch)
        {
        case 0:
            system("cls");
            enterexamdpt();
            system("cls");
            //Examdepartmentmainn();
            goto level5;
            break;
        case 1:
            system("cls");
            E1.show_date_time_duration();
            system("cls");
            //Examdepartmentmainn();
            goto level5;
            break;
        case 2:
            system("cls");
            t1.show_theory_course_hallno();
            system("cls");
            //Examdepartmentmainn();
            goto level5;
            break;
        case 3:
            system("cls");
            p1.show_labno();
            system("cls");
            //Examdepartmentmainn();
            goto level5;
            break;
        case 4:
            system("cls");
            i1.show_theory_lab_invigilators();
            system("cls");
            //Examdepartmentmainn();
            goto level5;
            break;
        case 5:
            system("cls");
            i1.show_invig_fee();
            system("cls");
            //Examdepartmentmainn();
            goto level5;
            break;
        case 6:
            system("cls");
            system("cls");
            cms();
            break;
        default:
            cout << "Invalid Input";
            Examdepartmentmainn();
            break;
        }
    }

    /////////////////manu///////////////////////
    virtual void cms()
    {
        adminlogin();
    level5:
        system("cls");
        system("color 80");
        PlaySound(TEXT("welcom to admin system.wav"), NULL, SND_ASYNC | SND_LOOP == 1 | SND_FILENAME);
        int ch;

        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>  Welcome to Admin System  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t||...>>>     "; showdate(); cout << " \t\t\t           "; showtime(); cout << "     <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 1 :->   To Manage Faculty                           <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 2 :->   To Manage Student                           <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 3 :->   To Manage Exam Department                   <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 0 :->   Back To Main Web View                       <<<...||";
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t||...>>>                                                                      <<<...||";
        cout << "\n\t\t                      ENTER YOUR CHOICE :   ";
        cin >> ch;
        cout << "\n\t\t||...>>>                                                                      <<<...||";
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);
        switch (ch)
        {
        case 0:
            system("CLS");
            break;
        case 1:
            system("CLS");
            facoptions();
            break;
        case 2:
            system("CLS");
            stoptions();
            break;
        case 3:
            system("CLS");
            Examdepartmentmainn();
            break;
        default:
            cout << "\n Sorry! I don't understand that! \n";
            system("pause");
            cms();
            break;
        }
    }
    ////////////////////////////////////////////

    ///////////////login////////////////////////
    void adminloginn()
    {
        system("cls");
        int count = 0;
        string userid, password, id, pass;
        string passs;
        char ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>          ADMIN LOGIN           <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER USER NAME :: "; cin >> userid;
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER PASSWORD  :: "; ch = _getch();
        while (ch != 13)
        {
            passs.push_back(ch);
            cout << "*";
            ch = _getch();
        }
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        Sleep(1000);
        password = passs;
        ifstream input("Admin login pass.txt", ios::in | ios::app | ios::out);
        while (input >> id >> pass)
        {
            if (id == userid && pass == password)
            {
                count = 1;
                system("cls");
            }
        }
        input.close();
        if (count == 1)
        {
            cout << "\nYour login is successfull\n\n";
            Sleep(1000);
        }
        else
        {
            cout << "\nlogin error\n";
            Sleep(1000);
            adminlogin();
        }
    }
    void adminregisterr()
    {
        system("cls");
        string ruserid, rpassword, rid, rpass;
        string passs = " ";
        char ch;
        system("cls");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>      ADMIN REGISTRATION        <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER USER NAME :: "; cin >> ruserid;
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER PASSWORD  :: "; ch = _getch();
        while (ch != 13)
        {
            passs.push_back(ch);
            cout << "*";
            ch = _getch();
        }
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        Sleep(1000);
        rpassword = passs;

        ofstream fi;
        fi.open("Admin login pass.txt", ios::app);
        fi << ruserid << " " << rpassword << endl;
        fi.close();
        system("cls");
        cout << "\n\t\t\tRegistration successfull\n";
        Sleep(1000);
        adminlogin();

    }
    void adminlogin()
    {
        system("cls");
        int c;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>      ADMIN LOGIN SYSTEM        <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t\t     --->  : 1 : REGISTER    <---";
        cout << "\n\t\t\t\t\t     ----------------------------";
        cout << "\n\t\t\t\t\t     --->  : 2 : LOGIN       <---";
        cout << "\n\t\t\t\t\t     ----------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t                                                                ";
        cout << "\n\t\t                      ENTER YOUR CHOICE :   "; cin >> c;
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);
        cout << "\n";
        switch (c)
        {
        case 1:
            adminregisterr();
            break;
        case 2:
            adminloginn();
            break;
        default:
            system("cls");
            cout << "\t\t\nselect from above \t\n";
            adminlogin();
            break;
        }
    }
    ///////////////////////////////////////////
    void stwaitForEnter()
    {
        cout << "\n\n\n Press enter to go back \n\n";
        cin.get();
        cin.get();
    }
    void stlist()
    {
        system("cls");
        FILE* file;
        file = fopen("student.txt", "r");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>         STUDENT LIST           <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t NAME        |     ID     |     Qualification      |   current degree \n";
        cout << "\t\t------------------------------------------------------------------------------------";
        while (fscanf(file, "%s %s %s %s %s %s", &stname[0], &stid[0], &stqualification[0], &stcurrent_deg[0], &stdob[0], &stud_pd[0]) != EOF)
            cout << "\n\n\t\t " << stname << "\t  \t" << stid << "\t\t" << stqualification << "\t\t\t" << stcurrent_deg;
        cout << "\n\t\t____________________________________________________________________________________";
        fclose(file);
        stwaitForEnter();
    }
    void stshowDetails()
    { 
        system("cls");
        FILE* file;
        char checkId[5];
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>        STUDENT DETAILS         <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER STUDENT ID : ";
        cin >> checkId;
        file = fopen("student.txt", "r");
        while (fscanf(file, "%s %s %s %s %s %s", &stname[0], &stid[0], &stqualification[0], &stcurrent_deg[0], &stdob[0], &stud_pd[0]) != EOF)
            if (strcmp(checkId, stid) == 0)
            {
                system("cls");
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   NAME :: " << stname;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   ID   :: " << stid;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   QUALIFICATION  :: " << stqualification;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   CURRENT DEGREE :: " << stcurrent_deg;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   DATE OF BIRTH  :: " << stdob;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   GRADUATION STATUS  :: " << stud_pd;
                cout << "\n\t\t______________________________________________________________________________________";
            }
        fclose(file);
        stwaitForEnter();
    }
    void steditExisting()
    { 
        system("cls");
        char checkId[10];
        char newDesignation[10];
        char newCtc[30];
        char ug_pg[30];
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>    UPDATE STUDENT DETAILS      <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER STUDENT ID :: "; cin >> checkId;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER NEW QUALIFICATION        :: "; cin >> newDesignation;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER UPDATED CURRENT DEGREE   :: "; cin >> newCtc;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER UPDATED DEGREE LEVEL     :: "; cin >> ug_pg;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        FILE* file, * tempfile;
        file = fopen("student.txt", "r");
        tempfile = fopen("temp.txt", "w");
        while (fscanf(file, "%s %s %s %s %s %s", &stname[0], &stid[0], &stqualification[0], &stcurrent_deg[0], &stdob[0], &stud_pd[0]) != EOF)
        {
            if (strcmp(checkId, stid) == 0)
                fprintf(tempfile, "%s %s %s %s %s %s \n", stname, stid, newDesignation, newCtc, ug_pg, stud_pd);
            else
                fprintf(tempfile, "%s %s %s %s %s %s \n", stname, stid, stqualification, stcurrent_deg, stud_pd, stdob);
        }
        fclose(file);
        fclose(tempfile);
        int isRemoved = remove("student.txt");
        int isRenamed = rename("temp.txt", "student.txt");
        stwaitForEnter();
    }
    void staddNew()
    { //adding records
        system("cls");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>        ADD NEW STUDENT         <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER STUDENT NAME :: "; cin >> stname;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER STUDENT ID [MAX 4 DIGITS ] :: "; cin >> stid;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER QUALIFICATION   :: "; cin >> stqualification;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER CURRENT DEGREE  :: "; cin >> stcurrent_deg;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER STUDENT DOB     :: "; cin >> stdob;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER GRADUATION LEVEL (UG OR PG)  :: "; cin >> stud_pd;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________";

        char ch;
        cout << "\nEnter 'y' to save above information\n";
        cin >> ch;
        if (ch == 'y') {
            FILE* file, * FILE;
            file = fopen("student.txt", "a");
            fprintf(file, "%s %s %s %s %s %s \n", stname, stid, stqualification, stcurrent_deg, stdob, stud_pd);
            fclose(file);
            cout << "\nNew student has been added to database\n";
            FILE = fopen("stattend.txt", "a");
            fprintf(FILE, "%s %s %s \n", stname, stid, stqualification);
            fclose(FILE);
            cout << "\nDone\n";
        }
        else
            staddNew();
        stwaitForEnter();
    }
    void stdeleteDetails() 
    { 
        system("cls");
        char checkId[5];
        char ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>        REMOVE STUDENT          <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER STUDENT ID :: "; cin >> checkId;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\n\n\t\t    --->   CONFIRMATION .... ";
        cout << "\n\n\t\t           Press Y To Confirm Deletion ... "; cin >> ch;
        cout << "\n\t\t______________________________________________________________________________________";

        if (ch == 'y') {
            FILE* file, * tempfile;
            file = fopen("student.txt", "r");
            tempfile = fopen("temp.txt", "w");
            while (fscanf(file, "%s %s %s %s %s %s", &stname[0], &stid[0], &stqualification[0], &stcurrent_deg[0], &stdob[0], &stud_pd[0]) != EOF)
                if (strcmp(checkId, stid) != 0)
                    fprintf(tempfile, "%s %s %s %s %s %s \n", stname, stid, stqualification, stcurrent_deg, stdob, stud_pd);
            fclose(file);
            fclose(tempfile);
            int isRemoved = remove("student.txt");
            int isRenamed = rename("temp.txt", "student.txt");
            cout << "\nRemoved Successfully\n";
            stwaitForEnter();
        }
        else
            stdeleteDetails();
    }
    void stoptions(void) 
    { 
        system("cls");
        PlaySound(TEXT("welcome-to-student-managment-system.wav"), NULL, SND_ASYNC | SND_LOOP == 1 | SND_FILENAME);
    level4:
        system("cls");
        int choice;
        
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>  WELCOME TO STUDENT MANAGMENT SYSTEM  <<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t||~~~...>>>  "; showdate(); cout << " \t\t\t          "; showtime(); cout << "    <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 1 :->   To View List of Student                      <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 2 :->   To View Student Details                      <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 3 :->   To Modify Existing Student Details           <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 4 :->   To Add New Student Details                   <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 5 :->   To Remove an Student Details                 <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 0 :->   To Exit                                      <<<~~~...||";
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t||~~~...>>>                                                                 <<<~~~...||";
        cout << "\n\t\t                      ENTER YOUR CHOICE :   ";
        cin >> choice;
        cout << "\n\t\t||~~~...>>>                                                                 <<<~~~...||";
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);
        
        switch (choice) {
        case 0:
            system("CLS");
            cms();
            break;
        case 1:
            stlist();
            //stoptions();
            goto level4;
            break;
        case 2:
            stshowDetails();
            //stoptions();
            goto level4;
            break;
        case 3:
            steditExisting();
            //stoptions();
            goto level4;
            break;
        case 4:
            staddNew();
            //stoptions();
            goto level4;
            break;
        case 5:
            stdeleteDetails();
            //stoptions();
            goto level4;
            break;
        default:
            cout << "\n Sorry! I don't understand that! \n";
            //stoptions();
            goto level4;
            break;
        }
    }

    //////////////////////////////////////////////////////////////////
    void facwaitForEnter()
    {
        cout << "\n\n\n Press enter to go back \n\n";
        cin.get();
        cin.get();
    }
    void faclist()
    {
        system("cls");
        FILE* file;

        file = fopen("data.txt", "r");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>         FACULTY LIST           <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t NAME        |     ID     |     Qualification      |   Specialization \n";
        cout << "\t\t------------------------------------------------------------------------------------";
        while (fscanf(file, "%s %s %s %s %s %s", &fname[0], &fid[0], &fqualification[0], &fspecialization[0], &fdob[0], &fhiredate[0]) != EOF)
            cout << "\n\n\t\t" << fname << " \t\t " << fid << "\t\t" << fqualification << "\t\t\t" << fspecialization;
        cout << "\n\t\t____________________________________________________________________________________";
        fclose(file);
        facwaitForEnter();
    }

    void facshowDetails()
    {
        system("cls");
        FILE* file;
        char checkId[5];
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>        FACULTY DETAILS         <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER FACULTY ID : ";
        cin >> checkId;
        file = fopen("data.txt", "r");
        while (fscanf(file, "%s %s %s %s %s %s", &fname[0], &fid[0], &fqualification[0], &fspecialization[0], &fdob[0], &fhiredate[0]) != EOF)
            if (strcmp(checkId, fid) == 0)
            {
                system("cls");

                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   NAME :: " << fname;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   ID   :: " << fid;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   QUALIFICATION  :: " << fqualification;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   SPECIALIZATION :: " << fspecialization;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   DATE OF BIRTH  :: " << fdob;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   HIRE DATE		 :: " << fhiredate;
                cout << "\n\t\t______________________________________________________________________________________";
            }
        fclose(file);
        facwaitForEnter();
    }

    void faceditExisting()
    {
        system("cls");
        char checkId[10];
        char newDesignation[10];
        char newCtc[30];
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>    UPDATE FACULTY DETAILS      <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER FACULTY ID : "; cin >> checkId;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER NEW QUALIFICATION    :: "; cin >> newDesignation;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER NEW SPECIALIZATION   :: "; cin >> newCtc;
        cout << "\n\t\t______________________________________________________________________________________";

        FILE* file, * tempfile;
        file = fopen("data.txt", "r");
        tempfile = fopen("temp.txt", "w");
        while (fscanf(file, "%s %s %s %s %s %s", &fname[0], &fid[0], &fqualification[0], &fspecialization[0], &fdob[0], &fhiredate[0]) != EOF)
        {
            if (strcmp(checkId, fid) == 0)
                fprintf(tempfile, "%s %s %s %s %s %s \n", fname, fid, newDesignation, newCtc, fdob, fhiredate);
            else
                fprintf(tempfile, "%s %s %s %s %s %s \n", fname, fid, fqualification, fspecialization, fdob, fhiredate);
        }
        fclose(file);
        fclose(tempfile);
        int isRemoved = remove("data.txt");
        int isRenamed = rename("temp.txt", "data.txt");
        facwaitForEnter();
    }

    void facaddNew()
    {
        system("cls");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>        ADD NEW FACULTY         <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER FACULTY NAME :: "; cin >> fname;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER FACULTY ID [MAX 4 DIGITS ] :: "; cin >> fid;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER QUALIFICATION   :: "; cin >> fqualification;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER SPECIALIZATION  :: "; cin >> fspecialization;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER FACULTY DOB     :: "; cin >> fdob;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER FACULTY HIRE DATE  :: "; cin >> fhiredate;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________";

        char ch;
        cout << "\nEnter 'y' to save above information\n";
        cin >> ch;
        if (ch == 'y') {
            FILE* file;
            file = fopen("data.txt", "a");
            fprintf(file, "%s %s %s %s %s %s \n", fname, fid, fqualification, fspecialization, fdob, fhiredate);
            fclose(file);
            cout << "\nNew faculty has been added to database\n";

        }
        else
            facaddNew();
        facwaitForEnter();
    }
    void facdeleteDetails()
    {
        system("cls");
        char checkId[5];
        char ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>        REMOVE FACULTY          <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER FACULTY ID :: "; cin >> checkId;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\n\n\t\t    --->   CONFIRMATION .... ";
        cout << "\n\n\t\t           Press Y To Confirm Deletion ... "; cin >> ch;
        cout << "\n\t\t______________________________________________________________________________________";
        if (ch == 'y') {
            FILE* file, * tempfile;
            file = fopen("data.txt", "r");
            tempfile = fopen("temp.txt", "w");
            while (fscanf(file, "%s %s %s %s %s %s", &fname[0], &fid[0], &fqualification[0], &fspecialization[0], &fdob[0], &fhiredate[0]) != EOF)
                if (strcmp(checkId, fid) != 0)
                    fprintf(tempfile, "%s %s %s %s %s %s \n", fname, fid, fqualification, fspecialization, fdob, fhiredate);
            fclose(file);
            fclose(tempfile);
            int isRemoved = remove("data.txt");
            int isRenamed = rename("temp.txt", "data.txt");
            cout << "\nRemoved Successfully\n";
            facwaitForEnter();
        }
        else
            facdeleteDetails();
    }

    void facoptions(void)
    {
        system("cls");
        PlaySound(TEXT("welcome-faculty-managment-system.wav"), NULL, SND_ASYNC | SND_LOOP == 1 | SND_FILENAME);
    level3:
        system("cls");
        int choice;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>  WELCOME TO FACULTY MANAGMENT SYSTEM  <<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t||~~~...>>>  "; showdate(); cout << " \t\t\t          "; showtime(); cout << "   <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 1 :->   To View List of Faculty                      <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 2 :->   To View faculty Details                      <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 3 :->   To Modify Existing faculty Details           <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 4 :->   To Add New faculty Details                   <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 5 :->   To Remove an faculty Details                 <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    ---------------------------------------------          <<<~~~...||";
        cout << "\n\t\t||~~~...>>>\t    : 0 :->   To Exit                                      <<<~~~...||";
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t||~~~...>>>                                                                 <<<~~~...||";
        cout << "\n\t\t                      ENTER YOUR CHOICE :   ";
        cin >> choice;
        cout << "\n\t\t||~~~...>>>                                                                 <<<~~~...||";
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);

        switch (choice) {
        case 0:
            system("CLS");
            cms();
            break;
        case 1:
            faclist();
            //facoptions();
            goto level3;
            break;
        case 2:
            facshowDetails();
            //facoptions();
            goto level3;
            break;
        case 3:
            faceditExisting();
            //facoptions();
            goto level3;
            break;
        case 4:
            facaddNew();
            //facoptions();
            goto level3;
            break;
        case 5:
            facdeleteDetails();
            //facoptions();
            goto level3;
            break;
        default:
            cout << "\n Sorry! I don't understand that! \n";
            //facoptions();
            goto level3;
            break;
        }

    }
};
////////////////////////////////////////////////////////////////////////
class facultyy : public Admin
{

protected:
    string fpass, email;
    char assignmentname[30], assignmentdeadline[30], astsubmissiontime[10];
    char quizzname[30], quizzdate[30], quizsubmissiontime[10];
    char lecturename[30] = " ", lecturedate[30];
public:

    ////////////////////////////////////////
    void stattendence()
    {
        system("cls");
        char checkId[10];
        char newDesignation[10];
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>       ATTENDENCE MARKING       <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER STUDENT ID :: "; cin >> checkId;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER ATTENDENCE STATUS :: "; cin >> newDesignation;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        FILE* file, * tempfile;
        file = fopen("stattend.txt", "r");
        tempfile = fopen("temp.txt", "w");
        while (fscanf(file, "%s %s %s ", &stname[0], &stid[0], &student_atten_mark[0]) != EOF)
        {
            if (strcmp(checkId, stid) == 0)
                fprintf(tempfile, "%s %s %s  \n", stname, stid, newDesignation);
            else
                fprintf(tempfile, "%s %s %s  \n", stname, stid, student_atten_mark);
        }
        fclose(file);
        fclose(tempfile);
        int isRemoved = remove("stattend.txt");
        int isRenamed = rename("temp.txt", "stattend.txt");
        
        cout << "\n\n\t\t\tAttendence marked\n";
        Sleep(1000);
        stwaitForEnter();
        //cms();
    }
    ///////////////////////////////////////
    void stviewatten()
    {
        system("cls");
        FILE* file;
        file = fopen("stattend.txt", "r");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>   STUDENT ATTENDENCE RECORD    <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t   NAME        |     ID     |     Attendence\n";
        cout << "\t\t------------------------------------------------------------------------------------";
        while (fscanf(file, "%s %s %s ", &stname[0], &stid[0], &student_atten_mark[0]) != EOF)
            cout << "\n\t\t\t\t  " << stname << "\t\t   " << stid << "\t\t\t" << student_atten_mark;
        fclose(file);
        cout << "\n\t\t______________________________________________________________________________________";
        stwaitForEnter();
        //cms();
    }
    ////////////////////////////////////////
    void viewassignment()
    {
        system("cls");
        FILE* file;
        file = fopen("assignment.txt", "r");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>   STUDENT ASSIGNMENT RECORD    <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t   NAME        |     DEADLINE     |     TIME\n";
        cout << "\t\t------------------------------------------------------------------------------------";
        while (fscanf(file, "%s %s %s ", &assignmentname[0], &assignmentdeadline[0], &astsubmissiontime[0]) != EOF)
            cout << "\n\t\t\t\t  " << assignmentname << "\t\t   " << assignmentdeadline << "\t\t" << astsubmissiontime;
        fclose(file);
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        stwaitForEnter();
        //cms();
    }

    void assignmentadd()
    { //adding records

        system("cls");
        char ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>      GENERATE ASSIGNMENT       <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER ASSIGNMENT NAME :: "; cin >> assignmentname;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER ASSIGNMENT DEADLINE :: "; cin >> assignmentdeadline;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER ASSIGNMENT SUBMISSION TIME :: "; cin >> astsubmissiontime;
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t                                                                ";
        cout << "\n\t\t          Enter 'y' to save above information ::   "; cin >> ch;
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);
        if (ch == 'y')
        {
            FILE* file, * FIle;
            file = fopen("assignment.txt", "a");
            FIle = fopen("st ast.txt", "a");
            fprintf(file, "%s %s %s \n", assignmentname, assignmentdeadline, astsubmissiontime);
            fprintf(FIle, "%s %s %s \n", assignmentname, assignmentdeadline, astsubmissiontime);
            fclose(file);
            fclose(FIle);
            cout << "\nNew Assignment has been added to database\n";
            cout << "\nDone\n";
            Sleep(1000);
        }
        else
            assignmentadd();

        cout << "Continue adding new Assignment? (y/n) : ";
        char cho;
        cin >> cho;
        if (cho == 'y' || cho == 'Y')
        {
            assignmentadd();
        }
        stwaitForEnter();
        //cms();
    }

    /////////////////////////////////
    void viewquizzMark()
    {
        system("cls");
        FILE* file;
        file = fopen("quizz.txt", "r");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>     STUDENT QUIZZ RECORD      <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t  NAME        |     DATE     |          TIME\n";
        cout << "\t\t------------------------------------------------------------------------------------";
        while (fscanf(file, "%s %s %s ", &quizzname[0], &quizzdate[0], &quizsubmissiontime[0]) != EOF)
            cout << "\n\t\t\t\t  " << quizzname << "\t\t   " << quizzdate << "\t\t" << quizsubmissiontime;
        fclose(file);
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        stwaitForEnter();
        //cms();
    }

    void quizzadd()
    { //adding records
        system("cls");
        char ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>         GENERATE QUIZZ         <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER QUIZZ NAME :: "; cin >> quizzname;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER QUIZZ DATE :: "; cin >> quizzdate;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER QUIZZ SUBMISSION TIME :: "; cin >> quizsubmissiontime;
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t                                                                ";
        cout << "\n\t\t          Enter 'y' to save above information ::   "; cin >> ch;
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);
        if (ch == 'y')
        {
            FILE* file, * FIle;
            file = fopen("quizz.txt", "a");
            FIle = fopen("quizz status.txt", "a");
            fprintf(file, "%s %s %s \n", quizzname, quizzdate, quizsubmissiontime);
            fprintf(FIle, "%s %s %s \n", quizzname, quizzdate, quizsubmissiontime);
            fclose(file);
            fclose(FIle);
            cout << "\nNew Quizz has been added to database\n";
            cout << "\nDone\n";
            Sleep(1000);
        }
        else
            quizzadd();

        cout << "Continue adding new Quizz? (y/n) : ";
        char cho;
        cin >> cho;
        if (cho == 'y' || cho == 'Y')
        {
            quizzadd();
        }

        stwaitForEnter();
        //cms();
    }
    /////////////////////////////////
    void viewlecturesUploaded()
    {
        system("cls");
        FILE* file;
        file = fopen("lectures.txt", "r");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>        LECTURES RECORD         <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t   NAME        | \t    DATE     \n";
        cout << "\t\t------------------------------------------------------------------------------------";
        while (fscanf(file, "%s %s ", &lecturename[0], &lecturedate[0]) != EOF)
            cout << "\n\t\t\t\t  " << lecturename << "\t\t   " << lecturedate;
        fclose(file);
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        stwaitForEnter();
        //cms();
    }

    void lecturesadd()
    { //adding records
        system("cls");
        char ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>           ADD LECTURE          <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER LECTURE NAME :: "; cin >> lecturename;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER LECTURE UPLOADED DATE :: "; cin >> lecturedate;
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t                                                                ";
        cout << "\n\t\t          Enter 'y' to save above information ::   "; cin >> ch;
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);
        if (ch == 'y')
        {
            FILE* file;
            file = fopen("lectures.txt", "a");
            fprintf(file, "%s %s \n", lecturename, lecturedate);
            fclose(file);
            ofstream myfile, yourfile, ourfile;
            myfile.open("Dummy lecture.txt");
            myfile << "This is dummy lecture \n\nthree newton law are as follow:\n\n1.newton first law\n2.newton second law\n3.newton thired law\n";
            myfile.close();
            yourfile.open("Dummy assignment.txt");
            yourfile << "This is dummy Assignment \nQ1.Write C++ program to display...Hello World ?:\nQ2.C++ Vs Python debate of Language ?\nQ3.C++ write program to display sum of 2 numbers ?\n";
            yourfile.close();
            ourfile.open("Dummy quizz.txt");
            ourfile << "This is dummy Quizz \nQ1.Write C++ program to take product of three numbers ?:\nQ2.Why Use c++ ?\nQ3.write C++ program to find max length string ?\n";
            cout << "\nNew Lecture has been added to database\n";
            Sleep(1000);
        }
        else
            lecturesadd();

        cout << "Continue adding new Lecture? (y/n) : ";
        char cho;
        cin >> cho;
        if (cho == 'y' || cho == 'Y')
        {
            lecturesadd();
        }

        stwaitForEnter();
        //cms();
    }
    ////////////////////////////////
    virtual void cms()
    {
        system("cls");
        faclogin();
        PlaySound(TEXT("welcome-to-faculty-cms.wav"), NULL, SND_ASYNC | SND_LOOP == 1 | SND_FILENAME);
    level2:
        
        system("cls");
        system("color 40");
        
        int choice;

        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>  Welcome to Faculty cms  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t||...>>>     "; showdate(); cout << " \t\t\t           "; showtime(); cout << "     <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 1 :->   To Upload Assignment                        <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 2 :->   To Generate Quizz                           <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 3 :->   To Upload Lectures                          <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 4 :->   To View All Assignments                     <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 5 :->   To View All Quizzes                         <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 6 :->   To View All Uploaded Lectures               <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 7 :->   To Mark Student Attendence                  <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 8 :->   To View Student Attendence                  <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 0 :->   Back to Main Manu                                <<<...||";
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t||...>>>                                                                      <<<...||";
        cout << "\n\t\t                      ENTER YOUR CHOICE :   ";
        cin >> choice;
        cout << "\n\t\t||...>>>                                                                      <<<...||";
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);
        switch (choice)
        {
        case 0:
            system("CLS");
            break;
        case 1:
            system("cls");
            assignmentadd();
            goto level2;
            break;
        case 2:
            system("cls");
            quizzadd();
            goto level2;
            break;
        case 3:
            system("cls");
            lecturesadd();
            goto level2;
            break;
        case 4:
            system("cls");
            viewassignment();
            goto level2;
            break;
        case 5:
            system("cls");
            viewquizzMark();
            goto level2;
            break;
        case 6:
            system("cls");
            viewlecturesUploaded();
            goto level2;
            break;
        case 7:
            system("cls");
            stattendence();
            goto level2;
            break;
        case 8:
            system("cls");
            stviewatten();
            goto level2;
            break;
        default:
            cout << "\n Sorry! I don't understand that! \n";
            system("cls");
            cms();
            break;
        }
    }
    ///////////////////////////////////////////////
    void facloginn()
    {
        system("cls");
        int count = 0;
        string userid, password, id, pass;
        string passs;
        char ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>         FACULTY LOGIN          <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER USER NAME :: "; cin >> userid;
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER PASSWORD  :: "; ch = _getch();
        while (ch != 13)
        {
            passs.push_back(ch);
            cout << "*";
            ch = _getch();
        }
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        Sleep(1000);
        password = passs;
        ifstream input("faculty login pass.txt", ios::in | ios::app | ios::out);
        while (input >> id >> pass)
        {
            if (id == userid && pass == password)
            {
                count = 1;
                system("cls");
            }
        }
        input.close();
        if (count == 1)
        {
            cout << "\nYour login is successfull\n\n";
            Sleep(1000);
        }
        else
        {
            cout << "\nlogin error\n";
            Sleep(1000);
            faclogin();
        }
    }
    void facregisterr()
    {
        system("cls");
        string ruserid, rpassword, rid, rpass;
        string passs = " ";
        char ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>      FACULTY REGISTRATON       <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER USER NAME :: "; cin >> ruserid;
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER PASSWORD  :: "; ch = _getch();
        while (ch != 13)
        {
            passs.push_back(ch);
            cout << "*";
            ch = _getch();
        }
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        Sleep(1000);
        rpassword = passs;

        ofstream fi;
        fi.open("faculty login pass.txt", ios::app);
        fi << ruserid << " " << rpassword << endl;
        fi.close();
        system("cls");
        cout << "\n\t\t\tRegistration successfull\n";
        Sleep(1000);
        faclogin();

    }
    void faclogin()
    {
        system("cls");
        int c;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>     FACULTY LOGIN SYSTEM       <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t\t     --->  : 1 : REGISTER    <---";
        cout << "\n\t\t\t\t\t     ----------------------------";
        cout << "\n\t\t\t\t\t     --->  : 2 : LOGIN       <---";
        cout << "\n\t\t\t\t\t     ----------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t                                                                ";
        cout << "\n\t\t                      ENTER YOUR CHOICE :   "; cin >> c;
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);
        switch (c)
        {
        case 1:
            facregisterr();
            break;
        case 2:
            facloginn();
            break;
        default:
            system("cls");
            cout << "\t\t\nselect from above \t\n";
            Sleep(1000);
            faclogin();
            break;
        }
    }
};
///////////////////////////////////////////////////////////////////////
class student :public facultyy
{

protected:
    string useridforprof;
public:
    ////////////////////st lms upload status section//////////////////////////
    void stassignmentstatus()
    {
        system("cls");
        char checkId[15];
        char newDesignation[10];
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>      ASSIGNMENT SUBMISSION     <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER ASSIGNMENT NAME :: "; cin >> checkId;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER ASSIGNMENT STATUS :: "; cin >> newDesignation;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);

        FILE* file, * tempfile;
        file = fopen("st ast.txt", "r");
        tempfile = fopen("temp.txt", "w");
        while (fscanf(file, "%s %s %s ", &assignmentname[0], &assignmentdeadline[0], &astsubmissiontime[0]) != EOF)
        {
            if (strcmp(checkId, assignmentname) == 0)
                fprintf(tempfile, "%s %s %s  \n", assignmentname, assignmentdeadline, newDesignation);
            else
                fprintf(tempfile, "%s %s %s  \n", assignmentname, assignmentdeadline, astsubmissiontime);
        }
        fclose(file);
        fclose(tempfile);
        int isRemoved = remove("st ast.txt");
        int isRenamed = rename("temp.txt", "st ast.txt");
        stwaitForEnter();
        stlms();
    }
    void stquizzstatus()
    {
        system("cls");
        char checkId[15];
        char newDesignation[10];
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>         QUIZZ SUBMISSION       <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER QUIZZ NAME :: "; cin >> checkId;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t    --->   ENTER QUIZZ STATUS :: "; cin >> newDesignation;
        cout << "\n\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        FILE* file, * tempfile;
        file = fopen("Quizz status.txt", "r");
        tempfile = fopen("temp.txt", "w");
        while (fscanf(file, "%s %s %s ", &quizzname[0], &quizzdate[0], &quizsubmissiontime[0]) != EOF)
        {
            if (strcmp(checkId, quizzname) == 0)
                fprintf(tempfile, "%s %s %s  \n", quizzname, quizzdate, newDesignation);
            else
                fprintf(tempfile, "%s %s %s  \n", quizzname, quizzdate, quizsubmissiontime);
        }
        fclose(file);
        fclose(tempfile);
        int isRemoved = remove("quizz status.txt");
        int isRenamed = rename("temp.txt", "quizz status.txt");
        stwaitForEnter();
        stlms();
    }
    //////////////////////////////////////////////

    void stviewassignment()
    {
        system("cls");
        FILE* file;
        file = fopen("st ast.txt", "r");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>    STUDENT ASSIGNMENT RECORD   <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t  NAME        |     DATE     |          STATUS\n";
        cout << "\t\t------------------------------------------------------------------------------------";
        while (fscanf(file, "%s %s %s", &assignmentname[0], &assignmentdeadline[0], &astsubmissiontime[0]) != EOF)
            cout << "\n\t\t\t\t  " << assignmentname << "\t\t   " << assignmentdeadline << "\t\t" << astsubmissiontime;
        fclose(file);
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        stwaitForEnter();
        stlms();
    }
    /////////////////////////////////////////////
    void stviewlectures()
    {
        system("cls");
        FILE* file;
        file = fopen("lectures.txt", "r");
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>         LECTURES RECORD        <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t  NAME        |     DATE     \n";
        cout << "\t\t------------------------------------------------------------------------------------";
        while (fscanf(file, "%s %s ", &lecturename[0], &lecturedate[0]) != EOF)
            cout << "\n\t\t\t\t  " << lecturename << "\t\t   " << lecturedate;
        fclose(file);
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        stwaitForEnter();
        stlms();
    }
    /////////////REad dummy////////////////////////////////////
    void streadlecture()
    {
        system("cls");
        ofstream file;
        file.open("Dummy lecture.txt");
        cout << "This is dummy lecture \nthree newton law are as follow:\n1.newton first law\n2.newton second law\n3.newton thired law\n";
        file.close();
        stwaitForEnter();
        stlms();
    }
    void streadAssignment()
    {
        system("cls");
        ofstream file;
        file.open("Dummy Assignment.txt");
        cout << "This is dummy Assignment \nQ1.Write C++ program to display...Hello World ?:\nQ2.C++ Vs Python debate of Language ?\nQ3.C++ write program to display sum of 2 numbers ?\n";
        file.close();

        stwaitForEnter();
        stlms();
    }
    void streadQuizz()
    {
        system("cls");
        ofstream file;
        file.open("Dummy Quizz.txt");
        cout << "This is dummy Quizz \nQ1.Write C++ program to take product of three numbers ?:\nQ2.Why Use c++ ?\nQ3.write C++ program to find max length string ?\n";
        file.close();

        stwaitForEnter();
        stlms();
    }
    /////////////////////////////////////////////
    void stviewquizz()
    {
        system("cls");
        FILE* file;
        file = fopen("quizz status.txt", "r");
        cout << "\n\t      List of Quizz\n";
        cout << "\n------------------------------------------------------------------------------";
        cout << "\n NAME        |   Date         |   Final Time \n";
        cout << "--------------------------------------------------------------------------------";
        while (fscanf(file, "%s %s %s", &quizzname[0], &quizzdate[0], &quizsubmissiontime[0]) != EOF)
            cout << "\n" << quizzname << "\t\t" << quizzdate << "\t\t" << quizsubmissiontime;
        fclose(file);
        stwaitForEnter();
        stlms();
    }
    //////////////////login////////////////////////
    void login()
    {
        system("cls");
        int count = 0;
        string userid, password, id, pass;
        string passs;
        char ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>         STUDENT LOGIN          <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER USER NAME :: "; cin >> userid; useridforprof = userid;
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER PASSWORD  :: "; ch = _getch();
        while (ch != 13)
        {
            passs.push_back(ch);
            cout << "*";
            ch = _getch();
        }
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        Sleep(1000);
        password = passs;
        ifstream input("student login pass.txt", ios::in | ios::app | ios::out);
        while (input >> id >> pass)
        {
            if (id == userid && pass == password)
            {
                count = 1;
                system("cls");
            }
        }
        input.close();
        if (count == 1)
        {
            cout << "\nYour login is successfull\n\n";
            Sleep(1000);
        }
        else
        {
            cout << "\nlogin error\n";
            Sleep(1000);
            studentlogin();
        }
    }
    void registerr()
    {
        system("cls");
        string ruserid, rpassword, rid, rpass;
        string passs = " ";
        char ch;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>      STUDENT REGISTRATION      <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER USER NAME :: "; cin >> ruserid;
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   ENTER PASSWORD  :: "; ch = _getch();
        while (ch != 13)
        {
            passs.push_back(ch);
            cout << "*";
            ch = _getch();
        }
        cout << "\n\t\t\t\t    -------------------------------------------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        _sleep(1000);
        rpassword = passs;
        ofstream fi;
        fi.open("student login pass.txt", ios::app);
        fi << ruserid << " " << rpassword << endl;
        fi.close();
        system("cls");
        cout << "\n\t\t\tRegistration successfull\n";
        Sleep(1000);
        studentlogin();

    }
    void studentlogin()
    {
        system("cls");
        int c;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>      STUDENT LOGIN SYSTEM      <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t\t     --->  : 1 : REGISTER    <---";
        cout << "\n\t\t\t\t\t     ----------------------------";
        cout << "\n\t\t\t\t\t     --->  : 2 : LOGIN       <---";
        cout << "\n\t\t\t\t\t     ----------------------------";
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t                                                                ";
        cout << "\n\t\t                      ENTER YOUR CHOICE :   "; cin >> c;
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(1000);
        switch (c)
        {
        case 1:
            registerr();
            break;
        case 2:
            login();
            break;
        default:
            system("cls");
            cout << "\t\t\nselect from above \t\n";
            Sleep(1000);
            studentlogin();
            break;
        }
    }
    //////////////////////////////////////////////
    Exam_department E1;
    theory_exam t1;
    practical_exam p1;

    virtual void cms()
    {
        studentlogin();
    level1:
        system("cls");
        int choice;
        system("color E5");
        PlaySound(TEXT("welcome-to-student-cms.wav"), NULL, SND_ASYNC | SND_LOOP == 1 | SND_FILENAME);
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>  Welcome to Student CMS  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t||...>>>     "; showdate(); cout << " \t\t\t           "; showtime(); cout << "     <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 1 :->   To Student Information                      <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 2 :->   To View Exam Date & Time                    <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 3 :->   To View Theory Exam hall no                 <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 4 :->   To View Lab Exam lab no                     <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 5 :->   To Go To LMS                                <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 0 :->   Back To Main Web Manu";
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t||...>>>                                                                      <<<...||";
        cout << "\n\t\t                      ENTER YOUR CHOICE :   ";
        cin >> choice;
        cout << "\n\t\t||...>>>                                                                      <<<...||";
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        Sleep(1000);
        switch (choice)
        {
        case 0:
            system("CLS");
            break;
        case 1:
            stprofinfo();
            //cms();
            goto level1;
            break;
        case 2:
            system("cls");
            E1.show_date_time_duration();
            //cms();
            goto level1;
            break;
        case 3:
            system("cls");
            t1.show_theory_course_hallno();
            //cms();
            goto level1;
            break;
        case 4:
            system("cls");
            p1.show_labno();
            //cms();
            goto level1;
            break;
        case 5:
            system("cls");
            stlms();
            //cms();
            goto level1;
            break;
        default:
            cout << "\n Sorry! I don't understand that! \n";
            system("cls");
            cms();
            break;
        }
    }
    /////////////////////////////////////////////
    void stlms()
    {
        system("cls");
        system("color E0");
        int choice;
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>  Welcome to Student LMS  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t||...>>>     "; showdate(); cout << " \t\t\t           "; showtime(); cout << "     <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 1 :->   To View Assignment                          <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 2 :->   To View Lecture                             <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 3 :->   To View Quizz                               <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 4 :->   To Read Assignment                          <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 5 :->   To Read Lecture                             <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 6 :->   To Read Quizz                               <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 7 :->   To Update Assignment Status                 <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 8 :->   To Update Quizz Status                      <<<...||";
        cout << "\n\t\t||...>>>\t\t--------------------------------------                <<<...||";
        cout << "\n\t\t||...>>>\t\t: 0 :->   Back to CMS                                 <<<...||";
        cout << "\n\t\t______________________________________________________________________________________";
        cout << "\n\n\t\t||...>>>                                                                      <<<...||";
        cout << "\n\t\t                      ENTER YOUR CHOICE :   ";
        cin >> choice;
        cout << "\n\t\t||...>>>                                                                      <<<...||";
        Sleep(1000);
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        switch (choice)
        {
        case 0:
            system("CLS");
            cms();
            break;
        case 1:
            stviewassignment();
            break;
        case 2:
            stviewlectures();
            break;
        case 3:
            stviewquizz();
            break;
        case 4:
            streadAssignment();
            break;
        case 5:
            streadlecture();
            break;
        case 6:
            streadQuizz();
            break;
        case 7:
            stassignmentstatus();
            break;
        case 8:
            stquizzstatus();
            break;
        default:
            cout << "\n Sorry! I don't understand that! \n";
            stlms();
            break;
        }
    }

    ////////////////////student profile information sync with login////////////////////////
    void stprofinfo()
    {
        system("cls");
        FILE* file;
        file = fopen("student.txt", "r");
        while (fscanf(file, "%s %s %s %s %s %s", &stname[0], &stid[0], &stqualification[0], &stcurrent_deg[0], &stdob[0], &stud_pd[0]) != EOF)
        {
            if (useridforprof == stname)
            {
                system("cls");
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   NAME :: " << stname;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   ID   :: " << stid;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   QUALIFICATION  :: " << stqualification;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   CURRENT DEGREE :: " << stcurrent_deg;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   DATE OF BIRTH  :: " << stdob;
                cout << "\n\t\t    -------------------------------------------------------------";
                cout << "\n\t\t    --->   GRADUATION STATUS  :: " << stud_pd;
                cout << "\n\t\t______________________________________________________________________________________";
            }
        }
        fclose(file);
        stwaitForEnter();
        //cms();
    }
};

void cmscall(Admin& ad)
{
    ad.cms();
}
int main()
{
    int ch;
    Admin a;
    facultyy f;
    student s;
jump:
    system("cls");
    system("color B1");
    //PlaySound(TEXT("main-manu.wav"), NULL, SND_FILENAME);
    PlaySound(TEXT("main-manu.wav"), NULL, SND_ASYNC | SND_LOOP== 1 | SND_FILENAME);
    cout << "\n\n\n\t\t_____________________________________________________________________________________";
    cout << "\n\t\t||...>>>                  ******* : MAIN MANU : *******                       <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                  ---> : 1 : ADMIN PORTAL <---                        <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                 ---> : 2 : fACULTY PORTAL <---                       <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                 ---> : 3 : STUDENT PORTAL <---                       <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t||...>>>                  **** : 0 : END PROGRAM ****                         <<<...||";
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t______________________________________________________________________________________";
    cout << "\n\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t                      ENTER YOUR CHOICE :   ";
    cin >> ch;
    cout << "\n\t\t||...>>>                                                                      <<<...||";
    cout << "\n\t\t______________________________________________________________________________________";
    Sleep(1000);
    switch (ch)
    {
    case 0:
        system("cls");
        PlaySound(TEXT("thank-you.wav"), NULL, SND_ASYNC | SND_LOOP == 1 | SND_FILENAME);
        
        cout << "\n\n\n\t\t_____________________________________________________________________________________";
        cout << "\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>         PROJECT CREDIT         <<<<<<<<<<<<<<<<<<<<<<<<<\n";
        cout << "\n\t\t------------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t    --->   BAHRIA UNIVERSITY ISLAMABAD ";
        cout << "\n\n\n\t\t\t\t    --->      MUHAMMAD UMAIR KHAN  ";
        //cout << "\n\n\n\t\t\t\t    --->      FAIZAN JAWAD  ";
        cout << "\n\n\n\t\t\t\t    --->   INSTRUCTOR   ::   MS NABIA ";        
        cout << "\n\t\t______________________________________________________________________________________" << endl;
        _sleep(5000);
        return 0;
    case 1:
        cmscall(a);
        goto jump;
        break;
    case 2:
        cmscall(f);
        goto jump;
        break;
    case 3:
        cmscall(s);
        goto jump;
        break;
    default:
        cout << "\n\n\t\t\tInvalid Input try again\t\n\n";
        Sleep(1000);
        main();
        break;
    }

    return 0;
}