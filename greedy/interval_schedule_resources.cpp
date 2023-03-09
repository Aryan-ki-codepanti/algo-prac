#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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

bool interval_compare(Interval i1, Interval i2)
{
    return i1.start_time <= i2.start_time;
}

bool isCompatible(Interval a, Interval b)
{
    if (a.start_time <= b.start_time && a.end_time <= b.end_time && a.end_time <= b.start_time)
        return true;
    return false;
}

void display(vector<Interval> intervals, vector<int> labels)
{

    int n = labels.size();
    map<int, vector<Interval>> label_map;
    for (int i = 0; i < n; i++)
        label_map[labels[i]].push_back(intervals[i]);

    cout << endl;
    for (auto it = label_map.begin(); it != label_map.end(); it++)
    {
        cout << "R" << it->first << " : ";
        for (auto &&interval : it->second)
            cout << interval.start_time << " " << interval.end_time << " , ";
        cout << endl;
    }
}

int get_good_label(vector<Interval> v, vector<int> labels, int current_interval)
{
    int n = v.size();

    vector<bool> possible_labels(n, true);
    for (int i = 0; i < current_interval; i++)
        if (!isCompatible(v[i], v[current_interval]))
            possible_labels[labels[i]] = possible_labels[labels[i]] && false;

    for (int i = 0; i < n; i++)
        if (possible_labels[i])
            return i;

    return -1;
}

vector<int> schedule_resources(vector<Interval> &intervals)
{

    int n = intervals.size();
    vector<int> labels(n, -1);

    sort(intervals.begin(), intervals.end(), interval_compare);

    for (int i = 0; i < n; i++)
        labels[i] = get_good_label(intervals, labels, i);
    return labels;
}

int main()
{

    int n;
    cout << "Enter number of intervals" << endl;
    cin >> n;

    vector<Interval> intervals(n);
    vector<int> labels;

    int x, y;
    cout << "Enter starting times and their finishing times" << endl;
    for (auto &&interval : intervals)
    {
        cin >> x >> y;
        interval = Interval(x, y);
    }

    labels = schedule_resources(intervals);

    display(intervals, labels);
    return 0;
}

/*

3
6 11
7 12
12 15

10
0 1
0 2
0 1
1 2
1 4
3 6
5 7
3 6
6 7
6 7

*/