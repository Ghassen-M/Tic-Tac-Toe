def board(): #Prepare the board 
    B=[' |_|',' |_|',' |_|',' |_|',' |_|',' |_|',' |_|',' |_|',' |_|']
    return(B)

def choice():    #function: select coordinates
    while True: 
        P=int(input('Where do you want to put it ?'))
        B=board()
        if (1<=P<=9) and (B[P-1]==' |_|') :
            break 
    return(P-1)
#function submission 
def submission():
    B=board()
    while True:  #1st turn
        C = input ("Select either X or O")
        if (C.upper()=='X') or (C.upper()=='O'):
            break 
    while True: #the rest of the turns
        P=choice()
        B[P]=C.upper()
        print('{}{}{}\n'.format(B[6],B[7],B[8])) #displaying
        print('{}{}{}\n'.format(B[3],B[4],B[5]))
        print('{}{}{}\n'.format(B[0],B[1],B[2]))
        if (rules(B)=='W'): #rules checking
            print('You have won the game !')
            break
        elif (rules(B)=='D'):
            print('Draw!!')
            break
        
        if (C.upper()=='X'): #role switching
            C='O'
        else:
            C='X'


def rules(B):
    #Win conditions
    for i in range (0,7,3):
        if ((B[i]==B[i+1]==B[i+2]=='O') or (B[i]==B[i+1]==B[i+2]=='X')) : #horizental lines
            return ('W')
    for i in range(3):
        if ((B[i]==B[i+3]==B[i+6]=='O') or (B[i]==B[i+3]==B[i+6]=='X')) : #vertical lines
            return('W')
    if B[0]==B[4]==B[8]=='O' or B[2]==B[4]==B[6]=='O' or B[0]==B[4]==B[8]=='O' or B[2]==B[4]==B[6]=='O'  or B[0]==B[4]==B[8]=='X' or B[2]==B[4]==B[6]=='X' : #diagonals
            return ('W')
    #Continuing condition 
    for i in range(9):
        if (B[i]==' |_|'):
            return('S')
    #Draw condition
    return ('D') 
submission()
