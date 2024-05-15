#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int exit_=0, numWin=0, talk=0, choice=2, numBlank[10]={0,0,0,0,0,0,0,0,0,0}, stats[10]={0,0,0,0,0,0,0,0,0,0}, endWin=0, deathDealerMode=0, round=1, dealer=1;
char numPrefere[50], Talk[100], ver[50]="0.8.0";
//ITEMS
int itemSaver=0, itemHeart=0, itemPistol=0;
//TRIES
int tries=3, triesDealer=0;

//ITEMS
int items() {
    if (itemSaver==0 && itemPistol==0 && itemHeart==0) {printf("You have no items!\n");}
    else {
        printf("You have:\n");
        if (itemSaver==1) {printf("Saver\n");}
        if (itemPistol==1) {printf("Pistol\n");}
        if (itemHeart==1) {printf("Hardened heart\n");}
    }
    printf("------------------------\n");
}


//SHOP EMOTIONS
int shopThankYou() {
    system("cls");
    if (choice==1) {
        printf("                  |\\_ _/|                    \n");//1
        printf("                  | . . |                     \n");//2
        printf("                   \\_U_/ - \"Thank you!\"    \n");//3
        printf("                  __| |__                     \n");//4
        printf("                 /       \\                   \n");//5
        printf(" ________________________________________     \n");//6  42*11
        printf("| 1 - Saver - 4 wins    4 - Leave        |    \n");//7
        printf("| 2 - Pistol - 8 wins                    |    \n");//8
        printf("| 3 - Hardened heart - 14 wins           |    \n");//9
        printf("|________________________________________|    \n");//10
        printf("|                                        |    \n");//11
    } else if (choice==0) {
        printf("                  |\\_ _/|                    \n");//1
        printf("                  | . . |                     \n");//2
        printf("                   \\_U_/ - \"Ok.\"    \n");//3
        printf("                  __| |__                     \n");//4
        printf("                 /       \\                   \n");//5
        printf(" ________________________________________     \n");//6  42*11
        printf("| 1 - Saver - 4 wins    4 - Leave        |    \n");//7
        printf("| 2 - Pistol - 8 wins                    |    \n");//8
        printf("| 3 - Hardened heart - 14 wins           |    \n");//9
        printf("|________________________________________|    \n");//10
        printf("|                                        |    \n");//11
    } else {
        printf("                  |\\_ _/|                    \n");//1
        printf("                  | . . |                     \n");//2
        printf("                   \\_U_/ - \"Not enoght winnings!\"\n");//3
        printf("                  __| |__                     \n");//4
        printf("                 /       \\                   \n");//5
        printf(" ________________________________________     \n");//6  42*11
        printf("| 1 - Saver - 4 wins    4 - Leave        |    \n");//7
        printf("| 2 - Pistol - 8 wins                    |    \n");//8
        printf("| 3 - Hardened heart - 14 wins           |    \n");//9
        printf("|________________________________________|    \n");//10
        printf("|                                        |    \n");//11
    }
}
int shopItemBuy() {
    system("cls");
    printf("                  |\\_ _/|                    \n");//1
    printf("                  | . . |                     \n");//2
    printf("                   \\_U_/ - \"Sorry, we don't have any more!\"\n");//3
    printf("                  __| |__                     \n");//4
    printf("                 /       \\                   \n");//5
    printf(" ________________________________________     \n");//6  42*11
    printf("| 1 - Saver - 4 wins    4 - Leave        |    \n");//7
    printf("| 2 - Pistol - 8 wins                    |    \n");//8
    printf("| 3 - Hardened heart - 14 wins           |    \n");//9
    printf("|________________________________________|    \n");//10
    printf("|                                        |    \n");//11
}

