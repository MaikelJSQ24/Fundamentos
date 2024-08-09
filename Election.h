#pragma once
#include <iostream>
#include <string>
#include "Candidate.h"
using namespace std;

class Election
{
private:
	Candidate listOfCandidates[8];
	int poblation = 1000000;
	int votes = 0;
public:
	Election();
	Election(string nameCandidates[]);
	~Election();

	void setVotes(int votes);
	int getVotes();

	int generateVotes();
	void fillVotes();
	void showByVotesPercentage();
	int totalVotes();
	bool isWinnerDefined();
	int getAbstentionism();
	void showElectionResults();
	void highestVotes();
	void showComparation(Election election);

	void toStringElection();
};

