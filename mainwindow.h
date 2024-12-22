#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>  // Inclure QString pour gérer les chaînes de caractères
#include <QLabel>   // Inclure QLabel pour afficher les coordonnées
#include <QSlider>  // Inclure QSlider pour les sliders

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT // Ajout de cette macro pour les signaux/slots

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    double scaleX, scaleY, scaleZ;

public slots:
    void updateCoordinates(double x, double y, double z); // Slot pour mettre à jour les coordonnées

    // Déclaration des autres slots pour les sliders
    void on_verticalSlider_actionTriggered(int action);       // Rotation X
    void on_verticalSlider_2_actionTriggered(int action);     // Rotation Y
    void on_verticalSlider_3_actionTriggered(int action);     // Rotation Z
    void on_translationSliderX_actionTriggered(int action);   // Translation X
    void on_translationSliderY_actionTriggered(int action);   // Translation Y
    void on_translationSliderZ_actionTriggered(int action);   // Translation Z

    // Slots pour la mise à l'échelle
    void on_scaleSliderX_actionTriggered(int action);  // Ajout de ce slot
    void on_scaleSliderY_actionTriggered(int action);  // Ajout de ce slot
    void on_scaleSliderZ_actionTriggered(int action);  // Ajout de ce slot

private:
    Ui::MainWindow *ui;
    QLabel *coordinatesLabel; // Un QLabel pour afficher les coordonnées

    // Variables pour stocker les coordonnées des sliders (rotation)
    double xCoordinate, yCoordinate, zCoordinate;

    // Variables pour stocker les coordonnées de translation
    double xTranslation, yTranslation, zTranslation;

    // Position initiale des sliders
    int initialSliderValue;
};

#endif // MAINWINDOW_H
