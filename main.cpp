#include "Generateur.h"

int main(int argc, const char *argv[]) {

    cout << "||-----------------------------------------------------------------------------------||" << endl;
    cout << "||          ####### Kakuro by Naim & Raouf #######                                   ||" << endl;
    cout << "||-----------------------------------------------------------------------------------||" << endl;
    cout << endl;


    // Déclaration des variables nécessaires
    Generateur *s = new Generateur();
    int solverChoice, valuesList, nbLines = 0, nbColumn = 0, nbValues = 0;

    //Initialisation
    cout << "\t--> Please enter nb Lines : ";
    cin >> nbLines;
    cout << "\t--> Please enter nb Columns : ";
    cin >> nbColumn;
    cout << "\t--> Please enter the number of possible values : ";
    cin >> nbValues;

    //Choix du solveur
    cout << "\t--> Nice! Now, you only have to choice between NaimRaouf Solver or MonteCarlo Solver : \n" << endl;
    cout << "\t--> 1- Naim & Raouf Solver \n\t-->2- MonteCarlo\n";
    cout << "\t--> Your choice : ";
    cin >> solverChoice;

    switch(solverChoice){
        case 1:
        {
            int* lineValue = new int[nbLines];
            int* columnValue = new int[nbColumn];
            int* pValues = new int[nbValues];
            cout << endl;
            cout << " Valeurs a atteindre sur les lignes : " << endl;

            for (int i = 0; i < nbLines; i++) {
                cout << "\tSomme ligne[" << i << "] = ";
                cin >> lineValue[i];
            }
            cout << endl;

            cout << "Valeurs a atteindre sur les colonnes : " << endl;
            for (int i = 0; i < nbColumn; i++) {
                cout << "\tSomme Colonne[" << i << "] = ";
                cin >> columnValue[i];
            }
            cout << endl;

           // cout << "Liste des  valeurs possibles : " << endl;
            for (int i = 1; i <= nbValues; i++) {
                pValues[i - 1] = i;
            }

            cout << "Liste des  valeurs possibles : [ ";
            for (int i = 0; i < nbValues; i++) {
                if (i != (nbValues - 1)) cout << pValues[i] << " , ";
                else cout << pValues[i] << " ]" << endl << endl;
            }


            Generateur s2 = Generateur(lineValue, columnValue, pValues, nbLines, nbColumn, nbValues);
            s2.print_grid();
            cout << "Choisir le nombre solutions possibles : ";
            cin >> valuesList;
            s2.solve(valuesList);
            }
            break;

        case 2:
        {
            s->generateK(nbLines, nbColumn, nbValues);
            s->monte_carlo();
        }
            break;

        default:
            "Valeur fausse.";

    }

    return 0;

}
