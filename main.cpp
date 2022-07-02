#include <iostream>
#include <cstdlib>


using namespace std;

int main()
{
    std::cout << "Tervetuloa kayttamaan HR-rekisteria!\n\nRekiterista loydat seka yrityksessa tyoskentelevat tyosuhteiset henkilot, etta yrittajasuhteiset henkilot.";

    int a=0;

    do{
     std::cout << "\nValitse halutun toiminnon numero ja paina enter.";
     std::cout << "\n\n1=Luo uusi tyosuhteinen henkilo\n2=Luo uusi yrittajasuhteinen henkilo\n3=Hae henkiloa\n4=Tulosta henkiloiden tiedot\n5=Muuta henkilon tietoja\n6=Poista henkilon tiedot\n6=Lopeta ohjelman suoritus\n\n";

      cin>> a;

        switch (a) {
        case 1: {
            system("CLS");
            string eNimi="";
            string sNimi="";
            int ika=0;
            int ID=rand();
            int puhelin=0;
            string sapo="";
            string tpiste="";

            std::cout << "\nHaluat luoda uuden työsuhteisen henkilön.\nAnna seuraavat tiedot:\nEtunimi:";
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

                    std::cout << "\nOlet luonut uuden tyosuhteisen henkilon "<<eNimi<<" "<<sNimi<<".\n";
                    std::cout << "\nHenkilon ID-numero on "<<ID<<".";

            system("pause");//pysäytetään ohjelman suoritus
            break;
    }
    }

            switch (a) {
            case 2: {
            system("CLS");
            string eNimi="";
            string sNimi="";
            int ika=0;
            int ID=rand();
            int puhelin=0;
            string sapo="";
            string tnimi="";

            std::cout << "\nHaluat luoda uuden yrittajasuhteisen henkilön.\nAnna seuraavat tiedot:\nEtunimi:";
                    cin>> eNimi;
                    std::cout <<"\nSukunimi:";
                    cin>> sNimi;
                    std::cout <<"\nIka:";
                    cin>> ika;
                    std::cout <<"\nPuhelin:";
                    cin>> puhelin;
                    std::cout <<"\nSahkoposti:";
                    cin>> sapo;
                    std::cout <<"\nToiminimen nimi:";
                    cin>> tnimi;

                    std::cout << "\nOlet luonut uuden yrittajasuhteisen henkilon "<<eNimi<<" "<<sNimi<<".\n";
                    std::cout << "\nHenkilon ID-numero on "<<ID<<".";
                system("pause");//pysäytetään ohjelman suoritus
                break;
    }
    }
            switch (a) {
            case 3: {
                 std::cout << "\nVoit hakea henkilon tietoja joko nimen tai ID-numeron perusteella.\n";
                 std::cout << "\n1=Hae nimella.\n";
                 std::cout << "\n2=Hae ID-numerolla.\n";
                system("pause");//pysäytetään ohjelman suoritus
                break;
    }
    }
            switch (a) {
            case 4: {
                std::cout << "\nVoit tulostaa kaikkien työsuhteisten ja / tai yrittäjäsuhteisten tiedot.\n";
                system("pause");//pysäytetään ohjelman suoritus
                break;
    }
    }
            switch (a) {
            case 5: {
                std::cout << "\nTaalla voit muuttaa henkilon tietoja. Hae ensin henklo joko nimen tai ID-numeron perusteella.\n";
                std::cout << "\n1=Hae nimella.\n";
                std::cout << "\n2=Hae ID-numerolla.\n";
                system("pause");//pysäytetään ohjelman suoritus
                break;
    }
    }

            switch (a) {
            case 6: {
                std::cout <<"\nOhjelman suoritus paattyy. Paina kaksi kertaa enter poistuaksesi.\n";
                system("pause");//pysäytetään ohjelman suoritus
                break;
    }
    }

    }
    while(a!=6);



    return 0;
}
