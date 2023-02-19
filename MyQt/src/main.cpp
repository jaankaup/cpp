#include <QApplication>
#include "window.h"
#include "card_loader.h"
#include "card.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    BoosterApp::CardLoader cl;
    cl.load_cards();

    BoosterApp::Window window;
    window.show();
    return app.exec();
}
