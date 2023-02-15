#include <QApplication>
#include "window.h"
#include "card_loader.h"
#include "card.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    BoosterApp::Card c;
    std::string str("Animate Wall	alpha	lea/1	lea	W	W	{W}	1	Enchantment - Aura				R		enchantment		Enchant Wall | Enchanted Wall can attack as though it didn't have defender."); 
    //std::string str; 
    c.parse(str); 
    BoosterApp::CardLoader cl;
    cl.write_something();
    BoosterApp::Window window;
    window.show();
    return app.exec();
}
