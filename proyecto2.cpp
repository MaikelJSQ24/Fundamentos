#include "Election.h"
#include "Candidate.h"

int main()
{
	string nameCandidates[8] = { "Ana", "Leo","Esmeralda","Luis", "Luz", "Diego","Mia", "Alex" };

	Election ELECCION_PROCESO1_2024(nameCandidates);
	Election ELECCION_PROCESO2_2024(nameCandidates);

	bool open = true;
	int option = 0;

	while (open)
	{
		cout << "Bienvenido a las elecciones de 2024 \n";
		cout << "1. Relizar votaciones.\n";
		cout << "2. Los candidato con mas votos. \n";
		cout << "3. Mostrar porcentages. \n";
		cout << "4. Saber abstencionismo. \n";
		cout << "5. Mostrar al ganador. \n";
		cout << "6. Mostrar comparacion. \n";
		cout << "7. Salir. \n";
		cin >> option;
		system("CLS");

		switch (option)
		{
		case 1:
			ELECCION_PROCESO1_2024.fillVotes();
			ELECCION_PROCESO1_2024.toStringElection();
			cout << endl;
			break;
		case 2:
			ELECCION_PROCESO1_2024.highestVotes();
			cout << endl;
			break;
		case 3:
			ELECCION_PROCESO1_2024.showByVotesPercentage();
			cout << endl;
			break;
		case 4:
			cout << "Abstencionismo es de: " << ELECCION_PROCESO1_2024.getAbstentionism();
			cout << endl;
			break;
		case 5:
			ELECCION_PROCESO1_2024.showElectionResults();
			if (!ELECCION_PROCESO1_2024.isWinnerDefined())
			{
				cout << "Segunda ronda: \n\n";
				ELECCION_PROCESO2_2024.fillVotes();
				ELECCION_PROCESO2_2024.toStringElection();
				cout << endl;
				ELECCION_PROCESO2_2024.highestVotes();
				cout << endl;
				ELECCION_PROCESO2_2024.showByVotesPercentage();
				cout << endl;
				cout << "Abstencionismo es de: " << ELECCION_PROCESO2_2024.getAbstentionism();
				cout << endl;
				ELECCION_PROCESO2_2024.showElectionResults();
				cout << endl;
			}
			cout << endl;
			break;
		case 6:
			if (!ELECCION_PROCESO1_2024.isWinnerDefined())
			{
				ELECCION_PROCESO1_2024.showComparation(ELECCION_PROCESO2_2024);
			}
			else {
				cout << "No hay segunda ronda\n";
			}

			break;
		case 7:
			cout << "Fin de las elecciones 2024";
			open = false;
			break;
		}
	}

}


