#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QSettings>
#include "flowlayout.h"
#include "connectionparameters.h"
#include "connectiontile.h"
#include "connectioneditor.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public slots:
        void updateConnections(ConnectionParameters* cnx);
        void removeConnection(ConnectionParameters* cnx);

    protected:
        void closeEvent(QCloseEvent *event);

    private:
        void readSettings();
        void writeSettings();
        void displayConnectionTile();

        Ui::MainWindow *ui;
        QSettings m_Settings;

        std::list<ConnectionParameters*> m_ListCnx;
        ConnectionEditor* m_ConnectionEditor;

        FlowLayout* m_CnxLayout;
        ConnectionTile* m_AddConnectionTile;
};

#endif // MAINWINDOW_H
