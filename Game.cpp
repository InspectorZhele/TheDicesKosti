#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int exit_=0, tries=3, numWin=0, talk=0, choice=2, numBlank[9]={0,0,0,0,0,0,0,0,0}, saver=0;
char numPrefere[50], Talk[100], ver[50]="0.6.2";

//ROULETTE
int roulette() {
    printf("R | \"It's simple, I toss a dice.\"\nu | \"If you get a 0, I'll give you life.\"\nl | \"If I get a 1, death.\"\ne | \ns | \n");
    printf("\n0 | \"Will you play?\" (1/0): ");
    scanf("%d",&choice);

    if (choice==1) {
        srand(time(NULL));

        if ((rand()%2)==1) {
        	printf("1 | \"The cube fell with the number one\"\n");
            printf("2 | \"I'm win, give me your life!\"\n");
            tries--;
        } 
        else {
        	printf("1 | \"The cube fell with the number zero\"\n");
            printf("2 | \"Okay, you've won, have a life.\"\n");
            tries++;
        }
    } else {printf("1 | \"Have a nice day\"\n");}
    printf("  | ");
    system("pause");
    if (tries>0) {
    	printf("3 | You returned to tovern\n");  
	} else {
		return 0;
	}
    printf("---------------------------------\n");
}
//STRANGE PLACE//
int strangeplace() {
	printf("A very strange landscape unfolds in this place, a strange smell of burnt bodies...\nYou see strange paper and pen\nWhat you write? ");
    scanf("%s",numPrefere);
				
	//CHEAT
    if (strcmp(numPrefere,"CHEAT")==0) {
		tries=999;
		numWin=999;
		printf("DEV: Cheats is activated\nYou have %d tries and %d Wins\n",tries,numWin);}
	//+life
    else if (strcmp(numPrefere,"life")==0 && numBlank[0]==0) {
        printf("You feel more healthy\n");
        tries++;
        numBlank[0]=1;
    }
    //InstaKill
    else if (strcmp(numPrefere,"666")==0) {
        tries=0;
        numWin=0;
        printf("You feel something bad\n");
    }
    //+win
    else if (strcmp(numPrefere,"win")==0 && numBlank[1]==0) {
        numWin++;
        numBlank[1]++;
        printf("You feel more rich\n");
    }
    //NOTHING
    else {printf("Nothing happened\n");}
    printf("You returned to tavern\n\n");
}

