#include "Candidate.h"

Candidate::Candidate()
{
	votes = 0;
	candidateName = " ";
}

Candidate::Candidate(string candidateName, int votes)
{
	this->candidateName = candidateName;
	this->votes = votes;
}

Candidate::~Candidate()
{
}

void Candidate::setCandidate(string candidateName)
{
	this->candidateName = candidateName;
}

void Candidate::setVotes(int votes)
{
	this->votes = votes;
}

string Candidate::getCandidate()
{
	return candidateName;
}

int Candidate::getVotes()
{
	return votes;
}

void Candidate::toString()
{
	cout << "El nombre del candidatos es: " << candidateName << " sus votos son: " << votes << endl;
}
