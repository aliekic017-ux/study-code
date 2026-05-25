#include <iostream>
#include <string>


class BankAccount
{
    private:
    
        std::string owner;
        double balance = 0.0;

        // Wenn balance am Anfang nicht mit einem bestimmten Wert initialisiert wird, so kann dieser einen
        // einen zufälligen Soeicherwert enthalten.

        // Lösung: Der Wert von Balance am Anfang mit einem Wert i.d.F 0.0 initialisieren..
        
    
    public:

        void setOwner(std::string ownerName)  // verändert den Besitzer 
        {
            owner = ownerName;
        }

        std::string getOwner () // gibt den Besitzer zurück
        {
            return owner;
        }

        void deposit (double amount) // gibt an wie hoch Balance ist -> verändert balance
        {
            // nur positive Beträge einzahlen 

            if (amount > 0)
            {
                balance = balance + amount;
            }
            else
            {
                std::cout << "Fehler beim Einzaheln des Geldes" << std::endl;
            }
        }

        void withdraw (double amount) // gibt an wie hoch Balance ist -> verändert Balance
        {
            // Geld abheben, nur wenn Betrag positiv ist und genug Geld auf dem Konto vorhanden ist
            if (amount > 0 && balance >= amount)
            {
                balance = balance - amount; 
            } 
            else 
            {
                std::cout<< "Fehler beim Auszahlen des Geldes" << std::endl;
            }
        }

        double getBalance ();  // gibt Kontostand zurück


        void getAccountInfo ();  // gibt etwas aus 

};

double BankAccount::getBalance()
{
    return balance;
}

void BankAccount::getAccountInfo()
{
    std::cout << "Owner: " << owner << std::endl;
    std::cout << "Balance: " << balance << std::endl;

}




int main ()
{
    BankAccount account;

    //setze Owner
    account.setOwner("Ali");

    //Geld einzahlen
    account.deposit(100);

    //Geld aiuszahlen
    account.withdraw(45);

    //Kontoinformationen ausgeben
    account.getAccountInfo();

    // Fehler testen
    account.withdraw(-32);

    // Fehler 2 testen --> mehr Geld als möglich ausbezahlen
    account.withdraw(150);


    return 0;
}