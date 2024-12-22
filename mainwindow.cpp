#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    xCoordinate(0), yCoordinate(0), zCoordinate(0),
    xTranslation(0), yTranslation(0), zTranslation(0),
    scaleX(1.0f), scaleY(1.0f), scaleZ(1.0f)  // Initialize scale
{
    ui->setupUi(this);

    // Initialisation du QLabel pour afficher les coordonnées
    coordinatesLabel = ui->coordinatesLabel;  // Automatiquement lié par Qt Designer

    // Définir le texte initial du QLabel (coordonnées = (0, 0, 0))
    updateCoordinates(0, 0, 0);

    // Initialisation des positions des sliders (assumer la valeur 0 initialement)
    ui->verticalSlider->setValue(0);         // Rotation X
    ui->verticalSlider_2->setValue(0);       // Rotation Y
    ui->verticalSlider_3->setValue(0);       // Rotation Z
    ui->translationSliderX->setValue(0);     // Translation X
    ui->translationSliderY->setValue(0);     // Translation Y
    ui->translationSliderZ->setValue(0);     // Translation Z
    ui->scaleSliderX->setValue(100);         // Scale X (100% as default)
    ui->scaleSliderY->setValue(100);         // Scale Y
    ui->scaleSliderZ->setValue(100);         // Scale Z

    // Connexions des signaux et des slots des sliders
    connect(ui->verticalSlider, &QSlider::actionTriggered, this, &MainWindow::on_verticalSlider_actionTriggered);
    connect(ui->verticalSlider_2, &QSlider::actionTriggered, this, &MainWindow::on_verticalSlider_2_actionTriggered);
    connect(ui->verticalSlider_3, &QSlider::actionTriggered, this, &MainWindow::on_verticalSlider_3_actionTriggered);
    connect(ui->translationSliderX, &QSlider::actionTriggered, this, &MainWindow::on_translationSliderX_actionTriggered);
    connect(ui->translationSliderY, &QSlider::actionTriggered, this, &MainWindow::on_translationSliderY_actionTriggered);
    connect(ui->translationSliderZ, &QSlider::actionTriggered, this, &MainWindow::on_translationSliderZ_actionTriggered);
    connect(ui->scaleSliderX, &QSlider::actionTriggered, this, &MainWindow::on_scaleSliderX_actionTriggered);
    connect(ui->scaleSliderY, &QSlider::actionTriggered, this, &MainWindow::on_scaleSliderY_actionTriggered);
    connect(ui->scaleSliderZ, &QSlider::actionTriggered, this, &MainWindow::on_scaleSliderZ_actionTriggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCoordinates(double x, double y, double z)
{
    // Mettre à jour le QLabel avec les coordonnées
    QString coordinatesText = QString("X: %1, Y: %2, Z: %3").arg(x).arg(y).arg(z);
    coordinatesLabel->setText(coordinatesText);  // Mettre à jour les coordonnées affichées
}

void MainWindow::on_verticalSlider_actionTriggered(int action)
{
    // Mise à jour de la rotation X selon la valeur du slider
    ui->widget->rotate_x = ui->verticalSlider->value();
    ui->widget->update(); // Mettre à jour le widget
}

void MainWindow::on_verticalSlider_2_actionTriggered(int action)
{
    // Mise à jour de la rotation Y selon la valeur du slider
    ui->widget->rotate_y = ui->verticalSlider_2->value();
    ui->widget->update(); // Mettre à jour le widget
}

void MainWindow::on_verticalSlider_3_actionTriggered(int action)
{
    // Mise à jour de la rotation Z selon la valeur du slider
    ui->widget->rotate_z = ui->verticalSlider_3->value();
    ui->widget->update(); // Mettre à jour le widget
}

void MainWindow::on_translationSliderX_actionTriggered(int action)
{
    // Mise à jour de la translation X selon la valeur du slider
    xTranslation = ui->translationSliderX->value();
    ui->widget->setTranslationX(xTranslation); // Mettre à jour la translation pour le widget
    ui->widget->update(); // Mettre à jour le widget
    updateCoordinates(xTranslation, yTranslation, zTranslation); // Mettre à jour les coordonnées dans le QLabel
}

void MainWindow::on_translationSliderY_actionTriggered(int action)
{
    // Mise à jour de la translation Y selon la valeur du slider
    yTranslation = ui->translationSliderY->value();
    ui->widget->setTranslationY(yTranslation); // Mettre à jour la translation pour le widget
    ui->widget->update(); // Mettre à jour le widget
    updateCoordinates(xTranslation, yTranslation, zTranslation); // Mettre à jour les coordonnées dans le QLabel
}

void MainWindow::on_translationSliderZ_actionTriggered(int action)
{
    // Mise à jour de la translation Z selon la valeur du slider
    zTranslation = ui->translationSliderZ->value();
    ui->widget->setTranslationZ(zTranslation); // Mettre à jour la translation pour le widget
    ui->widget->update(); // Mettre à jour le widget
    updateCoordinates(xTranslation, yTranslation, zTranslation); // Mettre à jour les coordonnées dans le QLabel
}

void MainWindow::on_scaleSliderX_actionTriggered(int action)
{
    // Mise à jour de l'échelle X selon la valeur du slider
    scaleX = ui->scaleSliderX->value() / 100.0f; // Convertir la valeur en facteur de mise à l'échelle
    ui->widget->setScaleX(scaleX); // Appliquer l'échelle au widget
    ui->widget->update(); // Mettre à jour le widget
}

void MainWindow::on_scaleSliderY_actionTriggered(int action)
{
    // Mise à jour de l'échelle Y selon la valeur du slider
    scaleY = ui->scaleSliderY->value() / 100.0f; // Convertir la valeur en facteur de mise à l'échelle
    ui->widget->setScaleY(scaleY); // Appliquer l'échelle au widget
    ui->widget->update(); // Mettre à jour le widget
}

void MainWindow::on_scaleSliderZ_actionTriggered(int action)
{
    // Mise à jour de l'échelle Z selon la valeur du slider
    scaleZ = ui->scaleSliderZ->value() / 100.0f; // Convertir la valeur en facteur de mise à l'échelle
    ui->widget->setScaleZ(scaleZ); // Appliquer l'échelle au widget
    ui->widget->update(); // Mettre à jour le widget
}
