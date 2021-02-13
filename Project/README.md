## Voting System

Team26

### Part 1 -How to run the code

Open terminal

Navigate to ../src

Execute following to compile:

```
make

```
To run the voting system:

```
./VotingSystem ../testing/CPL.CSV

```

or

```
./VotingSystem ../testing/OPL.CSV

```

### Part 2 -Testing

Open terminal

Navigate to ../src

To compile the tests, you only need to add the test file name ending with Test:

```
make [filename]

```

To run the tests, you can simply run the name of the tests:

```
./[filename]

```

**_Note: The following tests is slightly different since they need input file.**

To run promptFileTest, you will need to add a CSV file after:

```
./promptFileTest OPL.CSV

```

To run generateAuditFileTest, you will need to add a CSV file after:

```
./generateAuditFileTest ../testing/OPL.CSV

```
