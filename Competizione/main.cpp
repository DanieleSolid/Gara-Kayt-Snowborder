/*!
    \file main.cpp
    \author Daniele Solidoro
    \version 1.0
    \brief simula una gara di kayt-snowboarding restituendo il vincitore
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#define file "elenco.txt"

using namespace std;
int vetc[60], vetd[10];
string vetp[10];
int n;

/*!
    \fn inserimento_part
    \brief inserisce all'interno del file i partecipanti e le loro distanze in un vettore, infine stampa tali distanze per ogni partecipante
*/
void inserimento_part(){

int mat=0, cord=0, cont=0, cont2=0;
int z=0;
int segno=0, x1, x2, y1, y2, d=0;
string cognome;


ofstream fout (file);
cout<<"Quanti partecipanti vuoi inserire?"<<endl;
cin>>n;
for(int v=1;v<=n; v++){
        cout<<"Inserisci cognome"<<endl;

        cin>>cognome;
        mat=rand()%1001;

        fout<<mat<<" ";

        fout<<cognome;
        vetp[cont2]=cognome;
        cont2++;

        fout<<endl;

        fout<<"COORDINATE-->";

        for(int c=0; c<30; c++){

                if(c>0){
                    fout<<" - ";
                }
            for(int i=0; i<2; i++){

                    cord=rand()%101;
                    vetc[cont]=cord;
                    cont++;
                    fout<<cord;
                    if(i==0){
                        fout<<",";
                    }


            }

        }
        cont=0;
        fout<<endl;

        for(int v=0; v<15; v++){
                for(int i=0; i<4; i++){

                    if(i==0){
                        x1=vetc[segno];
                        segno++;

                    }
                    if(i==1){
                        y1=vetc[segno];
                        segno++;

                    }
                    if(i==2){
                        x2=vetc[segno];
                        segno++;

                    }
                    if(i==3){
                        y2=vetc[segno];
                        segno++;

                    }


                }

                d=abs(d+sqrt((y1-y2)*(y1-y2)+(x1-x2)*(x1-x2)));
            }

        vetd[z]=d;
        cout<<"Distanza percorsa: "<<vetd[z]<<endl;
        z++;
        d=0;

}

fout.close();

}

/*!
    \fn p_vin
    \brief trova il punteggio migliore tra le distanze salvate all'interno del vettore
*/
void p_vin(){
int cm=0;
string maggiore;
    for(int v=0; v<n; v++){
        for(int p=0; p<n; p++){
              if(vetd[v]>vetd[p]){
                cm++;

              }

            }
            if(cm==n-1){
                    maggiore=vetp[v];
                    v=n;

            }else{cm=0;}

    }

        cout<<"Il vicitore è: "<<maggiore<<endl;
        maggiore="";

}

/*!
    \fn menu
    \brief mette a disposizione un menu all'interno della quale puoi scegliere un'opzione
*/
void menu(){

int s;

do{
    cout<<"MENU"<<endl;
    cout<<"1- Inserisci partecipanti"<<endl;
    cout<<"2- Vincitore"<<endl;
    cout<<"3- Uscita"<<endl;

    cout<<"Scegli una voce: "<<endl;
    cin>>s;

    switch(s){

        case 1:
            inserimento_part();
            break;


        case 2:
            p_vin();
            break;

        }
    }while(s!=3);
}


/*!
    \fn main
    \brief richiama la funzione menu che contiene tutte le funzionalità del programma
*/
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}