//TAVERN//
int tavern() {
	//TAVERN
	int eat;
    //FIRST BEER
    if (numBlank[6]==0) {
        printf("                            ____\n");
        printf("                           |    |\n");
        printf("                           [|  |] - \"First beer free!\" \n");
        printf("                            \\__/\n");
        printf("                         __/|  |\\__ \n");
        printf("                        /          \\ \n");
	    printf("                       /__/      \\__\\         /\n");
        printf("                       |  |      |  |        /\n");
        printf("____________________________________________/ \n");
        printf("                        \n");
        printf("                        |   |_\n");
        printf("                        |___|/\n");
        printf("_________________________________________________________\n");
        printf("You drinked beer!\nThat's give you 1 life!\n\n");
        tries++;
        numBlank[6]=1;
        system("pause");
        system("cls");
    }
    printf("                            ____\n");
	printf("                           |    |\n");
	printf("                           [|  |] - \"What would you like to order?\" \n");
	printf("                            \\__/\n");
	printf("                         __/|  |\\__ \n");
	printf("                        /          \\ \n");
	printf("                       /__/      \\__\\         /\n");
	printf("                       |  |      |  |        /\n");
	printf("____________________________________________/ \n");
	printf("   1 - Beer - 2 wins            4 - Saver - 4 win\n");
	printf("  2 - Dried Meat - 5 wins      5 - Talk\n");
	printf(" 3 - Wine & Omlette - 9 wins  6 - Leave\n");
	printf("_________________________________________________________\n");
	printf("-{You have %d wins}-\n",numWin);
	printf("You chooce: ");
    scanf("%d",&eat);
                
    if (eat==1 && numWin>=2) {
        printf("You drinked beer!\nThat's give you 1 life!\n");
        tries++;
        numWin-=2;
    } else if (eat==2 && numWin>=5) {
        printf("You ate meet!\nThat's give you 3 life!\n");
        tries+=3;
        numWin-=5;
    
    } else if (eat==3 && numWin>=9) {
        printf("You drinked Wine and ate Omlette!\nThat's give you 5 life!\n");
        tries+=5;
        numWin-=9;
    
    }else if (eat==4) {
    	//SAVER
        system("cls");
        printf("                            ____\n");
		printf("                           |    |\n");
		printf("                           [|  |] - \"Hmm, an interesting choice.\" \n");
		printf("                            \\__/   \"Let me explain how it works...\" \n");
		printf("                         __/|  |\\__ \"If the dealer's number is higher,\"\n");
		printf("                        /          \\ \"you get a chance to break the tie.\"\n");
		printf("                       /__/      \\__\\         /\n");
		printf("                       |  |      |  |        /\n");
		printf("____________________________________________/ \n");
		printf("   1 - Beer - 2 wins            4 - Saver - 4 win\n");
		printf("  2 - Dried Meat - 5 wins      5 - Talk\n");
		printf(" 3 - Wine & Omlette - 9 wins  6 - Leave\n");
		printf("_________________________________________________________\n");
        printf("\"Will you buy?\" (1/0): ");
        scanf("%d",&choice);

        if (choice==1 && numWin>=4) {
        	system("cls");
	        printf("                            ____\n");
			printf("                           |    |\n");
			printf("                           [|  |] - \"Thank you\" \n");
			printf("                            \\__/    \n");
			printf("                         __/|  |\\__  \n");
            printf("                        /          \\ \n");
	        printf("                       /__/      \\__\\         /\n");
			printf("                       |  |      |  |        /\n");
			printf("____________________________________________/ \n");
			printf("   1 - Beer - 2 wins            4 - Saver - 4 win\n");
			printf("  2 - Dried Meat - 5 wins      5 - Talk\n");
			printf(" 3 - Wine & Omlette - 9 wins  6 - Leave\n");
			printf("_________________________________________________________\n");
            saver=1;
			numWin-=4;}
        else if (numWin<4 && choice==1) {printf("Not enoght winnings!\n");}
        else {printf("You leave\n");}
    } else if (eat==5) {
    	//TALK
        srand(time(NULL));
        choice=rand()%22;
        switch (choice) {
	        case 0 ... 1:
	        	strcpy(Talk,"\"I was told that if in strange place you seach paper and a pen, if you write life, a miracle will happen.\" \n\"But these are just stories and legends.\"");
	            break;
	        case 2:
	            strcpy(Talk,"\"I was told that if in strange place you seach paper and a pen, if you write win, a miracle will happen.\" \n\"But these are just stories and legends.\"");
	            break;
	        case 3 ... 5:
	            strcpy(Talk,"\"If you don't understand how to play, look at the handbook, it's called Book of Rules.\"");
	            break;
            case 6 ... 8:
	            strcpy(Talk,"\"I sell the best beer!\"");
	            break;
            case 9 ... 11:
	            strcpy(Talk,"\"If you leave forever, I will forget you immediately.\"");
	            break;
            case 12 ... 13:
	            strcpy(Talk,"\"The paper that you signed absolves me of responsibility.\"");
	            break;
            case 14 ... 15:
	            strcpy(Talk,"\"Not many people come here.\"");
	            break;
            case 16 ... 17:
	            strcpy(Talk,"\"That Dealer is an old friend of mine.\"");
	            break;
            case 18 ... 19:
	            strcpy(Talk,"\"I heard that you can buy interesting things in the store across the street.\"");
	            break;
            case 20 ... 21:
	            strcpy(Talk,"\"Don't ask why the toilet smells like corpses.\"");
	            break;}
	    system("cls");
	    printf("     ____\n");
		printf("    |    |\n");
		printf("    [|  |]\n");
		printf("     \\__/\n");
		printf("  __/|  |\\__ \n");
        printf(" /          \\ \n");
        printf("/__/      \\__\\  \n");
		printf("|  |      |  |\n");
		printf("%s\n",Talk);
	}
    //LEAVE
    else if (eat==6) {
        printf("You leave\n");}
    //NOT ENOGHT WINNINGS
    else {printf("Not enough winnings!\n");}
    printf("------------------------\n");
}

