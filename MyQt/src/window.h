#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;

namespace BoosterApp {

    class Window : public QWidget
    {
        Q_OBJECT
        public:
            explicit Window(QWidget *parent = 0);
        signals:
            void counterReached();
        private slots:
            void slotButtonClicked(bool checked);
        private:
            QPushButton *m_button;
            int m_counter = 0;
    };

} // namespace

#endif // WINDOW_H
