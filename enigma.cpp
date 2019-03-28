 
/**
 * @author Giuseppe La Gualano 02/08/2016
 * @license This software is free
 */
 
#include <iostream>
#include <stdlib.h>
#include <cstdlib>   
#include <ctime>    
using namespace std;
 
int main()
{
        srand((unsigned)time(NULL)); // AZZERO IL RANDOM (SEED)
        char lettera;
        int input,opzione,x,x1,x2,x3,x4,x5,x6,x7,x8,x9;
 
        //PRESENTAZIONE PROGRAMMA
        cout<<endl<<"    -------------------------";
        cout<<endl<<"    | SIMULATORE ENIGMA C++ |";
        cout<<endl<<"    -------------------------\n";
        cout<<"\nBenvenuto nel simulatore di Enigma"<<endl;
 
        cout<<endl<<"\nInserisci la chiave per l'algoritmo crittografico. (Premi 1 per random o 2 per input manuale): ";
        cin>>input;
 
        if(input==1){
 
           x1 = (rand()%100+20);
           x2 = (rand()%100+20);
           x3 = (rand()%100+20);
           x4 = (rand()%100+20);
           x5 = (rand()%100+20);
           x6 = (rand()%100+20);
           x7 = (rand()%100+20);
           x8 = (rand()%100+20);
           x9 = (rand()%100+20);
 
    }
 
        else if(input==2){
        cout<<endl<<"Primo numero: ";
        cin>>x1;
 
        cout<<endl<<"Secondo numero: ";
        cin>>x2;
 
        cout<<endl<<"Terzo numero: ";
        cin>>x3;
 
        cout<<endl<<"Quarto numero: ";
        cin>>x4;
 
        cout<<endl<<"Quinto numero: ";
        cin>>x5;
 
        cout<<endl<<"Sesto numero: ";
        cin>>x6;
 
        cout<<endl<<"Settimo numero: ";
        cin>>x7;
 
        cout<<endl<<"Ottavo numero: ";
        cin>>x8;
 
        cout<<endl<<"Nono numero: ";
        cin>>x9;
    }
 
        int rotore1[3] = {x1,x2,x3};
        int rotore2[3] = {x4,x5,x6};         // IPOTIZZIAMO VETTORI DI DIMENSIONE 3 PER ENIGMA
        int rotore3[3] = {x7,x8,x9};
 
        cout<<"\nrotore 1: "<<x1<<" "<<x2<<" "<<x3;    // RIASSUNTO DELLA CHIAVE
        cout<<"\nrotore 2: "<<x4<<" "<<x5<<" "<<x6;
        cout<<"\nrotore 3: "<<x7<<" "<<x8<<" "<<x9;
 
        //SELETTORE OPZIONE
 
do{
        int i=0,z=0; //RESET DEL CONTATORE PER NON DOVER RIAVVIARE IL PROGRAMMA
        cout<<endl<<"-----------------------------------\n";
        cout<<endl<<"[1] * Decripta"
            <<endl<<"[2] * Cripta"
            <<endl<<"[3] * Esci\n"<<endl;
            cout<<"Al tuo comando: ";
            cin>>opzione;   //ACQUISISCO IL COMANDO SCELTO E PASSO ALLO SWITCH
            cout<<endl<<"-----------------------------------\n";
 
        // SELETTORE DEL CASO DA OPZIONE SCELTA SOPRA
 
        switch (opzione)
               {
                case 1:
                    {while(z!=1){  // IMPOSTO IL CICLO WHILE PER NON DOVER RIPETERE IL MENU'
                    cout<<"\nInserisci una lettera (ALT+987 per tornare al menu' principale): "; //LETTERA DA DECRIPTARE Û (U maiuscola con accento circonflesso)
                    cin>>lettera;
 
                    if (lettera==(-37)){ // ESCO DAL CICLO WHILE PER INCREMENTO DELLA VARIABILE AD 1 E TORNO AL MENU'
                        z++;
                        break;    //TERMINO IL CICLO WHILE QUANDO Z VA AD 1 E PASSO AL CASE GIUNGENDO AL BREAK DI FONDO
                        }
                    else
                    cout<<"\nIl carattere che hai inserito e' : \""<<int(lettera)<<"\" in ASCII"<<endl;  //CORRISPONDENZA IN ASCII
 
                //   FUNZIONAMENTO MATEMATICO CONGRUO ALLA TABELLA ASCII ESTESA  //
 
                x=lettera-rotore1[i];           // ROTORI CHE PARTONO CON i=0 E SI RESETTANO TORNANDO AL MENU'
                        if (x < 32)
                            x = 126-(32-x);
 
                        else if (x > 126)
                            x = (x-126)+32;
                        x=x-rotore2[i];
 
                        if (x < 32)
                            x = 126-(32-x);
 
                        else if (x > 126)
                        x = (x-126)+32;
                        x=x-rotore3[i];
 
                        if (x < 32)
                            x = 126-(32-x);
 
                        else if(x > 126)
                            x = (x-126)+32;
                            cout<<"\nEnigma ha generato il numero: "<<x<<endl;  //GENERAZIONE MATEMATICA DELL'ALGORITMO
 
                            cout<<"\nIl carattere che hai inserito adesso e' : \""<<char(x)<<"\" in ASCII"<<endl; //LETTERA DECRIPTATA
                            i++; //INCREMENTO DELLA VARIABILE "i" CHE CONTA I TRE ROTORI
                            cout<<endl<<"-----------------------------------\n";
                    }
                        break;  //QUANDO TERMINA IL CICLO WHILE PER LA VARIABILE Z AD 1, ALLORA SI ATTIVA IL BREAK E TORNO AL MENU'
                }
 
 
                case 2:
                    {while(z!=1){  // IMPOSTO IL CICLO WHILE PER NON DOVER RIPETERE IL MENU'
                    cout<<"\nInserisci una lettera (ALT+987 per tornare al menu' principale): "; //LETTERA DA DECRIPTARE
                    cin>>lettera;
 
                    if (lettera==(-37)){   // ESCO DAL CICLO WHILE PER INCREMENTO DELLA VARIABILE AD 1 E TORNO AL MENU'
                        z++;
                        break;     //TERMINO IL CICLO WHILE QUANDO Z VA AD 1 E PASSO AL CASE GIUNGENDO AL BREAK DI FONDO
                        }
                    else
                    cout<<"\nIl carattere che hai inserito e' : \""<<int(lettera)<<"\" in ASCII"<<endl;  //CORRISPONDENZA IN ASCII
 
                //  FUNZIONAMENTO MATEMATICO CONGRUO ALLA TABELLA ASCII ESTESA   //
 
                x=lettera+rotore1[i];    // ROTORI CHE PARTONO CON i=0 E SI RESETTANO TORNANDO AL MENU'
                        if (x < 32)
                            x = 126-(32-x);
 
                        else if (x > 126)
                            x = (x-126)+32;
                        x=x+rotore2[i];
 
                        if (x < 32)
                            x = 126-(32-x);
 
                        else if (x > 126)
                            x = (x-126)+32;
                            x=x+rotore3[i];
 
                        if (x < 32)
                            x = 126-(32-x);
 
                        else if(x > 126)
                            x = (x-126)+32;
                            cout<<"\nEnigma ha generato il numero: "<<x<<endl; //GENERAZIONE MATEMATICA DELL'ALGORITMO
 
                            cout<<"\nIl carattere che hai inserito adesso e' : \""<<char(x)<<"\" in ASCII"<<endl; //NUOVA LETTERA CRIPTATA
                        i++; //INCREMENTO DELLA VARIABILE "i" CHE CONTA I TRE ROTORI
                        cout<<endl<<"-----------------------------------\n";
                    }
                        break; //QUANDO TERMINA IL CICLO WHILE PER LA VARIABILE Z AD 1, ALLORA SI ATTIVA IL BREAK E TORNO AL MENU'
                }
 
        }
 
}
 
while (opzione !=3);         //TERMINAZIONE DEL PROGRAMMA
    return 0;
}