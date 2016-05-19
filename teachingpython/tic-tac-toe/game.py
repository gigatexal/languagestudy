class tictactoe:
    def __init__(self):
        self.MAXPLAYERS = 2
        self.board = {1: ['*', '*', '*'],
                      2: ['*', '*', '*'],
                      3: ['*', '*', '*']}
        self.placement = (1,0)#top right most entry key or row 1, array item 0
        self.players = []
        self.is_playable = self.num_empty_squares()

    def get_players(self):
       for i in range(0, self.MAXPLAYERS):
          question = 'Please enter in your name player ' + str(i+1) + ': '
          self.players.append(input(question).strip())

    def placements(self,row,col): #make a __function
        self.placement = (row,col)



    def get_inputs(self):
           '''
           row = input("Enter in a row (1 - 3): ").strip()
           col = input("Enter in a column (1-3): ").strip()
           '''

           try:
              '''
              row = int(row)
              col = int(col)
              '''
              row,col = self.placement
              if row > 0 and row <=3 and col > 0 and col <= 3:
                  self.placement = (row,col)
              #else:
              #    self.get_inputs()
           except ValueError:
               print("Please enter in an integer for row and column, like 1 instead of 1.0 "
                     "\n and not A or a or any other letter(s)")
               #self.get_inputs()

    def place(self, token):
        self.get_inputs()
        row, col = self.placement
        if self.board[row][col] == '*':
           self.board[row][col] = token
        else:
           if self.is_playable == 0:
               print("Run Game Over function")
           else:
               print("That's an invalid location, please try again")
               self.place(self,token) #BUG HERE?

    def show_board(self):
        row = 1
        print("    1    2    3") #this seems like a hack, fix me?
        for i in self.board.values():
            print(row,i)
            row += 1

    def num_empty_squares(self):
        curr_board = self.board
        num_empty = 0
        for index in curr_board.values():
            for elem in index:
               if elem == '*':
                  num_empty += 1
        return num_empty



#rudimentary tests
def main():
    game = tictactoe()
    for i in range(1,4):
        for j in range(0,3):
            game.placements(i,j)
            game.place('x')
            game.show_board()


main()

