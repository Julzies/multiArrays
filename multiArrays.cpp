// **************************************************************
// Prompts for student names and scores, then prints
// them out with an average for each student
//
// Author: Marc Penalosa

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int NUM_STUDENTS = 3;
const int NUM_SCORES = 4;
const int MAX_LENGTH = 20;

char name[NUM_STUDENTS][MAX_LENGTH+1];
float score[NUM_STUDENTS][NUM_SCORES];
float average[NUM_STUDENTS];

// **************************************************************
// 
void PrintOutput(char name[][MAX_LENGTH+1], float score[][NUM_SCORES], float average[])
{
    for (int ii = 0; ii < NUM_STUDENTS; ii++)
    {
        cout << name[ii] << "'s scores:" << endl;
        for (int jj = 0; jj < NUM_SCORES; jj++)
        {
            cout << score[ii][jj] << endl;
        }
        cout << average[ii] << endl << endl;
    }
}

// **************************************************************
// 
void GetAverage(int ii)
{
    float totalScore = 0;
    for (int jj = 0; jj < NUM_SCORES; jj++)
    {
        totalScore += score[ii][jj];
    }
    average[ii] = totalScore / NUM_SCORES;
}

// **************************************************************
// 
void GetScore(int ii)
{
    for (int jj = 0; jj < NUM_SCORES; jj++)
    {
        cout << "Enter score #" << jj+1 << ": ";
        cin >> score[ii][jj];
        cin.ignore(cin.rdbuf()->in_avail());
    }
}

// **************************************************************
//
void GetName(char name[][MAX_LENGTH+1])
{
    for (int ii = 0; ii < NUM_STUDENTS; ii++)
    {
        cout << "Enter student name: ";
        cin >> name[ii];
        cin.ignore(cin.rdbuf()->in_avail());
        GetScore(ii);
        GetAverage(ii);
        cout << endl;
    }
}

// **************************************************************
// 
int main()
{
    GetName(name);
    PrintOutput(name, score, average);

    return 0;
}