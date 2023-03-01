#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Function prototypes
void addCandidate();
void castVote();
void showResults();

// Global variables
vector<string> candidateList;
map<string, int> voteCount;

int main()
{
    int choice;
    cout << "Welcome to Voting System!" << endl;
    do {
        cout << "\nPlease choose an option:" << endl;
        cout << "1. Add a candidate" << endl;
        cout << "2. Cast a vote" << endl;
        cout << "3. Show results" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                addCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                showResults();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}

void addCandidate()
{
    string name;
    cout << "Enter the candidate's name: ";
    cin >> name;
    candidateList.push_back(name);
    cout << "Candidate added." << endl;
}

void castVote()
{
    int choice;
    cout << "Please select a candidate to vote for:" << endl;
    for (int i = 0; i < candidateList.size(); i++)
    {
        cout << i+1 << ". " << candidateList[i] << endl;
    }
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice < 1 || choice > candidateList.size())
    {
        cout << "Invalid choice. Please try again." << endl;
    }
    else
    {
        string candidateName = candidateList[choice-1];
        voteCount[candidateName]++;
        cout << "Vote casted for " << candidateName << "." << endl;
    }
}

void showResults()
{
    cout << "Results:" << endl;
    for (int i = 0; i < candidateList.size(); i++)
    {
        string candidateName = candidateList[i];
        int votes = voteCount[candidateName];
        cout << candidateName << ": " << votes << " vote(s)" << endl;
    }
}

