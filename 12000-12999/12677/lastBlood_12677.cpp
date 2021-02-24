#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;


class Submission {
	public:
		int teamID;
		int time;
		char problemID;

		Submission(int teamID, int time, char problemID) {
			this->teamID = teamID;
			this->time = time;
			this->problemID = problemID;
		}

		Submission() {
			teamID = -1;
			time = -1;
			problemID = '-';
		}

		bool isNone() { 
			return teamID == -1 && time == -1 && problemID == '-';
		}
};


int main(){

	map<char, tuple<Submission, set<int>>> problemsSubmissions;
	int nproblems, nteams, nsubms, team, time;
	char prob;
	string subResult;
	set<int> *problemsIDs;
	Submission sub;

	cin >> nproblems >> nteams >> nsubms;

	for(char c = 'A'; c < 'A'+nproblems; c++) {
		problemsSubmissions[c] = {Submission(), {}};
	}

	while(nsubms--) {
		cin >> time >> team >> prob >> subResult;
		if (subResult[0] == 'N') continue;
		int diff = prob - 'A';
		if (diff < 0 || diff > nproblems) continue;

		problemsIDs = &get<1>(problemsSubmissions[prob]);
		auto insertResult = (*problemsIDs).insert(team);
		if (!insertResult.second) continue;

		get<0>(problemsSubmissions[prob]) = Submission(team, time, prob);
	}

	for (auto &entry : problemsSubmissions) {
		prob = entry.first;
		sub = get<0>(entry.second);

		if (sub.isNone()) {
			printf("%c - -\n", prob);
		}
		else {
			printf("%c %d %d\n", prob, sub.time, sub.teamID);
		}
	}

	return 0;
}
