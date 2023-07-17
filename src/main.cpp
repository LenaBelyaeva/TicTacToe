#include "GuiModel.h"
#include "GameManager.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
	QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication::setHighDpiScaleFactorRoundingPolicy(
	            Qt::HighDpiScaleFactorRoundingPolicy::PassThrough
	            );

	QGuiApplication::setOrganizationName("MeowMeow");
	QGuiApplication::setOrganizationDomain("com.meowmeow");
	QGuiApplication::setApplicationName("Tic-Tac-Toe Game");

	QGuiApplication app(argc, argv);

	GuiModel model;
	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty("guiModel", &model);
	engine.load(QUrl("qrc:/qml/MainWindow.qml"));

	return app.exec();
}