//SHOP
int shop() {
    if (triesDealer==0) {printf("Sorry, we are closed now!\n");} 
    else {
        do {
        printf("                  |\\_ _/|                    \n");//1
        printf("                  | . . |                     \n");//2
        printf("                   \\_U_/ - \"Hi in my shop!\"\n");//3
        printf("                  __| |__   \"I'm cat!\"      \n");//4
        printf("                 /       \\                   \n");//5
        printf(" ________________________________________     \n");//6  42*11
        printf("| 1 - Saver - 4 wins    4 - Leave        |    \n");//7
        printf("| 2 - Pistol - 8 wins                    |    \n");//8
        printf("| 3 - Hardened heart - 14 wins           |    \n");//9
        printf("|________________________________________|    \n");//10
        printf("|                                        |    \n");//11
        printf("-{You have %d wins}-\n",numWin);
        printf("You choose: ");
        scanf("%d",&choice);

        //DESCRIPTION OF ITEMS
        switch (choice) {
            case 1:
                if (itemSaver==0) {
                    system("cls");
                    printf("                  |\\_ _/|                    \n");//1
                    printf("                  | . . |                     \n");//2
                    printf("                   \\_U_/ - \"Good choice!!! Let me explain how it works!\"\n");//3
                    printf("                  __| |__   \"The Saver will give you a chance to reduce\"\n");//4
                    printf("                 /       \\ \"everything to a draw if the Dealer has more dices\"\n");//5
                    printf(" ________________________________________     \n");//6  42*11
                    printf("| 1 - Saver - 4 wins    4 - Leave        |    \n");//7
                    printf("| 2 - Pistol - 8 wins                    |    \n");//8
                    printf("| 3 - Hardened heart - 14 wins           |    \n");//9
                    printf("|________________________________________|    \n");//10
                    printf("|                                        |    \n");//11
                    printf("You want to buy? (1/0): ");
                    scanf("%d",&choice);
                    if (choice==1 && numWin>=4) {
                        shopThankYou();
                        printf("You buy & use item. \n");
                        itemSaver=1;
                        numWin-=4; 
                    }
                    else if (choice==0) {shopThankYou();}
                    else {
                        choice++;
                        shopThankYou();}
                } else {shopItemBuy();}
                break;
            case 2:
                if (itemPistol==0) {
                    system("cls");
                    printf("                  |\\_ _/|                    \n");//1
                    printf("                  | . . |                     \n");//2
                    printf("                   \\_U_/ - \"Good! This item is for the final round only\"\n");//3
                    printf("                  __| |__   \"The Pistol will allow you to take one life.\"\n");//4
                    printf("                 /       \\ \"If you know what I mean.\"\n");//5
                    printf(" ________________________________________     \n");//6  42*11
                    printf("| 1 - Saver - 4 wins    4 - Leave        |    \n");//7
                    printf("| 2 - Pistol - 8 wins                    |    \n");//8
                    printf("| 3 - Hardened heart - 14 wins           |    \n");//9
                    printf("|________________________________________|    \n");//10
                    printf("|                                        |    \n");//11
                    printf("You want to buy? (1/0): ");
                    scanf("%d",&choice);
                    if (choice==1 && numWin>=8) {
                        shopThankYou();
                        printf("This item will be used only in the final round.\n");
                        itemPistol=1;
                        numWin-=8;
                    } else if (choice==0) {shopThankYou();}
                    else {
                        choice++;
                        shopThankYou();} 
                    
                } else {shopItemBuy();}
                break;
            case 3:
                if (itemHeart==0) {
                    system("cls");
                    printf("                  |\\_ _/|                    \n");//1
                    printf("                  | . . |                     \n");//2
                    printf("                   \\_U_/ - \"Oh! This is very interesting choice!\"\n");//3
                    printf("                  __| |__   \"Gives you two more life in the final round\"\n");//4
                    printf("                 /       \\                   \n");//5
                    printf(" ________________________________________     \n");//6  42*11
                    printf("| 1 - Saver - 4 wins    4 - Leave        |    \n");//7
                    printf("| 2 - Pistol - 8 wins                    |    \n");//8
                    printf("| 3 - Hardened heart - 14 wins           |    \n");//9
                    printf("|________________________________________|    \n");//10
                    printf("|                                        |    \n");//11
                    printf("You want to buy? (1/0): ");
                    scanf("%d",&choice);
                    if (choice==1 && numWin>=12) {
                        shopThankYou();
                        printf("This item will be used only in the final round.\n");
                        itemHeart=1;
                        numWin-=12;
                    }
                    else if (choice==0) {shopThankYou();}
                    else {
                        choice++;
                        shopThankYou();}
                } else {
                    shopItemBuy();}
                break;
            default:
                printf("You leaved shop\n");
        }
        if (choice!=4) {
            system("pause");
            system("cls");
        }

        } while(choice!=4);
    }
    printf("------------------------\n");
}
//ROULETTE ПЕРЕРОБИТИ!!!?
int roulette() {
    printf("R | \"It's simple, I toss a dice.\"\nu | \"If you get a 0, I'll give you life.\"\nl | \"If I get a 1, 2 lifes.\"\ne | \ns | \n");
    printf("\n0 | \"Will you play?\" (1/0): ");
    scanf("%d",&choice);

    if (choice==1) {
        srand(time(NULL));

        if ((rand()%3)==1) {
        	printf("1 | \"The cube fell with the number one\"\n");
            printf("2 | \"I'm win, give me your life!\"\n");
            tries--;
        } 
        else {
        	printf("1 | \"The cube fell with the number zero\"\n");
            printf("2 | \"Okay, you've won, have a 2 lifes.\"\n");
            tries+=2;
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
    else if (strcmp(numPrefere,"round12")==0) {
        printf("round=12\n");
        round=12;
    }
    else if (strcmp(numPrefere,"round24")==0) {
        printf("round=24\n");
        round=24;
    }
    else if (strcmp(numPrefere,"2round24")==0) {
        printf("2round=24\n");
        round=24;
        numBlank[9]=1;
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
    do {
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
        stats[5]++;
    } else if (eat==2 && numWin>=5) {
        printf("You ate meet!\nThat's give you 3 life!\n");
        tries+=3;
        numWin-=5;
        stats[5]++;
    
    } else if (eat==3 && numWin>=9) {
        printf("You drinked Wine and ate Omlette!\nThat's give you 5 life!\n");
        tries+=5;
        numWin-=9;
        stats[5]++;
    
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

        if (choice==1 && numWin>=4 && itemSaver!=1) {
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
            itemSaver=1;
			numWin-=4;
            stats[0]++;}
        //NOT ENOGHT WINNINGS
        else if (numWin<4 && choice==1) {
            system("cls");
	        printf("                            ____\n");
			printf("                           |    |\n");
			printf("                           [|  |] - \"Not enoght winnings!\" \n");
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
            }
        //PLAYER ARLEADY HAVE THIS ITEM
        else if (itemSaver==1 && choice==1) {
            system("cls");
	        printf("                            ____\n");
			printf("                           |    |\n");
			printf("                           [|  |] - \"Sorry I don't have this item.\" \n");
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
            }
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

    if(eat!=6) {
        system("pause");
        system("cls");
        }
    }while(eat!=6);
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
            printf("2 - Items\n");
	        printf("3 - Bartender\n");
	        printf("4 - Roulette\n");
	        printf("5 - Shop\n");
	        printf("6 - Strange place\n");
	        printf("7 - Book of Rules\n");
	        printf("8 - Exit tavern\n");
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
                    items();
                    break;
	            case 3:
	                tavern();
	                break;
	            case 4:
	                roulette();
	                if (tries<1) {return 0;}
	                break;
                case 5:
                    shop();
                    break;
	            case 6:
	                //STRANGE PLACE
	                strangeplace();
	                break;
	            case 7:
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
	            case 8:
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
int imgbattle(int numRand, int numRandPlayer) {
    if (dealer==2) {
        if (numRand<10 && numRandPlayer<10) {
                printf("               ____\n");
				printf("              |\\  /|\n");
				printf("              [O  O]\n");
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
				printf("              |\\  /|\n");
				printf("              [O  O]\n");
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
				printf("              |\\  /|\n");
				printf("              [O  O]\n");
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
				printf("              |\\  /|\n");
				printf("              [O  O]\n");
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
    } 
    else {
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
        }
}

int imgdeathDealer(int choice) {
    switch (choice) {
    case 1:
        printf("               ____\n");
		printf("              |    |         _________\n");
		printf("              [-  -]      (|_______  |)\n");
		printf("               \\__/               (_| |\n");
		printf("            ___|  |___              |_|\n");
		printf("           /          \\\n");
	    printf("          /  /      \\  \\\n");
        printf("          |  |      |  |\n");
        printf("       ___|__|______|__|___\n");
	    printf("      /                    \\\n");
	    printf("     /                      \\\n");
	    printf("    /                         \\\n");
	    printf("   /__________________________\\ \n");
	    printf("   |__________________________| \n");
        system("pause");
        system("cls");
        printf("               ____               \n");
		printf("              |    |     |\\ _________\n");
		printf("              [-  -]   ==   (|_______  |)\n");
		printf("               \\__/      |/       (_| |\n");
		printf("            ___|  |___              |_|\n");
		printf("           /          \\\n");
	    printf("          /  /      \\  \\\n");
        printf("          |  |      |  |\n");
        printf("       ___|__|______|__|___\n");
	    printf("      /                    \\\n");
	    printf("     /                      \\\n");
	    printf("    /                         \\\n");
	    printf("   /__________________________\\ \n");
	    printf("   |__________________________| \n");
        system("pause");
        system("cls");
        break;
    case 2:
        system("pause");
        system("cls");
        printf("               ____\n");
		printf("              |\\  /|         _________\n");
		printf("              [-  -]      (|_______  |)\n");
		printf("               \\__/               (_| |\n");
		printf("            ___|  |___              |_|\n");
		printf("           /          \\\n");
	    printf("          /  /      \\  \\\n");
        printf("          |  |      |  |\n");
        printf("       ___|__|______|__|___\n");
	    printf("      /                    \\\n");
	    printf("     /                      \\\n");
	    printf("    /                         \\\n");
	    printf("   /__________________________\\ \n");
	    printf("   |__________________________| \n");
        system("pause");
        system("cls");
        printf("               ____               \n");
		printf("              |\\  /|     |\\  _________\n");
		printf("              [-  -]   ==   (|_______  |)\n");
		printf("               \\__/      |/       (_| |\n");
		printf("            ___|  |___              |_|\n");
		printf("           /          \\\n");
	    printf("          /  /      \\  \\\n");
        printf("          |  |      |  |\n");
        printf("       ___|__|______|__|___\n");
	    printf("      /                    \\\n");
	    printf("     /                      \\\n");
	    printf("    /                         \\\n");
	    printf("   /__________________________\\ \n");
	    printf("   |__________________________| \n");
        system("pause");
        system("cls");
        break;
    default:
        break;
    }
}

int finalRound(int numRand, int numRandPlayer) {
    int fRound=1;
    tries=999;
    triesDealer=3;
    do {
    //RULES REPETE
    system("pause");
    system("cls");
    if (itemPistol==1) {
        printf("You use Pistol!\n-{Dealer life -1}-\n");
        triesDealer--;
        itemPistol=0;
    }
    if (itemHeart==1) {
        printf("You use Hardered Heart!\n-{Your life +2}-\n");
        tries+=1;
        itemHeart=0;
    }

    //START
    numRand=(rand()%12)+1;
    numRandPlayer=(rand()%12)+1;
    if (numRand>numRandPlayer && tries==1) {numRandPlayer+=2;}
    imgbattle(numRand,numRandPlayer);
    if (numRand>numRandPlayer) {
        printf("\"Good.\" \n");
        tries--;
    } else if (numRand==numRandPlayer) {printf("\"Interesting, very interesting.\" \n");}
    else {
        printf("\"Shit!\" \n");
        triesDealer--;}
    if (tries>=4) {printf("[Round - %d]\nDealer lifes %d...\nYour lifes %d + 2...\n",fRound,triesDealer,tries-2);}
    else {printf("[Round - %d]\nDealer lifes %d...\nYour lifes %d...\n",fRound,triesDealer,tries);}
    fRound++;
    if (tries<1) {return 0;}
    } while (tries>0 && triesDealer>0);

}

int main(void) {
    int numRand, numRandPlayer, winPlayer;

//MENU START
    printf("KK   KK   OOOO     SSSS  TTTTTT  II\n");
    printf("KK  KK   OO  OO   SS       TT    II\n");
    printf("KKK     OO    OO   SSSS    TT    II\n");
    printf("KK KK    OO  OO       SS   TT    II\n");
    printf("KK  KK    OOOO     SSSS    TT    II\n");
    printf("--------------The Dices--------------\n");
	printf("By Inspector Zhele     VisualVer %s\n",ver);
    printf("\nPress any button to START\n");
    system("pause");
    system("cls");

    printf("One night you came to a tavern. An old tavern with a creaking floor.\nYou notice a gambling table with a dealer sitting at it. You walked up to the bartender.\n");
    printf("P. S. Survive to rounds 12 and 24 to see the story\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    do {
//RAND NUM
        srand(time(NULL));
        //HELP MODE
        if (tries==1 && numRandPlayer<=10 || tries==2 && numBlank[8]==1 && numRandPlayer<=10) {numRandPlayer=((rand()%12)+1)+2;} 
        else {numRandPlayer=(rand()%12)+1;}
        numRand=(rand()%12)+1;

        if (numRandPlayer>12) {numRandPlayer=12;}
        
//GAME
        if (choice==2) {menu();}
        if (deathDealerMode==1) {

        } else {
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
            if (itemSaver==1 && numRandPlayer<numRand) {
                printf("The saver give you %d dices!\n",numRand-numRandPlayer);
                numRandPlayer=numRand;
                itemSaver=0;}

            //IMG BATTLE
            imgbattle(numRand, numRandPlayer);
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
                stats[4]++;
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
                stats[3]++;
            }
            //x2 MODE
            if (round>12 && numBlank[7]==0) {
                printf("\"Interesting, very interesting... you are not a simple player.\"\n\"I will make the game more interesting. Everything is twice as big.\" \n");
                if (tries<3) {
                    printf("\"I give %d lives\" \n",3-tries);
                    tries+=3-tries;}
                numBlank[7]=1;
                numBlank[8]=1;
            }
            //1º Death Dealer
            if (round>=24 && numBlank[9]==0) {
                printf("\"Now the real game will begin.\" \n");
                printf("\"To be fair, I also have a life.\" \n");
                printf("\"You have 3 and I have 3 lives.\" \n");
                system("pause");//rr
                system("cls");//rr
                
                numBlank[9]=1;
                tries=3;
                triesDealer=3;
                numRand=9;
                numRandPlayer=8;
                printf("You have %d lives...\nDealer have %d lives...\n",tries,triesDealer);
                imgbattle(numRand,numRandPlayer);
                tries--;
                printf("\"Luck is on my side...\" \n");
                system("pause");//rr
                system("cls");//rr

                printf("You have %d lives...\nDealer have %d lives...\n",tries,triesDealer);
                numRand=12;
                numRandPlayer=4;
                imgbattle(numRand, numRandPlayer);
                tries--;
                printf("\"Your death is near!\" \n");
                system("pause");//rr
                system("cls");//rr

                printf("You have %d lives...\nDealer have %d lives...\n",tries,triesDealer);
                numRand=10;
                numRandPlayer=9;
                triesDealer--;
                imgbattle(numRand, numRandPlayer);
                printf("\"Next time You'll be lucky. Maybe\" \n");
                system("pause");//rr
                system("cls");//rr

                printf("You have %d lives...\nDealer have %d lives...\n",tries,triesDealer);
                numRand=5;
                numRandPlayer=8;
                triesDealer--;
                imgbattle(numRand, numRandPlayer);
                printf("\"Shit!\" \n");
                system("pause");//rr
                system("cls");//rr

                printf("You have %d lives...\nDealer have %d lives...\n",tries,triesDealer);
                numRand=7;
                numRandPlayer=8;
                triesDealer--;
                imgbattle(numRand, numRandPlayer);
                printf("\"...\" \n");
                system("pause");//rr
                printf("\"...\" \n");
                system("pause");//rr
                printf("\"...\" \n");
                system("pause");//rr
                system("cls");//rr

                printf("You have %d lives...\nDealer have %d lives...\n",tries,triesDealer);
                numRand=11;
                numRandPlayer=12;
                triesDealer--;
                imgbattle(numRand, numRandPlayer);
                printf("\"...\" \n");
                printf("\"It's not true...\" \n");
                system("pause");//rr
                printf("\"I DON'T WANT DIE...\" \n");
                system("pause");//rr
                system("cls");//rr

                choice=1;
                imgdeathDealer(choice);    
                printf("In next time will be other Dealer.\n");
                system("pause");
                printf("You returned to tavern.\n");
                printf("You see a sign open in front of the store.\n");

                dealer++;
                round=0;
                menu();
            }
            
            //DIE DEALER
            if (round>=24 && numBlank[9]==1) {
                printf("\"Time out.\" \n");
                printf("\"Time for final round.\" \n");
                finalRound(numRand,numRandPlayer);
                if (triesDealer<=0) {
                    choice=2;
                    imgdeathDealer(choice);
				}
                if (tries>0) {
                    dealer++;
                    printf("You returned to tavern.\n");}
                round=0;
                menu();
            }
            system("pause");

            if (tries>0) {

            //stats - round
            stats[6]++;

			//NEXT ROUND OR TAVERN
            printf("\n-{Your life: %d}-\n",tries);
            printf("-{You have %d wins}-\n\n",numWin);
            printf("1 - Next round\n");
            printf("2 - Go to a tavern\n");
            printf("------------------\n");
            printf("Choice option: ");
            scanf("%d",&choice);}

            system("cls");
        }

        }
    }while(exit_!=1 && tries>0);
    //BAD END AND EXIT END
    if (tries<=0) {
        if (dealer==2) {
            printf("               ____\n");
            printf("              |\\  /|\n");
            printf("              [O  O] - \"You have %d life... I win. You lose.\" \n",tries);
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
        }
        else {
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
        printf("   |__________________________| \n");}
		system("pause");    
    	for (int i=0; i<9999;i+=0.1) {
    		printf(" Dead End");
		}
	}
	if (exit_==1) {
		printf("You exit the tavern.\n");
	}
	if (endWin==1) {
        system("cls");
        printf("\n");
		printf("You win 34.000 $\n");
		printf("Your Stats:\n");
        printf("You have use saver %d times...\n",stats[0]);
        //printf("You had %d lives...\n",stats[1]);
        printf("You ate %d food...\n",stats[5]);
        printf("There were %d rounds...\n",stats[6]);
        printf("You win %d rounds...\n",stats[3]);
        printf("You lose %d rounds...\n",stats[4]);
	}
    system("pause");
    return 0;
}