//MENU
int menu() {
	if (tries>0) {
	    do {
	        printf("-{Your life: %d}-\n",tries);
	        printf("-{You have %d wins}-\n\n",numWin);
	        printf("Now, you in tovern\n");
	        printf("------------------\n");
	        printf("1 - Go to table\n");
	        printf("2 - Bartender\n");
	        printf("3 - Roulette\n");
	        printf("4 - Strange place\n");
	        printf("5 - Book of Rules\n");
	        printf("6 - Exit tavern\n");
	        printf("------------------\n");
	        printf("Your choose: ");
	        scanf("%d",&choice);
	        system("cls");
	        
	        if (choice==1234567) {
	        	tries++;
			}
	
	        switch (choice) {
	            case 1:
	            	//RUN
	            	return 0;
	                break;
	            case 2:
	                tavern();
	                break;
	            case 3:
	                roulette();
	                if (tries<1) {return 0;}
	                break;
	            case 4:
	                //STRANGE PLACE
	                strangeplace();
	                break;
	            case 5:
	            	//RULES
	                printf(" ______________________0______________________ \n");
	                printf("|  ______              0 It's simple, everyone| \n");
	                printf("| |      |             0 rolls the dice, and  | \n");
	                printf("| |DEALER| - Dealer's  0 whoever has the most | \n");
	                printf("| |  vs  |   dices     0 wins. But we are     | \n");
	                printf("| | YOUR | - Your      0 playing to the death.| \n");
	                printf("| |______|   dices     0               DEALER | \n");
	                printf("|______________________0______________________| \n");
	                printf("----------------------------------------------------------------------\n");
	                break;
	            case 6:
	            	//EXIT
	                printf("You want to leave? (1/0): ");
	                scanf("%d",&exit_);
	                printf("---------------------------\n");
	                break;
	            default:
	            	//INVAILD NUMBER
	                printf("Invaild code: 1-4\n");
	                break;
	            }
	    }while(exit_!=1);
    }
}


