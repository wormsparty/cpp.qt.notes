#include <QMainWindow>
#include <QApplication>
#include <QListView>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QStringListModel>
#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <iostream>

#if defined(_WIN64) || defined(_WIN32)

int WinMain()
{
	QApplication app(__argc, __argv);

#else

	int main(int argc, char** argv)
	{
		QApplication app(argc, argv);

#endif
	QMainWindow main;
    QWidget widget;
	QTextEdit editor;
	QGridLayout layout;
	QListView left;
	QStringListModel model;
	QMenuBar bar;
	QMenu menu;

	QAction select("&Select folder");
    select.setShortcuts(QKeySequence::Open);

	QObject::connect(&select, &QAction::triggered, []()
	{
    	std::cout << "Select" << std::endl;
	});

	QAction create("&New entry");
    create.setShortcuts(QKeySequence::New);

	QObject::connect(&create, &QAction::triggered, []()
	{
    	std::cout << "Create" << std::endl;
	});

	QAction quit("&Quit");
    quit.setShortcuts(QKeySequence::Quit);

	QObject::connect(&quit, &QAction::triggered, [&app]()
	{
    	app.closeAllWindows();
	});

	menu.setTitle("File");
	menu.addAction(&select);
	menu.addAction(&create);
	menu.addAction(&quit);

	bar.addMenu(&menu);

    QStringList list;
    list << "Clair de Lune" << "Reverie" << "Prelude";
    model.setStringList(list);

	left.setEditTriggers(QAbstractItemView::NoEditTriggers);
    left.setModel(&model);
	left.setMaximumWidth(200);

	layout.addWidget(&left, 0, 0, 1, 1);

	editor.setPlainText("I am text.");	
	layout.addWidget(&editor, 0, 1, 1, 1);
	
    widget.setLayout(&layout);
    widget.setWindowTitle("Hi !");

	main.setCentralWidget(&widget);
	main.setMenuBar(&bar);
    main.show();

	return app.exec();
}
