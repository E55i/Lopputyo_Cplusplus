#include <iostream>
#include <cstdlib> //exit- ja CLS-funktiot
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include <list>
#include<sstream>

using namespace std;
using std::cerr;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

class Henkilo{

public:
     int suhde; //1=työsuhteinen, 2=yrittäjäsuhteinen
     string eNimi;
     string sNimi;
     int ika;
     long int ID;
     string puhelin="";
     string sapo;
     string tpiste;

     void tulosta(){
         if (suhde == 1){
             cout << "Suhde= Tyosuhteinen\nEtunimi= " << eNimi << "\nSukunimi= " << sNimi << "\nIka= " << ika << "\nID-numero= " << ID <<"\nPuhelinnumero= " << puhelin <<"\nSahkoposti= " << sapo <<"\nToimipiste= " << tpiste<<"\n\n";
         }
         else{cout << "Suhde= Yrittajasuhteinen\nEtunimi= " << eNimi << "\nSukunimi= " << sNimi << "\nIka= " << ika << "\nID-numero= " << ID <<"\nPuhelinnumero= " << puhelin <<"\nSahkoposti= " << sapo <<"\nToimipiste= " << tpiste<<"\n";}
     }

     void alusta()
                {
                    suhde = 0;
                    eNimi = "";
                    sNimi = "";
                    ika = 0;
                    ID = 0;
                    puhelin = "";
                    sapo = "";
                    tpiste = "";
                }

         void aseta(int suhde, string eNimi, string sNimi,int ika, long int ID,  string puhelin, string sapo, string tpiste)
               {
                   this->suhde = suhde;
                   this->eNimi = eNimi;
                   this->sNimi = sNimi;
                   this->ika = ika;
                   this->ID = ID;
                   this->puhelin = puhelin;
                   this->sapo = sapo;
                   this->tpiste = tpiste;
               }

};