int main(void) {
    int numRand, numRandPlayer, winPlayer,round=0;

//MENU START
    printf("KK   KK   OOOO     SSSS  TTTTTT  II\n");
    printf("KK  KK   OO  OO   SS       TT    II\n");
    printf("KKK     OO    OO   SSSS    TT    II\n");
    printf("KK KK    OO  OO       SS   TT    II\n");
    printf("KK  KK    OOOO     SSSS    TT    II\n");
    printf("--------------The Dices--------------\n");
    //printf("______________________________________\n");
	printf("By Inspector Zhele     VisualVer %s\n",ver);
    printf("\nPress any button to START\n");
    system("pause");
    system("cls");

    printf("One night you came to a tavern. An old tavern with a creaking floor.\nYou notice a gambling table with a dealer sitting at it. You walked up to the bartender.\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    do {
//RAND NUM
        srand(time(NULL));
        numRand=(rand()%12)+1;
        numRandPlayer=(rand()%12)+1;
//GAME
        if (choice==2) {menu();}
        

        if (exit_==0) {
            round++;
            if (numBlank[5]==0) {
                printf("\"Enter your lucky number\" (1-50): ");
                scanf("%s",numPrefere);
                numBlank[5]++;
            }
            if (rand()%51==atoi(numPrefere)) {
                printf("Your lucky number work!\n");
                numRandPlayer++;}

            if (numRand<=0) {numRand=1;}

            system("cls");
            printf("[Round: %d] - [%d-DEALER %d-YOU]\n",round,numBlank[3],numBlank[4]);
            printf("Dealer rolls the dice...\n");
            system("pause");

            //USE ITEMS
            if (saver==1 && numRandPlayer<numRand) {
                printf("The saver give you %d dices!\n",numRand-numRandPlayer);
                numRandPlayer=numRand;
                saver=0;}

            if (numRand<10 && numRandPlayer<10) {
                printf("               ____\n");
				printf("              |    |\n");
				printf("              [0  0]\n");
				printf("               \\__/\n");
				printf("            ___|  |___\n");
				printf("           /          \\\n");
	            printf("          /  /      \\  \\\n");
                printf("          |  |      |  |\n");
                printf("       ___|__|______|__|___\n");
	            printf("      /         %d          \\\n",numRand);
	            printf("     /         v-s          \\\n");
	            printf("    /           %d            \\\n",numRandPlayer);
	            printf("   /__________________________\\ \n");
	            printf("   |__________________________| \n");
            } else if (numRand>=10 && numRandPlayer>=10) {
                printf("               ____\n");
				printf("              |    |\n");
				printf("              [0  0]\n");
				printf("               \\__/\n");
				printf("            ___|  |___\n");
				printf("           /          \\\n");
	            printf("          /  /      \\  \\\n");
                printf("          |  |      |  |\n");
                printf("       ___|__|______|__|___\n");
	            printf("      /         %d         \\\n",numRand);
	            printf("     /          vs          \\\n");
	            printf("    /           %d           \\\n",numRandPlayer);
	            printf("   /__________________________\\ \n");
	            printf("   |__________________________| \n");
            } else if (numRand<10 && numRandPlayer>=10) {
                printf("               ____\n");
				printf("              |    |\n");
				printf("              [0  0]\n");
				printf("               \\__/\n");
				printf("            ___|  |___\n");
				printf("           /          \\\n");
	            printf("          /  /      \\  \\\n");
                printf("          |  |      |  |\n");
                printf("       ___|__|______|__|___\n");
	            printf("      /         %d          \\\n",numRand);
	            printf("     /          vs          \\\n");
	            printf("    /           %d           \\\n",numRandPlayer);
	            printf("   /__________________________\\ \n");
	            printf("   |__________________________| \n");
            } else if (numRand>=10 && numRandPlayer<10) {
                printf("               ____\n");
				printf("              |    |\n");
				printf("              [0  0]\n");
				printf("               \\__/\n");
				printf("            ___|  |___\n");
				printf("           /          \\\n");
	            printf("          /  /      \\  \\\n");
                printf("          |  |      |  |\n");
                printf("       ___|__|______|__|___\n");
	            printf("      /         %d         \\\n",numRand);
	            printf("     /          vs          \\\n");
	            printf("    /           %d            \\\n",numRandPlayer);
	            printf("   /__________________________\\ \n");
	            printf("   |__________________________| \n");
            }
            system("pause");

			//RESULT
            if (numRand>numRandPlayer) {
                if (numBlank[8]==1) {
                    printf("\n\"Luck is on my side.\"\n-{Life -2}-\n-----------------\n");
                    tries-=2;
                } else {
                    printf("\n\"Luck is on my side.\"\n-{Life -1}-\n-----------------\n");
                    tries--;
                }
                numBlank[3]++;
            } else if (numRand==numRandPlayer){
                printf("\n%d:%d\n\"Luck is on your side.\"\n----------------------\n",numRand,numRandPlayer);
            } else {
                if (numBlank[8]==1) {
                    printf("\n\"I lose... Live now.\"\n-{Win +2}-\n-------------------\n");
                    numWin+=2;
                } else {
                    printf("\n\"I lose... Live now.\"\n-{Win +1}-\n-------------------\n");
                    numWin++;
                }
                numBlank[4]++;
            }
            //STORY
            if (numWin>6 && numBlank[7]==0) {
                printf("\"Interesting, very interesting... you are not a simple player.\"\n\"I will make the game more interesting. Everything is twice as big.\" \n");
                numBlank[7]=1;
                numBlank[8]=1;
            }

            system("pause");

			//NEXT ROUND OR TAVERN
            printf("\n-{Your life: %d}-\n",tries);
            printf("-{You have %d wins}-\n\n",numWin);
            printf("1 - Next round\n");
            printf("2 - Go to a tavern\n");
            printf("------------------\n");
            printf("Choice option: ");
            scanf("%d",&choice);

            system("cls");
        }
    }while(exit_!=1 && tries>0);
    //BAD END AND EXIT END
    if (tries<=0) {
    	printf("               ____\n");
        printf("              |    |\n");
        printf("              [0  0] - \"You have %d life... I win. You lose.\" \n",tries);
        printf("               \\__/    \"You died now\" \n");
        printf("            ___|  |___\n");
        printf("           /          \\\n");
        printf("          /  /      \\  \\\n");
        printf("          |  |      |  |\n");
        printf("       ___|__|______|__|___\n");
        printf("      /                    \\\n");
        printf("     /                      \\\n");
        printf("    /                        \\\n");
        printf("   /__________________________\\ \n");
        printf("   |__________________________| \n");
		system("pause");    
    	for (int i=0; i<9999;i+=0.1) {
    		printf(" Dead End");
		}
	} else {
		printf("You exit the tavern.\n");
	}
    system("pause");
    return 0;
}


