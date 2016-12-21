/*
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        if (people.size() == 0) {
            return result;
        }
        quickPairSort(people, 0, people.size() - 1);
        result.push_back(people[0]);
        for (unsigned int i = 1; i < people.size(); ++i) {
            int cnt = 0;
            vector<pair<int, int>>::iterator it = result.begin();
            while (it != result.end() && cnt < people[i].second) {
                if ((it -> first) >= people[i].first){
                    ++cnt;
                }
                ++it;
            }
            result.insert(it, people[i]);
        }
        return result;
    }
private:
    void quickPairSort(vector<pair<int, int>>& people, int low, int high) {
        if (low >= high) {
            return ;
        }
        int s = low;
        int t = high;
        pair<int ,int> key = people[s];
        while (s < t) {
            while (s < t && comparePair(people[t], key) == 1) {
                --t;
            }
            people[s] = people[t];
            while (s < t && comparePair(people[s], key) == -1) {
                ++s;
            }
            people[t] = people[s];
        }
        people[s] = key;
        quickPairSort(people, low, s - 1);
        quickPairSort(people, s + 1, high);
    }
    int comparePair(pair<int, int> a, pair<int, int> b) {
        if (a.second > b.second || (a.second == b.second && a.first < b.first))
            return 1;
        else if (a.second < b.second || (a.second == b.second && a.first > b.first))
            return -1;
        else 
            return 0;
    }
};
*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> result;
        for (auto& p : people){
            result.insert(result.begin() + p.second, p);
        }
        return result;
    }
private:
    static bool comp (const pair<int, int>& a, const pair<int, int>& b){
        return (a.first > b.first || (a.first == b.first && a.second < b.second ));
    }
};
