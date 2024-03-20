#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QSqlDatabase>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  // Ntework
  QNetworkAccessManager *manager = new QNetworkAccessManager(NULL);

  // DB
  QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
  db.setHostName("acidalia");
  db.setDatabaseName("customdb");
  db.setUserName("mojito");
  db.setPassword("J0a1m8");
  bool ok = db.open();

  delete manager;

  return a.exec();
}
