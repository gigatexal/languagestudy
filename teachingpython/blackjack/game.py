from cards import cards

class Fruit:
  def __init__(self,name):
     self.name = name

  def _get(self,attribute):
     if attribute == 'name':
        return self.name


apple = Fruit('apple')

print(apple._get('name'))



 



