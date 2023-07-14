#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    int number_of_cards = 21;
    int cards[number_of_cards];
    int iterations = 0;
    
    // Initialize all cards as face down (1 represents face down)
    for (int i = 0; i < number_of_cards; i++) {
        cards[i] = 1;
    }
    
    // Initialize the random number generator with current microsecond
    srand((unsigned int)time(NULL));
    
    while (true) {
        int faces_down_cards[number_of_cards];
        int faces_down_count = 0;
        
        // Get indices of face-down cards
        for (int i = 0; i < number_of_cards; i++) {
            if (cards[i] == 1) {
                faces_down_cards[faces_down_count] = i;
                faces_down_count++;
            }
        }
        
        // Check if all cards are face up
        if (faces_down_count == 0) {
            break;
        }
        
        // Pick a card with face down randomly
        int idx_c = faces_down_cards[rand() % faces_down_count];
        
        // Turn the selected card face up
        cards[idx_c] = 0;
        
        // Check if the neighbor card can be turned as well
        if (idx_c < number_of_cards - 1) {
            cards[idx_c + 1] = (cards[idx_c + 1] == 0) ? 1 : 0;
        }
        
        // Display the game progress
        printf("%-3d %-3d ", iterations, idx_c);
        for (int i = 0; i < number_of_cards; i++) {
            printf("%d", cards[i]);
        }
        printf("\n");
        
        iterations++;
    }
    
    printf("\nGame ended in %d rounds\n", iterations - 1);
    
    return 0;
}
