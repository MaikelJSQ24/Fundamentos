#pragma once
#include <iostream>
#include <string>
using namespace std;

class Candidate
{
private:
	int votes;
	string candidateName;
public:
	Candidate();
	Candidate(string candidateName, int votes);
	~Candidate();

	void setCandidate(string candidateName);
	void setVotes(int votes);

	string getCandidate();
	int getVotes();

	void toString();
};

