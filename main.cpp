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

    QWidget *memberTab2 = new QWidget;
    QLabel *memberLabel2 = new QLabel("這是組員2頁面");
    QPushButton *styleButton = new QPushButton("Front select");
    QVBoxLayout *member2Layout = new QVBoxLayout;
    member2Layout->addWidget(memberLabel2);
    member2Layout->addWidget(styleButton);
    memberTab2->setLayout(member2Layout);


    QObject::connect(styleButton, &QPushButton::clicked, [=]() {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, memberLabel0->font(), nullptr, "選擇字體");
        if (ok) {
            memberLabel0->setFont(font);
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
