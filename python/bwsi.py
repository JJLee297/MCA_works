import random
class Card:
    rank = 0
    suit = 'D'
    def __init__(self, rank: int, suit: str):
        
        assert 2 <= rank <= 14, 'Valid ranks are [2, 14] for the ranks: [2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A]'
        assert suit.upper() in {'C', 'H', 'S', 'D'}, 'Valid suits are [C, H, S, D]'
        
        self.rank = rank
        self.suit = suit
        

    def __repr__(self):
      
        _rank_to_str = {11: 'Jack', 12: 'Queen', 13: 'King', 14: 'Ace'}
        _suit_to_str = {'C': 'Clubs', 'H': 'Hearts', 'S': 'Spades', 'D': 'Diamonds'}
        if (self.rank > 10 and self.rank < 15):
            return "{} of {}".format(_rank_to_str[self.rank], _suit_to_str[self.suit])
        else:
            return "{} of {}".format(self.rank, _suit_to_str[self.suit])

    def __lt__(self, other):
        """ Determine whether the rank of this card is less than the rank of the other. """
        if (self.rank < other.rank):
            return True
        else:
            return False

    def __gt__(self, other):
        """ Determine whether the rank of this card is greater than the rank of the other. """
        if (self.rank > other.rank):
            return True
        else:
            return False

    def __le__(self, other):
        """ Determine whether the rank of this card is less than or equal to the rank of the other. """
        if (self.rank <= other.rank):
            return True
        else:
            return False

    def __ge__(self, other):
        """ Determine whether the rank of this card is greater than or equal to the rank of the other. """
        if (self.rank >= other.rank):
            return True
        else:
            return False

    def __eq__(self, other):
        """ Determine whether the rank of this card is equal to the rank of the other. """
        if (self.rank == other.rank):
            return True
        else:
            return False
    

class Deck:
    
    def __init__(self, *shuffle):
        self.dealt = 0
        self.shuffled = False
        self.cards = []
        trig = True
        for bol in shuffle:
            if (bol == True):
                trig = False
                self.dealt = 0
                self.shuffled = True
                p = ['C', 'H', 'S', 'D']
                for x in range(2, 15):
                    for i in p:
                        tmpCard = Card(x, i)
                        self.cards.append(tmpCard)

        if (trig == True):
            self.dealt = 0
            self.shuffled = False
            p = ['C', 'H', 'S', 'D']
            for i in p:
                for x in range(2, 15):
                    tmpCard = Card(x, i)
                    self.cards.append(tmpCard)
                    
    def shuffle(self):
        for i in range(1,len(self.cards)):
            r= random.randint(0,i)
            self.cards[i],self.cards[r]=self.cards[r],self.cards[i]
        
    def deal_card(self):
        if (self.dealt < 52):
            self.dealt += 1
            return self.cards.pop()
        else:
            return None
        
    def __repr__(self): 
        a = self.dealt
        b = self.shuffled
        return ("Deck(dealt {}, shuffled={})".format(a, b))
    
    def reset(self):
        self.cards = []
        self.dealt = 0
        self.shuffled = False
        p = ['C', 'H', 'S', 'D']
        for i in p:
            for x in range(2, 15):
                tmpCard = Card(x, i)
                self.cards.append(tmpCard)


