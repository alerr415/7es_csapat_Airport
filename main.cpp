#include <iostream>
#include "repuloter.h"
#include "manipulator.h"
#include "bejelentkezteto.h"
#include "utazo.h"
#include <fstream>
#include <vector>
#include "stringhandler.h"
#include <chrono>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <atomic>

/*
    MŰKÖDÉS:
    alapesetben 3 másodpercenként frissít
    ENTER egyszeri megnyomásával lehet megszakítani (lehet kicsit kell várni, mielőtt átáll)
    a minta adminisztrátor jelszava, felh.neve admin, admin
    a minta operátor jelszava, felh.neve: tester, tester
    elsőre csak egy err felirat fog megjelenni, a teljes adatbevitel fileból olvasás részével lehet feltölteni
    a járatadatok a tester.csv fileban vannak
*/


Manipulator* bejelentkeztetoForm()
{
    system("cls");
    std::string felhasznalonev,jelszo;
    std::cout << "Felhasznalonev: ";
    std::cin >> felhasznalonev;
    std::cout << "Jelszo: ";
    std::cin >> jelszo;
    system("cls");
    Manipulator* toReturn = Bejelentkezteto::getInstance().bejelentkeztet(felhasznalonev,jelszo);
    return toReturn;
}

int main()
{
        // thread control
        std::mutex mtx;
        std::atomic<int> mode(1);

        // program stop flag
        bool over = false;
        // képfrissítő stop flag
        bool stopClock = false;

        // képfrissítő függvény mehet ide
        auto clock_function = [&]() {

            mtx.lock();
            mtx.unlock();
            while (!stopClock)
            {
                system("cls");
                mtx.lock();
                std::chrono::system_clock::time_point most = std::chrono::system_clock::now();
                Repuloter::getInstance().szinkronizal(most);
                //std::cout << motd << std::endl;
                std::cout << "Budapest, Liszt Ferenc Repuloter - BUD" << std::endl;
                if (mode == 2)
                {
                    std::cout << "ERKEZO JARATOK" << std::endl;
                    Repuloter::getInstance().erkezoMegjelenit();
                } else {
                    std::cout << "INDULO JARATOK" << std::endl;
                    Repuloter::getInstance().induloMegjelenit();
                }
                mtx.unlock();
                std::this_thread::sleep_for(std::chrono::seconds(3));
            }
        };

        std::thread* clock = new std::thread(clock_function);

        // fő program
        while (!over)
        {
            std::cin.get();
            mtx.lock();
            stopClock = true;
            mtx.unlock();

            // töröljük a komplet thread-et
            clock->join();
            delete clock;
            // opciók
            system("cls");
            std::cout << "0 : Kilepes" << std::endl
                      << "1 : Utvonaltervezes" << std::endl
                      << "2 : Kereses (bejelentkezes szukseges)" << std::endl
                      << "3 : Teljes adatbevitel (bejelentkezes szukseges)" << std::endl
                      << "4 : Modositas (bejelentkezes szukseges)" << std::endl
                      << "5 : tabla uzemmod" << std::endl;
            std::cout << ">" << std::flush;
            int param = 0;
            std::cin >> param;
            if (param == 0)
            {
                std::cout << "Kilepes" << std::endl;
                over = true;
            }
            else
            {
                // frissítés létrehozása
                clock = new std::thread(clock_function);

                //
                mtx.lock();
                // megfelelő funkció elindítása
                switch (param)
                {
                case 1: {
                    Utazo u;
                    u.keres();
                    std::cout << "Utvonaltervezes vege" << std::endl;
                    break;
                }
                case 2: {
                    Manipulator* m = bejelentkeztetoForm();
                    if (m == nullptr)
                    {
                        std::cout << "Hibas felhasznalonev, vagy jelszo" << std::endl;
                        break;
                    }
                    m->keres();
                    delete m;

                    std::cout << "Kereses vege" << std::endl;
                    break;
                }
                case 3: {
                    Manipulator* m = bejelentkeztetoForm();
                    if (m == nullptr)
                    {
                        std::cout << "Hibás felhasznalonev, vagy jelszo" << std::endl;
                        break;
                    }
                    m->teljesBevitel();
                    delete m;

                    std::cout << "Teljes adatbevitel vege" << std::endl;
                    break;
                }
                case 4: {
                    Manipulator* m = bejelentkeztetoForm();
                    if (m==nullptr)
                    {
                        std::cout << "Hibas felhasznalonev, vagy jelszo" << std::endl;
                        break;
                    }
                    m->modosit();
                    delete m;
                    std::cout << "Modositas vege" << std::endl;
                    break;
                }
                case 5: {
                    std::cout << "1 : Indulo\n2 : Erkezo\n>";
                    int m;
                    std::cin >> m;
                    if (m == 1 || m == 2)
                    {
                        mode = m;
                        std::cout << "Uzemmod atallitva" << std::endl;
                    } else {
                        std::cout << "Ervenyetlen parancs" << std::endl;
                    }
                    break;
                }
                default: break;
                }

                // frissítés futási feltétele

                stopClock = false;

                // frissítés beindítása
                std::cin.ignore();
                std::cin.get();
                mtx.unlock();
            }

        }
    return 0;
}
