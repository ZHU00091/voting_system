# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -g

all: VotingSystem

PromptFile.o: PromptFile.cc promptFile.h
	$(CC) $(CFLAGS) -c PromptFile.cc

VotingSystem:main.cc PromptFile.o generateAuditFile.o cpl.o opl.o countVote.o countVoteOPL.o displayWinner.o displayWinnerCPL.o
	g++ -o VotingSystem main.cc PromptFile.cc generateAuditFile.cc cpl.cc opl.cc countVote.cc  countVoteOPL.cc displayWinner.cc displayWinnerCPL.cc


generateAuditFile.o: generateAuditFile.cc generateAuditFile.h
	$(CC) $(CFLAGS) -c generateAuditFile.cc

countVote.o: countVote.cc countVote.h
	$(CC) $(CFLAGS) -c countVote.cc

countVoteOPL.o: countVoteOPL.cc countVoteOPL.h
	$(CC) $(CFLAGS) -c countVoteOPL.cc

cpl.o: cpl.cc cpl.h
	$(CC) $(CFLAGS) -c cpl.cc

opl.o: opl.cc opl.h
	$(CC) $(CFLAGS) -c opl.cc

displayWinner.o: displayWinner.cc displayWinner.h
	$(CC) $(CFLAGS) -c displayWinner.cc

displayWinnerCPL.o: displayWinnerCPL.cc displayWinnerCPL.h
	$(CC) $(CFLAGS) -c displayWinnerCPL.cc

countVoteTest: countVoteTest.cc countVote.o cpl.o
	g++ -o countVoteTest countVoteTest.cc countVote.cc cpl.cc

countVoteOPLTest: countVoteOPLTest.cc countVoteOPL.o opl.o
	g++ -o countVoteOPLTest countVoteOPLTest.cc countVoteOPL.cc opl.cc

displayWinnerCPLTest: displayWinnerCPLTest.cc displayWinnerCPL.o
	g++ -o displayWinnerCPLTest displayWinnerCPLTest.cc displayWinnerCPL.cc

cplTest: cplTest.cc cpl.o
	g++ -o cplTest cplTest.cc cpl.cc


oplTest: oplTest.cc opl.o
	g++ -o oplTest oplTest.cc opl.cc

displayWinnerTest: displayWinnerTest.cc displayWinner.o
	g++ -o displayWinnerTest displayWinnerTest.cc displayWinner.cc

promptFileTest: promptFileTest.cc PromptFile.o
	g++ -o promptFileTest promptFileTest.cc PromptFile.cc

generateAuditFileTest: generateAuditFileTest.cc generateAuditFile.o
	g++ -o generateAuditFileTest generateAuditFileTest.cc generateAuditFile.cc

CPLSystemTest: CPLSystemTest.cc PromptFile.o generateAuditFile.o cpl.o countVote.o displayWinnerCPL.o
	g++ -o CPLSystemTest CPLSystemTest.cc PromptFile.cc generateAuditFile.cc cpl.cc countVote.cc displayWinnerCPL.cc
	
OPLSystemTest: OPLSystemTest.cc PromptFile.o generateAuditFile.o opl.o countVoteOPL.o displayWinner.o
	g++ -o OPLSystemTest OPLSystemTest.cc PromptFile.cc generateAuditFile.cc opl.cc countVoteOPL.cc displayWinner.cc
clean:
	$(RM) test *.o *~