int main()
{   int a=0;
    do{
     system("CLS");
     std::cout << "Tervetuloa kayttamaan HR-rekisteria!\n\nRekiterista loydat seka yrityksessa tyoskentelevat tyosuhteiset henkilot, etta yrittajasuhteiset henkilot.";
     std::cout << "\nValitse halutun toiminnon numero ja paina enter.";
     std::cout << "\n\n1=Luo uusi henkilo\n2=Hae henkiloa\n3=Tulosta henkiloiden tiedot\n4=Poista henkiloryhmien tietoja\n5=Lopeta ohjelman suoritus\n\n";

      cin>> a;
      system("CLS");

        switch (a) {
        case 1: {


            int suhde = 0;
            string eNimi="";
            string sNimi="";
            int ika=0;
            //halutaan että järjestelmä luo satunnaisesti ID-numeron.
            //Rand-funktio luo ohjelman käynnistyksen yhteydessä joka kerta saman numeron, jos ei käytetä srand-funktiota
            srand(time(0));
            int ID=rand();
            string puhelin="";
            string sapo="";
            string tpiste="";

            Henkilo h1;
            h1.alusta();

            std::cout << "\nHaluat luoda uuden henkilon.\nAnna seuraavat tiedot.\n\nPalvelussuhteen muoto (1=tyosuhteinen, 2=yrittajasuhteinen):";
                    cin>> suhde;
                    if(suhde != 1 && suhde != 2){ //Jos suhde ei ole 1 tai 2, palautetaan käyttäjä päävalikkoon
                    std::cout <<"\nPalvelussuhteen tulee olla 1(=tyosuhteinen) tai 2(=yrittajasuhteinen)!\nPalataan takaisin paavalikkoon 10 sekunnin kuluttua.\n";
                    std::chrono::seconds dura(10);
                    std::this_thread::sleep_for( dura );
                    system("CLS");
                    a=0;
                    }
                    else if(suhde==1){
                    std::cout <<"\nEtunimi= ";
                    cin>> eNimi;
                    std::cout <<"\nSukunimi= ";
                    cin>> sNimi;
                    std::cout <<"\nIka= ";
                    cin>> ika;
                    std::cout <<"\nPuhelin= ";
                    cin>> puhelin;
                    std::cout <<"\nSahkoposti= ";
                    cin>> sapo;
                    std::cout <<"\nToimipisteen sijainti= ";
                    cin>> tpiste;

                    h1.aseta(suhde, eNimi, sNimi, ika, ID, puhelin, sapo, tpiste);

                    std::cout << "\nOlet luonut uuden henkilon!\n\n";
                    h1.tulosta();
                    //Tallennetaan tiedostoon rekisteri1.txt kun kyseessä on työsuhteinen
                        ofstream myfile;
                        myfile.open ("rekisteri1.txt", ios::app);
                            if (myfile.is_open())
                            {
                            myfile << "ID-numero="<<h1.ID<<"\n";
                            myfile << "Palvelussuhteen muoto="<<h1.suhde<<"\n";
                            myfile << "Etunimi="<< h1.eNimi<<"\n";
                            myfile << "Sukunimi="<<h1.sNimi<<"\n";
                            myfile << "Ika="<<h1.ika<<"\n";
                            myfile << "Puhelinnumero="<<h1.puhelin<<"\n";
                            myfile << "Sahkoposti="<<h1.sapo<<"\n";
                            myfile << "Toimipiste="<<h1.tpiste<<"\n\n";
                            myfile << "********************************************************\n\n";
                            myfile.close();
                            }
                            else {cout << "Tiedoston avaaminen ei onnistu";}

                    }
                   else if(suhde==2){
                                std::cout <<"\nEtunimi:";
                                cin>> eNimi;
                                std::cout <<"\nSukunimi:";
                                cin>> sNimi;
                                std::cout <<"\nIka:";
                                cin>> ika;
                                std::cout <<"\nPuhelin:";
                                cin>> puhelin;
                                std::cout <<"\nSahkoposti:";
                                cin>> sapo;
                                std::cout <<"\nToimipisteen sijainti:";
                                cin>> tpiste;

                                h1.aseta(suhde, eNimi, sNimi, ika, ID, puhelin, sapo, tpiste);

                                std::cout << "\nOlet luonut uuden henkilon!\n\n";
                                h1.tulosta();
                        //Tallennetaan tiedostoon rekisteri2.txt kun kyseessä on yrittäjäsuhteinen
                           ofstream myfile;
                           myfile.open ("rekisteri2.txt", ios::app);
                           if (myfile.is_open())
                           {
                            myfile << "ID-numero="<<h1.ID<<"\n";
                            myfile << "Palvelussuhteen muoto="<<h1.suhde<<"\n";
                            myfile << "Etunimi="<< h1.eNimi<<"\n";
                            myfile << "Sukunimi="<<h1.sNimi<<"\n";
                            myfile << "Ika="<<h1.ika<<"\n";
                            myfile << "Puhelinnumero="<<h1.puhelin<<"\n";
                            myfile << "Sahkoposti="<<h1.sapo<<"\n";
                            myfile << "Toimipiste="<<h1.tpiste<<"\n\n";
                            myfile << "********************************************************\n\n";
                            myfile.close();}

                    else {cout << "Tiedoston avaaminen ei onnistu";}}

                    system("pause");//pysäytetään ohjelman suoritus
                    a=0;
                    break;

    }

                case 2: {
                int s=0;
                int count = 0;
                string numero="";
                string alku = "ID-numero=";
                string tarkistus="";
                std::cout << "\nVoit hakea henkilon tietoja ID-numeron perusteella.\n\nHaetko tyosuhteisen vai yrittajasuhteisen henkilon tietoja?\n\n1= Tyosuhteinen\n2= Yrittajasuhteinen\n\n";
                cin>> s;

                    if(s==1) {
                            system("CLS");
                            std::cout << "Anna tyosuhteisen henkilon ID-numero:";
                            cin>> numero;
                            string haettuNumero=alku+numero;
                            std::cout << "\n\n";
                            std::ifstream myfile;
                            myfile.open("rekisteri1.txt");
                            std::string myline;
                            if ( myfile.is_open() ) { //avataan tiedosto ja haetaan sieltä annettua ID-numeroa
                                while ( myfile ) {
                                    std::getline (myfile, myline);
                                    count++;

                                        if (myline==haettuNumero){
                                        int i=0;
                                        tarkistus="Henkilo loytyy!";
                                        i=count;
                                        for (i; i <= count+7; i++){
                                        getline(myfile, myline);
                                        cout<<myline <<"\n";
                                        }
                                        system("pause");//pysäytetään ohjelman suoritus
                                        break;
                                        }
                                        else if(tarkistus!="Henkilo loytyy!" && myfile.eof()==true) {
                                        std::cout << "Henkiloa ei loydy!\n";
                                        system("pause");//pysäytetään ohjelman suoritus
                                        }
                                        }

                                        }

                            else {
                            std::cout << "Tiedoston avaaminen ei onnistunut!\n";
                            }
                }
                    else if(s==2){
                            system("CLS");
                            std::cout << "Anna yrittajasuhteisen henkilon ID-numero:";
                            cin>> numero;
                            string haettuNumero=alku+numero;
                            std::cout << "\n\n";


                            std::ifstream myfile;
                            myfile.open("rekisteri2.txt");
                            std::string myline;
                            if ( myfile.is_open() ) {//avataan tiedosto ja haetaan sieltä annettua ID-numeroa
                            while ( myfile ) {
                                std::getline (myfile, myline);
                                count++;

                                    if (myline==haettuNumero){
                                    int i=0;
                                    tarkistus="Henkilo loytyy!";
                                    i=count;
                                    for (i; i <= count+7; i++){
                                    getline(myfile, myline);
                                    cout<<myline <<"\n";
                                    }
                                    system("pause");//pysäytetään ohjelman suoritus
                                    break;
                                    }
                                    else if(tarkistus!="Henkilo loytyy!" && myfile.eof()==true) {
                                    std::cout << "Henkiloa ei loydy!\n";
                                    system("pause");//pysäytetään ohjelman suoritus
                                    }
                                    }

                                    }

                        else {
                        std::cout << "Tiedoston avaaminen ei onnistunut!\n";
                        }
                    }

               break;
               }


                case 3: {
                int y=0;
                std::cout << "\nVoit tulostaa kaikkien tyosuhteisten ja / tai yrittajasuhteisten tiedot. Valitse haluamasi toiminto alla olevasta valikosta.\n\n";
                std::cout << "1=Tulosta kaikkien tyosuhteisten tiedot\n2=Tulosta kaikkien yrittajasuhteisten tiedot\n3=Tulosta kaikkien tyo- ja yrittajasuhteisten tiedot\n4=Palaa takaisin paavalikkoon\n\n";
                cin>> y;

                    switch (y) {
                        case 1: {
                            system("CLS");
                            std::ifstream myfile1;
                            myfile1.open("rekisteri1.txt");//avataan tiedosto tiedon lukemista varten
                            std::string mystring1;
                            if ( myfile1.is_open() ) {
                                char mychar1;
                                while ( myfile1 ) {
                                    mychar1 = myfile1.get();
                                    std::cout << mychar1;//tulostetaan jokainen merkki kerrallaan
                                    }
                            }
                            std::cout << "\nPalaa paavalikkoon painamalla enter.\n\n";

                            system("pause");//pysäytetään ohjelman suoritus
                            break;
                        }

                        case 2: {
                        system("CLS");
                        std::ifstream myfile2;
                        myfile2.open("rekisteri2.txt");//avataan tiedosto tiedon lukemista varten
                        std::string mystring2;
                        if ( myfile2.is_open() ) {
                            char mychar2;
                            while ( myfile2 ) {
                                mychar2 = myfile2.get();
                                std::cout << mychar2;//tulostetaan jokainen merkki kerrallaan
                                }
                        }

                        std::cout << "\nPalaa paavalikkoon painamalla enter.\n\n";
                        system("pause");//pysäytetään ohjelman suoritus
                        break;
                        }

                        case 3: {
                        system("CLS");
                        //avataan molemmat tiedostot erikseen ja tulostetaan niiden sisältö
                        std::ifstream myfile3;
                        myfile3.open("rekisteri1.txt");
                        std::string mystring3;
                        if ( myfile3.is_open() ) {
                            char mychar3;
                            while ( myfile3 ) {
                                mychar3 = myfile3.get();
                                std::cout << mychar3;
                                }
                        }

                        std::ifstream myfile4;
                        myfile4.open("rekisteri2.txt");
                        std::string mystring4;
                        if ( myfile4.is_open() ) {
                            char mychar4;
                            while ( myfile4 ) {
                                mychar4 = myfile4.get();
                                std::cout << mychar4;
                                }
                        }
                        std::cout << "\nPalaa paavalikkoon painamalla enter.\n\n";
                        system("pause");//pysäytetään ohjelman suoritus
                        break;
                        }

                        case 4:{
                        system("CLS");
                        a=0;
                        }

                    default: {//jos valinta ei ollut mikään valikossa kerrottu, ilmoitetaan että valinta on virheellinen
                        std::cout << "\nVirheellinen valinta!\n\n";

                    }
                    }
                    break;

    }

            case 4:{
                int valinta=0;
                int tila1,tila2;
                std::cout << "\nTaalla voit poistaa kaikkien työsuhteisten tiedot ja / tai kaikkien yrittajasuhteisten tiedot.\n\n1=Poista tyosuhteisten tiedot\n2= Poista yrittajasuhteisten tiedot\n3= Poista sekä tyo- etta yrittajasuihteisten tiedot\n\n";
                cin>>valinta;

                if (valinta==1){//valinnalla 1 poistetaan tiedosto jossa on kaikkien työsuhteisten tiedot
                    char tiedostoNimi[30]="rekisteri1.txt";
                    tila1=remove(tiedostoNimi);
                    if(tila1==0)
                    {cout<<"\nKaikkien tyosuhteisten henkiloiden tiedot sisaltava tiedosto on poistettu!\n";}
                    else
                    {cout<<"\nTiedoston poistaminen ei onnistunut tai sita ei loydy!\n";}


                }
                else if (valinta==2){//valinnalla 2 poistetaan tiedosto jossa on kaikkien yrittäjäsuhteisten tiedot
                    char tiedostoNimi[30]="rekisteri2.txt";
                    tila1=remove(tiedostoNimi);
                    if(tila1==0)
                    {cout<<"\nKaikkien yrittajasuhteisten henkiloiden tiedot sisaltava tiedosto on poistettu!\n";}
                    else
                    {cout<<"\nTiedoston poistaminen ei onnistunut tai sita ei loydy!\n";}
                }
                else if (valinta==3){//valinnalla 3 poistetaan molemmat tiedostot
                    char tiedostoNimi1[30]="rekisteri1.txt";
                    char tiedostoNimi2[30]="rekisteri2.txt";
                    tila1=remove(tiedostoNimi1);
                    tila2=remove(tiedostoNimi2);
                    if(tila1==0&&tila2==0)
                    {cout<<"\nKaikkien tyo- ja yrittajasuhteisten henkiloiden tiedot sisaltavay tiedostot on poistettu!\n";}
                    else
                    {cout<<"\nTiedoston poistaminen ei onnistunut tai sita ei loydy!\n";}
                }

                else {cout<<"\nVirheellinen valinta. Palataan takaisin paavalikkoon.\n";//Jos annetaan jokin muu valinta, ilmoitetaan että se on virheellinen
                        a=0;
                        }


                system("pause");//pysäytetään ohjelman suoritus

                break;
                }

    }}
    while(a!=5);

    std::cout <<"\nOhjelman suoritus paattyy. Paina kaksi kertaa enter poistuaksesi.\n";
    system("pause");//pysäytetään ohjelman suoritus



    return 0;
}
