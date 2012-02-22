#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototyes
void roll();

// Global Variables
int attack;
int defend;

int main() {

    srand(time(NULL));
    char attacker[5];
    char defender[5];
    char startAttack[5];
    printf( "Risk Roller\n\n" );

    // Get attacker count
    printf( "Input Attacker Minions: " );
    fgets( attacker, 10, stdin );
    attack = atoi( attacker );
    printf( "\n" );

    // Get defender count
    printf( "Input Defender Minions: " );
    fgets( defender, 10, stdin );
    defend = atoi( defender );
    printf( "\n" );

    // Start the attack
    printf( "Attacker: %d --- Defender: %d\n", attack, defend );
    printf( "Hit enter to begin attack\n" );

    // Carry out the attack
    while( ( attack > 0 ) && ( defend > 0 ) ) {
        fgets( startAttack, 5, stdin ); 
        roll( 5, 5);
        printf( "Attacker: %d --- Defender: %d\n", attack, defend );
        printf( "Hit enter to continue attacking\n" );
    }

}
/* roll()
 * Actually roll the dice and carry out
 * the attack.
 */
void roll( int attacker, int defender ) {

    int numDefendDice;
    int numAttackDice;
    int minDice;

    if( defend == 1 ) {
        numDefendDice = 1;
    } else {
        numDefendDice = 2;
    }
    if( attack == 1 ) {
        printf( "You can no longer attack, only one minion remains\n" );
        return;
    } else if( attack == 2 ) {
        numAttackDice = 1;
    } else if( attack == 3 ) {
        numAttackDice = 2;
    } else {
        numAttackDice = 3;
    }

    int attackMax = -1;
    int attackPos = -1;
    int defendMax = 0;
    int defendPos = 0;
    int attackDice[numAttackDice];
    int defendDice[numDefendDice];
    int sortedAttackDice[numAttackDice];
    int sortedDefendDice[numDefendDice];
    int i;

    if( numAttackDice < numDefendDice ) {
        minDice = numAttackDice;
    }else if( numDefendDice < numAttackDice ) {
        minDice = numDefendDice;
    }else{
        minDice = numDefendDice;
    }

    for( i = 0; i < numAttackDice; i++ ) {
        attackDice[i] = 1 + rand()%6;
        if( attackDice[i] > attackMax ) {
            attackMax = attackDice[i];
            attackPos = i;
        }
        printf("Attacker rolled: %d\n", attackDice[i] );
    }

    for( i = 0; i < numDefendDice; i++ ) {
        defendDice[i] = 1 + rand()%6;
        if( defendDice[i] > defendMax ) {
            defendMax = defendDice[i];
            defendPos = i;
        }
        printf("Defender rolled: %d\n", defendDice[i] );
    }

    defendDice[defendPos] =-1;
    attackDice[attackPos] = -1;
    if( attackMax > defendMax ) {
        defend--;
    }else{
        attack--;
    }
    if( minDice == 1) {
        return;
    }
    attackMax = -1;
    defendMax = -1;

    for( i = 0; i < numAttackDice; i++ ) {
        if( attackDice[i] > attackMax ) {
            attackMax = attackDice[i];
            attackPos = i;
        }
    }

    for( i = 0; i < numDefendDice; i++ ) {
        if( defendDice[i] > defendMax ) {
            defendMax = defendDice[i];
            defendPos = i;
        }
    }

    if( attackMax > defendMax ) {
        defend--;
    }else{
        attack--;
    }
}
