#include "user.h" 

bool modositFelhasznalo(const std::string& fajlNev, const std::string& becenev, int funkcio, const std::string& ujErtek) {
    std::ifstream input(fajlNev);
    if (!input) {
        std::cerr << "Nem siker�lt megnyitni a f�jlt: " << fajlNev << std::endl;
        return false;
    }

    std::ostringstream tartalomBuf;
    tartalomBuf << input.rdbuf();
    std::string tartalom = tartalomBuf.str();
    input.close();

    std::istringstream ss(tartalom);
    std::ostringstream ujTartalom;
    std::string sor;

    bool modositott = false;

    while (std::getline(ss, sor)) {
        if (sor.find("e-mail c�m:") == 0) {
            std::string emailSor = sor;
            std::string becenevSor, jelszoSor, jatszottSor;

            std::getline(ss, becenevSor);
            std::getline(ss, jelszoSor);
            std::getline(ss, jatszottSor);

            std::string aktBecenev = becenevSor.substr(strlen("Becen�v: "));
            if (aktBecenev == becenev) {
                // M�dos�t�s itt t�rt�nik
                switch (funkcio) {
                case -1: return true;
                case 1:
                    jelszoSor = "Jelszo: " + ujErtek;
                    break;
                case 2:
                    emailSor = "e-mail c�m: " + ujErtek;
                    break;
                case 3: {
                    std::string jatszottStr = jatszottSor.substr(strlen("Jatszott: "));
                    int szam = std::stoi(jatszottStr);
                    ++szam;
                    jatszottSor = "Jatszott: " + std::to_string(szam);
                    break;
                }
                default:
                    std::cerr << "Ismeretlen funkci�: " << funkcio << std::endl;
                    return false;
                }

                modositott = true;
            }

            // �rjuk vissza a blokkokat
            ujTartalom << emailSor << '\n'
                << becenevSor << '\n'
                << jelszoSor << '\n'
                << jatszottSor << '\n';
        }
        else {
            ujTartalom << sor << '\n'; // ritk�n, de lehet �res sorok is
        }
    }

    if (!modositott) {
        std::cerr << "Nem tal�ltam a becenevet: " << becenev << std::endl;
        return false;
    }

    std::ofstream output(fajlNev);
    if (!output) {
        std::cerr << "Nem siker�lt �rni a f�jlba." << std::endl;
        return false;
    }

    output << ujTartalom.str();
    output.close();

    return true;
}
