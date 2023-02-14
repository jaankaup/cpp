#include <QApplication>
#include "window.h"
#include "card_loader.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
   
    BoosterApp::CardLoader cl;
    cl.write_something();
    BoosterApp::Window window;
    window.show();
   
    return app.exec();
}
