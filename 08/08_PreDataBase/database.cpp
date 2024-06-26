#include "database.h"

DataBase::DataBase(QObject* parent) : QObject{ parent }
{
    dataBase = new QSqlDatabase();
}

DataBase::~DataBase()
{
    delete dataBase;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{
    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);
}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{
    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());

    ///Тут должен быть код ДЗ

    bool status;
    status = dataBase->open();
    emit sig_SendStatusConnection(status);
}

void DataBase::LoadAllTable(QTableView* view)
{
    QSqlTableModel* model = new QSqlTableModel(this, *dataBase);

    model->setTable("film");

    model->select();
    model->setHeaderData(0, Qt::Horizontal, QString("ID"));
    model->setHeaderData(1, Qt::Horizontal, QString("Название фильма"));
    model->setHeaderData(2, Qt::Horizontal, QString("Описание фильма"));

    //    qDebug() << model->lastError().text();
    view->setModel(model);
    view->show();
}

bool DataBase::LoadCategoryTable(QTableView* view, int id)
{
    bool res{ false };
    QString request = "";
    if (id == 1)
    {
        request =
            "SELECT title, description FROM film f JOIN film_category "
            "fc on f.film_id = fc.film_id JOIN category c on c.category_id = fc.category_id "
            "WHERE c.name = 'Comedy'";
    }
    else if (id == 2)
    {
        request =
            "SELECT title, description FROM film f JOIN film_category "
            "fc on f.film_id = fc.film_id JOIN category c on c.category_id = fc.category_id "
            "WHERE c.name = 'Horror'";
    }

    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(request, *dataBase);

    model->setHeaderData(0, Qt::Horizontal, QString("Название фильма"));
    model->setHeaderData(1, Qt::Horizontal, QString("Описание фильма"));
    if (model->lastError().isValid())
    {
        res = true;
    }

    view->setModel(model);
    view->show();
    return res;
}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{
    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();
}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QString request)
{
    ///Тут должен быть код ДЗ
}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
