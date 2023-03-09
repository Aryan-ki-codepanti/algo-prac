#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Interval
{
public:
    int start_time, end_time;
    Interval(int a = 0, int b = 0)
    {
        start_time = a;
        end_time = b;
    }
};

bool interval_comparator(Interval a, Interval b)
{
    return a.end_time <= b.end_time;
}

void schedule_intervals(vector<Interval> schedules)
{
    int n = schedules.size();
    sort(schedules.begin(), schedules.end(), interval_comparator);

    vector<bool> schedule(n, false);

    int i, j, c = 0;
    for (i = 0; i < n;)
    {
        // take this interval
        schedule[i] = true;
        c++;
        for (j = i + 1; j < n && schedules[j].start_time < schedules[i].end_time; j++)
            ;
        i = j;
    }

    cout << "\nOptimally  scheduled Intervals : " << c << endl;
    for (i = 0; i < n; i++)
        if (schedule[i])
            cout << schedules[i].start_time << " " << schedules[i].end_time << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<Interval> schedules(n);

    int x, y;
    for (auto &&interval : schedules)
    {
        cin >> x >> y;
        interval = Interval(x, y);
    }
    schedule_intervals(schedules);

    return 0;
}

/*

11

2 5
2 5
2 5
1 3
4 7
6 9
10 13
10 13
8 11
10 13
12 14
*/