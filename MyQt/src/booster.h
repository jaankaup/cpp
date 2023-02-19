#ifndef BOOSTER_H
#define BOOSTER_H

//#include <optional>
#include <QWidget>
#include <QLabel>

class QLabel;

class Booster : public QWidget
{
    Q_OBJECT

    public:
        explicit Booster(QWidget *parent = 0);
        // ~Booster() {};
    signals:
        //void counterReached();
    private slots:
        //void slotButtonClicked(bool checked);
    private:
        QLabel* p_label;
        //std::unique_ptr<QLabel> p_label;
};

#endif
