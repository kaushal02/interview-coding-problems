/*
Rivigo IITK 2018

There is a gate in an amusement park. There is an entrance queue and an exit queue.
Given two arrays of length n, time[] and direction[] such that time[i] represents 
the time when person_i reaches the gate and direction[i] represents whether the 
person is joining the entrance queue or exit queue, output an array timestamp[] 
of length n such that timestamp[i] represents the time when person_i crosses the 
gate. The gate operates as follows:

If the gate was used at time t - 1 for entrance, then entry queue will be preferred.
Else If the gate was used at time t - 1 for exit, then exit queue will be preferred.
Else exit queue will be preferred.

1 <= n <= 10^5
1 <= time[i] <= 10^9
time[i] <= time[i+1]
direction[i] = 0 means entrance, direction[i] = 1 means exit.

O(n)
*/
vector<int> getTimeStamps(vector<int> time, vector<int> dir) {
    int n = time.size();
    time.push_back(1E9 + 1E6);
    vector<int> out(n);
    queue<int> q[2]; // enter(0), exit(1)
    for (int i = 0, t = time[0], fl = -1; i < n; i++) {
        q[dir[i]].push(i);
        while (t < time[i + 1]) {
            if (not q[0].empty() and not fl) {
                out[q[0].front()] = t++;
                q[0].pop();
                fl = 0;
            }
            else if (not q[1].empty()) {
                out[q[1].front()] = t++;
                q[1].pop();
                fl = 1;
            }
            else if (not q[0].empty()) {
                out[q[0].front()] = t++;
                q[0].pop();
                fl = 0;
            }
            else {
                t = time[i + 1];
                fl = -1;
            }
        }
    }
    return out;
}