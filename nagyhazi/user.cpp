#include "user.h" 

bool modositFelhasznalo(const std::string& fajlNev, const std::string& becenev, int funkcio, const std::string& ujErtek) {
    std::ifstream input(fajlNev);
    if (!input) {
        std::cerr << "Nem sikerült megnyitni a fájlt: " << fajlNev << std::endl;
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
        if (sor.find("e-mail cím:") == 0) {
            std::string emailSor = sor;
            std::string becenevSor, jelszoSor, jatszottSor;

            std::getline(ss, becenevSor);
            std::getline(ss, jelszoSor);
            std::getline(ss, jatszottSor);

            std::string aktBecenev = becenevSor.substr(strlen("Becenév: "));
            if (aktBecenev == becenev) {
                // Módosítás itt történik
                switch (funkcio) {
                case -1: return true;
                case 1:
                    jelszoSor = "Jelszo: " + ujErtek;
                    break;
                case 2:
                    emailSor = "e-mail cím: " + ujErtek;
                    break;
                case 3: {
                    std::string jatszottStr = jatszottSor.substr(strlen("Jatszott: "));
                    int szam = std::stoi(jatszottStr);
                    ++szam;
                    jatszottSor = "Jatszott: " + std::to_string(szam);
                    break;
                }
                default:
                    std::cerr << "Ismeretlen funkció: " << funkcio << std::endl;
                    return false;
                }

                modositott = true;
            }

            // Írjuk vissza a blokkokat
            ujTartalom << emailSor << '\n'
                << becenevSor << '\n'
                << jelszoSor << '\n'
                << jatszottSor << '\n';
        }
        else {
            ujTartalom << sor << '\n'; // ritkán, de lehet üres sorok is
        }
    }

    if (!modositott) {
        std::cerr << "Nem találtam a becenevet: " << becenev << std::endl;
        return false;
    }

    std::ofstream output(fajlNev);
    if (!output) {
        std::cerr << "Nem sikerült írni a fájlba." << std::endl;
        return false;
    }

    output << ujTartalom.str();
    output.close();

    return true;
}
