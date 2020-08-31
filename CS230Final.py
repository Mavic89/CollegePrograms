import sys
import csv


bigDictionary = {}


def main():
    guessedwords = 0
    # Call the function readPuzzle() to read data file into puzzle object

    puzzle = readPuzzle()
    
    # Create 15 x 15 game grid, initially filled with blocks ('*')
    
    grid = createGrid(puzzle)

    # Iterate through every word in the puzzle, adding each word to the grid

    #    for i in puzzle:
     #       addWordToGrid(i, grid)

    # Print the fully-populated grid to the console
    
    #printGrid(puzzle, grid)
    #word = findWord(puzzle,'62','D')
    #print(word)
    # Pause before exiting the program
    #input('Press ENTER: ')
    while(guessedwords < 84):
        userinput = input("(G) Guess Word, (C) Show Clue, (R) Show Grid, (Q) Quit").upper()
        if userinput == 'G':
            boxnumberGuess = input("Box Number:").upper()
            directionGuess = input("Direction:").upper()
            wordGuess = input("Word:").upper()
            getGuessInfo = findWord(puzzle, boxnumberGuess, directionGuess)
            if (type(getGuessInfo) == str):
                playerGuess = puzzle[getGuessInfo]['word']
                if playerGuess == wordGuess:
                    print("Correct!")
                    guessedwords +=1
                    addWordToGrid(wordGuess,grid)
                else:
                    print("InCorrect")
                
            else:
                print("no")
        if userinput == 'C':
            boxnumber = input('Box number:').upper()
            directionInput = input('Direction:').upper()
            getInfo = findWord(puzzle,boxnumber, directionInput)
            if (type(getInfo) == str):
                print(puzzle[getInfo]['clue'])
            else:
                print("There's nothing there")
                
        elif userinput == 'R':
            printGrid(puzzle,grid)
        elif userinput == 'Q':
            print("Thanks for playing!")
            input("Press 'ENTER' to exit")
            sys.exit()
            
    



def createGrid(puzzle):
    grid = [['*' for x in range(15)] for x in range(15)]
    for i in puzzle:
        word = puzzle[i]['word']
        x = int(puzzle[i]['x'])
        y = int(puzzle[i]['y'])
        for j in word:
            grid[y][x] = " "
            if puzzle[i]['direction'] == "A":
                x+=1
            elif puzzle[i]['direction'] == "D":
                y+=1
    return grid


def findWord(puzzle,box,direction):
    for i in puzzle:
        newword = i
        newworddirection=puzzle[i]['direction']
        newwordbox = puzzle[i]['box']
        if newworddirection == direction and newwordbox == box:
            return newword


    return None
    

def readPuzzle():

    #
    # READ THE PUZZLE DATA FILE INTO A DICTIONARY
    #

    # This function should: open the data file, read each line (representing a
    # word), split each line into a list (representing the properties of the
    # word), store these properties into a dictionary with sensible key names,
    # and add these dictionaries into the main dictionary 'puzzle', using the
    # word as the key name.  Finally, return the 'puzzle' dictionary to the
    # caller.
    with open('puzzle.csv') as csvfile:
        csvreader = csv.reader(csvfile, delimiter='\n')
        for row in csvreader:
            worddict={}
            wordrow = ''.join(row)
            wordlist=wordrow.split('\t')
            worddict['y']=wordlist[0]
            worddict['x']=wordlist[1]
            worddict['box']=wordlist[2]
            worddict['direction']=wordlist[3]
            worddict['word']=wordlist[4]
            worddict['clue']=wordlist[5]
            #bigDictionary.update({wordlist[4]:worddict})
            bigDictionary[wordlist[4]] = worddict

    return bigDictionary



def addWordToGrid(newword, grid):

    #
    # ADD A WORD TO THE GRID
    #

    # This function should: accept a word dictionary ('newword') and the grid
    # object ('grid') as arguments, and add each letter of 'newword', one by
    # one, into the correct squares of the grid, replacing any letters or
    # blocks already in these squares.  (Remember that the word dictionary
    # includes all of the properties of the word, including the X and Y
    # coordinates of the first letter of the word and each letter of the word.
    # You can use this information to determine the correct square for every
    # letter of the word.)  This function does not have to return a value to
    # the caller.

    # INSERT YOUR CODE HERE (and remove the "pass" statement in the next line)

    gridWord=list(bigDictionary[newword]['word'])
    a=int(bigDictionary[newword]['x'])
    b=int(bigDictionary[newword]['y'])
    
    for i in range(len(gridWord)):
        if(bigDictionary[newword]['direction'] == 'A'):
            grid[b][a]=gridWord[i]
            a+=1
        elif(bigDictionary[newword]['direction']== 'D'):
            grid[b][a]=gridWord[i]
            b+=1
        
    
    
    
    


def printGrid(puzzle, grid):

    #
    # PRINT THE GAME GRID TO THE CONSOLE
    #

    # Begin by creating a new two-dimensional array for the box numbers
    
    boxnumbers = [[0 for x in range(15)] for x in range(15)]

    # Next, loop through all the words in the puzzle to get the box numbers

    for i in puzzle:

        # Get the next word in the puzzle

        nextword = puzzle[i];

        # Retrieve the X and Y of the first letter, along with the box number

        x = int(nextword['x'])
        y = int(nextword['y'])
        box = int(nextword['box'])

        # Add the box number to the array

        boxnumbers[y][x] = box

    # Now, print the grid to the console

    for y in range(0,15):

        # Print the top border of the next row, box by box

        for x in range(0, 15):

            # If there is no box number on this box, print an empty top

            if ( boxnumbers[y][x] == 0 ):
                sys.stdout.write('+---')

            # If there is a single-digit box number, print it in the center
            
            elif ( boxnumbers[y][x] < 10 ):
                sys.stdout.write('+-' + str(boxnumbers[y][x]) + '-')

            # If there is a double-digit box number, print it at the left edge
                
            elif ( boxnumbers[y][x] >= 10 ):
                sys.stdout.write('+' + str(boxnumbers[y][x]) + '-')

        # End the top border and begin printing the next row
        
        sys.stdout.write('+\n|')

        # Print the next row, box by box, padding each letter with spaces

        for x in range(0,15):

            sys.stdout.write(' ' + str(grid[y][x]) + ' |')

        print()

    # Print the bottom border for the grid

    print('+' + '---+' * 15)

    

main()
