#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record)
{
	vector<string> answer;
	unordered_map<string, string> uid;

	for (const auto& line : record)
	{
		stringstream ss(line);
		string cmd, id, nickname;
		ss >> cmd >> id;

		if (cmd != "Leave")
		{
			ss >> nickname;
			uid[id] = nickname;
		}
	}

	for (const auto& line : record)
	{
		stringstream ss(line);
		string cmd, id;
		ss >> cmd >> id;

		if (cmd == "Enter")
		{
			answer.push_back(uid[id] + "님이 들어왔습니다.");
		}
		if (cmd == "Leave")
		{
			answer.push_back(uid[id] + "님이 나갔습니다.");
		}
	}

	return answer;
}

int main()
{
	vector<string> record;

	record =
	{
		"Enter uid1234 Muzi",
		"Enter uid4567 Prodo",
		"Leave uid1234",
		"Enter uid1234 Prodo",
		"Change uid4567 Ryan"
	};

	vector<string> answer = solution(record);

	for (const string s : answer)
	{
		cout << s << endl;
	}

	return 0;
}