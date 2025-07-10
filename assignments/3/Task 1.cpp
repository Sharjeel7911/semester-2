#include <iostream>
#include <iomanip>		
#include<fstream>
using namespace std;

void sizeofarrayfromfile(char* filename, int& numCandidates);
int* dynamic(int numCandidates);
void readCandidateData(char* filename, int* candidateIds, int* votesReceived, int numCandidates);
int calculateTotalVotes(int* votesReceived, int numCandidates);
void calculateVotePercentages(double* votePercentages, int* votesReceived, int totalVotes, int numCandidates);
int findWinnerIndex(int* votesReceived, int numCandidates);
void displayCandidateInfo(int* candidateIds, int* votesReceived, double* votePercentages, int numCandidates);
void writeToFile(int* candidateIds, int* votesReceived, double* votePercentages, int numCandidates);

void task1() {
	system("cls");
	int numCandidates = 0;
	char filename[] = "Data.csv";
	sizeofarrayfromfile(filename, numCandidates);

	int* candidateIds = dynamic(numCandidates);
	int* votesReceived = dynamic(numCandidates);
	readCandidateData(filename, candidateIds, votesReceived, numCandidates);

	int totalVotes = calculateTotalVotes(votesReceived, numCandidates);
	if (totalVotes == 0) {
		cout << "No votes cast." << endl;
		delete[] candidateIds;
		delete[] votesReceived;
		return;
	}

	double* votePercentages = new double[numCandidates];
	calculateVotePercentages(votePercentages, votesReceived, totalVotes, numCandidates);

	int winnerIndex = findWinnerIndex(votesReceived, numCandidates);

	displayCandidateInfo(candidateIds, votesReceived, votePercentages, numCandidates);
	cout << endl;
	cout << "Total Votes: " << totalVotes << endl;
	cout << "The winner of the election is: " << candidateIds[winnerIndex] << endl;

	writeToFile(candidateIds, votesReceived, votePercentages, numCandidates);

	delete[] candidateIds;
	delete[] votesReceived;
	delete[] votePercentages;
}

void sizeofarrayfromfile(char* filename, int& numCandidates) {
	fstream read(filename, ios::in);
	if (!read) {
		cout << "Error: Unable to open 'Data.csv'." << endl;
		return;
	}
	char header[100];
	read.getline(header, 100);
	numCandidates = 0;
	char count[100];
	while (read.getline(count,100)) {
		numCandidates++;
	}
	read.close();
}
int* dynamic(int numCandidates) {
	return new int[numCandidates];
}
void readCandidateData(char* filename, int* candidateIds, int* votesReceived, int numCandidates) {
	fstream read(filename, ios::in);
	if (!read) {
		cout << "Error: Unable to open 'Data.csv'." << endl;
		return;
	}
	char header[100];
	read.getline(header, 100);

	for (int i = 0; i < numCandidates; i++) {
		read >> candidateIds[i];
		read.ignore();
		read >> votesReceived[i];
	}
	read.close();
}
int calculateTotalVotes(int* votesReceived, int numCandidates) {
	int totalVotes = 0;
	for (int i = 0; i < numCandidates; i++) {
		totalVotes += *(votesReceived + i);
	}
	return totalVotes;
}
void calculateVotePercentages(double* votePercentages, int* votesReceived, int totalVotes, int numCandidates) {
	for (int i = 0; i < numCandidates; i++) {
		votePercentages[i] = (votesReceived[i] * 100.0) / totalVotes;
	}
}
int findWinnerIndex(int* votesReceived, int numCandidates) {
	int max = 0;
	for (int i = 1; i < numCandidates; i++) {
		if (votesReceived[i] > votesReceived[max]) {
			max = i;
		}
	}
	return max;
}
void displayCandidateInfo(int* candidateIds, int* votesReceived, double* votePercentages, int numCandidates) {
	cout << left << setw(15) << "Candidate" << setw(20) << "Votes Received" << setw(18) << "% of Total Votes" << endl;
	for (int i = 0; i < numCandidates; i++) {
		cout << left << setw(15) << candidateIds[i] << setw(20) << votesReceived[i] << setw(18) << votePercentages[i] << endl;
	}
}
void writeToFile(int* candidateIds, int* votesReceived, double* votePercentages, int numCandidates) {
	fstream write("Results.csv", ios::out);
	if (!write) {
		cout << "Error: Unable to open 'Results.csv'." << endl;
		return;
	}
	write << "Candidate, Votes Received, % of Total Votes" << endl;
	for (int i = 0; i < numCandidates; i++) {
		write << candidateIds[i] << "," << votesReceived[i] << "," << votePercentages[i] << endl;
	}
	write.close();
}