#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    srand((int)time(0));
    Game New_Game ;
    stack<Carte> S ;
    S=New_Game.initialisation() ;
      stack<Carte> S1 ;
      while(S1.size()< 24 )
        {
          S1.push(S.top()) ;
          S.pop() ;
        }
    QApplication a(argc, argv);
    MainWindow w(nullptr,S1,S);
    w.show();
    return a.exec();
}
