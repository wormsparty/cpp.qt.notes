#include <QApplication>
#include <QListView>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QStringListModel>

#if defined(_WIN64) || defined(_WIN32)

int WinMain()
{
	QApplication app(__argc, __argv);

#else

	int main(int argc, char** argv)
	{
		QApplication app(argc, argv);

#endif

	QGridLayout layout;
	QListView left;
	QStringListModel model;

    QStringList list;
    list << "Clair de Lune" << "Reverie" << "Prelude";
    model.setStringList(list);

    left.setModel(&model);
	left.setMaximumWidth(200);

	layout.addWidget(&left, 0, 0, 1, 1);

	QTextEdit editor;
	editor.setPlainText("I am text.");	
	layout.addWidget(&editor, 0, 1, 1, 1);
	
    QWidget widget;
    widget.setLayout(&layout);
    widget.setWindowTitle("Hi !");
    widget.show();

	return app.exec();
}
