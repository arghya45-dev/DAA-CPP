#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int id, deadline, profit;
};

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobSequencing(vector<Job> &jobs, int n)
{
    sort(jobs.begin(), jobs.end(), cmp);
    vector<int> slot(n, -1);
    vector<int> result;

    for (auto job : jobs)
    {
        for (int j = min(n - 1, job.deadline - 1); j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = job.id;
                result.push_back(job.id);
                break;
            }
        }
    }

    cout << "Jobs selected: ";
    for (auto id : result)
        cout << id << " ";
    cout << endl;
}

int main()
{
    vector<Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = 3; // Number of available slots
    jobSequencing(jobs, n);
    return 0;
}
