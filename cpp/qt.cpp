#include <QApplication>
#include <QPushButton>

int main_2(int argc, char **argv)
{
 QApplication app (argc, argv);

 QPushButton button ("Hello world !");
 button.show();

 return app.exec();
}
