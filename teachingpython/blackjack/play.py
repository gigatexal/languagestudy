import random as rnd
from cards import cards

#randomly choose a card from the deck
#returns something like '5 of hearts'
def get_card(cards):
   return rnd.choice(cards)

#give a card get it's value i.e '5 of hearts' -> '5'
def get_card_value(card):
   return card.split()[0]





