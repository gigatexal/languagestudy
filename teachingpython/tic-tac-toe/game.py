class tictactoe():
    def __init__(self):
        self.MAXPLAYERS = 2
        self.board = {1: ['*', '*', '*'],
                      2: ['*', '*', '*'],
                      3: ['*', '*', '*']}
        self.placement = (0, 0)
        self.players = []

        #initial setup of the game
        self.get_players()

    def get_players(self):
       for i in range(0, self.MAXPLAYERS):
          question = 'Please enter in your name player ' + str(i+1) + ': '
          self.players.append(input(question).strip())

    def get_inputs(self):
       row = int(input("Enter in a row (1 - 3): "))
       col = int(input("Enter in a column (1-3): "))
       if (row > 0 and row <= 3) and (col > 0 and col <= 3):
          self.placement = (row, col)
       else:
           print("Please enter a row between (1-3) and a column of (1-3).")
           self.get_inputs()

    def place(self, placement, token):
        row, col = placement
        if self.board[row][col] == '*':
           self.board[row][col] = token
        else:
           print("That's an invalid location, please try again")
           self.place(placement, token)

    def show_board(self):
        row = 1
        print("    1    2    3") #this seems like a hack, fix me?
        for i in self.board.values():
            print(row,i)
            row += 1




#rudimentary tests
game = tictactoe()


