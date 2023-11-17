// GUI
#include <QApplication>

// Network
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QNetworkReply>

int main() {
    QApplication app(argc, argv);

	QUrlQuery postData;
	postData.addQueryItem("foo", "one");
	postData.addQueryItem("bar", "two");
	QNetworkRequest request(QUrl("http://localhost:5000"));
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

	QNetworkAccessManager networkManager;
	std::string response;

    QObject::connect(&networkManager, &QNetworkAccessManager::finished, [&](QNetworkReply* reply) {
		if (reply->error() == 1) {
			std::cout << reply->errorString().toStdString() << std::endl;
		} else if (reply->error() != 200) {
			std::cout << "Error: " << reply->error() << std::endl;
		} else {
			std::cout << "OK. Reponse: " << std::endl << response << std::endl;
		}
	});

	auto reply = networkManager.post(request, postData.toString(QUrl::FullyEncoded).toUtf8());

	QObject::connect(reply, &QIODevice::readyRead, [&]{
		response.append(reply->readAll().toStdString());
	});

    return app.exec();
}
