#include <stdio.h>

int kebabShort = 0;
int burgerShort = 0;
int pastaShort = 0;
int lahmacunShort = 0;
int saladShort = 0;

int passesThreshold(int x, char* y, int z, int listID) {
    if (x >= 10) {
        printf("\n%s has %d votes.\n", y, x);
        z++;

        switch (listID) {
        case 1:
            kebabShort = 1;
            break;
        case 2:
            burgerShort = 1;
            break;
        case 3:
            pastaShort = 1;
            break;
        case 4:
            lahmacunShort = 1;
            break;
        case 5:
            saladShort = 1;
            break;
        }
    }

    return z;
}

int main()
{
    int people;
    printf("How many people are there?\n");
    scanf("%d", &people);

    printf("The list of choices:\n1-Kebab \n2-Burger \n3-Pasta \n4-Lahmacun \n5-Salad\n");

    int choice = -1;
    int kebab = 0;
    int burger = 0;
    int pasta = 0;
    int lahmacun = 0;
    int salad = 0;

    for (int i = 1; i <= people; i++) {
        printf("\nPerson %d will choose their dishes now.\n", i);

        for (int j = 1; j <= 5; j++) {
            printf("Please enter your choice number for priority %d.\n", j);
            scanf("%d", &choice);

            switch(choice) {
            case 1:
                kebab += 6 - j;
                break;
            case 2:
                burger += 6 - j;
                break;
            case 3:
                pasta += 6 - j;
                break;
            case 4:
                lahmacun += 6 - j;
                break;
            case 5:
                salad += 6 - j;
                break;
            }
        }
    }

    int pass = 0;

    pass = passesThreshold(kebab, "Kebab", pass, 1);
    pass = passesThreshold(burger, "Burger", pass, 2);
    pass = passesThreshold(pasta, "Pasta", pass, 3);
    pass = passesThreshold(lahmacun, "Lahmacun", pass, 4);
    pass = passesThreshold(salad, "Salad", pass, 5);

    if (pass > 0) {
        int dummyVar = -1;
    } else if (pass == 0) {
        printf("You are eating at home today!\n");
    }

    kebab = 0;
    burger = 0;
    pasta = 0;
    lahmacun = 0;
    salad = 0;

    printf("The list of choices:\n1-Kebab \n2-Burger \n3-Pasta \n4-Lahmacun \n5-Salad \nYou are only allowed to choose between the items in the short list.\n");

    for (int i = 1; i <= people; i++) {
        printf("\nPerson %d will choose their dishes now.\n", i);

        for (int j = 1; j <= pass; j++) {
            printf("Please enter your choice number for priority %d. \n", j);
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                if (kebabShort == 1) {
                    kebab += pass + 1 - j;
                }
                break;
            case 2:
                if (burgerShort == 1) {
                    burger += pass + 1 - j;
                }
                break;
            case 3:
                if (pastaShort == 1) {
                    pasta += pass + 1 - j;
                }
                break;
            case 4:
                if (lahmacunShort == 1) {
                    lahmacun += pass + 1 - j;
                }
                break;
            case 5:
                if (saladShort == 1) {
                    salad += pass + 1 - j;
                }
                break;
            }
        }
    }

    int max = kebab;
    int maxID = 1;

    if (burger > max) {
        max = burger;
        maxID = 2;
    }

    if (pasta > max) {
        max = pasta;
        maxID = 3;
    }

    if (lahmacun > max) {
        max = lahmacun;
        maxID = 4;
    }

    if (salad > max) {
        max = salad;
        maxID = 5;
    }
    
    switch (maxID) {
    case 1:
        printf("\nYou have chosen to eat %s.", "Kebab");
        break;
    case 2:
        printf("\nYou have chosen to eat %s.", "Burger");
        break;
    case 3:
        printf("\nYou have chosen to eat %s.", "Pasta");
        break;
    case 4:
        printf("\nYou have chosen to eat %s.", "Lahmacun");
        break;
    case 5:
        printf("\nYou have chosen to eat %s.", "Salad");
        break;
    }

    return 0;
}
