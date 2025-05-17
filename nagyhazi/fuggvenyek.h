//#pragma once
#ifndef FUGGVENYEK_H 
#define FUGGVENYEK_H

class User; 


std::string mail(std::string cim) {
    std::string smtpServer = "smtp.gmail.com"; // SMTP szerver
    std::string smtpPort = "587";               // Port (Gmail: 587)
    std::string username = "szilvi.egyetemi@gmail.com"; // Saj�t email c�med
    std::string password = "ecps ivbm gnum mhrq";     // App Password, nem sima jelsz�

    srand(time(0));
    std::string key = std::to_string(rand());

    std::string recipient = cim;
    std::string subject = "CATchA email verification";
    std::string body = "If you registered to CATchA, your register key is ";
    body += key;
    body += " If you did not registered there, you can ignore this email.";

    // PowerShell parancs �ssze�ll�t�sa
    std::string command = "powershell -Command \"";
    command += "$securePassword = ConvertTo-SecureString \\\"" + password + "\\\" -AsPlainText -Force; ";
    command += "$credentials = New-Object System.Management.Automation.PSCredential (\\\"" + username + "\\\", $securePassword); ";
    command += "Send-MailMessage -From \\\"" + username + "\\\" -To \\\"" + recipient + "\\\" -Subject \\\"" + subject + "\\\" ";
    command += "-Body \\\"" + body + "\\\" -SmtpServer \\\"" + smtpServer + "\\\" -Port " + smtpPort + " -UseSsl -Credential $credentials\"";

    // Debug ki�r�s
    //std::cout << "Futtatott parancs: " << command << std::endl;

    int result = system(command.c_str());

    if (result != 0) {
        key = "abc";
    }
    else {
        std::cout << "E-mail sikeresen elk�ldve!" << std::endl;
    }

    return key;
}



bool vanuser(const std::string keresett) {

    std::ifstream file("jatekos.txt");
    std::string sor;
    while (std::getline(file, sor)) {
        if (sor.rfind("Becen�v:", 0) == 0) { // ha a sor "Becen�v:"-vel kezd�dik
            std::string becenev = sor.substr(9); // 8 karaktert kihagy ("Becen�v: ")
            std::cout << "Az aktualisan nezett becenev " << becenev << "mig a keresett " << keresett << "!\n";
            if (becenev == keresett) {
                return true;
            }
        }
    }
    return false;
}



bool ervenyes_felhasznalo(const std::string& fajlnev, const std::string& becenev, const std::string& jelszo) {
    std::ifstream fajl(fajlnev);
    if (!fajl.is_open()) {
        std::cerr << "Nem siker�lt megnyitni a f�jlt!" << std::endl;
        return false;
    }

    std::string sor;
    std::string akt_becenev;
    std::string akt_jelszo;

    while (std::getline(fajl, sor)) {
        if (sor.rfind("Becen�v:", 0) == 0) {
            akt_becenev = sor.substr(9); // "Becen�v: " ut�n
        }
        else if (sor.rfind("Jelszo:", 0) == 0) {
            akt_jelszo = sor.substr(8); // "Jelszo: " ut�n

            // Ekkor m�r van egy p�runk � ellen�rz�s
            if (akt_becenev == becenev && akt_jelszo == jelszo) {
                return true;
            }

            // Ellenkez� esetben tov�bb megy�nk a k�vetkez� blokkra
            akt_becenev.clear();
            akt_jelszo.clear();
        }
    }

    return false;
}


std::string szovegbekeres(std::string fajlnev) {

    std::string szoveg;
    std::fstream fajl(fajlnev);
    std::string fajlsor;
    while (std::getline(fajl, fajlsor)) std::cout << "\n" << fajlsor;
    fajl.close();
    std::getline(std::cin, szoveg);
    std::cout << "              |_________________________________________________| \n \n";
    return szoveg;

}


User regisztracio() {

    bool vanilyen = true;
    std::string user;
    while (vanilyen) {
        for (int i = 0; i < 25; i++) std::cout << "\n";
        user = szovegbekeres("username.txt");
        vanilyen = vanuser(user);
    }
    for (int i = 0; i < 5; i++) std::cout << "\n";
    std::string email = szovegbekeres("email.txt");

    int counter = 3;
    bool verified = false;
    while (not verified) {

        std::cout << "\n \n \n \n \n Verifying your e-mail account.. Please wait..";
        std::string key = mail(email);
        std::string userkey;

        if (key == "abc") {

            std::cout << "Ooops.. wrong email.. Try again!";
            counter = 0;

        }

        else {

            std::fstream fajl("verifytop.txt");
            std::string fajlsor;
            while (std::getline(fajl, fajlsor)) std::cout << "\n" << fajlsor;
            fajl.close();
            std::cout << email << ". Please follow the steps there! ";

            userkey = szovegbekeres("verifybottom.txt");
        }

        if (userkey == key) verified = true;
        else {

            std::cout << "\n \n \n \n \n Ooops.. That's not it. We're gonna resend it in (5) In " << counter << "tries you get to enter your e-mail again.";
            if (counter == 0) { email = szovegbekeres("email.txt"); counter = 3; }
            counter--;

        }
    }
    std::string password = szovegbekeres("password.txt");
    std::string repass;
    while (repass != password) repass = szovegbekeres("repass.txt");

    std::fstream file_example("jatekos.txt", std::ofstream::out | std::ofstream::app);
    file_example << "e-mail c�m: " << email << "\nBecen�v: " << user << "\nJelszo: " << password << "\nJatszott: 0\n\n";
    return User(email, user, password, 0);
}




User bejelentkezes() {

    std::string user;
    std::string pass;
    bool helyes = false;
    while (not helyes) {

        user = szovegbekeres("nickname.txt");
        pass = szovegbekeres("pass.txt");
        helyes = ervenyes_felhasznalo("jatekos.txt", user, pass);
        if (not helyes) std::cout << "\n \n \n \n Uhh something went wrong.. Maybe you did a typeo? \n \n \n";

    }
    return User("", user, pass, 0);
}

void palya() {} 

#endif // !FUGGVENYEK_H 



