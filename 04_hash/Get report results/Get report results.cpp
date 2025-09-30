#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    // 신고당한 유저 - 신고 유저 셋
    unordered_map<string, unordered_set<string>> reported_user;
    unordered_map<string, int> count; // 처리 결과 메일을 받은 유저 - 받은 횟수

    // 신고 기록 순회
    for (string &r : report) {
        // 각 report에서 user_id와 report_id를 분리하고 reported_user에 추가
        stringstream ss(r);
        string user_id, reported_id;
        ss >> user_id >> reported_id;
        reported_user[reported_id].insert(user_id);
    }

    for (auto &u : reported_user) {
        if (u.second.size() >= k) { // k명 이상에게 신고당했는지 확인
            for (const string &uid : u.second) {
                count[uid]++;
            }
        }
    }

    vector<int> answer;
    // 아이디별 메일 받은 횟수를 id_list 순서대로 answer에 추가
    for (string &id : id_list) {
        answer.push_back(count[id]);
    }
    
    return answer;
}

int main()
{
    vector<string> id_list;
    vector<string> report;
    int k;

    id_list = { "muzi", "frodo", "apeach", "neo" };
    report = { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };
    k = 2;

    vector<int> result = solution(id_list, report, k);

    for (const auto it : result)
    {
        cout << it << " " << endl;
    }

    return 0;
}