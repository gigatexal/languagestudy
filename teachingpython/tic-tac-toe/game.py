class tictactoe():
    def __init__(self):
        self.MAXPLAYERS = 2
        self.board = {1: ['*', '*', '*'],
                      2: ['*', '*', '*'],
                      3: ['*', '*', '*']}
        self.placement = (0,0)
        self.players = []

        #initial setup of the game
        self.get_players()

    def get_players(self):
       for i in range(0, self.MAXPLAYERS):
          question = 'Please enter in your name player ' + str(i+1) + ': '
          self.players.append(input(question).strip())

    def get_inputs(self):
           row = input("Enter in a row (1 - 3): ").strip()
           col = input("Enter in a column (1-3): ").strip()
           try:
              row = int(row)
              col = int(col)
              self.placement = (row,col)

           except ValueError:
               print("Please enter in an integer for row and column, like 1 instead of 1.0 "
                     "\n and not A or a or any other letter(s)")
               self.get_inputs()

    def place(self, token):
        row, col = self.placement
        if self.board[row][col] == '*':
           self.board[row][col] = token
        else:
           print("That's an invalid location, please try again")
           self.place(self.placement, token)

    def show_board(self):
        row = 1
        print("    1    2    3") #this seems like a hack, fix me?
        for i in self.board.values():
            print(row,i)
            row += 1



#rudimentary tests
game = tictactoe()
game.get_inputs()
game.place('x')
game.show_board()
