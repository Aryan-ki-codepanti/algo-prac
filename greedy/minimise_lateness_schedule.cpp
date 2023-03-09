#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Interval
{
public:
    int deadline, time_limit, id;
    Interval(int a = 0, int b = 0, int c = 0)
    {
        id = a;
        time_limit = b;
        deadline = c;
    }
};

bool interval_comparator(Interval a, Interval b) { return a.deadline <= b.deadline; }

void schedule_minimise_max_lateness(vector<Interval> intervals, int start)
{
    int max_lateness = -1, current_lateness, current_finishing;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), interval_comparator);

    int f = start;
    cout << "Interval ID\tStart\tFinish\tLateness" << endl;
    for (auto &&interval : intervals)
    {
        current_finishing = f + interval.time_limit;

        // lateness update
        current_lateness = current_finishing > interval.deadline ? current_finishing - interval.deadline : 0;
        max_lateness = max(max_lateness, current_lateness);

        cout << interval.id << "\t\t" << f << "\t" << current_finishing << "\t" << current_lateness << endl;
        f += interval.time_limit;
    }
    cout << "MAX Lateness : " << max_lateness << endl;
}

int main()
{

    int n, s = 0;
    cin >> n >> s;
    vector<Interval> schedules(n);

    int x, y, z;
    for (auto &&interval : schedules)
    {
        cin >> x >> y >> z;
        interval = Interval(x, y, z);
    }
    schedule_minimise_max_lateness(schedules, s);
    return 0;
}

/*
3 0
2 2 4
1 1 2
3 3 6

2 0
1 1 100
2 10 10

2 0
1 1 2
2 10 10
*/