#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTime(); //- слот обновления времени
    void on_start_stop_clicked(); //- слот нажатия кнопки старт/стоп
    void on_cleaner_clicked(); //- слот очистки
    void on_circle_clicked(); //- слот кругов

private:
    Ui::MainWindow *ui;

    QTimer *timer; //- указатель таймера
    double elapsedTime; //- время в десятых долях
    int circleCount; //- круги
};
#endif // MAINWINDOW_H
