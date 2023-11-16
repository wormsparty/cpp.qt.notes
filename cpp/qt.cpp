#include <QApplication>
#include <QPushButton>

#if defined(_WIN64) || defined(_WIN32)

int WinMain()
{
	QApplication app(__argc, __argv);

#else

	int main(int argc, char** argv)
	{
		QApplication app(argc, argv);

#endif

	QPushButton button ("Hello world !");
	button.show();

	return app.exec();
}
