#include <QApplication>
#include <QTabWidget>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QLabel *memberLabel0 = new QLabel("隊長\n組員1\n組員2\n組員3");
    QTabWidget *tabWidget = new QTabWidget;
    QWidget *memberTab0 = new QWidget;
    memberLabel0->setStyleSheet("color: blue;");
    QVBoxLayout *memberLayout0 = new QVBoxLayout;
    memberLayout0->addWidget(memberLabel0);
    memberTab0->setLayout(memberLayout0);

    QWidget *memberTab1 = new QWidget;
    QLabel *memberLabel1 = new QLabel("這是組員1頁面");
    QVBoxLayout *memberLayout1 = new QVBoxLayout;
    QPushButton *colorButton = new QPushButton("color select");
    memberLayout1->addWidget(memberLabel1);
    memberLayout1->addWidget(colorButton);
    memberTab1->setLayout(memberLayout1);


    QObject::connect(colorButton, &QPushButton::clicked, [=]() {
        QColor color = QColorDialog::getColor(Qt::white, nullptr, "選擇文字顏色");
        if (color.isValid()) {
            QString colorName = color.name();
            memberLabel0->setStyleSheet(QString("color: %1;").arg(colorName));
        }
    });
    
    tabWidget->addTab(memberTab0, "隊長");
    tabWidget->addTab(memberTab1, "組員1");
    tabWidget->addTab(memberTab2, "組員2");
    tabWidget->addTab(memberTab3, "組員3");

    tabWidget->setWindowTitle("WorkGroup");
    tabWidget->resize(400, 300);
    tabWidget->show();

    return app.exec();
}
