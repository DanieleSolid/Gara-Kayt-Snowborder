#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>
#define file "elenco.txt"

using namespace std;
int vetc[60];
string vetp[10];
int n;

void inserimento_part(){

int mat=0, cord=0, cont=0, cont2=0;
string cognome;
srand(time(NULL));

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
        fout<<endl;

}

fout.close();

}

void menu(){

int s;

do{
    cout<<"MENU"<<endl;
    cout<<"1- Inserisci partecipanti"<<endl;
    cout<<"2- Podio vincente"<<endl;
    cout<<"3- Uscita"<<endl;

    cout<<"Scegli una voce: "<<endl;
    cin>>s;

    switch(s){

        case 1:
            inserimento_part();
            break;

    }
    }while(s!=3);
}

int main()
{
    menu();
    return 0;
}
