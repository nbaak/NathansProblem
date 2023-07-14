import random


number_of_cards = 21
cards = [1] * number_of_cards

iterations = 0
while any(cards):
    faces_down_cards = [i for i,c in enumerate(cards) if c == 1]
    
    # pick a card with face down
    idx_c = random.choice(faces_down_cards)
    
    # turn card
    cards[idx_c] = 0
    
    # turn neighbour if possible
    if idx_c < number_of_cards-1:
        cards[idx_c+1] = 0 if cards[idx_c+1] else 1
    
    # give us a nice prompt
    print(f'{iterations:<3} {idx_c:<3} {"".join(map(str,cards))}')
    iterations += 1
    
print()
print(f"ended in {iterations-1} rounds")
