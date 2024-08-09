#include "Election.h"
#include <random>

Election::Election()
{
}

Election::Election(string nameCandidates[])
{
	for (int i = 0; i < 8; i++)
	{
		Candidate candidates(nameCandidates[i], 0);
		listOfCandidates[i] = candidates;
	}
}

Election::~Election()
{
}

void Election::setVotes(int votes)
{
	this->votes = votes;
}

int Election::getVotes()
{
	return votes;
}

int Election::generateVotes()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, poblation);

	votes = dis(gen);
	poblation -= votes;

	return votes;
}

void Election::fillVotes()
{
	for (int i = 0; i < 8; i++)
	{
		listOfCandidates[i].setVotes(generateVotes());
	}
}

void Election::showByVotesPercentage()
{
	float percentage = 0.0;

	for (int i = 0; i < 8; i++)
	{
		percentage = (float)listOfCandidates[i].getVotes() / totalVotes() * 100;
		cout << "El candidato: " << listOfCandidates[i].getCandidate() << " obtuvo un porcentage de: " << percentage << "%\n";
	}
}

int Election::totalVotes()
{
	int totalOfVotes = 0;
	for (int i = 0; i < 8; i++)
	{
		totalOfVotes += listOfCandidates[i].getVotes();
	}
	return totalOfVotes;
}

bool Election::isWinnerDefined()
{
	float percentage = 0.0;

	for (int i = 0; i < 8; i++)
	{
		percentage = (float)listOfCandidates[i].getVotes() / totalVotes() * 100;
		if (percentage >= 90)
		{
			return true;
		}
	}
	return false;
}

int Election::getAbstentionism()
{
	int abstentionism = 0;
	abstentionism = 1000000 - totalVotes();

	return abstentionism;
}

void Election::showElectionResults()
{
	for (int i = 0; i < 8; i++)
	{
		if (isWinnerDefined())
		{
			cout << "El ganador fue: " << listOfCandidates[i].getCandidate() << "\n";
			break;
		}
	}
}

void Election::highestVotes()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (listOfCandidates[j].getVotes() < listOfCandidates[j + 1].getVotes())
			{
				Candidate aux = listOfCandidates[j];
				listOfCandidates[j] = listOfCandidates[j + 1];
				listOfCandidates[j + 1] = aux;
			}
		}
	}
	cout << "Los dos mayores fueron: " << listOfCandidates[0].getCandidate() << " y " << listOfCandidates[1].getCandidate();
	cout << "\nCon un total de votos de: " << listOfCandidates[0].getVotes() << " y " << listOfCandidates[1].getVotes();
}

void Election::showComparation(Election election)
{
	for (int i = 0; i < 8; i++)
	{
		cout << "El candidato: " << listOfCandidates[i].getCandidate() << " obtuvo: " << listOfCandidates[i].getVotes() << " votos y en la segunda ronda: " << election.listOfCandidates[i].getVotes() << " votos\n";
	}
	cout << "El abtencionismo en la primera ronda fue de: " << getAbstentionism() << " y en la segunda fue de: " << election.getAbstentionism() << "\n\n";
}

void Election::toStringElection()
{
	for (int i = 0; i < 8; i++)
	{
		listOfCandidates[i].toString();
	}
}
