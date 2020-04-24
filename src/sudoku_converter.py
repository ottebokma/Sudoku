import sys
#..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3..

def istncruc(character):      #istncruc checks wether a character is part of the contents of the sudoku or mere layout.
    return character in [".", "1", "2", "3", "4", "5", "6", "7", "8", "9"]   #return True if the character is in this list, return False if not.

def uglyfier(mooi):                 #uglyfier transforms the beautifully layouted version of the sudoku into the pure information.
    loailist = []                   #prepare an empty list.
    for ch in mooi:                 #for every character from the input,
        if istncruc(ch):            #check wether the character is important using istncruc,
            loailist.append(ch)     #and if so, add it to the list we prepared in line 8.
    loaistring = ''.join(loailist)  #convert this list to a string (this is'nt neccesary and can be changed if a list is preferred output)
    return loaistring
            
#main starts here
inp = []                    #prepare an empty list.
for line in sys.stdin:      #put all the lines in the input document in this list.
    inp.append(line)
mooi = ''.join(inp)         #convert this list to a string (this is neccesary, as the for loop in line 9 won't work if this is a list of all lines)

print(uglyfier(mooi))       #print what the uglyfier returns.