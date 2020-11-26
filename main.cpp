#include <iostream>
#include "repuloter.h"
#include <fstream>
#include <vector>
#include "stringhandler.h"
#include <chrono>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <condition_variable>



using namespace std;


void printTime(const std::chrono::system_clock::time_point& tp)
{
    time_t tp_t = std::chrono::system_clock::to_time_t(tp);
    std::cout << ctime(&tp_t) << std::endl;
}

/*
   Működés:
   alapállapot: 1 percenként frissítve kiírja a képernyőre az időt (minta)
   [ENTER] megnyomására állapotot vált, megjelenik a prompt
   0: leállítja a futást
   1,2: átállítja a feliratot
*/


int main()
{
    std::string motd = "Message of the day";
        // thread control
        std::condition_variable cvar;
        std::mutex mtx;

        // program stop flag
        bool over = false;
        // képfrissítő stop flag
        bool stopClock = false;

        // képfrissítő függvény mehet ide
        auto clock_function = [&]() {
            // egyből meg is állítja magát, amíg nem kap értesítést
            std::unique_lock<std::mutex> lk(mtx);
            cvar.wait(lk,[&]() {return !stopClock;});
            mtx.unlock();

            while (!stopClock)
            {
                system("cls");
                std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
                printTime(now);
                mtx.lock();
                std::cout << motd << std::endl;
                mtx.unlock();
                std::this_thread::sleep_for(std::chrono::seconds(60));
            }
        };

        std::thread* clock = new std::thread(clock_function);

        while (!over)
        {
            std::cin.get();
            mtx.lock();
            stopClock = true;
            mtx.unlock();

            // töröljük a komplet thread-et
            //clock->join();
            clock->detach();
            delete clock;
            // opciók
            std::cout << ">" << std::flush;
            int param = 0;
            std::cin >> param;
            if (param == 0)
            {
                std::cout << "game over" << std::endl;
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
                case 1: {std::cout << "1-es opcio" << std::endl; motd = "option 1"; break;}
                case 2: {std::cout << "2-es opcio" << std::endl; motd = "option 2"; break;}
                }

                // frissítés futási feltétele

                stopClock = false;
                mtx.unlock();

                // frissítés beindítása
                cvar.notify_all();
                std::cin.ignore();
            }

        }
    return 0;
}
