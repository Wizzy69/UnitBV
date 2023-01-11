#include <stdio.h>
#include <malloc.h>

typedef struct tstiva tstiva;
struct tstiva
{
    char c;
    struct tstiva *next;
} * cap;

bool introducere(char ch)
{
    tstiva *p;
    p = (tstiva *)malloc(sizeof(tstiva));
    if (p == NULL)
        return false;
    p->c = ch;
    p->next = cap;
    cap = p;
    return true;
}
int main()
{
    tstiva *p;
    int op;

    puts("Meniu:");
    printf("1. Introducere caracter in stiva\n");
    printf("2. Extragere caracter din stiva\n");
    printf("3. Afisare stiva\n");
    printf("4. Iesire\n");
    do
    {
        printf("Introduceti optiunea: \n");
        scanf("%d", &op);
        printf("\n");
        switch (op)
        {
        case 1:
            char ch;
            printf("Introduceti caracterul: \n");
            getchar();
            scanf("%c", &ch);
            if (introducere(ch))
                printf("Caracterul a fost introdus in stiva\n");
            else
                printf("Stiva este plina");
            break;
        case 2:
            if (cap == NULL)
                printf("Stiva este goala");
            else
            {
                p = cap;
                cap = cap->next;
                printf("Caracterul extras este: %c\n", p->c);
                free(p);
            }
            break;
        case 3:
            if (cap == NULL)
                printf("Stiva este goala");
            else
            {
                p = cap;
                while (p != NULL)
                {
                    printf("%c", p->c);
                    p = p->next;
                }

                printf("\n");
            }
            break;
        case 4:
            printf("La revedere\n");
            return 0;
            break;
        default:
            printf("Optiune incorecta\n");
            break;
        }
    } while (op != 4);
    // persoana = (pers *)malloc(sizeof(pers));

    // if (persoana == NULL)
    // {
    //     printf("Eroare la alocarea memoriei");
    //     exit(1);
    // }

    // printf("Introduceti numele: ");
    // scanf("%s", persoana->nume);

    // printf("Introduceti prenumele: ");
    // scanf("%s", persoana->prenume);

    // printf("Introduceti varsta: ");
    // scanf("%d", &persoana->varsta);

    // printf("Numele este: %s %s, iar varsta este: %d", persoana.nume, persoana.prenume, persoana.varsta);
    // return 0;
}